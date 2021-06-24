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
#include "XMLParser4BFB.h"
#include "DynFBTypeEntry.h"
char CXMLParser4BFB::algText[4096] = {0};
char  CXMLParser4BFB::internalValDeclText[1024] = { 0 };
static const char* strDataTypeId[] =
{
	"ANY",
	"bool",
	"SINT",
	"INT",
	"DINT",
	"LINT",
	"USINT",
	"UINT",
	"UDINT",
	"ULINT",
	"BYTE",
	"WORD",
	"DWORD",
	"LWORD",
	"DATE",
	"TIME_OF_DAY",
	"DATE_AND_TIME",
	"TIME", //until here simple Datatypes
	"REAL",
	"LREAL",
	"STRING",
	"WSTRING",
	"DerivedData",
	"DirectlyDerivedData",
	"EnumeratedData",
	"SubrangeData",
	"ARRAY", //according to the compliance profile
	"STRUCT",
	"External", // Base for CIEC_ANY based types outside of the forte base
};
static char stdDataTypeDef[] =
"typedef union UAnyData\n"
"{\n"
"	char fieldSINT;\n"
"	unsigned char fieldBYTE;\n"
"	unsigned char fieldBOOL;\n"
"	unsigned char fieldUSINT;\n"
"	unsigned short fieldWORD;\n"
"	unsigned short fieldUINT;\n"
"	short fieldINT;\n"
"	unsigned int fieldDWORD;\n"
"	unsigned int fieldUDINT;\n"
"	int fieldDINT;\n"
"	long long fieldLINT;\n"
"	unsigned long long fieldULINT;\n"
"	float fieldREAL;\n"
"	double fieldLREAL;\n"
"	char* fieldSTRING_;\n"
"	void* fieldVP_;\n"
"}UAnyData;\n"
"typedef struct VAR\n"
"{\n"
"	UAnyData m_uAnyData;\n"
"	unsigned char	m_DataType;\n"
"}VAR;\n"
"extern VAR* getDI(void* p1, unsigned int p2);\n"
"extern VAR* getDO(void* p1, unsigned int p2);\n";

typedef union UAnyData
{
	char fieldSINT;
	unsigned char fieldBYTE;
	unsigned char fieldBOOL;
	unsigned char fieldUSINT;
	unsigned short fieldWORD;
	unsigned short fieldUINT;
	short fieldINT;
	unsigned int fieldDWORD;
	unsigned int fieldUDINT;
	int fieldDINT;
	long long fieldLINT;
	unsigned long long fieldULINT;
	float fieldREAL;
	double fieldLREAL;
	char* fieldSTRING_;
	void* fieldVP_;
}UAnyData;

