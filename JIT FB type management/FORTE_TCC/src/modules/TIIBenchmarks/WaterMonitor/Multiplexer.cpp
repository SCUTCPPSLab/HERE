/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Multiplexer
 *** Description: null
 *** Version: 
 ***     0.2: 2003-12-04/JHC - Rockwell Automation - Renamed for better indexing.
 ***     0.1: 2002-11-05/JHC - Rockwell Automation - Corrected missing ST element in Algorithm REQ.
 ***     0.0: 2000-05-30/JHC - Rockwell Automation - 
 *************************************************************************/

#include "Multiplexer.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "Multiplexer_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_Multiplexer, g_nStringIdMultiplexer)

const TForteInt16 FORTE_Multiplexer::scm_anEIWithIndexes[] = {-1, -1, -1, -1};
const CStringDictionary::TStringId FORTE_Multiplexer::scm_anEventInputNames[] = {g_nStringIdstandby, g_nStringIdoperating, g_nStringIdshutdown, g_nStringIdtest};

const TForteInt16 FORTE_Multiplexer::scm_anEOWithIndexes[] = {-1, -1, -1};
const CStringDictionary::TStringId FORTE_Multiplexer::scm_anEventOutputNames[] = {g_nStringIdtestTimer, g_nStringIdshutdownTimer};

const SFBInterfaceSpec FORTE_Multiplexer::scm_stFBInterfaceSpec = {
  4,  scm_anEventInputNames,  0,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  0, 0,  0,  0, 0, 
  0,  0, 0,
  0, 0
};


void FORTE_Multiplexer::enterStateDONTCARE(void){
  m_nECCState = scm_nStateDONTCARE;
}

void FORTE_Multiplexer::enterStateSHUTDOWN(void){
  m_nECCState = scm_nStateSHUTDOWN;
  sendOutputEvent( scm_nEventshutdownTimerID);
}

void FORTE_Multiplexer::enterStateTEST(void){
  m_nECCState = scm_nStateTEST;
  sendOutputEvent( scm_nEventtestTimerID);
}

void FORTE_Multiplexer::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateDONTCARE:
        if(scm_nEventtestID == pa_nEIID)
          enterStateTEST();
        else
        if(scm_nEventshutdownID == pa_nEIID)
          enterStateSHUTDOWN();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateSHUTDOWN:
        if(scm_nEventshutdownID == pa_nEIID)
          enterStateSHUTDOWN();
        else
        if(scm_nEventtestID == pa_nEIID)
          enterStateTEST();
        else
        if(scm_nEventoperatingID == pa_nEIID)
          enterStateDONTCARE();
        else
        if(scm_nEventstandbyID == pa_nEIID)
          enterStateDONTCARE();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateTEST:
        if(scm_nEventtestID == pa_nEIID)
          enterStateTEST();
        else
        if(scm_nEventshutdownID == pa_nEIID)
          enterStateSHUTDOWN();
        else
        if(scm_nEventoperatingID == pa_nEIID)
          enterStateDONTCARE();
        else
        if(scm_nEventstandbyID == pa_nEIID)
          enterStateDONTCARE();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 2.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


