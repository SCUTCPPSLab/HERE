/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Throttle
 *** Description: null
 *** Version: 
 ***     0.2: 2003-12-04/JHC - Rockwell Automation - Renamed for better indexing.
 ***     0.1: 2002-11-05/JHC - Rockwell Automation - Corrected missing ST element in Algorithm REQ.
 ***     0.0: 2000-05-30/JHC - Rockwell Automation - 
 *************************************************************************/

#include "Throttle.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "Throttle_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_Throttle, g_nStringIdThrottle)

const CStringDictionary::TStringId FORTE_Throttle::scm_anDataInputNames[] = {g_nStringIdcruiseSpeed, g_nStringIdspeed, g_nStringIdthrottleOffset};

const CStringDictionary::TStringId FORTE_Throttle::scm_anDataInputTypeIds[] = {g_nStringIdINT, g_nStringIdINT, g_nStringIdSINT};

const CStringDictionary::TStringId FORTE_Throttle::scm_anDataOutputNames[] = {g_nStringIdthrottleVal};

const CStringDictionary::TStringId FORTE_Throttle::scm_anDataOutputTypeIds[] = {g_nStringIdSINT};

const TForteInt16 FORTE_Throttle::scm_anEIWithIndexes[] = {0, 2, 5, 8, 11, 13};
const TDataIOID FORTE_Throttle::scm_anEIWith[] = {0, 255, 0, 1, 255, 0, 1, 255, 1, 2, 255, 2, 255, 2, 255};
const CStringDictionary::TStringId FORTE_Throttle::scm_anEventInputNames[] = {g_nStringIdcruiseOff, g_nStringIdcruiseOn, g_nStringIdspeedSet, g_nStringIdcclock, g_nStringIdaccelPressed, g_nStringIdaccelReleased};

const TDataIOID FORTE_Throttle::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_Throttle::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_Throttle::scm_anEventOutputNames[] = {g_nStringIdthrottleChg};

const CStringDictionary::TStringId FORTE_Throttle::scm_anInternalsNames[] = {g_nStringIdprevOffset, g_nStringIdtmp};

const CStringDictionary::TStringId FORTE_Throttle::scm_anInternalsTypeIds[] = {g_nStringIdSINT, g_nStringIdSINT};

const SFBInterfaceSpec FORTE_Throttle::scm_stFBInterfaceSpec = {
  6,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  3,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_Throttle::scm_stInternalVars = {2, scm_anInternalsNames, scm_anInternalsTypeIds};


void FORTE_Throttle::setInitialValues(){
  cruiseSpeed() = 0;
  speed() = 0;
  throttleOffset() = 0;
  throttleVal() = 0;
  prevOffset() = 0;
  tmp() = 0;
}

void FORTE_Throttle::alg_normal(void){
throttleVal() = throttleOffset();
prevOffset() = 0;

}

void FORTE_Throttle::alg_accel(void){
throttleVal() = throttleVal()+throttleOffset()-prevOffset();
prevOffset() = throttleOffset();

}

void FORTE_Throttle::alg_cruise(void){
tmp() = ((cruiseSpeed()-speed()));
tmp() = tmp()*3;
if((tmp() > 45)){
tmp() = 45;
}
else
  if((tmp() < 0)){
tmp() = 0;
};
throttleVal() = tmp();

}


void FORTE_Throttle::enterStateNORMAL(void){
  m_nECCState = scm_nStateNORMAL;
  alg_normal();
  sendOutputEvent( scm_nEventthrottleChgID);
}

void FORTE_Throttle::enterStateCRUISE(void){
  m_nECCState = scm_nStateCRUISE;
  alg_cruise();
  sendOutputEvent( scm_nEventthrottleChgID);
}

void FORTE_Throttle::enterStateACCEL(void){
  m_nECCState = scm_nStateACCEL;
  alg_accel();
  sendOutputEvent( scm_nEventthrottleChgID);
}

void FORTE_Throttle::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateNORMAL:
        if(scm_nEventcruiseOnID == pa_nEIID)
          enterStateCRUISE();
        else
        if(scm_nEventaccelPressedID == pa_nEIID)
          enterStateNORMAL();
        else
        if(scm_nEventaccelReleasedID == pa_nEIID)
          enterStateNORMAL();
        else
        if(scm_nEventcclockID == pa_nEIID)
          enterStateNORMAL();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateCRUISE:
        if(scm_nEventcruiseOffID == pa_nEIID)
          enterStateNORMAL();
        else
        if(scm_nEventaccelPressedID == pa_nEIID)
          enterStateACCEL();
        else
        if(scm_nEventcruiseOnID == pa_nEIID)
          enterStateCRUISE();
        else
        if(scm_nEventspeedSetID == pa_nEIID)
          enterStateCRUISE();
        else
        if(scm_nEventcclockID == pa_nEIID)
          enterStateCRUISE();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateACCEL:
        if(scm_nEventcruiseOffID == pa_nEIID)
          enterStateNORMAL();
        else
        if(scm_nEventaccelReleasedID == pa_nEIID)
          enterStateCRUISE();
        else
        if(scm_nEventcclockID == pa_nEIID)
          enterStateACCEL();
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


