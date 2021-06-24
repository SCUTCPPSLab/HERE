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
#include "XMLParser4CFB.h"
#include "DynFBTypeEntry.h"
#include "cfb.h"
CXMLParser4CFB::CXMLParser4CFB(mxml_node_t *rootNode, TCCState *s)
	:rootNode(rootNode),
	s(s)
{

}
CXMLParser4CFB::~CXMLParser4CFB()
{

}

EMGMResponse CXMLParser4CFB::createDynamicFB(CResource * pa_pRes, CStringDictionary::TStringId paTypeId, CStringDictionary::TStringId paNameId)
{
	EMGMResponse retVal = e_RDY;
	parseInterfaces(rootNode, s);
	
	TForteByte *pa_acFBConnData = new TForteByte[sizeof(CEventConnection) * unEONum + sizeof(TDataConnectionPtr) * unDINum +
		sizeof(CDataConnection) * unDONum];
	TForteByte *pa_acCFBVarsData = new TForteByte[sizeof(CIEC_ANY) *(unDINum + unDONum)];
	m_FBNData =  (SCFB_FBNData*)malloc(sizeof(SCFB_FBNData));
	parseFBN(pa_pRes,NULL,true);
	parseEC(pa_pRes, NULL, true);
	parseDC(pa_pRes, NULL, true);
	m_FBNData->m_nNumParams = 0;
	m_FBNData->m_pstParams = NULL;
	m_FB = new CDynCFB(pa_pRes, m_FBInterf, paNameId, m_FBNData, pa_acFBConnData, pa_acCFBVarsData);// (pa_pRes, m_FBInterf, paNameId, NULL, pa_acFBConnData, pa_acBasicFBVarsData, unECStateNum, unECTransitNum);
	if (0 != m_FB)
	{
		m_FB->setFBTypeId(paTypeId);
		// perform reset to move it into idle state and set the initial values
		m_FB->changeFBExecutionState(cg_nMGM_CMD_Reset);
		lstDynCFBType.push_back(m_FB);
	}
	if (retVal == e_RDY)
	{
		//CDynFBTypeEntry* newTypeEntry = new CDynFBTypeEntry(paTypeId, m_FB->createFB);
	}
	return retVal;
}
CFunctionBlock* CXMLParser4CFB::getFB(CStringDictionary::TStringId paTypeId)
{
	CDynCFB* retFB = NULL;
	for (TDynCFBTypeList::Iterator itRunner(lstDynCFBType.begin());
	itRunner != lstDynCFBType.end(); ++itRunner)
	{
		if (itRunner->getFBTypeId() == paTypeId)
		{
			retFB = *itRunner;
			break;
		}
	}
	return dynamic_cast<CFunctionBlock*>(retFB);
}
int CXMLParser4CFB::getFBIdx(const char* pa_strFBName)
{
	int ret = -1;
	for (unsigned int i = 0; i < m_FBNData->m_nNumFBs; i++)
	{
		if (!strncmp(m_FBNameList[i], pa_strFBName,strlen(m_FBNameList[i])))
		{
			ret = i;
			break;
		}
	}
	return ret;
}
void CXMLParser4CFB::parseFBN(CResource * pa_pRes, CCompositeFB*pa_FB, bool pa_bInit)
{
	mxml_node_t *node;
	m_FBNData->m_nNumFBs = 0;
	for (node = mxmlFindElement(rootNode, rootNode, "FB", 0, 0, MXML_DESCEND);
	node != NULL;
		node = mxmlFindElement(node, rootNode, "FB", 0, 0, MXML_DESCEND)
		)
	{
		m_FBNData->m_nNumFBs++;
	}
	if (m_FBNData->m_nNumFBs != 0)
	{
		int i = 0;
		SCFB_FBInstanceData* runner = NULL;
		m_FBNData->m_pstFBInstances = new SCFB_FBInstanceData[m_FBNData->m_nNumFBs];
		m_FBNameList = new const char*[m_FBNData->m_nNumFBs];
		runner = const_cast<SCFB_FBInstanceData*>(m_FBNData->m_pstFBInstances);
		for (node = mxmlFindElement(rootNode, rootNode, "FB", 0, 0, MXML_DESCEND);
		node != NULL;
			node = mxmlFindElement(node, rootNode, "FB", 0, 0, MXML_DESCEND)
			)
		{
			const char* c = mxmlElementGetAttr(node, "Name");
			const char* c2 = mxmlElementGetAttr(node, "Type");
			runner[i].m_nFBInstanceNameId = CStringDictionary::getInstance().getId(c);
			runner[i].m_nFBTypeNameId = CStringDictionary::getInstance().getId(c2);
			if (runner[i].m_nFBInstanceNameId == CStringDictionary::scm_nInvalidStringId)
			{
				runner[i].m_nFBInstanceNameId = CStringDictionary::getInstance().insert(c);
			}
			if (runner[i].m_nFBTypeNameId == CStringDictionary::scm_nInvalidStringId)
			{
				runner[i].m_nFBTypeNameId = CStringDictionary::getInstance().insert(c2);
			}
			m_FBNameList[i] = c;
			i++;
		}
	}
	else
	{
		m_FBNData->m_pstFBInstances = NULL;
	}
}
void CXMLParser4CFB::parseEC(CResource * pa_pRes, CCompositeFB*pa_FB, bool pa_bInit)
{
	mxml_node_t *node;
	mxml_node_t *ecnode;
	m_FBNData->m_nNumEventConnections  = 0;
	node = mxmlFindElement(rootNode, rootNode, "EventConnections", 0, 0, MXML_DESCEND);
	for (ecnode = mxmlFindElement(node, node, "Connection", 0, 0, MXML_DESCEND);
	ecnode != NULL;
		ecnode = mxmlFindElement(ecnode, node, "Connection", 0, 0, MXML_DESCEND)
		)
	{
		m_FBNData->m_nNumEventConnections++;
	}
	if (m_FBNData->m_nNumEventConnections != 0)
	{
		int i = 0;
		SCFB_FBConnectionData* runner = NULL;
		m_FBNData->m_pstEventConnections = new SCFB_FBConnectionData[m_FBNData->m_nNumEventConnections];
		runner = const_cast<SCFB_FBConnectionData*>(m_FBNData->m_pstEventConnections);
		node = mxmlFindElement(rootNode, rootNode, "EventConnections", 0, 0, MXML_DESCEND);
		for (ecnode = mxmlFindElement(node, node, "Connection", 0, 0, MXML_DESCEND);
		ecnode != NULL;
			ecnode = mxmlFindElement(ecnode, node, "Connection", 0, 0, MXML_DESCEND)
			)
		{
			const char* c = mxmlElementGetAttr(ecnode, "Source");
			const char* c2 = mxmlElementGetAttr(ecnode, "Destination");
			const char* srcportname = strchr(c, '.');
			const char* dstportname = strchr(c2, '.');
			if (srcportname == NULL)
			{
				runner[i].m_nSrcId = CStringDictionary::getInstance().getId(c);
				if (runner[i].m_nSrcId == CStringDictionary::scm_nInvalidStringId)
				{
					runner[i].m_nSrcId = CStringDictionary::getInstance().insert(c);
				}
				runner[i].m_nSrcId = GENERATE_CONNECTION_PORT_ID_1_ARG(runner[i].m_nSrcId);
				runner[i].m_nSrcFBNum = -1;
				
			}
			else
			{
				int len,fbid,portid;
				char* srcfbname;
				char* eoname = const_cast<char*>(srcportname);
				char* totalname = const_cast<char*>(c);
				len = eoname - c;
				if (len>0)
				{
					srcfbname = new char[len];
					memset(srcfbname, 0x00, len*sizeof(char));
					memcpy(srcfbname, c, len);
				}
				eoname++;
				portid = CStringDictionary::getInstance().getId(eoname);
				if (portid == CStringDictionary::scm_nInvalidStringId)
				{
					portid = CStringDictionary::getInstance().insert(eoname);
				}
				fbid = CStringDictionary::getInstance().getId(srcfbname);
				if (fbid == CStringDictionary::scm_nInvalidStringId)
				{
					fbid = CStringDictionary::getInstance().insert(srcfbname);
				}
				runner[i].m_nSrcFBNum = getFBIdx(srcfbname);
				runner[i].m_nSrcId = GENERATE_CONNECTION_PORT_ID_2_ARG(fbid,portid);
				delete[]srcfbname;
			}
			if (dstportname == NULL)
			{
				runner[i].m_nDstId = CStringDictionary::getInstance().getId(c2);
				if (runner[i].m_nDstId == CStringDictionary::scm_nInvalidStringId)
				{
					runner[i].m_nDstId = CStringDictionary::getInstance().insert(c2);
				}
				runner[i].m_nDstId = GENERATE_CONNECTION_PORT_ID_1_ARG(runner[i].m_nDstId);
				runner[i].m_nDstFBNum = -1;
			}
			else
			{
				int len, fbid, portid;
				char* dstfbname;
				char* einame = const_cast<char*>(dstportname);
				len = einame - c2;
				if (len>0)
				{
					dstfbname = (char*)malloc(len*sizeof(char));
					memset(dstfbname, 0x00, len*sizeof(char));
					memcpy(dstfbname, c2, len);
				}
				einame++;
				portid = CStringDictionary::getInstance().getId(einame);
				if (portid == CStringDictionary::scm_nInvalidStringId)
				{
					portid = CStringDictionary::getInstance().insert(einame);
				}
				fbid = CStringDictionary::getInstance().getId(dstfbname);
				if (fbid == CStringDictionary::scm_nInvalidStringId)
				{
					fbid = CStringDictionary::getInstance().insert(dstfbname);
				}
				runner[i].m_nDstFBNum = getFBIdx(dstfbname);
				runner[i].m_nDstId = GENERATE_CONNECTION_PORT_ID_2_ARG(fbid, portid);
				delete[]dstfbname;
			}
			i++;
		}
		m_FBNData->m_nNumFannedOutEventConnections = 0;
		m_FBNData->m_pstFannedOutEventConnections = NULL;
	}
	else
	{
		m_FBNData->m_pstFBInstances = NULL;
	}
}
void CXMLParser4CFB::parseDC(CResource * pa_pRes, CCompositeFB*pa_FB, bool pa_bInit)
{
	mxml_node_t *node;
	mxml_node_t *dcnode;
	m_FBNData->m_nNumDataConnections = 0;
	node = mxmlFindElement(rootNode, rootNode, "DataConnections", 0, 0, MXML_DESCEND);
	for (dcnode = mxmlFindElement(node, node, "Connection", 0, 0, MXML_DESCEND);
	dcnode != NULL;
		dcnode = mxmlFindElement(dcnode, node, "Connection", 0, 0, MXML_DESCEND)
		)
	{
		m_FBNData->m_nNumDataConnections++;
	}
	if (m_FBNData->m_nNumDataConnections != 0)
	{
		int i = 0;
		SCFB_FBConnectionData* runner = NULL;
		m_FBNData->m_pstDataConnections = new SCFB_FBConnectionData[m_FBNData->m_nNumDataConnections];
		runner = const_cast<SCFB_FBConnectionData*>(m_FBNData->m_pstDataConnections);
		node = mxmlFindElement(rootNode, rootNode, "DataConnections", 0, 0, MXML_DESCEND);
		for (dcnode = mxmlFindElement(node, node, "Connection", 0, 0, MXML_DESCEND);
		dcnode != NULL;
			dcnode = mxmlFindElement(dcnode, node, "Connection", 0, 0, MXML_DESCEND)
			)
		{
			const char* c = mxmlElementGetAttr(dcnode, "Source");
			const char* c2 = mxmlElementGetAttr(dcnode, "Destination");
			const char* srcportname = strchr(c, '.');
			const char* dstportname = strchr(c2, '.');
			if (srcportname == NULL)
			{
				runner[i].m_nSrcId = CStringDictionary::getInstance().getId(c);
				if (runner[i].m_nSrcId == CStringDictionary::scm_nInvalidStringId)
				{
					runner[i].m_nSrcId = CStringDictionary::getInstance().insert(c);
				}
				runner[i].m_nSrcId = GENERATE_CONNECTION_PORT_ID_1_ARG(runner[i].m_nSrcId);
				runner[i].m_nSrcFBNum = -1;

			}
			else
			{
				int len, fbid, portid;
				char* srcfbname;
				char* eoname = const_cast<char*>(srcportname);
				char* totalname = const_cast<char*>(c);
				len = eoname - c;
				if (len>0)
				{
					srcfbname = new char[len];
					memset(srcfbname, 0x00, len*sizeof(char));
					memcpy(srcfbname, c, len);
				}
				eoname++;
				portid = CStringDictionary::getInstance().getId(eoname);
				if (portid == CStringDictionary::scm_nInvalidStringId)
				{
					portid = CStringDictionary::getInstance().insert(eoname);
				}
				fbid = CStringDictionary::getInstance().getId(srcfbname);
				if (fbid == CStringDictionary::scm_nInvalidStringId)
				{
					fbid = CStringDictionary::getInstance().insert(srcfbname);
				}
				runner[i].m_nSrcFBNum = getFBIdx(srcfbname);
				runner[i].m_nSrcId = GENERATE_CONNECTION_PORT_ID_2_ARG(fbid, portid);
				delete[]srcfbname;
			}
			if (dstportname == NULL)
			{
				runner[i].m_nDstId = CStringDictionary::getInstance().getId(c2);
				if (runner[i].m_nDstId == CStringDictionary::scm_nInvalidStringId)
				{
					runner[i].m_nDstId = CStringDictionary::getInstance().insert(c2);
				}
				runner[i].m_nDstId = GENERATE_CONNECTION_PORT_ID_1_ARG(runner[i].m_nDstId);
				runner[i].m_nDstFBNum = -1;
			}
			else
			{
				int len, fbid, portid;
				char* dstfbname;
				char* einame = const_cast<char*>(dstportname);
				len = einame - c2;
				if (len>0)
				{
					dstfbname = (char*)malloc(len*sizeof(char));
					memset(dstfbname, 0x00, len*sizeof(char));
					memcpy(dstfbname, c2, len);
				}
				einame++;
				portid = CStringDictionary::getInstance().getId(einame);
				if (portid == CStringDictionary::scm_nInvalidStringId)
				{
					portid = CStringDictionary::getInstance().insert(einame);
				}
				fbid = CStringDictionary::getInstance().getId(dstfbname);
				if (fbid == CStringDictionary::scm_nInvalidStringId)
				{
					fbid = CStringDictionary::getInstance().insert(dstfbname);
				}
				runner[i].m_nDstFBNum = getFBIdx(dstfbname);
				runner[i].m_nDstId = GENERATE_CONNECTION_PORT_ID_2_ARG(fbid, portid);
				delete[]dstfbname;
			}
			i++;
		}
		m_FBNData->m_nNumFannedOutDataConnections = 0;
		m_FBNData->m_pstFannedOutDataConnections = NULL;
	}
	else
	{
		m_FBNData->m_pstFBInstances = NULL;
	}
}