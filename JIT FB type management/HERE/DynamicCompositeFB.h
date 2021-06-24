/*
*********************************************************************************************************
*fb C code  
*File name:DynamicCFB.h
*Description:;
*********************************************************************************************************
*/
#ifdef _CLASS2_ENABLE
#ifndef   _DYNAMICCOMPOSITEFB_H_
#define   _DYNAMICCOMPOSITEFB_H_

#include "ooc.h" 
#include "HERE.h"
#include "cfb.h"
#include "libtcc.h"

#define FREE_CFBINTERF() HERE_free((void*)this->m.pDynamicFB_stFBInterfaceSpec->m_anEIWith);\
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

#undef OBJECT
#define OBJECT FB_DYNAMICCFB

OBJECT_INTERFACE
	INHERIT_MEMBERS_OF(CCOMPOSITEFB);
	TCCState *public(s);
	char* public(strTypeName);
	char* public(m_anConnData);
	char* public(m_anVarsData);
	char** public(m_anstrFBName);
	//DYNAMIC PART-InterfaceList
	struct SFBInterfaceSpec* public(pDynamicFB_stFBInterfaceSpec);
	//DYNAMIC PART-FBNetwork
	SCFB_FBNData* public(FBNData);
	UINT8 public(unLocalInstanceId);
	EFBType public(eDybFBType);
OBJECT_METHODS
	INHERIT_METHODS_OF(CCOMPOSITEFB);
	void method(detorFB);
	t_FUNCTIONBLOCK *method_(createFB) UINT pa_nInstanceNameId, void *pa_poSrcRes __;
ENDOF_INTERFACE
CLASS_INTERFACE
	t_FB_DYNAMICCFB*const classMethod_(new)  void* pa_vpRes, struct SFBInterfaceSpec* pa_Interface, SCFB_FBNData* pa_FBNData   __;
	void method_(init) struct SFBInterfaceSpec* pa_Interface, SCFB_FBNData* pa_FBNData __;
ENDOF_INTERFACE
#endif
#endif
