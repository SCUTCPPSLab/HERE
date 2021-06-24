/*******************************************************************************
 * Copyright (c) 2013 ACIN
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *   Monika Wenger
 *   - initial API and implementation and/or initial documentation
 *******************************************************************************/

#include "F_TIME_TO_DINT.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "F_TIME_TO_DINT_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_F_TIME_TO_DINT, g_nStringIdF_TIME_TO_DINT)

const CStringDictionary::TStringId FORTE_F_TIME_TO_DINT::scm_anDataInputNames[] = {g_nStringIdIN};

const CStringDictionary::TStringId FORTE_F_TIME_TO_DINT::scm_anDataInputTypeIds[] = {g_nStringIdTIME};

const CStringDictionary::TStringId FORTE_F_TIME_TO_DINT::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_F_TIME_TO_DINT::scm_anDataOutputTypeIds[] = {g_nStringIdDINT};

const TForteInt16 FORTE_F_TIME_TO_DINT::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_F_TIME_TO_DINT::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId FORTE_F_TIME_TO_DINT::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_F_TIME_TO_DINT::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_F_TIME_TO_DINT::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_F_TIME_TO_DINT::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_F_TIME_TO_DINT::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_F_TIME_TO_DINT::executeEvent(int pa_nEIID){
  if(scm_nEventREQID == pa_nEIID){
    OUT() = TIME_TO_DINT(IN());
    sendOutputEvent(scm_nEventCNFID);
  }
}
