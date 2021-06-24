/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: MP3PLAYER_DECODEECC
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.2: 2003-12-04/JHC - Rockwell Automation - Renamed for better indexing.
 *************************************************************************/

#include "MP3PLAYER_DECODEECC.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "MP3PLAYER_DECODEECC_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_MP3PLAYER_DECODEECC, g_nStringIdMP3PLAYER_DECODEECC)

const CStringDictionary::TStringId FORTE_MP3PLAYER_DECODEECC::scm_anDataInputNames[] = {g_nStringIdBufferFull};

const CStringDictionary::TStringId FORTE_MP3PLAYER_DECODEECC::scm_anDataInputTypeIds[] = {g_nStringIdBOOL};

const CStringDictionary::TStringId FORTE_MP3PLAYER_DECODEECC::scm_anDataOutputNames[] = {g_nStringIdDataToWrite};

const CStringDictionary::TStringId FORTE_MP3PLAYER_DECODEECC::scm_anDataOutputTypeIds[] = {g_nStringIdINT};

const TForteInt16 FORTE_MP3PLAYER_DECODEECC::scm_anEIWithIndexes[] = {0, 2, 4, 6};
const TDataIOID FORTE_MP3PLAYER_DECODEECC::scm_anEIWith[] = {0, 255, 0, 255, 0, 255, 0, 255};
const CStringDictionary::TStringId FORTE_MP3PLAYER_DECODEECC::scm_anEventInputNames[] = {g_nStringIdPLAY, g_nStringIdSTOP, g_nStringIdPAUSE, g_nStringIdBufferChange};

const TDataIOID FORTE_MP3PLAYER_DECODEECC::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_MP3PLAYER_DECODEECC::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_MP3PLAYER_DECODEECC::scm_anEventOutputNames[] = {g_nStringIdWriteOut};

const CStringDictionary::TStringId FORTE_MP3PLAYER_DECODEECC::scm_anInternalsNames[] = {g_nStringIdBufferTail, g_nStringIdBufferHead, g_nStringIdBufferSize};

const CStringDictionary::TStringId FORTE_MP3PLAYER_DECODEECC::scm_anInternalsTypeIds[] = {g_nStringIdINT, g_nStringIdINT, g_nStringIdINT};

const SFBInterfaceSpec FORTE_MP3PLAYER_DECODEECC::scm_stFBInterfaceSpec = {
  4,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_MP3PLAYER_DECODEECC::scm_stInternalVars = {3, scm_anInternalsNames, scm_anInternalsTypeIds};


void FORTE_MP3PLAYER_DECODEECC::setInitialValues(){
  BufferFull() = false;
  DataToWrite() = 0;
  BufferTail() = 0;
  BufferHead() = 0;
  BufferSize() = 20;
}

void FORTE_MP3PLAYER_DECODEECC::alg_DECODE(void){
DataToWrite() = 5;

}


void FORTE_MP3PLAYER_DECODEECC::enterStateSTOP(void){
  m_nECCState = scm_nStateSTOP;
}

void FORTE_MP3PLAYER_DECODEECC::enterStatePLAY(void){
  m_nECCState = scm_nStatePLAY;
}

void FORTE_MP3PLAYER_DECODEECC::enterStateDECODE_AND_BUFFER(void){
  m_nECCState = scm_nStateDECODE_AND_BUFFER;
  alg_DECODE();
  sendOutputEvent( scm_nEventWriteOutID);
}

void FORTE_MP3PLAYER_DECODEECC::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTOP:
        if(scm_nEventPLAYID == pa_nEIID)
          enterStateDECODE_AND_BUFFER();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStatePLAY:
        if((scm_nEventPLAYID == pa_nEIID) && (!BufferFull()))
          enterStateDECODE_AND_BUFFER();
        else
        if(scm_nEventSTOPID == pa_nEIID)
          enterStateSTOP();
        else
        if((scm_nEventBufferChangeID == pa_nEIID) && (!BufferFull()))
          enterStateDECODE_AND_BUFFER();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateDECODE_AND_BUFFER:
        if(scm_nEventSTOPID == pa_nEIID)
          enterStateSTOP();
        else
        if(1)
          enterStatePLAY();
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


