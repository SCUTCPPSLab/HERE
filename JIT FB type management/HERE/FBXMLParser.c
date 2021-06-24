#ifdef _CLASS2_ENABLE
#include "lib.h"
#include "DynamicLib.h"
#define IMPLEMENTATION
#include "FBXmlParser.h"

static char stdDataTypeDef[] =
"typedef union UAnyData\n"
"{\n"
"	char fieldSINT;\n"
"	unsigned char fieldBYTE;\n"
"	unsigned char fieldBOOL;\n"
"	unsigned char fieldUSINT;\n"
"	unsigned short fieldWORD;\n"
"	unsigned int fieldUINT;\n"
"	short fieldINT;\n"
"	unsigned int fieldDWORD;\n"
"	unsigned long fieldUDINT;\n"
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

static int convertTypeStr2Enum(const char* pa_strTypeId)
{
	UINT8 i;
	UINT8 retVal = 0xff;
	for (i = 0; i < 29; i++)
	{
		if (!strcmp(DataTypeLibEntry[i], pa_strTypeId))
		{
			retVal = i;
			break;
		}
	}
	return retVal;
}
static char algText[4096];
static char ivDeclText[1024];


void methodDecl_(parseInterfaces) BOOL pa_bInit __
{
	mxml_node_t *var;
	mxml_node_t *node;
	mxml_node_t *with;
	char name[30];
	char val[256];
	const char* fbType;
	UINT8 unEOWithIndexId = 0, unEIWithIndexId = 0;
	node = mxmlFindElement(this->m.rootNode, this->m.rootNode, "InputVars", 0, 0, MXML_DESCEND);
	fbType = mxmlElementGetAttr(mxmlFindElement(this->m.rootNode, this->m.rootNode, "FBType", 0, 0, MXML_DESCEND), "Name");
	for (var = mxmlFindElement(node, this->m.rootNode, "VarDeclaration", 0, 0, MXML_DESCEND);
	var != NULL;
		var = mxmlFindElement(var, node, "VarDeclaration", 0, 0, MXML_DESCEND)
		)
	{
		char id[3];
		const char* c = mxmlElementGetAttr(var, "Name");
		const char* type = mxmlElementGetAttr(var, "Type");
		this->m.strDIName[this->m.unDINum] = c;
		this->m.unDITypeName[this->m.unDINum] = convertTypeStr2Enum(type);
		this->m.unDIName[this->m.unDINum] = regisiterNewPortName(c);
		sprintf(id, "%d", this->m.unDINum);
		tcc_define_symbol(this->m.s, c, id);
		sprintf(name, "VAL_OF_%s()", c);
		sprintf(val, "((VAR* )(getDI(pa_poFBInstance, %s)))->m_uAnyData.field%s", c, type);
		tcc_define_symbol(this->m.s, name, val);
		this->m.unDINum++;
	}
	node = mxmlFindElement(this->m.rootNode, this->m.rootNode, "OutputVars", 0, 0, MXML_DESCEND);
	for (var = mxmlFindElement(node, this->m.rootNode, "VarDeclaration", 0, 0, MXML_DESCEND);
	var != NULL;
		var = mxmlFindElement(var, node, "VarDeclaration", 0, 0, MXML_DESCEND)
		)
	{
		char id[3];
		const char* c = mxmlElementGetAttr(var, "Name");
		const char* type = mxmlElementGetAttr(var, "Type");
		this->m.strDOName[this->m.unDONum] = c;
		this->m.unDOTypeName[this->m.unDONum] = convertTypeStr2Enum(type);
		this->m.unDOName[this->m.unDONum] = regisiterNewPortName(c);
		sprintf(id, "%d", this->m.unDONum);
		tcc_define_symbol(this->m.s, c, id);
		sprintf(name, "VAL_OF_%s()", c);
		sprintf(val, "((VAR* )(getDO(pa_poFBInstance, %s)))->m_uAnyData.field%s", c, type);
		tcc_define_symbol(this->m.s, name, val);
		this->m.unDONum++;
	}
	node = mxmlFindElement(this->m.rootNode, this->m.rootNode, "EventOutputs", 0, 0, MXML_DESCEND);
	for (var = mxmlFindElement(node, this->m.rootNode, "Event", 0, 0, MXML_DESCEND);
	var != NULL;
		var = mxmlFindElement(var, node, "Event", 0, 0, MXML_DESCEND)
		)
	{
		char evName[20];
		char id[3];
		UINT8 tmpCnt = 0;
		BOOL bHasWith = FALSE;
		//UINT8 unEOWithNum = 0;
		const char* c = mxmlElementGetAttr(var, "Name");
		this->m.strEOName[this->m.unEONum] = c;
		sprintf(evName, "%s_%s", fbType, c);
		this->m.unEOName[this->m.unEONum] = regisiterNewPortName(c);
		sprintf(id, "%d", this->m.unEONum);
		tcc_define_symbol(this->m.s, evName, id);
		for (with = mxmlFindElement(var, var, "With", 0, 0, MXML_DESCEND);
		with != NULL;
			with = mxmlFindElement(with, var, "With", 0, 0, MXML_DESCEND)
			)
		{
			UINT8 DOId;
			DOId = sendMsg_(this, getDOId) mxmlElementGetAttr(with, "Var") __;
			this->m.nEOWith[unEOWithIndexId] = DOId;
			bHasWith = TRUE;
			unEOWithIndexId++;
			tmpCnt++;
		}
		if (bHasWith != TRUE)
		{
			this->m.nEOWithIndex[this->m.unEONum] = -1;
		}
		else
		{
			this->m.nEOWith[unEOWithIndexId] = 255;
			this->m.nEOWithIndex[this->m.unEONum] = unEOWithIndexId - tmpCnt;
			unEOWithIndexId++;
		}
		this->m.unEONum++;
		this->m.unEOWithNum = unEOWithIndexId;
	}
	node = mxmlFindElement(this->m.rootNode, this->m.rootNode, "EventInputs", 0, 0, MXML_DESCEND);
	for (var = mxmlFindElement(node, this->m.rootNode, "Event", 0, 0, MXML_DESCEND);
	var != NULL;
		var = mxmlFindElement(var, node, "Event", 0, 0, MXML_DESCEND)
		)
	{
		char evName[20];
		char id[3];
		UINT8 tmpCnt = 0;
		BOOL bHasWith = FALSE;
		const char* c = mxmlElementGetAttr(var, "Name");
		this->m.strEIName[this->m.unEINum] = c;
		sprintf(evName, "%s_%s", fbType, c);
		this->m.unEIName[this->m.unEINum] = regisiterNewPortName(c);
		sprintf(id, "%d", this->m.unEINum);
		tcc_define_symbol(this->m.s, evName, id);
		for (with = mxmlFindElement(var, var, "With", 0, 0, MXML_DESCEND);
		with != NULL;
			with = mxmlFindElement(with, var, "With", 0, 0, MXML_DESCEND)
			)
		{
			UINT8 DIId;
			DIId = sendMsg_(this, getDIId) mxmlElementGetAttr(with, "Var") __;
			this->m.nEIWith[unEIWithIndexId] = DIId;
			bHasWith = TRUE;
			unEIWithIndexId++;
			tmpCnt++;
		}
		if (bHasWith != TRUE)
		{
			this->m.nEIWithIndex[this->m.unEINum] = -1;
		}
		else
		{
			this->m.nEIWith[unEIWithIndexId] = 255;
			this->m.nEIWithIndex[this->m.unEINum] = unEIWithIndexId - tmpCnt;
			unEIWithIndexId++;
		}
		this->m.unEINum++;
		this->m.unEIWithNum = unEIWithIndexId;
	}

	this->m.pFBInterfaceSpec->m_nNumDIs = this->m.unDINum;
	this->m.pFBInterfaceSpec->m_nNumDOs = this->m.unDONum;
	this->m.pFBInterfaceSpec->m_nNumEIs = this->m.unEINum;
	this->m.pFBInterfaceSpec->m_nNumEOs = this->m.unEONum;
	if (this->m.unDINum)
	{
		this->m.pFBInterfaceSpec->m_aunDIDataTypeNames = HERE_malloc(sizeof(UINT16)*this->m.unDINum);
		this->m.pFBInterfaceSpec->m_aunDINames = HERE_malloc(sizeof(UINT16)*this->m.unDINum);
		memcpy((void*)this->m.pFBInterfaceSpec->m_aunDIDataTypeNames, this->m.unDITypeName, this->m.unDINum*sizeof(UINT16));
		memcpy((void*)this->m.pFBInterfaceSpec->m_aunDINames, this->m.unDIName, this->m.unDINum*sizeof(UINT16));
	}
	else
	{
		this->m.pFBInterfaceSpec->m_aunDIDataTypeNames = NULL;
		this->m.pFBInterfaceSpec->m_aunDINames = NULL;
	}
	if (this->m.unDONum)
	{
		this->m.pFBInterfaceSpec->m_aunDODataTypeNames = HERE_malloc(sizeof(UINT16)*this->m.unDONum);;
		this->m.pFBInterfaceSpec->m_aunDONames = HERE_malloc(sizeof(UINT16)*this->m.unDONum);
		memcpy((void*)this->m.pFBInterfaceSpec->m_aunDODataTypeNames, this->m.unDOTypeName, this->m.unDONum*sizeof(UINT16));
		memcpy((void*)this->m.pFBInterfaceSpec->m_aunDONames, this->m.unDOName, this->m.unDONum*sizeof(UINT16));
	}
	else
	{
		this->m.pFBInterfaceSpec->m_aunDODataTypeNames = NULL;
		this->m.pFBInterfaceSpec->m_aunDONames = NULL;
	}
	if (this->m.unEIWithNum)
	{
		this->m.pFBInterfaceSpec->m_anEIWithIndexes = HERE_malloc(this->m.unEIWithNum*sizeof(INT16));
		this->m.pFBInterfaceSpec->m_anEIWith = HERE_malloc(this->m.unEIWithNum*sizeof(INT16));
		memcpy((void*)this->m.pFBInterfaceSpec->m_anEIWith, this->m.nEIWith, this->m.unEIWithNum*sizeof(INT16));
		memcpy((void*)this->m.pFBInterfaceSpec->m_anEIWithIndexes, this->m.nEIWithIndex, this->m.unEINum*sizeof(INT8));
	}
	else
	{
		this->m.pFBInterfaceSpec->m_anEIWithIndexes = NULL;
		this->m.pFBInterfaceSpec->m_anEIWith = NULL;
	}
	if (this->m.unEOWithNum)
	{
		this->m.pFBInterfaceSpec->m_anEOWithIndexes = HERE_malloc(this->m.unEOWithNum*sizeof(INT16));
		this->m.pFBInterfaceSpec->m_anEOWith = HERE_malloc(this->m.unEOWithNum*sizeof(INT16));
		memcpy((void*)this->m.pFBInterfaceSpec->m_anEOWith, this->m.nEOWith, this->m.unEOWithNum*sizeof(INT16));
		memcpy((void*)this->m.pFBInterfaceSpec->m_anEOWithIndexes, this->m.nEOWithIndex, this->m.unEONum*sizeof(INT8));
	}
	else
	{
		this->m.pFBInterfaceSpec->m_anEOWithIndexes = NULL;
		this->m.pFBInterfaceSpec->m_anEOWith = NULL;
	}
	this->m.pFBInterfaceSpec->m_aunEINames = HERE_malloc(sizeof(INT16)*this->m.unEINum);
	this->m.pFBInterfaceSpec->m_aunEONames = HERE_malloc(sizeof(INT16)*this->m.unEONum);

	memcpy((void*)this->m.pFBInterfaceSpec->m_aunEINames, this->m.unEIName, this->m.unEINum*sizeof(UINT16));
	memcpy((void*)this->m.pFBInterfaceSpec->m_aunEONames, this->m.unEOName, this->m.unEONum*sizeof(UINT16));
}
void methodDecl_(parseAlgorithms)
t_FB_DYNAMICBFB* pa_pstDFB, BOOL pa_bInit __
{
	int i = 0;
	int retval = 0;
	mxml_node_t *node;
	const char* fbType;
	memset(algText, 0x00, 4096);
	sprintf(algText, "%s", stdDataTypeDef);
	if (pa_bInit != TRUE)
	{
		retval = tcc_add_symbol(this->m.s, "getDI", this->m.pstDFB->m.FUNCTIONBLOCK.__vptr->getDI);
		retval = tcc_add_symbol(this->m.s, "getDO", this->m.pstDFB->m.FUNCTIONBLOCK.__vptr->getDO);
		retval = tcc_relocate(this->m.s, TCC_RELOCATE_AUTO);
	}
	else
	{
		tcc_define_symbol(this->m.s, "EVAL_EV(ei)", "(pa_nEIId == ei) ");
	}
	fbType = mxmlElementGetAttr(mxmlFindElement(this->m.rootNode, this->m.rootNode, "FBType", 0, 0, MXML_DESCEND), "Name");
	for (node = mxmlFindElement(this->m.rootNode, this->m.rootNode, "Algorithm", 0, 0, MXML_DESCEND);
	node != NULL;
		node = mxmlFindElement(node, this->m.rootNode, "Algorithm", 0, 0, MXML_DESCEND)
		)
	{
		const char* text;
		mxml_node_t *alg;
		const char* c = mxmlElementGetAttr(node, "Name");
		if (pa_bInit == TRUE)
		{

			for (alg = mxmlFindElement(node, node, "ST", 0, 0, MXML_DESCEND);
			alg != NULL;
				alg = mxmlFindElement(alg, node, "ST", 0, 0, MXML_DESCEND)
				)
			{
				text = mxmlElementGetAttr(alg, "Text");
				sprintf(algText, "%svoid %s_alg_%s(void* pa_poFBInstance){%s};", algText, fbType, c, text);
			}
			this->m.pAlgEntity[i].m_strName = c;
			this->m.unAlgNum++;
			i++;
		}
		else
		{
			void* p;
			char name[30];
			sprintf(name, "%s_alg_%s", fbType, c);
			p = tcc_get_symbol(this->m.s, name);
			this->m.pAlgEntity[i].m_pAlgFunc = p;
			i++;
		}
	}
}
void methodDecl_(parseInternalVars)t_FB_DYNAMICFB* pa_pstDFB, BOOL pa_bInit __
{
	mxml_node_t *var;
	mxml_node_t *node;
	char val[256];
	memset(ivDeclText, 0x00, 1024);
	node = mxmlFindElement(this->m.rootNode, this->m.rootNode, "InternalVars", 0, 0, MXML_DESCEND);
	if (node)
	{
		for (var = mxmlFindElement(node, this->m.rootNode, "VarDeclaration", 0, 0, MXML_DESCEND);
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
			sprintf(ivDeclText, "%s;\n%s\n", ivDeclText, val);
		}
		
	}

}
void methodDecl_(parseECStates)t_FB_DYNAMICBFB* pa_pstDFB, BOOL pa_bInit __
{
	mxml_node_t *node;
	mxml_node_t *ecstate;
	int i = 0;
	for (node = mxmlFindElement(this->m.rootNode, this->m.rootNode, "ECState", 0, 0, MXML_DESCEND);
	node != NULL;
		node = mxmlFindElement(node, this->m.rootNode, "ECState", 0, 0, MXML_DESCEND)
		)
	{
		if (pa_bInit == TRUE)
		{
			this->m.strECStateName[this->m.unECStateNum] = mxmlElementGetAttr(node, "Name");
			for (ecstate = mxmlFindElement(node, node, "ECAction", 0, 0, MXML_DESCEND);
			ecstate != NULL;
				ecstate = mxmlFindElement(ecstate, node, "ECAction", 0, 0, MXML_DESCEND)
				)
			{
				this->m.nECStateAcNum[this->m.unECStateNum] ++;
			}
			this->m.unECStateNum++;
		}
		else
		{
			int nTransIdx = 0;
			FB_DYNAMICFB.initState(pa_pstDFB, i, this->m.nECStateAcNum[i]);
			FB_DYNAMICFB.bindStateTranstion(pa_pstDFB, i);
			for (ecstate = mxmlFindElement(node, node, "ECAction", 0, 0, MXML_DESCEND);
			ecstate != NULL;
				ecstate = mxmlFindElement(ecstate, node, "ECAction", 0, 0, MXML_DESCEND)
				)
			{
				UINT8 EOId;
				const char* c = mxmlElementGetAttr(ecstate, "Output");
				const char* alg = mxmlElementGetAttr(ecstate, "Algorithm");
				if (c)
				{
					EOId = sendMsg_(this, getEOId) c  __;
				}
				else
				{
					EOId = 0xff;
				}
				FB_DYNAMICFB.bindStateAction(pa_pstDFB, i, nTransIdx, EOId, sendMsg_(this, getAlgorithm) alg __);
				nTransIdx++;
			}
			i++;
		}
	}
}
VAR*  tempgetDI(void* p1, unsigned int unDIID)
{
	return NULL;
}
void methodDecl_(parseECTransitions)t_FB_DYNAMICBFB* pa_pstDFB, BOOL pa_bInit __
{
	int retVal;
	mxml_node_t *node;
	int i = 0;
	if (pa_bInit == TRUE)
	{
		sprintf(algText, "%s; unsigned char evalFor%s_ECC(void* pa_poFBInstance, short pa_nEIId,unsigned char pa_unEvalId)\n{\nswitch (pa_unEvalId){\n",
			algText,
			mxmlElementGetAttr(mxmlFindElement(this->m.rootNode, this->m.rootNode, "FBType", 0, 0, MXML_DESCEND), "Name"));
	}
	for (node = mxmlFindElement(this->m.rootNode, this->m.rootNode, "ECTransition", 0, 0, MXML_DESCEND);
	node != NULL;
		node = mxmlFindElement(node, this->m.rootNode, "ECTransition", 0, 0, MXML_DESCEND)
		)
	{
		if (pa_bInit == TRUE)
		{
			sprintf(algText, "%s case %d:	return (%s);\n",
				algText,
				this->m.unECTransitNum,
				mxmlElementGetAttr(node, "Condition"));
			this->m.unECTransitNum++;

		}
		else
		{
			UINT8 srcId, dstId;
			srcId = sendMsg_(this, getECStateId) mxmlElementGetAttr(node, "Source") __;
			dstId = sendMsg_(this, getECStateId) mxmlElementGetAttr(node, "Destination") __;
			FB_DYNAMICFB.initTranstion(pa_pstDFB, srcId, dstId);
			//eval condition
			i++;
		}
	}
	if (pa_bInit == TRUE)
	{
		sprintf(algText, "%s	default:			return 1;	}}; ", algText);
		retVal = tcc_compile_string(this->m.s, algText);
	}
}
UINT8 methodDecl_(getECStateId)const char* pa_strStateName __
{
	UINT8 i;
	UINT8 retVal = 0xff;
	for (i = 0; i < this->m.unECStateNum; i++)
	{
		if (!strcmp(this->m.strECStateName[i], pa_strStateName))
		{
			retVal = i;
			break;
		}
	}
	return retVal;
}
UINT8 methodDecl_(getEOId)const char* pa_strEOName __
{
	UINT8 i;
	UINT8 retVal = 0xff;
	for (i = 0; i < this->m.unEONum; i++)
	{
		if (!strcmp(this->m.strEOName[i], pa_strEOName))
		{
			retVal = i;
			break;
		}
	}
	return retVal;
}
UINT8 methodDecl_(getDOId)const char* pa_strDOName __
{
	UINT8 i;
	UINT8 retVal = 0xff;
	for (i = 0; i < this->m.unDONum; i++)
	{
		if (!strcmp(this->m.strDOName[i], pa_strDOName))
		{
			retVal = i;
			break;
		}
	}
	return retVal;
}
UINT8 methodDecl_(getEIId)const char* pa_strEIName __
{
	UINT8 i;
	UINT8 retVal = 0xff;
	for (i = 0; i < this->m.unEINum; i++)
	{
		if (!strcmp(this->m.strEIName[i], pa_strEIName))
		{
			retVal = i;
			break;
		}
	}
	return retVal;
}
UINT8 methodDecl_(getDIId)const char* pa_strDIName __
{
	UINT8 i;
	UINT8 retVal = 0xff;
	for (i = 0; i < this->m.unDINum; i++)
	{
		if (!strcmp(this->m.strDIName[i], pa_strDIName))
		{
			retVal = i;
			break;
		}
	}
	return retVal;
}
funcAlg methodDecl_(getAlgorithm)const char* pa_strAlgName __
{
	UINT8 i;
	funcAlg retVal = 0;
	if (pa_strAlgName == NULL)
	{
		return retVal;
	}
	for (i = 0; i < this->m.unAlgNum; i++)
	{
		if (!strcmp(this->m.pAlgEntity[i].m_strName, pa_strAlgName))
		{
			retVal = this->m.pAlgEntity[i].m_pAlgFunc;
			break;
		}
	}
	return retVal;
}
void methodDecl(parseFBN)
{
	mxml_node_t *node;
	this->m.m_FBNData->m_nNumFBs = 0;
	for (node = mxmlFindElement(this->m.rootNode, this->m.rootNode, "FB", 0, 0, MXML_DESCEND);
	node != NULL;
		node = mxmlFindElement(node, this->m.rootNode, "FB", 0, 0, MXML_DESCEND)
		)
	{
		this->m.m_FBNData->m_nNumFBs++;
	}
	if (this->m.m_FBNData->m_nNumFBs != 0)
	{
		int i = 0;
		SCFB_FBInstanceData* runner = NULL;
		this->m.m_FBNData->m_pstFBInstances = HERE_malloc(sizeof(struct SCFB_FBInstanceData)*this->m.m_FBNData->m_nNumFBs);
		this->m.m_FBNameList = HERE_malloc(sizeof(char*) * this->m.m_FBNData->m_nNumFBs);
		runner = this->m.m_FBNData->m_pstFBInstances;
		for (node = mxmlFindElement(this->m.rootNode, this->m.rootNode, "FB", 0, 0, MXML_DESCEND);
		node != NULL;
			node = mxmlFindElement(node, this->m.rootNode, "FB", 0, 0, MXML_DESCEND)
			)
		{
			int typeId;
			const char* c = mxmlElementGetAttr(node, "Name");
			const char* c2 = mxmlElementGetAttr(node, "Type");
			typeId = searchFBTypeName(c2);
			if (0xffff == typeId)
			{
				strcpy(runner[i].m_strFBTypeName, c2);
			}
			runner[i].m_nFBTypeNameId = typeId;
			runner[i].m_nFBInstanceNameId = regisiterNewFBName(c);
			this->m.m_FBNameList[i] = c;
			i++;
		}
	}
	else
	{
		this->m.m_FBNData->m_pstFBInstances = NULL;
	}
}
void methodDecl(parseEC)
{
	mxml_node_t *node;
	mxml_node_t *ecnode;
	this->m.m_FBNData->m_nNumEventConnections = 0;
	node = mxmlFindElement(this->m.rootNode, this->m.rootNode, "EventConnections", 0, 0, MXML_DESCEND);
	for (ecnode = mxmlFindElement(node, node, "Connection", 0, 0, MXML_DESCEND);
	ecnode != NULL;
		ecnode = mxmlFindElement(ecnode, node, "Connection", 0, 0, MXML_DESCEND)
		)
	{
		this->m.m_FBNData->m_nNumEventConnections++;
	}
	if (this->m.m_FBNData->m_nNumEventConnections != 0)
	{
		int i = 0;
		SCFB_FBConnectionData* runner = NULL;
		this->m.m_FBNData->m_pstEventConnections = HERE_malloc(sizeof(SCFB_FBConnectionData)*this->m.m_FBNData->m_nNumEventConnections);
		runner = (SCFB_FBConnectionData*)(this->m.m_FBNData->m_pstEventConnections);
		node = mxmlFindElement(this->m.rootNode, this->m.rootNode, "EventConnections", 0, 0, MXML_DESCEND);
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
				runner[i].m_nSrcId = regisiterNewPortName(c);// CStringDictionary::getInstance().getId(c);
				runner[i].m_nSrcId = GENERATE_CONNECTION_PORT_ID_2_ARG(0xffffffff,runner[i].m_nSrcId);
				runner[i].m_nSrcFBNum = -1;

			}
			else
			{
				int len, fbid, portid;
				char* srcfbname;
				char* eoname = (char*)(srcportname);
				char* totalname = (char*)(c);
				len = eoname - c;
				if (len>0)
				{
					srcfbname = HERE_malloc(len + 1);
					memset(srcfbname,0x00,len+1);
					strncpy(srcfbname, c,len);
					eoname++;
					portid = regisiterNewPortName(eoname);
					fbid = regisiterNewFBName(srcfbname);
					runner[i].m_nSrcFBNum = CFBXmlParser.getFBIdx(this, srcfbname);
					runner[i].m_nSrcId = GENERATE_CONNECTION_PORT_ID_2_ARG(fbid, portid);
					HERE_free(srcfbname);
				}

			}
			if (dstportname == NULL)
			{
				runner[i].m_nDstId = regisiterNewPortName(c2);
				runner[i].m_nDstId = GENERATE_CONNECTION_PORT_ID_2_ARG(0xffffffff,runner[i].m_nDstId);
				runner[i].m_nDstFBNum = -1;
			}
			else
			{
				int len, fbid, portid;
				char* dstfbname;
				char* einame = (char*)(dstportname);
				len = einame - c2;
				if (len>0)
				{
					dstfbname = HERE_malloc(len + 1);
					memset(dstfbname,0x00,len+1);
					strncpy(dstfbname, c2, len);
					einame++;
					portid = regisiterNewPortName(einame);
					fbid = regisiterNewFBName(dstfbname);
					runner[i].m_nDstFBNum = CFBXmlParser.getFBIdx(this, dstfbname);
					runner[i].m_nDstId = GENERATE_CONNECTION_PORT_ID_2_ARG(fbid, portid);
					HERE_free(dstfbname);
				}

			}
			i++;
		}
		this->m.m_FBNData->m_nNumFannedOutEventConnections = 0;
		this->m.m_FBNData->m_pstFannedOutEventConnections = NULL;
	}
	else
	{
		this->m.m_FBNData->m_pstEventConnections = NULL;
	}
}
void methodDecl(parseDC)
{
	mxml_node_t *node;
	mxml_node_t *ecnode;
	this->m.m_FBNData->m_nNumDataConnections = 0;
	node = mxmlFindElement(this->m.rootNode, this->m.rootNode, "DataConnections", 0, 0, MXML_DESCEND);
	for (ecnode = mxmlFindElement(node, node, "Connection", 0, 0, MXML_DESCEND);
	ecnode != NULL;
		ecnode = mxmlFindElement(ecnode, node, "Connection", 0, 0, MXML_DESCEND)
		)
	{
		this->m.m_FBNData->m_nNumDataConnections++;
	}
	if (this->m.m_FBNData->m_nNumDataConnections != 0)
	{
		int i = 0;
		SCFB_FBConnectionData* runner = NULL;
		this->m.m_FBNData->m_pstDataConnections = malloc(sizeof(SCFB_FBConnectionData)*this->m.m_FBNData->m_nNumDataConnections);
		runner = (SCFB_FBConnectionData*)(this->m.m_FBNData->m_pstDataConnections);
		node = mxmlFindElement(this->m.rootNode, this->m.rootNode, "DataConnections", 0, 0, MXML_DESCEND);
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
				runner[i].m_nSrcId = regisiterNewPortName(c);
				runner[i].m_nSrcId = GENERATE_CONNECTION_PORT_ID_2_ARG(0xffffffff, runner[i].m_nSrcId);
				runner[i].m_nSrcFBNum = -1;

			}
			else
			{
				int len, fbid, portid;
				char* srcfbname;
				char* doname = (char*)(srcportname);
				char* totalname = (char*)(c);
				len = doname - c;
				if (len>0)
				{
					srcfbname = HERE_malloc(len + 1);
					memset(srcfbname, 0x00, len + 1);
					strncpy(srcfbname, c, len);
					doname++;
					portid = regisiterNewPortName(doname);
					fbid = regisiterNewFBName(srcfbname);
					runner[i].m_nSrcFBNum = CFBXmlParser.getFBIdx(this, srcfbname);
					runner[i].m_nSrcId = GENERATE_CONNECTION_PORT_ID_2_ARG(fbid, portid);
					HERE_free(srcfbname);
				}

			}
			if (dstportname == NULL)
			{
				runner[i].m_nDstId = regisiterNewPortName(c2);
				runner[i].m_nDstId = GENERATE_CONNECTION_PORT_ID_2_ARG(0xffffffff, runner[i].m_nDstId);
				runner[i].m_nDstFBNum = -1;
			}
			else
			{
				int len, fbid, portid;
				char* dstfbname;
				char* diname = (char*)(dstportname);
				len = diname - c2;
				if (len>0)
				{
					dstfbname = HERE_malloc(len + 1);
					memset(dstfbname, 0x00, len + 1);
					strncpy(dstfbname, c2, len);
					diname++;
					portid = regisiterNewPortName(diname);
					fbid = regisiterNewFBName(dstfbname);
					runner[i].m_nDstFBNum = CFBXmlParser.getFBIdx(this, dstfbname);
					runner[i].m_nDstId = GENERATE_CONNECTION_PORT_ID_2_ARG(fbid, portid);
					HERE_free(dstfbname);
				}

			}
			i++;
		}
		this->m.m_FBNData->m_nNumFannedOutDataConnections = 0;
		this->m.m_FBNData->m_pstFannedOutDataConnections = NULL;
	}
	else
	{
		this->m.m_FBNData->m_pstDataConnections = NULL;
	}
}
BASEOBJECT_IMPLEMENTATION
	methodName(parseInterfaces),
	methodName(parseAlgorithms),
	methodName(parseInternalVars),
	methodName(parseECStates),
	methodName(parseECTransitions),
	methodName(getECStateId),
	methodName(getEOId),
	methodName(getDOId),
	methodName(getEIId),
	methodName(getDIId),
	methodName(getAlgorithm),
	methodName(parseFBN),
	methodName(parseEC),
	methodName(parseDC)
