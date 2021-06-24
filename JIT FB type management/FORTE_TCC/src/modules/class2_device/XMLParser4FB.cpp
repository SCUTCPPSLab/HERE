/*******************************************************************************
* All rights reserved. This program and the accompanying materials
* are made available under the terms of the Eclipse Public License v1.0
* which accompanies this distribution, and is available at
* http://www.eclipse.org/legal/epl-v10.html
*
* Contributors:
*    #########
*      - initial implementation
*******************************************************************************/
#include "XMLParser4FB.h"
#include "XMLParser4BFB.h"
#include "XMLParser4CFB.h"

SFBInterfaceSpec* CXMLParser4FB::m_FBInterf;

static char evalText[1024];
 
CXMLParser4FB::CXMLParser4FB():
	unEINum(0),
	unEONum(0),
	unDINum(0),
	unDONum(0),
	unECStateNum(0),
	unECTransitNum(0),
	unAlgNum(0),
	unEIWithNum(0),
	unEOWithNum(0),
	bfbHandler(NULL),
	cfbHandler(NULL)
{
	rootNode = NULL;
	m_FB = NULL;
	memset(nECStateAcNum, 0x00, sizeof(TForteUInt8)*MAX_ESTATE_NUM);
}


CXMLParser4FB::~CXMLParser4FB()
{
	if (bfbHandler)
	{
		delete bfbHandler;
	}
	if (cfbHandler)
	{
		delete cfbHandler;
	}
	mxmlDelete(rootNode);
}

EMGMResponse CXMLParser4FB::createDynamicFB(CResource * pa_pRes, CStringDictionary::TStringId paTypeId,CStringDictionary::TStringId paNameId)
{
	EMGMResponse retVal = e_RDY;
	FILE		*fp;
	mxml_node_t *bfbnode = NULL;
	char fbName[256];
	const char* pa_strFBName = CStringDictionary::getInstance().get(paTypeId);
	sprintf(fbName, "/home/pi/fbtlib/%s.fbt", pa_strFBName);
	if ((fp = fopen(fbName, "rb")) == NULL)
	{
		perror(pa_strFBName);
		return e_UNSUPPORTED_TYPE;
	}
	if (rootNode)
	{
		mxmlDelete(rootNode);
		rootNode = NULL;
	}
	rootNode = mxmlLoadFile(NULL, fp, MXML_IGNORE_CALLBACK);
	fclose(fp);
	s = tcc_new();
	int ret = tcc_set_options(s, "-nostdlib");
	ret = tcc_set_output_type(s, TCC_OUTPUT_MEMORY);
	m_FBInterf = new SFBInterfaceSpec;
	bfbnode = mxmlFindElement(rootNode, rootNode, "BasicFB", 0, 0, MXML_DESCEND);
	if (bfbnode)
	{
		bfbHandler = new CXMLParser4BFB(rootNode, s);
		bfbHandler->createDynamicFB(pa_pRes, paTypeId,paNameId);
	}
	else
	{
		mxml_node_t *cfbnode = NULL;
		cfbnode = mxmlFindElement(rootNode, rootNode, "FBNetwork", 0, 0, MXML_DESCEND);
		if (cfbnode)
		{
			cfbHandler = new CXMLParser4CFB(rootNode, s);
			cfbHandler->createDynamicFB(pa_pRes, paTypeId, paNameId);
		}
	}

	return retVal;
}

