/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Drill
 *** Description: Drill
 *** Version: 
 ***     0.2: 2003-12-04/JHC - Rockwell Automation - Renamed for better indexing.
 ***     0.1: 2002-11-05/JHC - Rockwell Automation - Corrected missing ST element in Algorithm REQ.
 ***     0.0: 2000-05-30/JHC - Rockwell Automation - 
 *************************************************************************/

#include "Drill.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "Drill_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_Drill, g_nStringIdDrill)

const CStringDictionary::TStringId FORTE_Drill::scm_anDataOutputNames[] = {g_nStringIdUP_DOWN};

const CStringDictionary::TStringId FORTE_Drill::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL};

const TForteInt16 FORTE_Drill::scm_anEIWithIndexes[] = {-1, -1, -1};
const CStringDictionary::TStringId FORTE_Drill::scm_anEventInputNames[] = {g_nStringIdREQ, g_nStringIdDrillMove, g_nStringIdDrillDone};

const TDataIOID FORTE_Drill::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_Drill::scm_anEOWithIndexes[] = {0, -1, -1};
const CStringDictionary::TStringId FORTE_Drill::scm_anEventOutputNames[] = {g_nStringIdStatus, g_nStringIdDone};

const SFBInterfaceSpec FORTE_Drill::scm_stFBInterfaceSpec = {
  3,  scm_anEventInputNames,  0,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  0,  0, 0, 
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_Drill::setInitialValues(){
  UP_DOWN() = true;
}

void FORTE_Drill::alg_INIT(void){
UP_DOWN() = true;

}

void FORTE_Drill::alg_MovingDown(void){
UP_DOWN() = false;

}


void FORTE_Drill::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
  alg_INIT();
  sendOutputEvent( scm_nEventStatusID);
}

void FORTE_Drill::enterStateREQ(void){
  m_nECCState = scm_nStateREQ;
  alg_MovingDown();
  sendOutputEvent( scm_nEventStatusID);
}

void FORTE_Drill::enterStateDone(void){
  m_nECCState = scm_nStateDone;
  sendOutputEvent( scm_nEventDoneID);
}

void FORTE_Drill::enterStateDrilling(void){
  m_nECCState = scm_nStateDrilling;
}

void FORTE_Drill::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventREQID == pa_nEIID)
          enterStateREQ();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateREQ:
        if(scm_nEventDrillMoveID == pa_nEIID)
          enterStateDrilling();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateDone:
        if(scm_nEventDrillMoveID == pa_nEIID)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateDrilling:
        if(scm_nEventDrillDoneID == pa_nEIID)
          enterStateDone();
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