ENDOF_IMPLEMENTATION
initClassDecl()
{

}
dtorDecl()
{
	struct list_head * pos;
	struct list_head *posNext;
	STCCEntry* tmp = NULL;
	list_for_each_safe(pos, posNext, &(this->m.tcclist))
	{
		tmp = list_entry((pos), STCCEntry, list);
		list_del(&tmp->list);
		tcc_delete(tmp->m_tcc);
		HERE_free(tmp);
	}
	mxmlDelete(this->m.rootNode);
	HERE_free(this);
}
t_CFBXmlParser
classMethodDecl(*const new)
{
	t_CFBXmlParser *const this = CFBXmlParser.alloc();
	this->m.rootNode = 0;
	this->m.pFuncCreator = NULL;
	INIT_LIST_HEAD(&this->m.tcclist);
	return this;
}

t_FUNCTIONBLOCK* methodDecl_(createDynamicFB)  void* pa_pRes, char* pa_strFBName __
{
	t_FUNCTIONBLOCK* retFB = NULL;
	FILE		*fp;		/* File to read */
	char fbName[256];
	void* p;
	char name[100];
	mxml_node_t *bfbnode = 0;
	
	sprintf(fbName, "/home/pi/fbtlib/%s.fbt", pa_strFBName);
	if ((fp = fopen(fbName, "rb")) == NULL)
	{
		perror(pa_strFBName);
		return NULL;
	}
	if (this->m.rootNode)
	{
		mxmlDelete(this->m.rootNode);
	}
	this->m.rootNode = mxmlLoadFile(NULL, fp, MXML_IGNORE_CALLBACK);
	fclose(fp);
	struct STCCEntry* newTCC = malloc(sizeof(struct STCCEntry));
	newTCC->m_tcc = tcc_new();
	this->m.s = newTCC->m_tcc;
	list_add_tail(&(newTCC->list), &(this->m.tcclist));
	tcc_set_options(this->m.s, "-nostdlib");
	tcc_set_output_type(this->m.s, TCC_OUTPUT_MEMORY);

	this->m.unECStateNum = 0;
	this->m.unECTransitNum = 0;
	this->m.unEINum = 0;
	this->m.unEONum = 0;
	this->m.unDINum = 0;
	this->m.unDONum = 0;
	this->m.unAlgNum = 0;
	this->m.unEIWithNum = 0;
	this->m.unEOWithNum = 0;
	memset(this->m.nECStateAcNum, 0x00, sizeof(UINT8)*MAX_ESTATE_NUM);
	this->m.pFBInterfaceSpec = malloc(sizeof(struct SFBInterfaceSpec));
	bfbnode = mxmlFindElement(this->m.rootNode, this->m.rootNode, "BasicFB", 0, 0, MXML_DESCEND);
	
	if (bfbnode)
	{
		sendMsg_(this, parseInternalVars) 0, TRUE __;
		sendMsg_(this, parseInterfaces) TRUE __;
		sendMsg_(this, parseAlgorithms) 0, TRUE __;
		sendMsg_(this, parseECTransitions) 0, TRUE __;
		sendMsg_(this, parseECStates) 0, TRUE __;

		this->m.pstDFB = FB_DYNAMICFB.new(pa_pRes,
			this->m.pFBInterfaceSpec,
			this->m.unECStateNum,
			this->m.unECTransitNum);
		memset(this->m.pstDFB->m.strTypeName, 0x0, 256);
		strcpy(this->m.pstDFB->m.strTypeName,pa_strFBName);


		sendMsg_(this, parseAlgorithms) this->m.pstDFB, FALSE __;
		sendMsg_(this, parseECTransitions) this->m.pstDFB, FALSE __;
		sendMsg_(this, parseECStates) this->m.pstDFB, FALSE __;

		sprintf(name, "evalFor%s_ECC", pa_strFBName);
		p = tcc_get_symbol(this->m.s, name);
		this->m.pstDFB->m.pFuncEval = p;
		this->m.pstDFB->m.s = this->m.s;
		retFB = &(this->m.pstDFB->m.FUNCTIONBLOCK);
		this->m.pFuncCreator = this->m.pstDFB->__vptr->createFB;
	}
	else
	{
		mxml_node_t *cfbnode = 0;
		cfbnode = mxmlFindElement(this->m.rootNode, this->m.rootNode, "FBNetwork", 0, 0, MXML_DESCEND);
		if (cfbnode)
		{
			t_FB_DYNAMICCFB* newDCFB = NULL;
			this->m.m_FBNData = (SCFB_FBNData*)HERE_malloc(sizeof(SCFB_FBNData));
			sendMsg_(this, parseInterfaces) TRUE __;
			sendMsg(this, parseFBN);
			if (this->m.m_FBNData == NULL)
			{
				return NULL;
			}
			sendMsg(this, parseEC);
			sendMsg(this, parseDC);
			newDCFB = FB_DYNAMICCFB.new(pa_pRes,
				this->m.pFBInterfaceSpec,
				this->m.m_FBNData);
			newDCFB->m.m_anstrFBName = this->m.m_FBNameList;
			newDCFB->m.strTypeName = pa_strFBName;
			this->m.pFuncCreator = newDCFB->__vptr->createFB;
			retFB = &(newDCFB->m.CCOMPOSITEFB.m.FUNCTIONBLOCK);
		}
	}
	return retFB;
}
int methodDecl_(getFBIdx) const char* pa_strFBName __
{
	int ret = -1;
	for (int i = 0; i < this->m.m_FBNData->m_nNumFBs; i++)
	{
		if (!strcmp(this->m.m_FBNameList[i], pa_strFBName))
		{
			ret = i;
			break;
		}
	}
	return ret;
}
CLASS_IMPLEMENTATION
	methodName(new),
	methodName(createDynamicFB),
	methodName(getFBIdx)
ENDOF_IMPLEMENTATION

#endif
