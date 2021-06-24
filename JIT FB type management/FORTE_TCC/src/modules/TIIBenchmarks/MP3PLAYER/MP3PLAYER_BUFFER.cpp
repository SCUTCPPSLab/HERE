/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: MP3PLAYER_BUFFER
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.2: 2003-12-04/JHC - Rockwell Automation - Renamed for better indexing.
 *************************************************************************/

#include "MP3PLAYER_BUFFER.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "MP3PLAYER_BUFFER_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_MP3PLAYER_BUFFER, g_nStringIdMP3PLAYER_BUFFER)

const CStringDictionary::TStringId FORTE_MP3PLAYER_BUFFER::scm_anDataInputNames[] = {g_nStringIdDataToWrite};

const CStringDictionary::TStringId FORTE_MP3PLAYER_BUFFER::scm_anDataInputTypeIds[] = {g_nStringIdINT};

const CStringDictionary::TStringId FORTE_MP3PLAYER_BUFFER::scm_anDataOutputNames[] = {g_nStringIdBufferFull, g_nStringIdBufferEmpty, g_nStringIdReadData};

const CStringDictionary::TStringId FORTE_MP3PLAYER_BUFFER::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdINT};

const TForteInt16 FORTE_MP3PLAYER_BUFFER::scm_anEIWithIndexes[] = {0, -1};
const TDataIOID FORTE_MP3PLAYER_BUFFER::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId FORTE_MP3PLAYER_BUFFER::scm_anEventInputNames[] = {g_nStringIdWrite, g_nStringIdRead};

const TDataIOID FORTE_MP3PLAYER_BUFFER::scm_anEOWith[] = {2, 255, 0, 1, 255};
const TForteInt16 FORTE_MP3PLAYER_BUFFER::scm_anEOWithIndexes[] = {0, 2, -1};
const CStringDictionary::TStringId FORTE_MP3PLAYER_BUFFER::scm_anEventOutputNames[] = {g_nStringIdDataOut, g_nStringIdBufferChange};

const CStringDictionary::TStringId FORTE_MP3PLAYER_BUFFER::scm_anInternalsNames[] = {g_nStringIdBufferTail, g_nStringIdBufferHead, g_nStringIdBufferSize, g_nStringIdBuffer};

const CStringDictionary::TStringId FORTE_MP3PLAYER_BUFFER::scm_anInternalsTypeIds[] = {g_nStringIdINT, g_nStringIdINT, g_nStringIdINT, g_nStringIdARRAY, 20, g_nStringIdINT};

const SFBInterfaceSpec FORTE_MP3PLAYER_BUFFER::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  3,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_MP3PLAYER_BUFFER::scm_stInternalVars = {4, scm_anInternalsNames, scm_anInternalsTypeIds};


void FORTE_MP3PLAYER_BUFFER::setInitialValues(){
  BufferFull() = false;
  BufferEmpty() = true;
  BufferTail() = 0;
  BufferHead() = 0;
  BufferSize() = 20;
}

void FORTE_MP3PLAYER_BUFFER::alg_WRITE(void){
Buffer()[BufferHead()] = DataToWrite();
BufferHead() = BufferHead()+1;
if((BufferHead() >= BufferSize())){
BufferHead() = 0;
};

if((BufferTail() == BufferHead())){
BufferFull() = true;
};

BufferEmpty() = false;

}

void FORTE_MP3PLAYER_BUFFER::alg_READ(void){
ReadData() = Buffer()[BufferTail()];
BufferTail() = BufferTail()+1;

if((BufferTail() >= BufferSize())){
BufferTail() = 0;
};

if((BufferTail() == BufferHead())){
BufferEmpty() = true;
};

BufferFull() = false;

}


void FORTE_MP3PLAYER_BUFFER::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_MP3PLAYER_BUFFER::enterStateWRITE(void){
  m_nECCState = scm_nStateWRITE;
  alg_WRITE();
  sendOutputEvent( scm_nEventBufferChangeID);
}

void FORTE_MP3PLAYER_BUFFER::enterStateREAD(void){
  m_nECCState = scm_nStateREAD;
  alg_READ();
  sendOutputEvent( scm_nEventDataOutID);
}

void FORTE_MP3PLAYER_BUFFER::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventWriteID == pa_nEIID)
          enterStateWRITE();
        else
        if(scm_nEventReadID == pa_nEIID)
          enterStateREAD();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateWRITE:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateREAD:
        if(1)
          enterStateSTART();
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


