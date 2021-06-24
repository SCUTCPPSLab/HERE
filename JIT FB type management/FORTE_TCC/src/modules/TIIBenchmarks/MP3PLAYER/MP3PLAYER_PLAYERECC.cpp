/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: MP3PLAYER_PLAYERECC
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.2: 2003-12-04/JHC - Rockwell Automation - Renamed for better indexing.
 *************************************************************************/

#include "MP3PLAYER_PLAYERECC.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "MP3PLAYER_PLAYERECC_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_MP3PLAYER_PLAYERECC, g_nStringIdMP3PLAYER_PLAYERECC)

const CStringDictionary::TStringId FORTE_MP3PLAYER_PLAYERECC::scm_anDataInputNames[] = {g_nStringIdDecodedData};

const CStringDictionary::TStringId FORTE_MP3PLAYER_PLAYERECC::scm_anDataInputTypeIds[] = {g_nStringIdINT};

const CStringDictionary::TStringId FORTE_MP3PLAYER_PLAYERECC::scm_anDataOutputNames[] = {g_nStringIdAudioData};

const CStringDictionary::TStringId FORTE_MP3PLAYER_PLAYERECC::scm_anDataOutputTypeIds[] = {g_nStringIdINT};

const TForteInt16 FORTE_MP3PLAYER_PLAYERECC::scm_anEIWithIndexes[] = {-1, -1, -1, 0, 2};
const TDataIOID FORTE_MP3PLAYER_PLAYERECC::scm_anEIWith[] = {0, 255, 0, 255};
const CStringDictionary::TStringId FORTE_MP3PLAYER_PLAYERECC::scm_anEventInputNames[] = {g_nStringIdPLAY, g_nStringIdSTOP, g_nStringIdPAUSE, g_nStringIdIncomingData, g_nStringIdDataAvailable};

const TDataIOID FORTE_MP3PLAYER_PLAYERECC::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_MP3PLAYER_PLAYERECC::scm_anEOWithIndexes[] = {-1, 0, -1};
const CStringDictionary::TStringId FORTE_MP3PLAYER_PLAYERECC::scm_anEventOutputNames[] = {g_nStringIdGetData, g_nStringIdAUDIO};

const SFBInterfaceSpec FORTE_MP3PLAYER_PLAYERECC::scm_stFBInterfaceSpec = {
  5,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

void FORTE_MP3PLAYER_PLAYERECC::alg_PLAYAUDIO(void){
AudioData() = DecodedData();

}


void FORTE_MP3PLAYER_PLAYERECC::enterStateSTOPPED(void){
  m_nECCState = scm_nStateSTOPPED;
}

void FORTE_MP3PLAYER_PLAYERECC::enterStateWAIT(void){
  m_nECCState = scm_nStateWAIT;
  sendOutputEvent( scm_nEventGetDataID);
}

void FORTE_MP3PLAYER_PLAYERECC::enterStatePLAY(void){
  m_nECCState = scm_nStatePLAY;
  alg_PLAYAUDIO();
  sendOutputEvent( scm_nEventAUDIOID);
}

void FORTE_MP3PLAYER_PLAYERECC::enterStatePAUSE(void){
  m_nECCState = scm_nStatePAUSE;
}

void FORTE_MP3PLAYER_PLAYERECC::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTOPPED:
        if(scm_nEventPLAYID == pa_nEIID)
          enterStateWAIT();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateWAIT:
        if(scm_nEventPAUSEID == pa_nEIID)
          enterStatePAUSE();
        else
        if(scm_nEventSTOPID == pa_nEIID)
          enterStateSTOPPED();
        else
        if(scm_nEventIncomingDataID == pa_nEIID)
          enterStatePLAY();
        else
        if(scm_nEventDataAvailableID == pa_nEIID)
          enterStatePLAY();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStatePLAY:
        if(scm_nEventPAUSEID == pa_nEIID)
          enterStatePAUSE();
        else
        if(scm_nEventSTOPID == pa_nEIID)
          enterStateSTOPPED();
        else
        if(1)
          enterStateWAIT();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStatePAUSE:
        if(scm_nEventSTOPID == pa_nEIID)
          enterStateSTOPPED();
        else
        if(scm_nEventPAUSEID == pa_nEIID)
          enterStatePLAY();
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


