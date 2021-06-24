/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: WaterMonitor
 *** Description: null
 *** Version: 
 ***     0.2: 2003-12-05/JHC - Rockwell Automation - Renamed from NEWCOMPFB.
 *************************************************************************/

#include "WaterMonitor.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "WaterMonitor_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_WaterMonitor, g_nStringIdWaterMonitor)

const CStringDictionary::TStringId FORTE_WaterMonitor::scm_anDataInputNames[] = {g_nStringIdwaterLevel};

const CStringDictionary::TStringId FORTE_WaterMonitor::scm_anDataInputTypeIds[] = {g_nStringIdUSINT};

const CStringDictionary::TStringId FORTE_WaterMonitor::scm_anDataOutputNames[] = {g_nStringIdwithinLimits, g_nStringIdwithinHys};

const CStringDictionary::TStringId FORTE_WaterMonitor::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL};

const TForteInt16 FORTE_WaterMonitor::scm_anEIWithIndexes[] = {0, 2, 4};
const TDataIOID FORTE_WaterMonitor::scm_anEIWith[] = {0, 255, 0, 255, 0, 255};
const CStringDictionary::TStringId FORTE_WaterMonitor::scm_anEventInputNames[] = {g_nStringIdms, g_nStringIdtstButton, g_nStringIdresetButton};

const TDataIOID FORTE_WaterMonitor::scm_anEOWith[] = {0, 1, 255};
const TForteInt16 FORTE_WaterMonitor::scm_anEOWithIndexes[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, 0};
const CStringDictionary::TStringId FORTE_WaterMonitor::scm_anEventOutputNames[] = {g_nStringIdstandby, g_nStringIdoperating, g_nStringIdshutdown, g_nStringIdtest, g_nStringIdslfTstInterval, g_nStringIdreset1, g_nStringIdtstInterval, g_nStringIdshutdownLock, g_nStringIdrange};

const SFBInterfaceSpec FORTE_WaterMonitor::scm_stFBInterfaceSpec = {
  3,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  9,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SCFB_FBInstanceData FORTE_WaterMonitor::scm_astInternalFBs[] = {
  {g_nStringIdtstButtonTimer, g_nStringIdTimer},
  {g_nStringIdtstModeTimer, g_nStringIdTimer},
  {g_nStringIdshutdownModeTImer, g_nStringIdTimer},
  {g_nStringIdresetButtonTimer, g_nStringIdTimer},
  {g_nStringIdselector, g_nStringIdMultiplexer},
  {g_nStringIdmonitor, g_nStringIdMonitor},
  {g_nStringIdsensor, g_nStringIdWaterSensor},
};

const SCFB_FBParameter FORTE_WaterMonitor::scm_astParamters[] = {
  {0, g_nStringIdtimeout, "500"},
  {1, g_nStringIdtimeout, "5000"},
  {2, g_nStringIdtimeout, "200"},
  {3, g_nStringIdtimeout, "3000"},
  {6, g_nStringIdlowLimit, "100"},
  {6, g_nStringIdhighLimit, "200"},
};

const SCFB_FBConnectionData FORTE_WaterMonitor::scm_astEventConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdms), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdtstButtonTimer, g_nStringIdms), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdtstButton), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdtstButtonTimer, g_nStringIdstartStop), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdresetButton), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdresetButtonTimer, g_nStringIdstartStop), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdtstButtonTimer, g_nStringIdtimed), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdmonitor, g_nStringIdslfTstInterval), 5},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdresetButtonTimer, g_nStringIdtimed), 3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdmonitor, g_nStringIdreset1), 5},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdtstModeTimer, g_nStringIdtimed), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdmonitor, g_nStringIdtstInterval), 5},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdshutdownModeTImer, g_nStringIdtimed), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdmonitor, g_nStringIdshutdownLock), 5},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdmonitor, g_nStringIdstandby), 5, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdselector, g_nStringIdstandby), 4},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdmonitor, g_nStringIdoperating), 5, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdselector, g_nStringIdoperating), 4},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdmonitor, g_nStringIdshutdown), 5, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdselector, g_nStringIdshutdown), 4},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdmonitor, g_nStringIdtest), 5, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdselector, g_nStringIdtest), 4},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdselector, g_nStringIdshutdownTimer), 4, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdshutdownModeTImer, g_nStringIdstartStop), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdselector, g_nStringIdtestTimer), 4, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdtstModeTimer, g_nStringIdstartStop), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdsensor, g_nStringIdrange), 6, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdmonitor, g_nStringIdrange), 5},
};

const SCFB_FBFannedOutConnectionData FORTE_WaterMonitor::scm_astFannedOutEventConnections[] = {
  {0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdresetButtonTimer, g_nStringIdms), 3},
  {0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdtstModeTimer, g_nStringIdms), 1},
  {0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdshutdownModeTImer, g_nStringIdms), 2},
  {0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdsensor, g_nStringIdms), 6},
  {3, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdslfTstInterval), -1},
  {4, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdreset1), -1},
  {5, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdtstInterval), -1},
  {6, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdshutdownLock), -1},
  {7, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdstandby), -1},
  {8, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdoperating), -1},
  {9, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdshutdown), -1},
  {10, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdtest), -1},
};

const SCFB_FBConnectionData FORTE_WaterMonitor::scm_astDataConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdwaterLevel), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdsensor, g_nStringIdwaterLevel), 6},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdsensor, g_nStringIdwithinLimits), 6, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdwithinLimits), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdsensor, g_nStringIdwithinHys), 6, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdwithinHys), -1},
};

const SCFB_FBFannedOutConnectionData FORTE_WaterMonitor::scm_astFannedOutDataConnections[] = {
  {1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdmonitor, g_nStringIdwithinLimits), 5},
  {2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdmonitor, g_nStringIdwithinHys), 5},
};

const SCFB_FBNData FORTE_WaterMonitor::scm_stFBNData = {
  7, scm_astInternalFBs,
  14, scm_astEventConnections,
  12, scm_astFannedOutEventConnections,
  3, scm_astDataConnections,
  2, scm_astFannedOutDataConnections,
  6, scm_astParamters
};


