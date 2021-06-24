/*
*********************************************************************************************************
*fb C code  
*File name:FB_DYNAMICBFB.h
*Description:;
*********************************************************************************************************
*/
#ifdef _CLASS2_ENABLE
#ifndef   _DYNAMICBFB_H_
#define   _DYNAMICBFB_H_

#include "ooc.h" 
#include "HERE.h"
#include "functionblock.h"
#include "libtcc.h"
#undef OBJECT
#define OBJECT FB_DYNAMICBFB

typedef void(*t_algFunc)(void*);
typedef BOOL(*t_stateTransitEvalFunc)(void*, INT16, UINT8);

typedef struct t_stateAction
{
	t_algFunc m_pAlgFunc;
	UINT m_nEOId;
}t_stateAction;

#define INIT_FBINTERF(pa_unDINum,pa_unDONum,pa_unEINum,pa_unEONum) this->m.pDynamicFB_stFBInterfaceSpec = HERE_malloc(sizeof(struct SFBInterfaceSpec));\
this->m.pDynamicFB_stFBInterfaceSpec->m_aunDIDataTypeNames = HERE_malloc(sizeof(UINT16)*pa_unDINum);\
this->m.pDynamicFB_stFBInterfaceSpec->m_aunDINames = HERE_malloc(sizeof(UINT16)*pa_unDINum);\
this->m.pDynamicFB_stFBInterfaceSpec->m_aunDODataTypeNames = HERE_malloc(sizeof(UINT16)*pa_unDONum);\
this->m.pDynamicFB_stFBInterfaceSpec->m_aunDONames = HERE_malloc(sizeof(UINT16)*pa_unDONum);\
this->m.pDynamicFB_stFBInterfaceSpec->m_aunEINames = HERE_malloc(sizeof(INT16)*pa_unEINum);\
this->m.pDynamicFB_stFBInterfaceSpec->m_anEIWith = 0;\
this->m.pDynamicFB_stFBInterfaceSpec->m_anEIWithIndexes = HERE_malloc(sizeof(INT8)*pa_unEINum);\
this->m.pDynamicFB_stFBInterfaceSpec->m_aunEONames = HERE_malloc(sizeof(INT16)*pa_unEONum);\
this->m.pDynamicFB_stFBInterfaceSpec->m_anEOWith = 0;\
this->m.pDynamicFB_stFBInterfaceSpec->m_anEOWithIndexes = HERE_malloc(sizeof(INT8)*pa_unEONum);\
this->m.pDynamicFB_stFBInterfaceSpec->m_nNumDIs = pa_unDINum;\
this->m.pDynamicFB_stFBInterfaceSpec->m_nNumEIs = pa_unEINum;\
this->m.pDynamicFB_stFBInterfaceSpec->m_nNumEOs = pa_unEONum;\
this->m.pDynamicFB_stFBInterfaceSpec->m_nNumDOs = pa_unDONum;

#define FREE_FBINTERF() HERE_free((void*)this->m.pDynamicFB_stFBInterfaceSpec->m_anEIWith);\
HERE_free((void*)this->m.pDynamicFB_stFBInterfaceSpec->m_anEIWithIndexes);\
HERE_free((void*)this->m.pDynamicFB_stFBInterfaceSpec->m_anEOWith);\
HERE_free((void*)this->m.pDynamicFB_stFBInterfaceSpec->m_anEOWithIndexes);\
HERE_free((void*)this->m.pDynamicFB_stFBInterfaceSpec->m_aunDIDataTypeNames);\
HERE_free((void*)this->m.pDynamicFB_stFBInterfaceSpec->m_aunDINames);\
HERE_free((void*)this->m.pDynamicFB_stFBInterfaceSpec->m_aunDODataTypeNames);\
HERE_free((void*)this->m.pDynamicFB_stFBInterfaceSpec->m_aunDONames);\
HERE_free((void*)this->m.pDynamicFB_stFBInterfaceSpec->m_aunEINames);\
HERE_free((void*)this->m.pDynamicFB_stFBInterfaceSpec->m_aunEONames);\
HERE_free((void*)this->m.pDynamicFB_stFBInterfaceSpec);

OBJECT_INTERFACE
	INHERIT_MEMBERS_OF(FUNCTIONBLOCK);
	TCCState *public(s);
	char public(strTypeName[256]);
	char* public(m_anConnData);
	char* public(m_anVarsData);
	t_stateTransitEvalFunc public(pFuncEval);
	//DYNAMIC PART-InterfaceList
	struct SFBInterfaceSpec* public(pDynamicFB_stFBInterfaceSpec);
	//DYNAMIC PART-ECC
	UINT8 public(unCurState);
	UINT8 public(unStateNum);
	UINT8 public(unTransNum);
	void** public(aStates);
	void* public(aTransits);
	BOOL public(bTransitCleared);
	//DYNAMIC PART-FBNetwork
	//SCFB_FBNData* public(FBNData);

	UINT8 public(unLocalInstanceId);
	EFBType public(eDybFBType);
OBJECT_METHODS
	INHERIT_METHODS_OF(FUNCTIONBLOCK);
	void method_(executeECC) 	unsigned int curEIID __;
	void method(detorFB);
	t_FUNCTIONBLOCK *method_(createFB) UINT pa_nInstanceNameId, void *pa_poSrcRes __;
ENDOF_INTERFACE
CLASS_INTERFACE
	t_FB_DYNAMICBFB*const classMethod_(new)  void* pa_vpRes, struct SFBInterfaceSpec* pa_Interface, UINT8 pa_unStateNum, UINT8 pa_unTransNum   __;
	void method_(init) struct SFBInterfaceSpec* pa_Interface, UINT8 pa_unStateNum, UINT8 pa_unTransNum __;
	void method_(initState) UINT8 pa_unStateId, UINT8 pa_nActionNum __;
	void method_(initTranstion) UINT8 pa_unSrcStateId, UINT8 pa_unDstStateId __;
	void method_(bindStateAction) UINT8 pa_unStateId, UINT8 pa_unActionId, UINT8 pa_unEOId, void* pa_vpFunc __;
	void method_(bindStateTranstion) UINT8 pa_unSrcStateId __;
ENDOF_INTERFACE
#endif
#endif
