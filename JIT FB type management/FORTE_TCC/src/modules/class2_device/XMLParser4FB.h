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
#include "mxml.h"
#include "resource.h"
#include "DynBasicFunctionBlock.h"
#include "include/libtcc.h"
typedef void(*funcAlg)(void*);
typedef struct t_AlgEntity
{
	funcAlg m_pAlgFunc;
	const char* m_strName;
}t_AlgEntity;

class CXMLParser4BFB;
class CXMLParser4CFB;
class CXMLParser4FB
{

#define MAX_ESTATE_NUM 20
#define MAX_DYEO_NUM 20
#define MAX_DYEI_NUM 20
#define MAX_DYDO_NUM 10
#define MAX_DYDI_NUM 10
#define MAX_ALG_NUM 10
	
public:
	CXMLParser4FB();
	~CXMLParser4FB();
	EMGMResponse createDynamicFB  (CResource * pa_pRes, CStringDictionary::TStringId paTypeId, CStringDictionary::TStringId paNameId);
	CFunctionBlock* getFB(CStringDictionary::TStringId paTypeId);
	TForteUInt8 getDIId(const char* pa_strDIName);
	TForteUInt8 getDOId(const char* pa_strDOName);
	void parseInterfaces(mxml_node_t *rootNode, TCCState *s);
	TForteUInt8 getEIId(const char* pa_strEIName);
	TForteUInt8 getEOId(const char* pa_strEOName);
private:
	mxml_node_t *rootNode;
	CFunctionBlock* m_FB;
	TForteUInt8 unECStateNum;
	TForteUInt8 unECTransitNum;
	CXMLParser4BFB* bfbHandler;
	CXMLParser4CFB* cfbHandler;
protected:
	TForteUInt8 unEINum;
	TForteUInt8 unEONum;
	TForteUInt8 unDINum;
	TForteUInt8 unDONum;
	TForteUInt8 unAlgNum;
	TForteUInt8 unEIWithNum;
	TForteUInt8 unEOWithNum;
 
	CStringDictionary::TStringId unEIName[MAX_DYEI_NUM];
	TDataIOID nEIWith[MAX_DYEI_NUM*MAX_DYDI_NUM];
	TForteInt16 nEIWithIndex[MAX_DYEI_NUM];
	CStringDictionary::TStringId unEOName[MAX_DYEO_NUM];
	TDataIOID nEOWith[MAX_DYEO_NUM*MAX_DYDO_NUM];
	TForteInt16 nEOWithIndex[MAX_DYEO_NUM];

	CStringDictionary::TStringId unDIName[MAX_DYDI_NUM];
	CStringDictionary::TStringId unDITypeName[MAX_DYDI_NUM];
	CStringDictionary::TStringId unDOName[MAX_DYDO_NUM];
	CStringDictionary::TStringId unDOTypeName[MAX_DYDO_NUM];

	TForteUInt8 nECStateAcNum[MAX_ESTATE_NUM];

	const char*  strEIName[MAX_DYEI_NUM];
	const char*  strEOName[MAX_DYEO_NUM];
	const char*  strDOName[MAX_DYDO_NUM];
	const char*  strDIName[MAX_DYDI_NUM];
	const char*  strECStateName[MAX_ESTATE_NUM];
	t_AlgEntity pAlgEntity[MAX_ALG_NUM];

	static SFBInterfaceSpec* m_FBInterf;

	TCCState *s;
};

