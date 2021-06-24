/*
*********************************************************************************************************
*fb C code  
*File name:DynamicBFB.c
*Description:;
*********************************************************************************************************
*/
#ifdef _CLASS2_ENABLE
#include "stateNode.h"
#define IMPLEMENTATION
#include "DynamicBFB.h"
void 	methodOvldDecl_(executeECC, FUNCTIONBLOCK)
	unsigned int curEIID __
{
	sendMsg_(sub_cast(this, FUNCTIONBLOCK), executeECC)  curEIID __;
}
void 	methodOvldDecl(detorFB, FUNCTIONBLOCK)
{
	sendMsg(sub_cast(this, FUNCTIONBLOCK), detorFB);
}
void methodDecl_(executeECC)
unsigned int curEIID __
{
	t_CStateNode* pState;
	this->m.bTransitCleared = TRUE;
	while (this->m.bTransitCleared)
	{
		pState = ((t_CStateNode**)this->m.aStates)[this->m.unCurState];
		sendMsg_(pState, doAction) curEIID __;
		//IEC61499 ed2.0关于ECC行为的新规定
		curEIID = 0xff;
	}
}
void methodDecl(detorFB)
{
	/* delete the state */
	int i;
	if (this->m.unLocalInstanceId ==0)
	{
		for (i = 0; i < this->m.unStateNum; i++)
		{
			CStateNode._CStateNode(((t_CStateNode*)this->m.aStates[i]));
		}
		HERE_free(this->m.aStates);
		HERE_free(this->m.aTransits);
	}
	if (this->m.unLocalInstanceId == 0)
	{
		this->m.pDynamicFB_stFBInterfaceSpec->m_nNumDIs = 0;
		this->m.pDynamicFB_stFBInterfaceSpec->m_nNumDOs = 0;
		this->m.pDynamicFB_stFBInterfaceSpec->m_nNumEIs = 0;
		this->m.pDynamicFB_stFBInterfaceSpec->m_nNumEOs = 0;
		HERE_free((void*)this->m.pDynamicFB_stFBInterfaceSpec->m_anEIWith);
		HERE_free((void*)this->m.pDynamicFB_stFBInterfaceSpec->m_anEIWithIndexes);
		HERE_free((void*)this->m.pDynamicFB_stFBInterfaceSpec->m_anEOWith);
		HERE_free((void*)this->m.pDynamicFB_stFBInterfaceSpec->m_anEOWithIndexes);
		HERE_free((void*)this->m.pDynamicFB_stFBInterfaceSpec->m_aunDIDataTypeNames);
		HERE_free((void*)this->m.pDynamicFB_stFBInterfaceSpec->m_aunDINames);
		HERE_free((void*)this->m.pDynamicFB_stFBInterfaceSpec->m_aunDODataTypeNames);
		HERE_free((void*)this->m.pDynamicFB_stFBInterfaceSpec->m_aunDONames);
		HERE_free((void*)this->m.pDynamicFB_stFBInterfaceSpec->m_aunEINames);
		HERE_free((void*)this->m.pDynamicFB_stFBInterfaceSpec->m_aunEONames);
		HERE_free((void*)this->m.pDynamicFB_stFBInterfaceSpec);
	}
	HERE_free((void*)this->m.m_anConnData);
	HERE_free((void*)this->m.m_anVarsData);
	//this->m.pDynamicFB_stFBInterfaceSpec = NULL;
	//this->m.FUNCTIONBLOCK.m.pstInterfaceSpec = NULL;
}
t_FUNCTIONBLOCK *methodDecl_(createFB) UINT pa_nInstanceNameId, void *pa_poSrcRes __
{
	t_FB_DYNAMICBFB *  copyFB = FB_DYNAMICBFB.alloc();
	copyFB->m.pDynamicFB_stFBInterfaceSpec = this->m.pDynamicFB_stFBInterfaceSpec;
	char *pa_acFBConnData = HERE_malloc(sizeof(void*) *(this->m.pDynamicFB_stFBInterfaceSpec->m_nNumDIs
		+ this->m.pDynamicFB_stFBInterfaceSpec->m_nNumDOs
		+ this->m.pDynamicFB_stFBInterfaceSpec->m_nNumEOs));
	char *pa_acBasicFBVarsData = HERE_malloc(sizeof(VAR) * (this->m.pDynamicFB_stFBInterfaceSpec->m_nNumDIs
		+ this->m.pDynamicFB_stFBInterfaceSpec->m_nNumDOs));
	FUNCTIONBLOCK.init(super(copyFB, FUNCTIONBLOCK),
		copyFB->m.pDynamicFB_stFBInterfaceSpec,
		pa_acFBConnData,
		pa_acBasicFBVarsData);
	copyFB->m.pFuncEval = this->m.pFuncEval;
	copyFB->m.aStates = this->m.aStates;
	copyFB->m.aTransits = this->m.aTransits;
	memset(copyFB->m.strTypeName,0x0, 256);
	strcpy(copyFB->m.strTypeName, this->m.strTypeName);
	copyFB->m.FUNCTIONBLOCK.m.nFBInstanceName = pa_nInstanceNameId;
	copyFB->m.FUNCTIONBLOCK.m.m_poResource = pa_poSrcRes;
	copyFB->m.unLocalInstanceId = this->m.unLocalInstanceId + 1;
	copyFB->m.m_anConnData = pa_acFBConnData;
	copyFB->m.m_anVarsData = pa_acBasicFBVarsData;
	return &(copyFB->m.FUNCTIONBLOCK);
}
OBJECT_IMPLEMENTATION
	SUPERCLASS(FUNCTIONBLOCK),
	methodName(executeECC),
	methodName(detorFB),
	methodName(createFB)
