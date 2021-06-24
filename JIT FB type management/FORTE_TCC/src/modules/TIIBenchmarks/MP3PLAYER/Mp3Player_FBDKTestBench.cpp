/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Mp3Player_FBDKTestBench
 *** Description: Composite Function Block Type
 *** Version: 
 ***     0.2: 2003-12-05/JHC - Rockwell Automation - Renamed from NEWCOMPFB.
 ***     0.1: 2002-01-08/JHC - Rockwell Automation - Added DLY FB as example.
 ***     0.0: 2000-05-27/JHC - Rockwell Automation - 
 *************************************************************************/

#include "Mp3Player_FBDKTestBench.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "Mp3Player_FBDKTestBench_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_Mp3Player_FBDKTestBench, g_nStringIdMp3Player_FBDKTestBench)

const TForteInt16 FORTE_Mp3Player_FBDKTestBench::scm_anEIWithIndexes[] = {-1};
const CStringDictionary::TStringId FORTE_Mp3Player_FBDKTestBench::scm_anEventInputNames[] = {g_nStringIdINIT};

const TForteInt16 FORTE_Mp3Player_FBDKTestBench::scm_anEOWithIndexes[] = {-1};
const SFBInterfaceSpec FORTE_Mp3Player_FBDKTestBench::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  0,  scm_anEIWithIndexes,
  0,  0,   0, 0,  0,  0, 0, 
  0,  0, 0,
  0, 0
};


const SCFB_FBInstanceData FORTE_Mp3Player_FBDKTestBench::scm_astInternalFBs[] = {
  {g_nStringIdInterface, g_nStringIdMP3Player_FBDKInterface},
  {g_nStringIdUUT, g_nStringIdMP3Player_WithECC},
};

const SCFB_FBConnectionData FORTE_Mp3Player_FBDKTestBench::scm_astEventConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINIT), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdInterface, g_nStringIdINIT), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdInterface, g_nStringIdPLAY), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdUUT, g_nStringIdPLAY), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdInterface, g_nStringIdSTOP), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdUUT, g_nStringIdSTOP), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdInterface, g_nStringIdPAUSE), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdUUT, g_nStringIdPAUSE), 1},
};

const SCFB_FBNData FORTE_Mp3Player_FBDKTestBench::scm_stFBNData = {
  2, scm_astInternalFBs,
  4, scm_astEventConnections,
  0, 0,
  0, 0,
  0, 0,
  0, 0
};


