/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: CruiseManager
 *** Description: Manages the state of the cruise control
 *** Version: 
 ***     0.2: 2003-12-04/JHC - Rockwell Automation - Renamed for better indexing.
 ***     0.1: 2002-11-05/JHC - Rockwell Automation - Corrected missing ST element in Algorithm REQ.
 ***     0.0: 2000-05-30/JHC - Rockwell Automation - 
 *************************************************************************/

#include "CruiseManager.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "CruiseManager_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_CruiseManager, g_nStringIdCruiseManager)

const CStringDictionary::TStringId FORTE_CruiseManager::scm_anDataInputNames[] = {g_nStringIdspeed};

const CStringDictionary::TStringId FORTE_CruiseManager::scm_anDataInputTypeIds[] = {g_nStringIdINT};

const CStringDictionary::TStringId FORTE_CruiseManager::scm_anDataOutputNames[] = {g_nStringIdcruiseSpeed};

const CStringDictionary::TStringId FORTE_CruiseManager::scm_anDataOutputTypeIds[] = {g_nStringIdINT};

const TForteInt16 FORTE_CruiseManager::scm_anEIWithIndexes[] = {0, 2, 4, 6, 8, 10, 12};
const TDataIOID FORTE_CruiseManager::scm_anEIWith[] = {0, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 255};
const CStringDictionary::TStringId FORTE_CruiseManager::scm_anEventInputNames[] = {g_nStringIdset, g_nStringIdoff, g_nStringIdresume, g_nStringIdquickAccel, g_nStringIdquickDecel, g_nStringIdbrakePressed, g_nStringIdcclock};

const TDataIOID FORTE_CruiseManager::scm_anEOWith[] = {0, 255, 0, 255, 0, 255, 0, 255};
const TForteInt16 FORTE_CruiseManager::scm_anEOWithIndexes[] = {0, 2, -1, 4, 6, -1};
const CStringDictionary::TStringId FORTE_CruiseManager::scm_anEventOutputNames[] = {g_nStringIdregulOff, g_nStringIdregulSet, g_nStringIdregulStdby, g_nStringIdregulResume, g_nStringIdspeedSet};

const CStringDictionary::TStringId FORTE_CruiseManager::scm_anInternalsNames[] = {g_nStringIddesiredSpeed};

const CStringDictionary::TStringId FORTE_CruiseManager::scm_anInternalsTypeIds[] = {g_nStringIdINT};

const SFBInterfaceSpec FORTE_CruiseManager::scm_stFBInterfaceSpec = {
  7,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  5,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_CruiseManager::scm_stInternalVars = {1, scm_anInternalsNames, scm_anInternalsTypeIds};


void FORTE_CruiseManager::setInitialValues(){
  speed() = 0;
  cruiseSpeed() = 0;
  desiredSpeed() = 0;
}

void FORTE_CruiseManager::alg_off(void){
desiredSpeed() = 0;
cruiseSpeed() = 0;

}

void FORTE_CruiseManager::alg_set(void){
desiredSpeed() = speed();
cruiseSpeed() = desiredSpeed();

}

void FORTE_CruiseManager::alg_resume(void){
cruiseSpeed() = desiredSpeed();

}

void FORTE_CruiseManager::alg_standby(void){
cruiseSpeed() = 0;

}

void FORTE_CruiseManager::alg_accel(void){
if((desiredSpeed() < 165)){
desiredSpeed() = desiredSpeed()+5;
cruiseSpeed() = desiredSpeed();
};

}

void FORTE_CruiseManager::alg_decel(void){
if((desiredSpeed() >= 5)){
desiredSpeed() = desiredSpeed()-5;
cruiseSpeed() = desiredSpeed();
}
else{desiredSpeed() = 0;
};

}


void FORTE_CruiseManager::enterStateOFF(void){
  m_nECCState = scm_nStateOFF;
  alg_off();
  sendOutputEvent( scm_nEventregulOffID);
}

void FORTE_CruiseManager::enterStateSET(void){
  m_nECCState = scm_nStateSET;
  alg_set();
  sendOutputEvent( scm_nEventregulSetID);
}

void FORTE_CruiseManager::enterStateSTDBY(void){
  m_nECCState = scm_nStateSTDBY;
  alg_standby();
  sendOutputEvent( scm_nEventregulStdbyID);
}

void FORTE_CruiseManager::enterStateRESUME(void){
  m_nECCState = scm_nStateRESUME;
  alg_resume();
  sendOutputEvent( scm_nEventregulResumeID);
}

void FORTE_CruiseManager::enterStateACCEL(void){
  m_nECCState = scm_nStateACCEL;
  alg_accel();
  sendOutputEvent( scm_nEventspeedSetID);
}

void FORTE_CruiseManager::enterStateDECEL(void){
  m_nECCState = scm_nStateDECEL;
  alg_decel();
  sendOutputEvent( scm_nEventspeedSetID);
}

void FORTE_CruiseManager::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateOFF:
        if((scm_nEventsetID == pa_nEIID) && ((speed() > 50) && (speed() < 170)))
          enterStateSET();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateSET:
        if(scm_nEventoffID == pa_nEIID)
          enterStateOFF();
        else
        if((scm_nEventsetID == pa_nEIID) && ((speed() > 50) && (speed() < 170)))
          enterStateSET();
        else
        if(scm_nEventbrakePressedID == pa_nEIID)
          enterStateSTDBY();
        else
        if(scm_nEventquickAccelID == pa_nEIID)
          enterStateACCEL();
        else
        if(scm_nEventquickDecelID == pa_nEIID)
          enterStateDECEL();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateSTDBY:
        if(scm_nEventoffID == pa_nEIID)
          enterStateOFF();
        else
        if((scm_nEventsetID == pa_nEIID) && ((speed() > 50) && (speed() < 170)))
          enterStateSET();
        else
        if(scm_nEventresumeID == pa_nEIID)
          enterStateRESUME();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateRESUME:
        if(scm_nEventoffID == pa_nEIID)
          enterStateOFF();
        else
        if((scm_nEventsetID == pa_nEIID) && ((speed() > 50) && (speed() < 170)))
          enterStateSET();
        else
        if(scm_nEventbrakePressedID == pa_nEIID)
          enterStateSTDBY();
        else
        if(scm_nEventquickAccelID == pa_nEIID)
          enterStateACCEL();
        else
        if(scm_nEventquickDecelID == pa_nEIID)
          enterStateDECEL();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateACCEL:
        if(scm_nEventoffID == pa_nEIID)
          enterStateOFF();
        else
        if((scm_nEventsetID == pa_nEIID) && ((speed() > 50) && (speed() < 170)))
          enterStateSET();
        else
        if(scm_nEventbrakePressedID == pa_nEIID)
          enterStateSTDBY();
        else
        if(scm_nEventquickAccelID == pa_nEIID)
          enterStateACCEL();
        else
        if(scm_nEventquickDecelID == pa_nEIID)
          enterStateDECEL();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateDECEL:
        if(scm_nEventoffID == pa_nEIID)
          enterStateOFF();
        else
        if((scm_nEventsetID == pa_nEIID) && ((speed() > 50) && (speed() < 170)))
          enterStateSET();
        else
        if(scm_nEventbrakePressedID == pa_nEIID)
          enterStateSTDBY();
        else
        if(scm_nEventquickAccelID == pa_nEIID)
          enterStateACCEL();
        else
        if(scm_nEventquickDecelID == pa_nEIID)
          enterStateDECEL();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 5.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


