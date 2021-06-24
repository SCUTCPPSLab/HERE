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
#include "DynCompositeFunctionBlock.h"
CDynCFB::CDynCFB(CResource *pa_poSrcRes, const SFBInterfaceSpec *pa_pstInterfaceSpec,
	const CStringDictionary::TStringId pa_nInstanceNameId,
	 SCFB_FBNData * const pa_cpoFBNData, TForteByte *pa_acFBConnData, TForteByte *pa_acFBVarsData
	) :
	aFBConnData(pa_acFBConnData),
	aFBVarsData(pa_acFBVarsData),
	CCompositeFB(pa_poSrcRes, pa_pstInterfaceSpec, pa_nInstanceNameId, pa_cpoFBNData, pa_acFBConnData, pa_acFBVarsData)

{
	aFBNData = pa_cpoFBNData;
	m_FBInterf = (const SFBInterfaceSpecforGenerics*)pa_pstInterfaceSpec;
}

CDynCFB::~CDynCFB()
{

}