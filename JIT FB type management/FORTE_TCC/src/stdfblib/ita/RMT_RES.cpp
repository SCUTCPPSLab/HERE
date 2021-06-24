/*******************************************************************************
 * Copyright (c) 2005 - 2015 ACIN, Profactor GmbH, fortiss GmbH
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *   Alois Zoitl, Gerhard Ebenhofer, Rene Smodic, Thomas Strasser,
 *   Martin Melik Merkumians, Ingo Hegny
 *    - initial API and implementation and/or initial documentation
 *******************************************************************************/
#include "RMT_RES.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "RMT_RES_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(RMT_RES, g_nStringIdRMT_RES);

const CStringDictionary::TStringId RMT_RES::scm_aunVarInputNameIds[] = {g_nStringIdMGR_ID};
const CStringDictionary::TStringId RMT_RES::scm_aunDIDataTypeIds[] = {g_nStringIdWSTRING};


const SFBInterfaceSpec RMT_RES::scm_stRESInterfaceSpec = {
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  1,
  scm_aunVarInputNameIds,
  scm_aunDIDataTypeIds,
  0,
  0,
  0,
  0,
  0
  };


RMT_RES::RMT_RES(CStringDictionary::TStringId pa_nInstanceNameId, CResource* pa_poDevice):
       CResource(pa_poDevice, &scm_stRESInterfaceSpec, pa_nInstanceNameId, m_anFBConnData, m_anFBVarsData){
  addFB(CTypeLib::createFB(g_nStringIdSTART, g_nStringIdE_RESTART, this));
  addFB(CTypeLib::createFB(g_nStringIdMGR_FF, g_nStringIdE_SR, this));
  addFB(CTypeLib::createFB(g_nStringIdMGR, g_nStringIdDEV_MGR, this));

  forte::core::SManagementCMD command;

  command.mFirstParam.pushBack(g_nStringIdSTART);
  command.mFirstParam.pushBack(g_nStringIdCOLD);
  command.mSecondParam.pushBack(g_nStringIdMGR_FF);
  command.mSecondParam.pushBack(g_nStringIdS);
  createConnection(command);

  command.mFirstParam.clear();
  command.mFirstParam.pushBack(g_nStringIdSTART);
  command.mFirstParam.pushBack(g_nStringIdwARM);
  command.mSecondParam.clear();
  command.mSecondParam.pushBack(g_nStringIdMGR_FF);
  command.mSecondParam.pushBack(g_nStringIdS);
  createConnection(command);

  command.mFirstParam.clear();
  command.mFirstParam.pushBack(g_nStringIdSTART);
  command.mFirstParam.pushBack(g_nStringIdSTOP);
  command.mSecondParam.clear();
  command.mSecondParam.pushBack(g_nStringIdMGR_FF);
  command.mSecondParam.pushBack(g_nStringIdR);
  createConnection(command);

  command.mFirstParam.clear();
  command.mFirstParam.pushBack(g_nStringIdMGR_FF);
  command.mFirstParam.pushBack(g_nStringIdEO);
  command.mSecondParam.clear();
  command.mSecondParam.pushBack(g_nStringIdMGR);
  command.mSecondParam.pushBack(g_nStringIdINIT);
  createConnection(command);

  command.mFirstParam.clear();
  command.mFirstParam.pushBack(g_nStringIdMGR_FF);
  command.mFirstParam.pushBack(g_nStringIdQ);
  command.mSecondParam.clear();
  command.mSecondParam.pushBack(g_nStringIdMGR);
  command.mSecondParam.pushBack(g_nStringIdQI);
  createConnection(command);

  command.mFirstParam.clear();
  command.mFirstParam.pushBack(g_nStringIdMGR_ID);
  command.mSecondParam.clear();
  command.mSecondParam.pushBack(g_nStringIdMGR);
  command.mSecondParam.pushBack(g_nStringIdID);
  createConnection(command);
  
  //Perform reset command normally done by the typelib during the creation process
  changeFBExecutionState(cg_nMGM_CMD_Reset);
}

RMT_RES::~RMT_RES(){
}


#ifdef FORTE_SUPPORT_CLASS2DEV
CFunctionBlock* RMT_RES::handleUnknownType(CStringDictionary::TStringId paNameId, CStringDictionary::TStringId paTypeId, bool bCreateInstance)
{
	EMGMResponse eRetVal;
	eRetVal = m_xmlparser.createDynamicFB(this, paTypeId, paNameId);
	if (bCreateInstance == true)
	{
		return m_xmlparser.getFB(paTypeId);
	}
	else
	{
		return NULL;
	}
}
#endif