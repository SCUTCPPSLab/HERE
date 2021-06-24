/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Watch_WatchMode
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.2: 2003-12-04/JHC - Rockwell Automation - Renamed for better indexing.
 *************************************************************************/

#include "Watch_WatchMode.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "Watch_WatchMode_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_Watch_WatchMode, g_nStringIdWatch_WatchMode)

const TForteInt16 FORTE_Watch_WatchMode::scm_anEIWithIndexes[] = {-1, -1, -1};
const CStringDictionary::TStringId FORTE_Watch_WatchMode::scm_anEventInputNames[] = {g_nStringIdB1, g_nStringIdEnable, g_nStringIdDisable};

const TForteInt16 FORTE_Watch_WatchMode::scm_anEOWithIndexes[] = {-1, -1, -1, -1};
const CStringDictionary::TStringId FORTE_Watch_WatchMode::scm_anEventOutputNames[] = {g_nStringIdShow24h, g_nStringIdShow12h, g_nStringIdEnableNext};

const CStringDictionary::TStringId FORTE_Watch_WatchMode::scm_anInternalsNames[] = {g_nStringIdAlarmOn};

const CStringDictionary::TStringId FORTE_Watch_WatchMode::scm_anInternalsTypeIds[] = {g_nStringIdBOOL};

const SFBInterfaceSpec FORTE_Watch_WatchMode::scm_stFBInterfaceSpec = {
  3,  scm_anEventInputNames,  0,  scm_anEIWithIndexes,
  3,  scm_anEventOutputNames,  0, 0,  0,  0, 0, 
  0,  0, 0,
  0, 0
};


const SInternalVarsInformation FORTE_Watch_WatchMode::scm_stInternalVars = {1, scm_anInternalsNames, scm_anInternalsTypeIds};


void FORTE_Watch_WatchMode::setInitialValues(){
  AlarmOn() = false;
}


void FORTE_Watch_WatchMode::enterStateDisabled(void){
  m_nECCState = scm_nStateDisabled;
}

void FORTE_Watch_WatchMode::enterStateWatch24h(void){
  m_nECCState = scm_nStateWatch24h;
  sendOutputEvent( scm_nEventShow24hID);
}

void FORTE_Watch_WatchMode::enterStateWatch12h(void){
  m_nECCState = scm_nStateWatch12h;
  sendOutputEvent( scm_nEventShow12hID);
}

void FORTE_Watch_WatchMode::enterStateTriggerNext(void){
  m_nECCState = scm_nStateTriggerNext;
  sendOutputEvent( scm_nEventEnableNextID);
}

void FORTE_Watch_WatchMode::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateDisabled:
        if(scm_nEventEnableID == pa_nEIID)
          enterStateWatch24h();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateWatch24h:
        if(scm_nEventB1ID == pa_nEIID)
          enterStateWatch12h();
        else
        if(scm_nEventDisableID == pa_nEIID)
          enterStateTriggerNext();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateWatch12h:
        if(scm_nEventB1ID == pa_nEIID)
          enterStateWatch24h();
        else
        if(scm_nEventDisableID == pa_nEIID)
          enterStateTriggerNext();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateTriggerNext:
        if(1)
          enterStateDisabled();
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


