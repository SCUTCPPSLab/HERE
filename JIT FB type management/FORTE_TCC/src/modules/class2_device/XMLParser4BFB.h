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
#pragma once
#include "XMLParser4FB.h"

class CXMLParser4BFB : public CXMLParser4FB 
{
	#define MAX_ESTATE_NUM 20
	#define MAX_ALG_NUM 10
	#define MAX_DYIV_NUM 10
	typedef CSinglyLinkedList<CDynBasicFunctionBlock*> TDynBFBTypeList;
public:
	CXMLParser4BFB(mxml_node_t *rootNode, TCCState *s);
	~CXMLParser4BFB();

	EMGMResponse createDynamicFB(CResource * pa_pRes, CStringDictionary::TStringId paTypeId, CStringDictionary::TStringId paNameId);
	CFunctionBlock* getFB(CStringDictionary::TStringId paTypeId);
	void parseInternalVars(CDynBasicFunctionBlock* pa_pstDFB, bool pa_bInit);
	void parseAlgorithms(CDynBasicFunctionBlock* pa_pstDFB, bool pa_bInit);
	void parseECTransitions(CDynBasicFunctionBlock* pa_pstDFB, bool pa_bInit);
	void parseECStates(CDynBasicFunctionBlock* pa_pstDFB, bool pa_bInit);
	funcAlg getAlgorithm(const char* pa_strAlgName);
	TForteUInt8 getECStateId(const char* pa_strStateName);
public:
	static char algText[4096];
	static char internalValDeclText[1024];
private:
	mxml_node_t *rootNode;
	CDynBasicFunctionBlock* m_FB;
	TForteUInt8 unECStateNum;
	TForteUInt8 unECTransitNum;
	TForteUInt8 unAlgNum;
	TForteUInt8 nECStateAcNum[MAX_ESTATE_NUM];
	const char*  strECStateName[MAX_ESTATE_NUM];
	t_AlgEntity pAlgEntity[MAX_ALG_NUM];
	TCCState *s;
	TDynBFBTypeList lstDynBFBType;
};