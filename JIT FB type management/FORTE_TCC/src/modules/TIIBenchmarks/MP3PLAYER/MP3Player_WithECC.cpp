/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: MP3Player_WithECC
 *** Description: Composite Function Block Type
 *** Version: 
 ***     0.2: 2003-12-05/JHC - Rockwell Automation - Renamed from NEWCOMPFB.
 *************************************************************************/

#include "MP3Player_WithECC.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "MP3Player_WithECC_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_MP3Player_WithECC, g_nStringIdMP3Player_WithECC)

const CStringDictionary::TStringId FORTE_MP3Player_WithECC::scm_anDataOutputNames[] = {g_nStringIdAudioData};

const CStringDictionary::TStringId FORTE_MP3Player_WithECC::scm_anDataOutputTypeIds[] = {g_nStringIdINT};

const TForteInt16 FORTE_MP3Player_WithECC::scm_anEIWithIndexes[] = {-1, -1, -1};
const CStringDictionary::TStringId FORTE_MP3Player_WithECC::scm_anEventInputNames[] = {g_nStringIdPLAY, g_nStringIdSTOP, g_nStringIdPAUSE};

const TDataIOID FORTE_MP3Player_WithECC::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_MP3Player_WithECC::scm_anEOWithIndexes[] = {-1, -1, -1, 0, -1};
const CStringDictionary::TStringId FORTE_MP3Player_WithECC::scm_anEventOutputNames[] = {g_nStringIdSHOWDEFAULT, g_nStringIdSHOWPLAY, g_nStringIdSHOWPAUSE, g_nStringIdAUDIO};

const SFBInterfaceSpec FORTE_MP3Player_WithECC::scm_stFBInterfaceSpec = {
  3,  scm_anEventInputNames,  0,  scm_anEIWithIndexes,
  4,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  0,  0, 0, 
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SCFB_FBInstanceData FORTE_MP3Player_WithECC::scm_astInternalFBs[] = {
  {g_nStringIdDECODER, g_nStringIdMP3PLAYER_DECODEECC},
  {g_nStringIdPLAYER, g_nStringIdMP3PLAYER_PLAYERECC},
  {g_nStringIdDISPLAY, g_nStringIdMP3PLAYER_DISPLAYECC},
  {g_nStringIdBUFFER, g_nStringIdMP3PLAYER_BUFFER},
};

const SCFB_FBConnectionData FORTE_MP3Player_WithECC::scm_astEventConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdPLAY), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDISPLAY, g_nStringIdPLAY), 2},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdSTOP), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDISPLAY, g_nStringIdSTOP), 2},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdPAUSE), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDISPLAY, g_nStringIdPAUSE), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdPLAYER, g_nStringIdAUDIO), 1, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdAUDIO), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdPLAYER, g_nStringIdGetData), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdBUFFER, g_nStringIdRead), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdBUFFER, g_nStringIdDataOut), 3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdPLAYER, g_nStringIdIncomingData), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdBUFFER, g_nStringIdBufferChange), 3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDECODER, g_nStringIdBufferChange), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDISPLAY, g_nStringIdSHOWDEFAULT), 2, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdSHOWDEFAULT), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDISPLAY, g_nStringIdSHOWPLAY), 2, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdSHOWPLAY), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDISPLAY, g_nStringIdSHOWPAUSE), 2, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdSHOWPAUSE), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDECODER, g_nStringIdWriteOut), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdBUFFER, g_nStringIdWrite), 3},
};

const SCFB_FBFannedOutConnectionData FORTE_MP3Player_WithECC::scm_astFannedOutEventConnections[] = {
  {0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDECODER, g_nStringIdPLAY), 0},
  {0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdPLAYER, g_nStringIdPLAY), 1},
  {1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDECODER, g_nStringIdSTOP), 0},
  {1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdPLAYER, g_nStringIdSTOP), 1},
  {2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDECODER, g_nStringIdPAUSE), 0},
  {2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdPLAYER, g_nStringIdPAUSE), 1},
  {6, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdPLAYER, g_nStringIdDataAvailable), 1},
};

const SCFB_FBConnectionData FORTE_MP3Player_WithECC::scm_astDataConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdBUFFER, g_nStringIdBufferFull), 3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDECODER, g_nStringIdBufferFull), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdBUFFER, g_nStringIdReadData), 3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdPLAYER, g_nStringIdDecodedData), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDECODER, g_nStringIdDataToWrite), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdBUFFER, g_nStringIdDataToWrite), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdPLAYER, g_nStringIdAudioData), 1, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdAudioData), -1},
};

const SCFB_FBNData FORTE_MP3Player_WithECC::scm_stFBNData = {
  4, scm_astInternalFBs,
  11, scm_astEventConnections,
  7, scm_astFannedOutEventConnections,
  4, scm_astDataConnections,
  0, 0,
  0, 0
};


