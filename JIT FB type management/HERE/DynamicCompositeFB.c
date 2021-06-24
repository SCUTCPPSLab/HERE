/*
*********************************************************************************************************
*fb C code  
*File name:DynamicCFB.c
*Description:;
*********************************************************************************************************
*/
#ifdef _CLASS2_ENABLE
#define IMPLEMENTATION
#include "DynamicCompositeFB.h"
void 	methodOvldDecl(detorFB, CCOMPOSITEFB)
{
	sendMsg(sub_cast(this, CCOMPOSITEFB), detorFB);
}

void methodDecl(detorFB)
{
	/* delete the state */
	int i;
	
	if (this->m.unLocalInstanceId ==0)
	{
		HERE_free(this->m.m_anstrFBName);
		HERE_free(this->m.FBNData->m_pstDataConnections);
		HERE_free(this->m.FBNData->m_pstEventConnections);
		HERE_free(this->m.FBNData->m_pstFBInstances);
		HERE_free(this->m.FBNData);
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
	HERE_free(this->m.CCOMPOSITEFB.m.m_apoEventConnections);
	HERE_free(this->m.CCOMPOSITEFB.m.m_apoDataConnections);
	this->m.pDynamicFB_stFBInterfaceSpec = NULL;
	this->m.CCOMPOSITEFB.m.FUNCTIONBLOCK.m.pstInterfaceSpec = NULL;
}
t_FUNCTIONBLOCK *methodDecl_(createFB) UINT pa_nInstanceNameId, void *pa_poSrcRes __
{
	t_FB_DYNAMICCFB *  copyFB = FB_DYNAMICCFB.alloc();
	copyFB->m.pDynamicFB_stFBInterfaceSpec = this->m.pDynamicFB_stFBInterfaceSpec;
	copyFB->m.FBNData = this->m.FBNData;
	copyFB->m.CCOMPOSITEFB.m.FUNCTIONBLOCK.m.m_poResource = this->m.CCOMPOSITEFB.m.FUNCTIONBLOCK.m.m_poResource;
	char *pa_acFBConnData = HERE_malloc(sizeof(void*) *(this->m.pDynamicFB_stFBInterfaceSpec->m_nNumDIs
		+ this->m.pDynamicFB_stFBInterfaceSpec->m_nNumDOs
		+ this->m.pDynamicFB_stFBInterfaceSpec->m_nNumEOs));
	char *pa_acBasicFBVarsData = HERE_malloc(sizeof(VAR) * (this->m.pDynamicFB_stFBInterfaceSpec->m_nNumDIs
		+ this->m.pDynamicFB_stFBInterfaceSpec->m_nNumDOs));
	CCOMPOSITEFB.init(super(copyFB, CCOMPOSITEFB),
		copyFB->m.pDynamicFB_stFBInterfaceSpec,
		pa_acFBConnData,
		pa_acBasicFBVarsData,
		copyFB->m.FBNData);
	copyFB->m.strTypeName = this->m.strTypeName;
	copyFB->m.CCOMPOSITEFB.m.FUNCTIONBLOCK.m.nFBInstanceName = pa_nInstanceNameId;
	copyFB->m.CCOMPOSITEFB.m.FUNCTIONBLOCK.m.m_poResource = pa_poSrcRes;
	copyFB->m.unLocalInstanceId = this->m.unLocalInstanceId + 1;
	copyFB->m.m_anConnData = pa_acFBConnData;
	copyFB->m.m_anVarsData = pa_acBasicFBVarsData;
	return &(copyFB->m.CCOMPOSITEFB.m.FUNCTIONBLOCK);
}
OBJECT_IMPLEMENTATION
	SUPERCLASS(CCOMPOSITEFB),
	methodName(detorFB),
	methodName(createFB)
ENDOF_IMPLEMENTATION
initClassDecl()
{
	initSuper(CCOMPOSITEFB);
	overload(CCOMPOSITEFB.detorFB) = methodOvldName(detorFB, CCOMPOSITEFB);
}
dtorDecl()
{
	HERE_free(this);
}
t_FB_DYNAMICCFB
classMethodDecl_(*const new) 
void* pa_vpRes, struct SFBInterfaceSpec* pa_Interface, SCFB_FBNData* pa_FBNData  __
{
	t_FB_DYNAMICCFB *const this = FB_DYNAMICCFB.alloc();
	if (this)
	{
		this->m.CCOMPOSITEFB.m.FUNCTIONBLOCK.m.m_poResource = pa_vpRes;
		FB_DYNAMICCFB.init(this, pa_Interface, pa_FBNData);
	}
	this->m.unLocalInstanceId = 0;
	this->m.eDybFBType = eCFB;
	return this;
}
void
methodDecl_(init)
	struct SFBInterfaceSpec* pa_Interface , SCFB_FBNData* pa_FBNData  __
{
	this->m.pDynamicFB_stFBInterfaceSpec = pa_Interface;
	this->m.FBNData = pa_FBNData;
	this->m.m_anVarsData = HERE_malloc(sizeof(VAR) * (this->m.pDynamicFB_stFBInterfaceSpec->m_nNumDIs
		+ this->m.pDynamicFB_stFBInterfaceSpec->m_nNumDOs));
	this->m.m_anConnData = HERE_malloc(sizeof(void*) *(this->m.pDynamicFB_stFBInterfaceSpec->m_nNumDIs
		+ this->m.pDynamicFB_stFBInterfaceSpec->m_nNumDOs
		+ this->m.pDynamicFB_stFBInterfaceSpec->m_nNumEOs));
	CCOMPOSITEFB.init(super(this, CCOMPOSITEFB), pa_Interface, this->m.m_anConnData, this->m.m_anVarsData,this->m.FBNData);
}
CLASS_IMPLEMENTATION
	methodName(new),
	methodName(init)
ENDOF_IMPLEMENTATION
#endif