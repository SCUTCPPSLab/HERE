/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: AccelDecel
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.2: 2003-12-04/JHC - Rockwell Automation - Renamed for better indexing.
 ***     0.1: 2002-11-05/JHC - Rockwell Automation - Corrected missing ST element in Algorithm REQ.
 ***     0.0: 2000-05-30/JHC - Rockwell Automation - 
 *************************************************************************/

#include "AccelDecel.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "AccelDecel_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_AccelDecel, g_nStringIdAccelDecel)

const CStringDictionary::TStringId FORTE_AccelDecel::scm_anDataInputNames[] = {g_nStringIdcruiseSpeed};

const CStringDictionary::TStringId FORTE_AccelDecel::scm_anDataInputTypeIds[] = {g_nStringIdINT};

const TForteInt16 FORTE_AccelDecel::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_AccelDecel::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId FORTE_AccelDecel::scm_anEventInputNames[] = {g_nStringIdspeedSet};

const TForteInt16 FORTE_AccelDecel::scm_anEOWithIndexes[] = {-1, -1};
const CStringDictionary::TStringId FORTE_AccelDecel::scm_anEventOutputNames[] = {g_nStringIdviolated};

const SFBInterfaceSpec FORTE_AccelDecel::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  0, 0,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  0,  0, 0,
  0, 0
};

void FORTE_AccelDecel::alg_INIT(void){

}


void FORTE_AccelDecel::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_AccelDecel::enterStateINIT(void){
  m_nECCState = scm_nStateINIT;
  alg_INIT();
  sendOutputEvent( scm_nEventviolatedID);
}

void FORTE_AccelDecel::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventspeedSetID == pa_nEIID)
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


