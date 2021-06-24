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
#include "DynCompositeFunctionBlock.h"
class CXMLParser4CFB : public CXMLParser4FB
{
	typedef CSinglyLinkedList<CDynCFB*> TDynCFBTypeList;
public:
	CXMLParser4CFB(mxml_node_t *rootNode, TCCState *s);
	~CXMLParser4CFB();

	EMGMResponse createDynamicFB(CResource * pa_pRes, CStringDictionary::TStringId paTypeId, CStringDictionary::TStringId paNameId);
	CFunctionBlock* getFB(CStringDictionary::TStringId paTypeId);
	void parseFBN(CResource * pa_pRes, CCompositeFB*pa_FB, bool pa_bInit);
	void parseEC(CResource * pa_pRes, CCompositeFB*pa_FB, bool pa_bInit);
	void parseDC(CResource * pa_pRes, CCompositeFB*pa_FB, bool pa_bInit);
private:
	int getFBIdx(const char* pa_strFBName);
private:
	mxml_node_t *rootNode;
	CDynCFB* m_FB;
	TCCState *s;
	TDynCFBTypeList lstDynCFBType;
	struct SCFB_FBNData* m_FBNData;
	const char** m_FBNameList;
};