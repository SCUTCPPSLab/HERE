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
#include "typelib.h"

//! The base class for dynamically loaded function block types entries in the type lib.
class CDynFBTypeEntry : public CTypeLib::CFBTypeEntry {
public:
	CDynFBTypeEntry(CStringDictionary::TStringId pa_nTypeNameId, TFunctionBlockCreateFunc pa_pfuncCreateFB);
	~CDynFBTypeEntry(void);
	CFunctionBlock * createFBInstance(CStringDictionary::TStringId pa_nInstanceNameId, CResource * pa_poSrcRes);

private:
	TFunctionBlockCreateFunc m_pfuncFBCreationFunc;
};