/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Watch_ECC
 *** Description: Composite Function Block Type
 *** Version: 
 ***     0.2: 2003-12-05/JHC - Rockwell Automation - Renamed from NEWCOMPFB.
 *************************************************************************/

#include "Watch_ECC.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "Watch_ECC_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_Watch_ECC, g_nStringIdWatch_ECC)

const CStringDictionary::TStringId FORTE_Watch_ECC::scm_anDataInputNames[] = {g_nStringIdCurrentTime};

const CStringDictionary::TStringId FORTE_Watch_ECC::scm_anDataInputTypeIds[] = {g_nStringIdDINT};

const CStringDictionary::TStringId FORTE_Watch_ECC::scm_anDataOutputNames[] = {g_nStringIdAlarmOn, g_nStringIdsASms};

const CStringDictionary::TStringId FORTE_Watch_ECC::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL};

const TForteInt16 FORTE_Watch_ECC::scm_anEIWithIndexes[] = {-1, 0, -1, -1, -1};
const TDataIOID FORTE_Watch_ECC::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId FORTE_Watch_ECC::scm_anEventInputNames[] = {g_nStringIdInit, g_nStringIdTimeChange, g_nStringIdB1, g_nStringIdB2, g_nStringIdB3};

const TDataIOID FORTE_Watch_ECC::scm_anEOWith[] = {0, 255, 1, 255};
const TForteInt16 FORTE_Watch_ECC::scm_anEOWithIndexes[] = {0, -1, -1, 2, -1, -1, -1};
const CStringDictionary::TStringId FORTE_Watch_ECC::scm_anEventOutputNames[] = {g_nStringIdAlarmIndicator, g_nStringIdShow24h, g_nStringIdShow12h, g_nStringIdShowTimer, g_nStringIdFlashHour, g_nStringIdFlashMinute};

const SFBInterfaceSpec FORTE_Watch_ECC::scm_stFBInterfaceSpec = {
  5,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  6,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_Watch_ECC::setInitialValues(){
  CurrentTime() = 0;
  AlarmOn() = true;
  sASms() = true;
}


const SCFB_FBInstanceData FORTE_Watch_ECC::scm_astInternalFBs[] = {
  {g_nStringIdWatch, g_nStringIdWatch_WatchMode},
  {g_nStringIdStopWatchMode, g_nStringIdWatch_StopWatchMode},
  {g_nStringIdAlarmMode, g_nStringIdWatch_ShowAlarmMode},
};

const SCFB_FBConnectionData FORTE_Watch_ECC::scm_astEventConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdB1), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdAlarmMode, g_nStringIdB1), 2},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdInit), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdWatch, g_nStringIdEnable), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdWatch, g_nStringIdEnableNext), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdStopWatchMode, g_nStringIdEnable), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdStopWatchMode, g_nStringIdEnableNext), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdAlarmMode, g_nStringIdEnable), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdAlarmMode, g_nStringIdEnableNext), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdWatch, g_nStringIdEnable), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdB3), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdWatch, g_nStringIdDisable), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdStopWatchMode, g_nStringIdShowTimer), 1, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdShowTimer), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdWatch, g_nStringIdShow24h), 0, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdShow24h), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdWatch, g_nStringIdShow12h), 0, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdShow12h), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdAlarmMode, g_nStringIdAlarmIndicator), 2, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdAlarmIndicator), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdAlarmMode, g_nStringIdFlashMinute), 2, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdFlashMinute), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdAlarmMode, g_nStringIdFlashHour), 2, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdFlashHour), -1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdB2), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdStopWatchMode, g_nStringIdB2), 1},
};

const SCFB_FBFannedOutConnectionData FORTE_Watch_ECC::scm_astFannedOutEventConnections[] = {
  {0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdWatch, g_nStringIdB1), 0},
  {0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdStopWatchMode, g_nStringIdB1), 1},
  {1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdStopWatchMode, g_nStringIdDisable), 1},
  {1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdAlarmMode, g_nStringIdDisable), 2},
  {5, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdStopWatchMode, g_nStringIdDisable), 1},
  {5, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdAlarmMode, g_nStringIdDisable), 2},
};

const SCFB_FBConnectionData FORTE_Watch_ECC::scm_astDataConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdAlarmMode, g_nStringIdAlarmOn), 2, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdAlarmOn), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdStopWatchMode, g_nStringIdsASms), 1, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdsASms), -1},
};

const SCFB_FBNData FORTE_Watch_ECC::scm_stFBNData = {
  3, scm_astInternalFBs,
  13, scm_astEventConnections,
  6, scm_astFannedOutEventConnections,
  2, scm_astDataConnections,
  0, 0,
  0, 0
};


