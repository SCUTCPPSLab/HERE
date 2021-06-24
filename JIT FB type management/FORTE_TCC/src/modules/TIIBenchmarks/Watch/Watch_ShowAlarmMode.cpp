/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Watch_ShowAlarmMode
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.2: 2003-12-04/JHC - Rockwell Automation - Renamed for better indexing.
 *************************************************************************/

#include "Watch_ShowAlarmMode.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "Watch_ShowAlarmMode_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_Watch_ShowAlarmMode, g_nStringIdWatch_ShowAlarmMode)

const CStringDictionary::TStringId FORTE_Watch_ShowAlarmMode::scm_anDataOutputNames[] = {g_nStringIdAlarmOn};

const CStringDictionary::TStringId FORTE_Watch_ShowAlarmMode::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL};

const TForteInt16 FORTE_Watch_ShowAlarmMode::scm_anEIWithIndexes[] = {-1, -1, -1, -1};
const CStringDictionary::TStringId FORTE_Watch_ShowAlarmMode::scm_anEventInputNames[] = {g_nStringIdB1, g_nStringIdB2, g_nStringIdEnable, g_nStringIdDisable};

const TDataIOID FORTE_Watch_ShowAlarmMode::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_Watch_ShowAlarmMode::scm_anEOWithIndexes[] = {0, -1, -1, -1, -1};
const CStringDictionary::TStringId FORTE_Watch_ShowAlarmMode::scm_anEventOutputNames[] = {g_nStringIdAlarmIndicator, g_nStringIdFlashHour, g_nStringIdFlashMinute, g_nStringIdEnableNext};

const SFBInterfaceSpec FORTE_Watch_ShowAlarmMode::scm_stFBInterfaceSpec = {
  4,  scm_anEventInputNames,  0,  scm_anEIWithIndexes,
  4,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  0,  0, 0, 
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

void FORTE_Watch_ShowAlarmMode::alg_ToggleAlarm(void){
if((AlarmOn())){
AlarmOn() = false;
}
else{
AlarmOn() = true;
};
}

void FORTE_Watch_ShowAlarmMode::alg_IncHour(void){

}

void FORTE_Watch_ShowAlarmMode::alg_IncMinute(void){

}


void FORTE_Watch_ShowAlarmMode::enterStateDisabled(void){
  m_nECCState = scm_nStateDisabled;
}

void FORTE_Watch_ShowAlarmMode::enterStateShowAlarm(void){
  m_nECCState = scm_nStateShowAlarm;
}

void FORTE_Watch_ShowAlarmMode::enterStateSetHour(void){
  m_nECCState = scm_nStateSetHour;
  sendOutputEvent( scm_nEventFlashHourID);
}

void FORTE_Watch_ShowAlarmMode::enterStateIncrHour(void){
  m_nECCState = scm_nStateIncrHour;
  alg_IncHour();
}

void FORTE_Watch_ShowAlarmMode::enterStateSetMinute(void){
  m_nECCState = scm_nStateSetMinute;
  sendOutputEvent( scm_nEventFlashMinuteID);
}

void FORTE_Watch_ShowAlarmMode::enterStateIncrMinute(void){
  m_nECCState = scm_nStateIncrMinute;
  alg_IncMinute();
}

void FORTE_Watch_ShowAlarmMode::enterStateToggle(void){
  m_nECCState = scm_nStateToggle;
  alg_ToggleAlarm();
  sendOutputEvent( scm_nEventAlarmIndicatorID);
}

void FORTE_Watch_ShowAlarmMode::enterStateTriggerNext(void){
  m_nECCState = scm_nStateTriggerNext;
  sendOutputEvent( scm_nEventEnableNextID);
}

void FORTE_Watch_ShowAlarmMode::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateDisabled:
        if(scm_nEventEnableID == pa_nEIID)
          enterStateShowAlarm();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateShowAlarm:
        if(scm_nEventB1ID == pa_nEIID)
          enterStateSetHour();
        else
        if(scm_nEventB2ID == pa_nEIID)
          enterStateToggle();
        else
        if(scm_nEventDisableID == pa_nEIID)
          enterStateTriggerNext();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateSetHour:
        if(scm_nEventB2ID == pa_nEIID)
          enterStateIncrHour();
        else
        if(scm_nEventB1ID == pa_nEIID)
          enterStateSetMinute();
        else
        if(scm_nEventDisableID == pa_nEIID)
          enterStateTriggerNext();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateIncrHour:
        if(scm_nEventB1ID == pa_nEIID)
          enterStateSetMinute();
        else
        if(scm_nEventB2ID == pa_nEIID)
          enterStateIncrHour();
        else
        if(scm_nEventDisableID == pa_nEIID)
          enterStateTriggerNext();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateSetMinute:
        if(scm_nEventB2ID == pa_nEIID)
          enterStateIncrMinute();
        else
        if(scm_nEventB1ID == pa_nEIID)
          enterStateShowAlarm();
        else
        if(scm_nEventDisableID == pa_nEIID)
          enterStateTriggerNext();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateIncrMinute:
        if(scm_nEventB2ID == pa_nEIID)
          enterStateIncrMinute();
        else
        if(scm_nEventB1ID == pa_nEIID)
          enterStateShowAlarm();
        else
        if(scm_nEventDisableID == pa_nEIID)
          enterStateTriggerNext();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateToggle:
        if(1)
          enterStateShowAlarm();
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
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 7.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


