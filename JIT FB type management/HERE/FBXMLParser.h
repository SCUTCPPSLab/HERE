#ifdef _CLASS2_ENABLE
#ifndef _FBXMLPARSER_H__
#define	_FBXMLPARSER_H__
#include "ooc.h" 
#include "HERE.h"
#include "DynamicBFB.h"
#include "DynamicCompositeFB.h"
#include "mxml.h"
#include "libtcc.h"
#undef OBJECT
#define OBJECT CFBXmlParser

#define MAX_ESTATE_NUM 10
#define MAX_DYEO_NUM 5
#define MAX_DYEI_NUM 5
#define MAX_DYDO_NUM 10
#define MAX_DYDI_NUM 10
#define MAX_ALG_NUM 10
typedef void(*funcAlg)(void*);

typedef struct t_AlgEntity
{
	funcAlg m_pAlgFunc;
	const char* m_strName;
}t_AlgEntity;

typedef struct SDyFBEntry{
	t_FUNCTIONBLOCK* m_fb;
	struct list_head list;
}SDyFBEntry;

typedef struct STCCEntry {
	TCCState* m_tcc;
	struct list_head list;
}STCCEntry;
typedef void *(*TDynFunctionBlockCreateFunc)(void* fbtype, UINT pa_nInstanceNameId, void *pa_poSrcRes);
BASEOBJECT_INTERFACE
	struct SFBInterfaceSpec* public(pFBInterfaceSpec);
	UINT8 public(unEINum);
	UINT8 public(unEONum);
	UINT8 public(unDINum);
	UINT8 public(unDONum);
	UINT8 public(unEIWithNum);
	UINT8 public(unEOWithNum);
	INT8 public(nEOWithIndex[MAX_DYEO_NUM]);
	INT8 public(nEIWithIndex[MAX_DYEI_NUM]);
	INT16 public(nEOWith[MAX_DYEO_NUM*MAX_DYDO_NUM]);
	INT16 public(nEIWith[MAX_DYEI_NUM*MAX_DYDI_NUM]);
	UINT16 public(unEOName[MAX_DYEO_NUM]);
	UINT16 public(unEIName[MAX_DYEI_NUM]);
	UINT16 public(unDOName[MAX_DYDO_NUM]);
	UINT16 public(unDIName[MAX_DYDI_NUM]);
	UINT16 public(unDITypeName[MAX_DYDI_NUM]);
	UINT16 public(unDOTypeName[MAX_DYDO_NUM]);

	const char* public(strEIName[MAX_DYEI_NUM]);
	const char* public(strEOName[MAX_DYEO_NUM]);
	const char* public(strDOName[MAX_DYDO_NUM]);
	const char* public(strDIName[MAX_DYDI_NUM]);

	UINT8 public(unECStateNum);
	UINT8 public(unECTransitNum);
	UINT8 public(unAlgNum);
	UINT8 public(nECStateAcNum[MAX_ESTATE_NUM]);
	const char* public(strECStateName[MAX_ESTATE_NUM]);
	t_AlgEntity public(pAlgEntity[MAX_ALG_NUM]);

	struct SCFB_FBNData* public(m_FBNData);
	const char** public(m_FBNameList);

	mxml_node_t *public(rootNode);
	t_FB_DYNAMICFB* public(pstDFB);
	
	struct list_head public(tcclist);
	TCCState* public(s);
	void* public(pFuncCreator);
BASEOBJECT_METHODS
	void method_(parseInterfaces) BOOL pa_bInit __;
	void method_(parseAlgorithms)t_FB_DYNAMICBFB* pa_pstDFB, BOOL pa_bInit __;
	void method_(parseInternalVars)t_FB_DYNAMICFB* pa_pstDFB, BOOL pa_bInit __;
	void method_(parseECStates)t_FB_DYNAMICBFB* pa_pstDFB, BOOL pa_bInit __;
	void method_(parseECTransitions)t_FB_DYNAMICBFB* pa_pstDFB, BOOL pa_bInit __;
	UINT8 method_(getECStateId)const char* pa_strStateName __;
	UINT8 method_(getEOId)const char* pa_strEOName __;
	UINT8 method_(getDOId)const char* pa_strDOName __;
	UINT8 method_(getEIId)const char* pa_strEIName __;
	UINT8 method_(getDIId)const char* pa_strDIName __;
	funcAlg method_(getAlgorithm)const char* pa_strAlgName __;
	void method(parseFBN);
	void method(parseEC);
	void method(parseDC);
ENDOF_INTERFACE
CLASS_INTERFACE
	t_CFBXmlParser*const classMethod(new) ;
	t_FUNCTIONBLOCK* method_(createDynamicFB)  void* pa_pRes, char* pa_strFBName __;
	int method_(getFBIdx) const char* pa_strFBName __;
ENDOF_INTERFACE

#endif // !_FBXMLPARSER_H__
#endif
