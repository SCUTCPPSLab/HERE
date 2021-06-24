/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: SpeedGauge
 *** Description: Measures the linear speed from the rotary encoder count
 *** Version: 
 ***     0.2: 2003-12-04/JHC - Rockwell Automation - Renamed for better indexing.
 ***     0.1: 2002-11-05/JHC - Rockwell Automation - Corrected missing ST element in Algorithm REQ.
 ***     0.0: 2000-05-30/JHC - Rockwell Automation - 
 *************************************************************************/

#include "SpeedGauge.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "SpeedGauge_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_SpeedGauge, g_nStringIdSpeedGauge)

const CStringDictionary::TStringId FORTE_SpeedGauge::scm_anDataInputNames[] = {g_nStringIdtime, g_nStringIdrotaryCount};

const CStringDictionary::TStringId FORTE_SpeedGauge::scm_anDataInputTypeIds[] = {g_nStringIdUDINT, g_nStringIdUINT};

const CStringDictionary::TStringId FORTE_SpeedGauge::scm_anDataOutputNames[] = {g_nStringIdspeedVal};

const CStringDictionary::TStringId FORTE_SpeedGauge::scm_anDataOutputTypeIds[] = {g_nStringIdINT};

const TForteInt16 FORTE_SpeedGauge::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_SpeedGauge::scm_anEIWith[] = {0, 1, 255};
const CStringDictionary::TStringId FORTE_SpeedGauge::scm_anEventInputNames[] = {g_nStringIdcclock};

const TDataIOID FORTE_SpeedGauge::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_SpeedGauge::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_SpeedGauge::scm_anEventOutputNames[] = {g_nStringIdspeed};

const CStringDictionary::TStringId FORTE_SpeedGauge::scm_anInternalsNames[] = {g_nStringIdprevCount, g_nStringIdprevTime, g_nStringIdcount};

const CStringDictionary::TStringId FORTE_SpeedGauge::scm_anInternalsTypeIds[] = {g_nStringIdUINT, g_nStringIdUDINT, g_nStringIdUSINT};

const SFBInterfaceSpec FORTE_SpeedGauge::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_SpeedGauge::scm_stInternalVars = {3, scm_anInternalsNames, scm_anInternalsTypeIds};


void FORTE_SpeedGauge::setInitialValues(){
  time() = 0;
  rotaryCount() = 0;
  speedVal() = 0;
  prevCount() = 0;
  prevTime() = 0;
}

void FORTE_SpeedGauge::alg_calcSpeed(void){
if((rotaryCount() >= prevCount())){
count() = rotaryCount()-prevCount();
}
else{
count() = 1000+rotaryCount()-prevCount();
};

if((speedVal() == 0)){
speedVal() = ((count()*7012))/10000;
}
else{
speedVal() = ((count()*7012))/10000;
};

prevTime() = time();
prevCount() = rotaryCount();

}


void FORTE_SpeedGauge::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_SpeedGauge::enterStateCALC(void){
  m_nECCState = scm_nStateCALC;
  alg_calcSpeed();
  sendOutputEvent( scm_nEventspeedID);
}

void FORTE_SpeedGauge::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventcclockID == pa_nEIID)
          enterStateCALC();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateCALC:
        if(scm_nEventcclockID == pa_nEIID)
          enterStateCALC();
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