CFunctionBlock * CXMLParser4FB::getFB(CStringDictionary::TStringId paTypeId)
{
	CFunctionBlock * retFB = NULL;
	if (bfbHandler)
	{
		retFB = dynamic_cast<CFunctionBlock*>(bfbHandler->getFB(paTypeId));
	}
	 if(retFB==NULL )
	{
		if (cfbHandler)
		{
			retFB = dynamic_cast<CFunctionBlock*>(cfbHandler->getFB(paTypeId));
		}
	}
	return retFB;
}
void CXMLParser4FB::parseInterfaces(mxml_node_t *rootNode, TCCState *s)
{
	mxml_node_t *var;
	mxml_node_t *node;
	mxml_node_t *with;
	char name[cg_nIdentifierLength];
	char val[256];
	const char* fbType;
	TForteUInt8 unEOWithIndexId = 0, unEIWithIndexId = 0;
	

		node = mxmlFindElement(rootNode, rootNode, "InputVars", 0, 0, MXML_DESCEND);
		fbType = mxmlElementGetAttr(mxmlFindElement(rootNode, rootNode, "FBType", 0, 0, MXML_DESCEND), "Name");
		for (var = mxmlFindElement(node, rootNode, "VarDeclaration", 0, 0, MXML_DESCEND);
		var != NULL;
			var = mxmlFindElement(var, node, "VarDeclaration", 0, 0, MXML_DESCEND)
			)
		{
			char id[3];
			const char* c = mxmlElementGetAttr(var, "Name");
			const char* type = mxmlElementGetAttr(var, "Type");
			strDIName[unDINum] = c;
			unDITypeName[unDINum] = CStringDictionary::getInstance().getId(type);
			unDIName[unDINum] = CStringDictionary::getInstance().insert(c);
			sprintf(id, "%d", unDINum);
			tcc_define_symbol(s, c, id);
			sprintf(name, "VAL_OF_%s()", c);
			sprintf(val, "((VAR* )(getDI(pa_poFBInstance, %s)))->m_uAnyData.field%s", c, type);
			tcc_define_symbol(s, name, val);
			unDINum++;
		}
		node = mxmlFindElement(rootNode, rootNode, "OutputVars", 0, 0, MXML_DESCEND);
		for (var = mxmlFindElement(node, rootNode, "VarDeclaration", 0, 0, MXML_DESCEND);
		var != NULL;
			var = mxmlFindElement(var, node, "VarDeclaration", 0, 0, MXML_DESCEND)
			)
		{
			char id[3];
			const char* c = mxmlElementGetAttr(var, "Name");
			const char* type = mxmlElementGetAttr(var, "Type");
			strDOName[unDONum] = c;
			unDOTypeName[unDONum] = CStringDictionary::getInstance().getId(type);
			unDOName[unDONum] = CStringDictionary::getInstance().insert(c);
			sprintf(id, "%d", unDONum);
			tcc_define_symbol(s, c, id);
			sprintf(name, "VAL_OF_%s()", c);
			sprintf(val, "((VAR* )(getDO(pa_poFBInstance, %s)))->m_uAnyData.field%s", c, type);
			tcc_define_symbol(s, name, val);
			unDONum++;
		}
		node = mxmlFindElement(rootNode, rootNode, "EventOutputs", 0, 0, MXML_DESCEND);
		for (var = mxmlFindElement(node, rootNode, "Event", 0, 0, MXML_DESCEND);
		var != NULL;
			var = mxmlFindElement(var, node, "Event", 0, 0, MXML_DESCEND)
			)
		{
			char evName[50];
			char id[3];
			TForteUInt8 tmpCnt = 0;
			bool bHasWith = false;
			const char* c = mxmlElementGetAttr(var, "Name");
			strEOName[unEONum] = c;
			sprintf(evName, "%s_%s", fbType, c);
			unEOName[unEONum] = CStringDictionary::getInstance().insert(c);
			sprintf(id, "%d", unEONum);
			tcc_define_symbol(s, evName, id);
			for (with = mxmlFindElement(var, var, "With", 0, 0, MXML_DESCEND);
			with != NULL;
				with = mxmlFindElement(with, var, "With", 0, 0, MXML_DESCEND)
				)
			{
				TForteUInt8 DOId;
				DOId = getDOId(mxmlElementGetAttr(with, "Var"));
				nEOWith[unEOWithIndexId] = DOId;
				bHasWith = true;
				unEOWithIndexId++;
				tmpCnt++;
			}
			if (bHasWith != true)
			{
				nEOWithIndex[unEONum] = -1;
			}
			else
			{
				nEOWith[unEOWithIndexId] = 255;
				nEOWithIndex[unEONum] = unEOWithIndexId - tmpCnt;
				unEOWithIndexId++;
			}
			unEONum++;
			unEOWithNum = unEOWithIndexId;
		}
		node = mxmlFindElement(rootNode, rootNode, "EventInputs", 0, 0, MXML_DESCEND);
		for (var = mxmlFindElement(node, rootNode, "Event", 0, 0, MXML_DESCEND);
		var != NULL;
			var = mxmlFindElement(var, node, "Event", 0, 0, MXML_DESCEND)
			)
		{
			char evName[50];
			char id[3];
			TForteUInt8 tmpCnt = 0;
			bool bHasWith = false;
			const char* c = mxmlElementGetAttr(var, "Name");
			strEIName[unEINum] = c;
			sprintf(evName, "%s_%s", fbType, c);
			unEIName[unEINum] = CStringDictionary::getInstance().insert(c);
			sprintf(id, "%d", unEINum);
			tcc_define_symbol(s, evName, id);
			for (with = mxmlFindElement(var, var, "With", 0, 0, MXML_DESCEND);
			with != NULL;
				with = mxmlFindElement(with, var, "With", 0, 0, MXML_DESCEND)
				)
			{
				TForteUInt8 DIId;
				DIId = getDIId(mxmlElementGetAttr(with, "Var"));
				nEIWith[unEIWithIndexId] = DIId;
				bHasWith = true;
				unEIWithIndexId++;
				tmpCnt++;
			}
			if (bHasWith != true)
			{
				nEIWithIndex[unEINum] = -1;
			}
			else
			{
				nEIWith[unEIWithIndexId] = 255;
				nEIWithIndex[unEINum] = unEIWithIndexId - tmpCnt;
				unEIWithIndexId++;
			}
			unEINum++;
			unEIWithNum = unEIWithIndexId;
		}

		m_FBInterf->m_nNumDIs = unDINum;
		m_FBInterf->m_nNumDOs = unDONum;
		m_FBInterf->m_nNumEIs = unEINum;
		m_FBInterf->m_nNumEOs = unEONum;

		m_FBInterf->m_aunDIDataTypeNames = new CStringDictionary::TStringId[unDINum];
		m_FBInterf->m_aunDINames = new CStringDictionary::TStringId[unDINum];
		m_FBInterf->m_aunDODataTypeNames = new CStringDictionary::TStringId[unDONum];
		m_FBInterf->m_aunDONames = new CStringDictionary::TStringId[unDONum];
		m_FBInterf->m_aunEINames = new CStringDictionary::TStringId[unEINum];
		m_FBInterf->m_anEIWithIndexes = new TForteInt16[unEINum];
		m_FBInterf->m_aunEONames = new CStringDictionary::TStringId[unEONum];
		m_FBInterf->m_anEOWithIndexes = new TForteInt16[unEONum];
		m_FBInterf->m_nNumAdapters = 0;
		m_FBInterf->m_pstAdapterInstanceDefinition = NULL;

		memcpy((void*)m_FBInterf->m_aunDIDataTypeNames, unDITypeName, unDINum*sizeof(CStringDictionary::TStringId));
		memcpy((void*)m_FBInterf->m_aunDINames, unDIName, unDINum*sizeof(CStringDictionary::TStringId));

		memcpy((void*)m_FBInterf->m_aunDODataTypeNames, unDOTypeName, unDONum*sizeof(CStringDictionary::TStringId));
		memcpy((void*)m_FBInterf->m_aunDONames, unDOName, unDONum*sizeof(CStringDictionary::TStringId));

		memcpy((void*)m_FBInterf->m_aunEINames, unEIName, unEINum*sizeof(CStringDictionary::TStringId));
		memcpy((void*)m_FBInterf->m_aunEONames, unEOName, unEONum*sizeof(CStringDictionary::TStringId));

		m_FBInterf->m_anEOWith = (TDataIOID*)malloc(unEOWithNum*sizeof(CStringDictionary::TStringId));
		memcpy((void*)m_FBInterf->m_anEOWith, nEOWith,unEOWithNum*sizeof(TDataIOID));
		memcpy((void*)m_FBInterf->m_anEOWithIndexes, nEOWithIndex, unEONum*sizeof(TForteInt16));

		m_FBInterf->m_anEIWith = (TDataIOID*)malloc(unEIWithNum*sizeof(CStringDictionary::TStringId));
		memcpy((void*)m_FBInterf->m_anEIWith, nEIWith, unEIWithNum*sizeof(TDataIOID));
		memcpy((void*)m_FBInterf->m_anEIWithIndexes, nEIWithIndex, unEINum*sizeof(TForteInt16));

}