ENDOF_IMPLEMENTATION
initClassDecl()
{
	initSuper(FUNCTIONBLOCK);
	overload(FUNCTIONBLOCK.executeECC) = methodOvldName(executeECC, FUNCTIONBLOCK);
	overload(FUNCTIONBLOCK.detorFB) = methodOvldName(detorFB, FUNCTIONBLOCK);
}
dtorDecl()
{
	HERE_free(this);
}
t_FB_DYNAMICBFB
classMethodDecl_(*const new) 
void* pa_vpRes, struct SFBInterfaceSpec* pa_Interface, UINT8 pa_unStateNum, UINT8 pa_unTransNum  __
{
	t_FB_DYNAMICBFB *const this = FB_DYNAMICBFB.alloc();
	if (this) FB_DYNAMICBFB.init(this, pa_Interface, pa_unStateNum, pa_unTransNum);
	this->m.FUNCTIONBLOCK.m.m_poResource = pa_vpRes;
	this->m.unLocalInstanceId = 0;
	this->m.eDybFBType = eBFB;
	//this->m.FUNCTIONBLOCK.m.bParaized = TRUE;
	return this;
}
void
methodDecl_(init)
	struct SFBInterfaceSpec* pa_Interface, UINT8 pa_unStateNum,UINT8 pa_unTransNum  __
{
	int i;
	this->m.pFuncEval = 0;
	this->m.pDynamicFB_stFBInterfaceSpec = pa_Interface;
	this->m.m_anVarsData = HERE_malloc(sizeof(VAR) * (this->m.pDynamicFB_stFBInterfaceSpec->m_nNumDIs 
		+ this->m.pDynamicFB_stFBInterfaceSpec->m_nNumDOs));
	this->m.m_anConnData = HERE_malloc(sizeof(void*) *(this->m.pDynamicFB_stFBInterfaceSpec->m_nNumDIs 
		+ this->m.pDynamicFB_stFBInterfaceSpec->m_nNumDOs 
		+ this->m.pDynamicFB_stFBInterfaceSpec->m_nNumEOs));
	if (this->m.eDybFBType == eBFB)
	{
		this->m.aTransits = HERE_malloc(sizeof(t_stateTransition) * pa_unTransNum);
		this->m.unTransNum = 0;
		this->m.aStates = HERE_malloc(sizeof(t_CStateNode*) * pa_unStateNum);
		this->m.unStateNum = pa_unStateNum;
		for (i = 0; i < pa_unStateNum; i++)
		{
			((t_CStateNode*)this->m.aStates[i]) = CStateNode.new(i, this);
		}
		this->m.unCurState = 0;
		this->m.bTransitCleared = FALSE;
	}
	FUNCTIONBLOCK.init(super(this, FUNCTIONBLOCK),
		this->m.pDynamicFB_stFBInterfaceSpec,
		this->m.m_anConnData,
		this->m.m_anVarsData);
}
void methodDecl_(initState) UINT8 pa_unStateId, UINT8 pa_nActionNum __
{
	((t_CStateNode*)this->m.aStates[pa_unStateId])->m.nActionNum = pa_nActionNum;
	if (pa_nActionNum != 0)
	{
		((t_CStateNode*)this->m.aStates[pa_unStateId])->m.poAction = HERE_malloc(sizeof(t_stateAction) * pa_nActionNum);
	}
}
void methodDecl_(initTranstion) UINT8 pa_unSrcStateId, UINT8 pa_unDstStateId __
{
	((t_stateTransition*)this->m.aTransits)[this->m.unTransNum].m_unSrcStateId = pa_unSrcStateId;
	((t_stateTransition*)this->m.aTransits)[this->m.unTransNum].m_unDstStateId = pa_unDstStateId;
	((t_stateTransition*)this->m.aTransits)[this->m.unTransNum].m_unTransId = this->m.unTransNum;
	this->m.unTransNum++;
}
void methodDecl_(bindStateAction) UINT8 pa_unStateId, UINT8 pa_unActionId, UINT8 pa_unEOId, void* pa_vpFunc __
{
	if (pa_unStateId < this->m.unStateNum )
	{
		if (pa_unActionId < ((t_CStateNode*)this->m.aStates[pa_unStateId])->m.nActionNum)
		{
			((t_stateAction*)((t_CStateNode*)this->m.aStates[pa_unStateId])->m.poAction)[pa_unActionId].m_nEOId = pa_unEOId;
			((t_stateAction*)((t_CStateNode*)this->m.aStates[pa_unStateId])->m.poAction)[pa_unActionId].m_pAlgFunc = pa_vpFunc;
		}
	}
}
void methodDecl_(bindStateTranstion) UINT8 pa_unSrcStateId __
{
	int i;
	for ( i = 0; i < this->m.unTransNum; i++)
	{
		if (((t_stateTransition*)this->m.aTransits)[i].m_unSrcStateId == pa_unSrcStateId)
		{
			t_StateTransitionEntry* poNewTrans = HERE_malloc(sizeof(t_StateTransitionEntry));
			poNewTrans->m_st = ((t_stateTransition*)this->m.aTransits) + i;
			list_add_tail(&(poNewTrans->list), &(((t_CStateNode*)this->m.aStates[pa_unSrcStateId])->m.lstStateTransit));
		}
	}
}
CLASS_IMPLEMENTATION
	methodName(new),
	methodName(init),
	methodName(initState),
	methodName(initTranstion),
	methodName(bindStateAction),
	methodName(bindStateTranstion)
ENDOF_IMPLEMENTATION
#endif