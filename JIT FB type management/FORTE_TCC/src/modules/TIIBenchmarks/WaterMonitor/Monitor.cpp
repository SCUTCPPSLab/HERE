/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Monitor
 *** Description: null
 *** Version: 
 ***     0.2: 2003-12-04/JHC - Rockwell Automation - Renamed for better indexing.
 ***     0.1: 2002-11-05/JHC - Rockwell Automation - Corrected missing ST element in Algorithm REQ.
 ***     0.0: 2000-05-30/JHC - Rockwell Automation - 
 *************************************************************************/

#include "Monitor.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "Monitor_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_Monitor, g_nStringIdMonitor)

const CStringDictionary::TStringId FORTE_Monitor::scm_anDataInputNames[] = {g_nStringIdwithinLimits, g_nStringIdwithinHys};

const CStringDictionary::TStringId FORTE_Monitor::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL};

const TForteInt16 FORTE_Monitor::scm_anEIWithIndexes[] = {-1, -1, -1, -1, 0};
const TDataIOID FORTE_Monitor::scm_anEIWith[] = {0, 1, 255};
const CStringDictionary::TStringId FORTE_Monitor::scm_anEventInputNames[] = {g_nStringIdslfTstInterval, g_nStringIdreset1, g_nStringIdtstInterval, g_nStringIdshutdownLock, g_nStringIdrange};

const TForteInt16 FORTE_Monitor::scm_anEOWithIndexes[] = {-1, -1, -1, -1, -1};
const CStringDictionary::TStringId FORTE_Monitor::scm_anEventOutputNames[] = {g_nStringIdstandby, g_nStringIdoperating, g_nStringIdshutdown, g_nStringIdtest};

const SFBInterfaceSpec FORTE_Monitor::scm_stFBInterfaceSpec = {
  5,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  4,  scm_anEventOutputNames,  0, 0,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  0,  0, 0,
  0, 0
};


void FORTE_Monitor::setInitialValues(){
  withinLimits() = true;
  withinHys() = true;
}


void FORTE_Monitor::enterStateSTANDBY(void){
  m_nECCState = scm_nStateSTANDBY;
}

void FORTE_Monitor::enterStateSHUTDOWN(void){
  m_nECCState = scm_nStateSHUTDOWN;
  sendOutputEvent( scm_nEventshutdownID);
}

void FORTE_Monitor::enterStateOPERATING(void){
  m_nECCState = scm_nStateOPERATING;
  sendOutputEvent( scm_nEventoperatingID);
}

void FORTE_Monitor::enterStateTEST(void){
  m_nECCState = scm_nStateTEST;
  sendOutputEvent( scm_nEventtestID);
}

void FORTE_Monitor::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTANDBY:
        if(scm_nEventslfTstIntervalID == pa_nEIID)
          enterStateTEST();
        else
        if((scm_nEventreset1ID == pa_nEIID) && (withinLimits()))
          enterStateOPERATING();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateSHUTDOWN:
        if(scm_nEventslfTstIntervalID == pa_nEIID)
          enterStateTEST();
        else
        if((scm_nEventrangeID == pa_nEIID) && (withinHys()))
          enterStateOPERATING();
        else
        if(scm_nEventshutdownLockID == pa_nEIID)
          enterStateSTANDBY();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateOPERATING:
        if(scm_nEventslfTstIntervalID == pa_nEIID)
          enterStateTEST();
        else
        if((scm_nEventrangeID == pa_nEIID) && (!withinLimits()))
          enterStateSHUTDOWN();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateTEST:
        if(scm_nEventslfTstIntervalID == pa_nEIID)
          enterStateTEST();
        else
        if(scm_nEventtstIntervalID == pa_nEIID)
          enterStateSTANDBY();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 3.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