TForteUInt8 CXMLParser4FB::getDIId(const char* pa_strDOName)
{
	TForteUInt8 i;
	TForteUInt8 retVal = 0xff;
	for (i = 0; i < unDINum; i++)
	{
		if (!strcmp(strDIName[i], pa_strDOName))
		{
			retVal = i;
			break;
		}
	}
	return retVal;
}
TForteUInt8 CXMLParser4FB::getDOId(const char* pa_strDOName)
{
	TForteUInt8 i;
	TForteUInt8 retVal = 0xff;
	for (i = 0; i < unDONum; i++)
	{
		if (!strcmp(strDOName[i], pa_strDOName))
		{
			retVal = i;
			break;
		}
	}
	return retVal;
}
TForteUInt8 CXMLParser4FB::getEIId(const char* pa_strEIName)
{
	TForteUInt8 i;
	TForteUInt8 retVal = 0xff;
	for (i = 0; i < unEINum; i++)
	{
		if (!strcmp(strEIName[i], pa_strEIName))
		{
			retVal = i;
			break;
		}
	}
	return retVal;
}
TForteUInt8 CXMLParser4FB::getEOId(const char* pa_strEOName)
{
	TForteUInt8 i;
	TForteUInt8 retVal = 0xff;
	for (i = 0; i < unEONum; i++)
	{
		if (!strcmp(strEOName[i], pa_strEOName))
		{
			retVal = i;
			break;
		}
	}
	return retVal;
}