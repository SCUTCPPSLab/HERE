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
#include "DynFBTypeEntry.h"
#include "mxml.h"


CDynFBTypeEntry::CDynFBTypeEntry(CStringDictionary::TStringId pa_nTypeNameId, TFunctionBlockCreateFunc pa_pfuncCreateFB)
	:CTypeLib::CFBTypeEntry(pa_nTypeNameId, pa_pfuncCreateFB)
{
	 
}

CDynFBTypeEntry::~CDynFBTypeEntry()
{
	
}
CFunctionBlock *CDynFBTypeEntry::createFBInstance(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes)
{
	return m_pfuncFBCreationFunc(pa_nInstanceNameId, pa_poSrcRes);
}