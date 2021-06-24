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
#include "cfb.h"

class CDynCFB : public CCompositeFB
{
public:
	CDynCFB(CResource *pa_poSrcRes, const SFBInterfaceSpec *pa_pstInterfaceSpec,
		const CStringDictionary::TStringId pa_nInstanceNameId,
		 SCFB_FBNData * const pa_cpoFBNData, TForteByte *pa_acFBConnData, TForteByte *pa_acFBVarsData) ;
	~CDynCFB();
	void setFBTypeId(CStringDictionary::TStringId pa_FBTypeId) { m_FBTypeId = pa_FBTypeId; }
	virtual CStringDictionary::TStringId getFBTypeId(void) const { return m_FBTypeId; };
private:
	CStringDictionary::TStringId m_FBTypeId;
	TForteByte *aFBConnData;
	TForteByte *aFBVarsData;
	const SCFB_FBNData* aFBNData;
	const SFBInterfaceSpecforGenerics* m_FBInterf;
};