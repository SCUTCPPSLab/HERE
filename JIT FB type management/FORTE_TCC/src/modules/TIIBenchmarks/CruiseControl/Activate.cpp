/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Activate
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.2: 2003-12-04/JHC - Rockwell Automation - Renamed for better indexing.
 ***     0.1: 2002-11-05/JHC - Rockwell Automation - Corrected missing ST element in Algorithm REQ.
 ***     0.0: 2000-05-30/JHC - Rockwell Automation - 
 *************************************************************************/

#include "Activate.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "Activate_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_Activate, g_nStringIdActivate)

const CStringDictionary::TStringId FORTE_Activate::scm_anDataInputNames[] = {g_nStringIdspeedVal};

const CStringDictionary::TStringId FORTE_Activate::scm_anDataInputTypeIds[] = {g_nStringIdINT};

const TForteInt16 FORTE_Activate::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_Activate::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId FORTE_Activate::scm_anEventInputNames[] = {g_nStringIdregulSet};

const TForteInt16 FORTE_Activate::scm_anEOWithIndexes[] = {-1, -1};
const CStringDictionary::TStringId FORTE_Activate::scm_anEventOutputNames[] = {g_nStringIdviolated};

const SFBInterfaceSpec FORTE_Activate::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  0, 0,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  0,  0, 0,
  0, 0
};

void FORTE_Activate::alg_INIT(void){

}


void FORTE_Activate::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_Activate::enterStateINIT(void){
  m_nECCState = scm_nStateINIT;
  alg_INIT();
  sendOutputEvent( scm_nEventviolatedID);
}

void FORTE_Activate::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventregulSetID == pa_nEIID)
          enterStateINIT();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateINIT:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 1.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


