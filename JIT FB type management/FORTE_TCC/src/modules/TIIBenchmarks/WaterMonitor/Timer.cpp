/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Timer
 *** Description: null
 *** Version: 
 ***     0.2: 2003-12-04/JHC - Rockwell Automation - Renamed for better indexing.
 ***     0.1: 2002-11-05/JHC - Rockwell Automation - Corrected missing ST element in Algorithm REQ.
 ***     0.0: 2000-05-30/JHC - Rockwell Automation - 
 *************************************************************************/

#include "Timer.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "Timer_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_Timer, g_nStringIdTimer)

const CStringDictionary::TStringId FORTE_Timer::scm_anDataInputNames[] = {g_nStringIdtimeout};

const CStringDictionary::TStringId FORTE_Timer::scm_anDataInputTypeIds[] = {g_nStringIdUINT};

const TForteInt16 FORTE_Timer::scm_anEIWithIndexes[] = {-1, 0};
const TDataIOID FORTE_Timer::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId FORTE_Timer::scm_anEventInputNames[] = {g_nStringIdms, g_nStringIdstartStop};

const TForteInt16 FORTE_Timer::scm_anEOWithIndexes[] = {-1, -1};
const CStringDictionary::TStringId FORTE_Timer::scm_anEventOutputNames[] = {g_nStringIdtimed};

const CStringDictionary::TStringId FORTE_Timer::scm_anInternalsNames[] = {g_nStringIdcount};

const CStringDictionary::TStringId FORTE_Timer::scm_anInternalsTypeIds[] = {g_nStringIdUINT};

const SFBInterfaceSpec FORTE_Timer::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  0, 0,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  0,  0, 0,
  0, 0
};


const SInternalVarsInformation FORTE_Timer::scm_stInternalVars = {1, scm_anInternalsNames, scm_anInternalsTypeIds};


void FORTE_Timer::setInitialValues(){
  timeout() = 0;
  count() = 0;
}

void FORTE_Timer::alg_count(void){
count() = count()+1;

}


void FORTE_Timer::enterStateSTOP(void){
  m_nECCState = scm_nStateSTOP;
}

void FORTE_Timer::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_Timer::enterStateCOUNT(void){
  m_nECCState = scm_nStateCOUNT;
  alg_count();
  sendOutputEvent( scm_nEventtimedID);
}

void FORTE_Timer::enterStateDONE(void){
  m_nECCState = scm_nStateDONE;
  sendOutputEvent( scm_nEventtimedID);
}

void FORTE_Timer::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTOP:
        if((scm_nEventstartStopID == pa_nEIID) && (timeout() > 0))
          enterStateSTART();
        else
        if(scm_nEventstartStopID == pa_nEIID)
          enterStateDONE();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateSTART:
        if(scm_nEventstartStopID == pa_nEIID)
          enterStateSTOP();
        else
        if(scm_nEventmsID == pa_nEIID)
          enterStateCOUNT();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateCOUNT:
        if(scm_nEventstartStopID == pa_nEIID)
          enterStateSTOP();
        else
        if((scm_nEventmsID == pa_nEIID) && (timeout() == count()-1))
          enterStateDONE();
        else
        if(scm_nEventmsID == pa_nEIID)
          enterStateCOUNT();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateDONE:
        if((scm_nEventstartStopID == pa_nEIID) && (timeout() > 0))
          enterStateSTART();
        else
        if(scm_nEventstartStopID == pa_nEIID)
          enterStateDONE();
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


