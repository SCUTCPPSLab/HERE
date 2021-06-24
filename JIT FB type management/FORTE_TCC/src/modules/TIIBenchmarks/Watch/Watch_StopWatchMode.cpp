/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Watch_StopWatchMode
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.2: 2003-12-04/JHC - Rockwell Automation - Renamed for better indexing.
 *************************************************************************/

#include "Watch_StopWatchMode.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "Watch_StopWatchMode_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_Watch_StopWatchMode, g_nStringIdWatch_StopWatchMode)

const CStringDictionary::TStringId FORTE_Watch_StopWatchMode::scm_anDataOutputNames[] = {g_nStringIdsASms};

const CStringDictionary::TStringId FORTE_Watch_StopWatchMode::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL};

const TForteInt16 FORTE_Watch_StopWatchMode::scm_anEIWithIndexes[] = {-1, -1, -1, -1};
const CStringDictionary::TStringId FORTE_Watch_StopWatchMode::scm_anEventInputNames[] = {g_nStringIdB1, g_nStringIdB2, g_nStringIdEnable, g_nStringIdDisable};

const TDataIOID FORTE_Watch_StopWatchMode::scm_anEOWith[] = {0, 255, 0, 255};
const TForteInt16 FORTE_Watch_StopWatchMode::scm_anEOWithIndexes[] = {0, 2, -1};
const CStringDictionary::TStringId FORTE_Watch_StopWatchMode::scm_anEventOutputNames[] = {g_nStringIdShowTimer, g_nStringIdEnableNext};

const CStringDictionary::TStringId FORTE_Watch_StopWatchMode::scm_anInternalsNames[] = {g_nStringIdAlarmOn};

const CStringDictionary::TStringId FORTE_Watch_StopWatchMode::scm_anInternalsTypeIds[] = {g_nStringIdBOOL};

const SFBInterfaceSpec FORTE_Watch_StopWatchMode::scm_stFBInterfaceSpec = {
  4,  scm_anEventInputNames,  0,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  0,  0, 0, 
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_Watch_StopWatchMode::scm_stInternalVars = {1, scm_anInternalsNames, scm_anInternalsTypeIds};


void FORTE_Watch_StopWatchMode::setInitialValues(){
  AlarmOn() = false;
}

void FORTE_Watch_StopWatchMode::alg_ToggleTimer(void){

}

void FORTE_Watch_StopWatchMode::alg_ResetTimer(void){

}

void FORTE_Watch_StopWatchMode::alg_ToggleUseSasMS(void){
if((sASms())){
sASms() = false;
}
else{
sASms() = true;
};
}


void FORTE_Watch_StopWatchMode::enterStateDisabled(void){
  m_nECCState = scm_nStateDisabled;
}

void FORTE_Watch_StopWatchMode::enterStateStopWatch(void){
  m_nECCState = scm_nStateStopWatch;
  alg_ToggleUseSasMS();
  sendOutputEvent( scm_nEventShowTimerID);
}

void FORTE_Watch_StopWatchMode::enterStateToggle(void){
  m_nECCState = scm_nStateToggle;
  alg_ToggleTimer();
}

void FORTE_Watch_StopWatchMode::enterStateReset(void){
  m_nECCState = scm_nStateReset;
  alg_ResetTimer();
}

void FORTE_Watch_StopWatchMode::enterStateTriggerNext(void){
  m_nECCState = scm_nStateTriggerNext;
  alg_ToggleUseSasMS();
  sendOutputEvent( scm_nEventEnableNextID);
}

void FORTE_Watch_StopWatchMode::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateDisabled:
        if(scm_nEventEnableID == pa_nEIID)
          enterStateStopWatch();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateStopWatch:
        if(scm_nEventDisableID == pa_nEIID)
          enterStateTriggerNext();
        else
        if(scm_nEventB2ID == pa_nEIID)
          enterStateToggle();
        else
        if(scm_nEventB1ID == pa_nEIID)
          enterStateReset();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateToggle:
        if(scm_nEventDisableID == pa_nEIID)
          enterStateTriggerNext();
        else
        if(1)
          enterStateStopWatch();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateReset:
        if(scm_nEventDisableID == pa_nEIID)
          enterStateTriggerNext();
        else
        if(1)
          enterStateStopWatch();
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
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 4.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