typedef struct CVAR
{
	UAnyData m_uAnyData;
	TForteUInt8	m_DataType;
}CVAR;
static CVAR dynVar;
#ifdef __cplusplus  
extern "C" {
#endif 
	void convertIECType(TIEC_ANYPtr var)
	{
		CIEC_ANY::EDataTypeID id = var->getDataTypeID();
		switch (id)
		{
		case CIEC_ANY::e_ANY:
			break;
		case CIEC_ANY::e_BOOL:
			dynVar.m_uAnyData.fieldBOOL = static_cast<bool>(*static_cast<CIEC_BOOL*>(var));
			break;
		case CIEC_ANY::e_SINT:
			dynVar.m_uAnyData.fieldSINT = static_cast<TForteInt8>(*static_cast<CIEC_SINT*>(var));
			break;
		case CIEC_ANY::e_INT:
			dynVar.m_uAnyData.fieldINT = static_cast<TForteInt16>(*static_cast<CIEC_INT*>(var));
			break;
		case CIEC_ANY::e_DINT:
			 dynVar.m_uAnyData.fieldDINT = static_cast<TForteInt32>(*static_cast<CIEC_DINT*>(var));
			break;
		case CIEC_ANY::e_LINT:
			 dynVar.m_uAnyData.fieldLINT = static_cast<TForteInt64>(*static_cast<CIEC_LINT*>(var));
			break;
		case CIEC_ANY::e_USINT:
			 dynVar.m_uAnyData.fieldUSINT = static_cast<TForteUInt8>(*static_cast<CIEC_USINT*>(var));
			break;
		case CIEC_ANY::e_UINT:
			 dynVar.m_uAnyData.fieldUINT = static_cast<TForteUInt16>(*static_cast<CIEC_UINT*>(var));
			break;
		case CIEC_ANY::e_UDINT:
			 dynVar.m_uAnyData.fieldUDINT = static_cast<TForteUInt32>(*static_cast<CIEC_UDINT*>(var));
			break;
		case CIEC_ANY::e_ULINT:
			 dynVar.m_uAnyData.fieldULINT = static_cast<TForteUInt64>(*static_cast<CIEC_ULINT*>(var));
			break;
		case CIEC_ANY::e_BYTE:
			 dynVar.m_uAnyData.fieldBYTE = static_cast<TForteByte>(*static_cast<CIEC_BYTE*>(var));
			break;
		case CIEC_ANY::e_WORD:
			 dynVar.m_uAnyData.fieldWORD = static_cast<TForteWord>(*static_cast<CIEC_WORD*>(var));
			break;
		case CIEC_ANY::e_DWORD:
			 dynVar.m_uAnyData.fieldDWORD = static_cast<TForteDWord>(*static_cast<CIEC_DWORD*>(var));
			break;
		case CIEC_ANY::e_LWORD:
			break;
		case CIEC_ANY::e_DATE:
			break;
		case CIEC_ANY::e_TIME_OF_DAY:
			break;
		case CIEC_ANY::e_DATE_AND_TIME:
			break;
		case CIEC_ANY::e_TIME:
			break;
		case CIEC_ANY::e_REAL:
			dynVar.m_uAnyData.fieldREAL = static_cast<TForteFloat>(*static_cast<CIEC_REAL*>(var));
			break;
		case CIEC_ANY::e_LREAL:
			dynVar.m_uAnyData.fieldLREAL = static_cast<TForteDFloat>(*static_cast<CIEC_LREAL*>(var));
			break;
		case CIEC_ANY::e_STRING:
			dynVar.m_uAnyData.fieldSTRING_ = static_cast<CIEC_STRING*>(var)->getValue();
			break;
		case CIEC_ANY::e_WSTRING:
			break;
		case CIEC_ANY::e_DerivedData:
			break;
		case CIEC_ANY::e_DirectlyDerivedData:
			break;
		case CIEC_ANY::e_EnumeratedData:
			break;
		case CIEC_ANY::e_SubrangeData:
			break;
		case CIEC_ANY::e_ARRAY:
			break;
		case CIEC_ANY::e_STRUCT:
			break;
		case CIEC_ANY::e_External:
			break;
		case CIEC_ANY::e_Max:
			break;
		default:
			break;
		}

	}

	//To implemente this function, the getDI function of CFunctionBlock is changed from "protected" to "public"
	void* getDI(void* thisC, unsigned int pa_nDINum)
	{
		TIEC_ANYPtr var = static_cast<CFunctionBlock*>(thisC)->getDI(pa_nDINum);
		CIEC_ANY::EDataTypeID id = var->getDataTypeID();
		dynVar.m_DataType = id;
		convertIECType(var);
		return &dynVar;
	}
	//To implemente this function, the getDO function of CFunctionBlock is changed from "protected" to "public"

	void* getDO(void* thisC, unsigned int pa_nDONum)
	{
		TIEC_ANYPtr var = static_cast<CFunctionBlock*>(thisC)->getDO(pa_nDONum);
		CIEC_ANY::EDataTypeID id = var->getDataTypeID();
		dynVar.m_DataType = id;
		convertIECType(var);
		return &dynVar;
	}
#ifdef __cplusplus  
};
#endif 
CXMLParser4BFB ::CXMLParser4BFB(mxml_node_t *rootNode, TCCState *s)
	:rootNode(rootNode),
	s(s),
	unECStateNum(0),
	unECTransitNum(0),
	unAlgNum(0)
{
	memset(nECStateAcNum, 0x00, sizeof(TForteUInt8)*MAX_ESTATE_NUM);
}

