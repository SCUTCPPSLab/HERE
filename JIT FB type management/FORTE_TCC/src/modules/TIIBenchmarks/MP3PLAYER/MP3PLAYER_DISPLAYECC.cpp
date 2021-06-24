/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: MP3PLAYER_DISPLAYECC
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.2: 2003-12-04/JHC - Rockwell Automation - Renamed for better indexing.
 *************************************************************************/

#include "MP3PLAYER_DISPLAYECC.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "MP3PLAYER_DISPLAYECC_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_MP3PLAYER_DISPLAYECC, g_nStringIdMP3PLAYER_DISPLAYECC)

const TForteInt16 FORTE_MP3PLAYER_DISPLAYECC::scm_anEIWithIndexes[] = {-1, -1, -1};
const CStringDictionary::TStringId FORTE_MP3PLAYER_DISPLAYECC::scm_anEventInputNames[] = {g_nStringIdPLAY, g_nStringIdSTOP, g_nStringIdPAUSE};

const TForteInt16 FORTE_MP3PLAYER_DISPLAYECC::scm_anEOWithIndexes[] = {-1, -1, -1, -1};
const CStringDictionary::TStringId FORTE_MP3PLAYER_DISPLAYECC::scm_anEventOutputNames[] = {g_nStringIdSHOWDEFAULT, g_nStringIdSHOWPLAY, g_nStringIdSHOWPAUSE};

const SFBInterfaceSpec FORTE_MP3PLAYER_DISPLAYECC::scm_stFBInterfaceSpec = {
  3,  scm_anEventInputNames,  0,  scm_anEIWithIndexes,
  3,  scm_anEventOutputNames,  0, 0,  0,  0, 0, 
  0,  0, 0,
  0, 0
};


void FORTE_MP3PLAYER_DISPLAYECC::enterStateDEFAULT(void){
  m_nECCState = scm_nStateDEFAULT;
  sendOutputEvent( scm_nEventSHOWDEFAULTID);
}

void FORTE_MP3PLAYER_DISPLAYECC::enterStatePLAYING(void){
  m_nECCState = scm_nStatePLAYING;
  sendOutputEvent( scm_nEventSHOWPLAYID);
}

void FORTE_MP3PLAYER_DISPLAYECC::enterStatePAUSED(void){
  m_nECCState = scm_nStatePAUSED;
  sendOutputEvent( scm_nEventSHOWPAUSEID);
}

void FORTE_MP3PLAYER_DISPLAYECC::enterStateDEFAUL(void){
  m_nECCState = scm_nStateDEFAUL;
  sendOutputEvent( scm_nEventSHOWDEFAULTID);
}

void FORTE_MP3PLAYER_DISPLAYECC::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateDEFAULT:
        if(scm_nEventPLAYID == pa_nEIID)
          enterStatePLAYING();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStatePLAYING:
        if(scm_nEventPAUSEID == pa_nEIID)
          enterStatePAUSED();
        else
        if(scm_nEventSTOPID == pa_nEIID)
          enterStateDEFAULT();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStatePAUSED:
        if(scm_nEventSTOPID == pa_nEIID)
          enterStateDEFAULT();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateDEFAUL:
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