CXMLParser4BFB::~CXMLParser4BFB()
{
	tcc_delete(s);	
}
EMGMResponse CXMLParser4BFB::createDynamicFB(CResource * pa_pRes, CStringDictionary::TStringId paTypeId, CStringDictionary::TStringId paNameId)
{
	EMGMResponse retVal = e_RDY;
	parseInternalVars(NULL, true);
	parseInterfaces(rootNode,s);
	parseAlgorithms(NULL, true);
	parseECTransitions(NULL, true);
	parseECStates(NULL, true);
	TForteByte *pa_acFBConnData = new TForteByte[sizeof(CEventConnection) * unEONum + sizeof(TDataConnectionPtr) * unDINum +
		sizeof(CDataConnection) * unDONum];
	TForteByte *pa_acBasicFBVarsData = new TForteByte[sizeof(CIEC_ANY) *(unDINum + unDONum)];
	m_FB = new CDynBasicFunctionBlock(pa_pRes, m_FBInterf, paNameId, NULL, pa_acFBConnData, pa_acBasicFBVarsData, unECStateNum, unECTransitNum,0);
	parseAlgorithms(m_FB, false);
	parseECTransitions(m_FB, false);
	parseECStates(m_FB, false);
	void* p;
	char name[100];
	sprintf(name, "evalFor%s_ECC", mxmlElementGetAttr(mxmlFindElement(rootNode, rootNode, "FBType", 0, 0, MXML_DESCEND), "Name"));
	p = tcc_get_symbol(s, name);
	m_FB->pFuncEval = (t_stateTransitEvalFunc)p;
	if (0 != m_FB)
	{
		m_FB->setFBTypeId(paTypeId);
		// perform reset to move it into idle state and set the initial values
		m_FB->changeFBExecutionState(cg_nMGM_CMD_Reset);
		lstDynBFBType.push_back(m_FB);
	}
	if (retVal == e_RDY)
	{
		//CDynFBTypeEntry* newTypeEntry = new CDynFBTypeEntry(paTypeId, m_FB->createFB);
	}
	return e_RDY;
}
CFunctionBlock* CXMLParser4BFB::getFB(CStringDictionary::TStringId paTypeId)
{
	CDynBasicFunctionBlock* retFB = NULL;
	for (TDynBFBTypeList::Iterator itRunner(lstDynBFBType.begin());
	itRunner != lstDynBFBType.end(); ++itRunner)
	{
		if (itRunner->getFBTypeId() == paTypeId)
		{
			retFB = *itRunner;
			break;
		}
	}
	return dynamic_cast<CFunctionBlock*>(retFB);
}
void CXMLParser4BFB::parseInternalVars(CDynBasicFunctionBlock* pa_pstDFB, bool pa_bInit)
{
	mxml_node_t *var;
	mxml_node_t *node;
	char val[256];
	memset(internalValDeclText, 0x00, 1024);
	node = mxmlFindElement(rootNode, rootNode, "InternalVars", 0, 0, MXML_DESCEND);
	if (node)
	{
		for (var = mxmlFindElement(node,rootNode, "VarDeclaration", 0, 0, MXML_DESCEND);
			var != NULL;
			var = mxmlFindElement(var, node, "VarDeclaration", 0, 0, MXML_DESCEND)
			)
		{
			const char* c = mxmlElementGetAttr(var, "Name");
			const char* type = mxmlElementGetAttr(var, "Type");
			const char* initval = mxmlElementGetAttr(var, "InitialValue");
			if (initval)
			{
				sprintf(val, "%s %s = %s;\n", type, c, initval);
			}
			else
			{
				sprintf(val, "%s %s ;\n", type, c);
			}
			sprintf(internalValDeclText, "%s;\n%s\n", internalValDeclText, val);
		}

	}

}
void CXMLParser4BFB::parseAlgorithms(CDynBasicFunctionBlock* pa_pstDFB, bool pa_bInit)
{
	int i = 0;
	int retval = 0;
	mxml_node_t *node;
	const char* fbType;
	memset(algText, 0x00, 4096);
	sprintf(algText, "%s%s", stdDataTypeDef, internalValDeclText);
	if (pa_bInit != true)
	{
		retval = tcc_add_symbol(s, "getDI", (void*)getDI);
		retval = tcc_add_symbol(s, "getDO", (void*)getDO);
		retval = tcc_relocate(s, TCC_RELOCATE_AUTO);
		//VOID* P1 = tcc_get_symbol(s, "getDI");
		//VOID* P2 = tcc_get_symbol(s, "getDO");

	}
	else
	{
		tcc_define_symbol(s, "EVAL_EV(ei)", "(pa_nEIId == ei) ");
	}
	fbType = mxmlElementGetAttr(mxmlFindElement(rootNode, rootNode, "FBType", 0, 0, MXML_DESCEND), "Name");
	for (node = mxmlFindElement(rootNode, rootNode, "Algorithm", 0, 0, MXML_DESCEND);
	node != NULL;
		node = mxmlFindElement(node, rootNode, "Algorithm", 0, 0, MXML_DESCEND)
		)
	{
		const char* text;
		mxml_node_t *alg;
		const char* c = mxmlElementGetAttr(node, "Name");
		if (pa_bInit == true)
		{

			for (alg = mxmlFindElement(node, node, "ST", 0, 0, MXML_DESCEND);
			alg != NULL;
				alg = mxmlFindElement(alg, node, "ST", 0, 0, MXML_DESCEND)
				)
			{
				text = mxmlElementGetAttr(alg, "Text");
				sprintf(algText, "%svoid %s_alg_%s(void* pa_poFBInstance){%s};", algText, fbType, c, text);
			}
			pAlgEntity[i].m_strName = c;
			unAlgNum++;
			i++;
		}
		else
		{
			void* p;
			char name[30];
			sprintf(name, "%s_alg_%s", fbType, c);
			p = tcc_get_symbol(s, name);
			pAlgEntity[i].m_pAlgFunc = (funcAlg)p;
			i++;
		}
	}
}
void CXMLParser4BFB::parseECTransitions(CDynBasicFunctionBlock* pa_pstDFB, bool pa_bInit)
{
	int retVal;
	mxml_node_t *node;
	int i = 0;
	if (pa_bInit == true)
	{
		sprintf(algText, "%s; unsigned char evalFor%s_ECC(void* pa_poFBInstance, short pa_nEIId,unsigned char pa_unEvalId)\n{\nswitch (pa_unEvalId){\n",
			algText,
			mxmlElementGetAttr(mxmlFindElement(rootNode, rootNode, "FBType", 0, 0, MXML_DESCEND), "Name"));
	}
	for (node = mxmlFindElement(rootNode, rootNode, "ECTransition", 0, 0, MXML_DESCEND);
	node != NULL;
		node = mxmlFindElement(node, rootNode, "ECTransition", 0, 0, MXML_DESCEND)
		)
	{
		if (pa_bInit == true)
		{
			sprintf(algText, "%s case %d:	return (%s);\n",
				algText,
				unECTransitNum,
				mxmlElementGetAttr(node, "Condition"));
			unECTransitNum++;

		}
		else
		{
			TForteUInt8 srcId, dstId;
			srcId = getECStateId(mxmlElementGetAttr(node, "Source"));
			dstId = getECStateId(mxmlElementGetAttr(node, "Destination"));
			pa_pstDFB->initTranstion(srcId, dstId);
			i++;
		}
	}
	if (pa_bInit == true)
	{
		sprintf(algText, "%s	default:			return 1;	}}; ", algText);
		retVal = tcc_compile_string(s, algText);
	}
}
void CXMLParser4BFB::parseECStates(CDynBasicFunctionBlock* pa_pstDFB, bool pa_bInit)
{
	mxml_node_t *node;
	mxml_node_t *ecstate;
	int i = 0;
	for (node = mxmlFindElement(rootNode, rootNode, "ECState", 0, 0, MXML_DESCEND);
	node != NULL;
		node = mxmlFindElement(node, rootNode, "ECState", 0, 0, MXML_DESCEND)
		)
	{
		if (pa_bInit == true)
		{
			strECStateName[unECStateNum] = mxmlElementGetAttr(node, "Name");
			for (ecstate = mxmlFindElement(node, node, "ECAction", 0, 0, MXML_DESCEND);
			ecstate != NULL;
				ecstate = mxmlFindElement(ecstate, node, "ECAction", 0, 0, MXML_DESCEND)
				)
			{
				nECStateAcNum[unECStateNum] ++;
			}
			unECStateNum++;
		}
		else
		{
			int nTransIdx = 0;
			pa_pstDFB->initState(i, nECStateAcNum[i]);
			pa_pstDFB->bindStateTranstion(i);
			for (ecstate = mxmlFindElement(node, node, "ECAction", 0, 0, MXML_DESCEND);
			ecstate != NULL;
				ecstate = mxmlFindElement(ecstate, node, "ECAction", 0, 0, MXML_DESCEND)
				)
			{
				TForteUInt8 EOId;
				const char* c = mxmlElementGetAttr(ecstate, "Output");
				const char* alg = mxmlElementGetAttr(ecstate, "Algorithm");
				if (c)
				{
					EOId = getEOId(c);
				}
				else
				{
					EOId = 0xff;
				}
				pa_pstDFB->bindStateAction(i, nTransIdx, EOId, getAlgorithm(alg));
				nTransIdx++;
			}
			i++;
		}
	}
}
funcAlg CXMLParser4BFB::getAlgorithm(const char* pa_strAlgName)
{
	TForteUInt8 i;
	funcAlg retVal = 0;
	if (pa_strAlgName==NULL)
	{
		return retVal;
	}
	for (i = 0; i < unAlgNum; i++)
	{
		if (!strcmp(pAlgEntity[i].m_strName, pa_strAlgName))
		{
			retVal = pAlgEntity[i].m_pAlgFunc;
			break;
		}
	}
	return retVal;
}
TForteUInt8 CXMLParser4BFB::getECStateId(const char* pa_strStateName)
{
	TForteUInt8 i;
	TForteUInt8 retVal = 0xff;
	for (i = 0; i < unECStateNum; i++)
	{
		if (!strcmp(strECStateName[i], pa_strStateName))
		{
			retVal = i;
			break;
		}
	}
	return retVal;
}
