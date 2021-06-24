/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: CruiseControl
 *** Description: null
 *** Version: 
 ***     0.2: 2003-12-05/JHC - Rockwell Automation - Renamed from NEWCOMPFB.
 ***     0.1: 2002-01-08/JHC - Rockwell Automation - Added DLY FB as example.
 ***     0.0: 2000-05-27/JHC - Rockwell Automation - 
 *************************************************************************/

#include "CruiseControl.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "CruiseControl_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_CruiseControl, g_nStringIdCruiseControl)

const CStringDictionary::TStringId FORTE_CruiseControl::scm_anDataInputNames[] = {g_nStringIdtime, g_nStringIdrotaryCount, g_nStringIdthrottleOffset};

const CStringDictionary::TStringId FORTE_CruiseControl::scm_anDataInputTypeIds[] = {g_nStringIdUDINT, g_nStringIdUINT, g_nStringIdSINT};

const CStringDictionary::TStringId FORTE_CruiseControl::scm_anDataOutputNames[] = {g_nStringIdspeedVal, g_nStringIdcruiseSpeed, g_nStringIdthrottleVal};

const CStringDictionary::TStringId FORTE_CruiseControl::scm_anDataOutputTypeIds[] = {g_nStringIdINT, g_nStringIdINT, g_nStringIdSINT};

const TForteInt16 FORTE_CruiseControl::scm_anEIWithIndexes[] = {0, 4, 8, 12, 16, 20, 24, 28, 32};
const TDataIOID FORTE_CruiseControl::scm_anEIWith[] = {0, 1, 2, 255, 0, 1, 2, 255, 0, 1, 2, 255, 0, 1, 2, 255, 0, 1, 2, 255, 0, 1, 2, 255, 0, 1, 2, 255, 0, 1, 2, 255, 0, 1, 2, 255};
const CStringDictionary::TStringId FORTE_CruiseControl::scm_anEventInputNames[] = {g_nStringIdcclock, g_nStringIdset, g_nStringIdoff, g_nStringIdresume, g_nStringIdquickAccel, g_nStringIdquickDecel, g_nStringIdbrakePressed, g_nStringIdaccelPressed, g_nStringIdaccelReleased};

const TDataIOID FORTE_CruiseControl::scm_anEOWith[] = {0, 1, 2, 255, 0, 1, 2, 255, 0, 1, 2, 255, 0, 1, 2, 255, 0, 1, 2, 255, 0, 1, 2, 255, 0, 1, 2, 255};
const TForteInt16 FORTE_CruiseControl::scm_anEOWithIndexes[] = {0, 4, 8, 12, 16, 20, 24, -1};
const CStringDictionary::TStringId FORTE_CruiseControl::scm_anEventOutputNames[] = {g_nStringIdspeed, g_nStringIdspeedSet, g_nStringIdthrottleChg, g_nStringIdregulOff, g_nStringIdregulStdby, g_nStringIdregulSet, g_nStringIdregulResume};

const SFBInterfaceSpec FORTE_CruiseControl::scm_stFBInterfaceSpec = {
  9,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  7,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  3,  scm_anDataInputNames, scm_anDataInputTypeIds,
  3,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SCFB_FBInstanceData FORTE_CruiseControl::scm_astInternalFBs[] = {
  {g_nStringIdspeedo, g_nStringIdSpeedGauge},
  {g_nStringIdcontroller, g_nStringIdCruiseManager},
  {g_nStringIdthrottle, g_nStringIdThrottle},
};

const SCFB_FBConnectionData FORTE_CruiseControl::scm_astEventConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdcclock), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdspeedo, g_nStringIdcclock), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdspeedo, g_nStringIdspeed), 0, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdspeed), -1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdset), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdcontroller, g_nStringIdset), 1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdoff), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdcontroller, g_nStringIdoff), 1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdresume), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdcontroller, g_nStringIdresume), 1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdquickAccel), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdcontroller, g_nStringIdquickAccel), 1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdquickDecel), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdcontroller, g_nStringIdquickDecel), 1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdbrakePressed), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdcontroller, g_nStringIdbrakePressed), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdcontroller, g_nStringIdregulOff), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdthrottle, g_nStringIdcruiseOff), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdcontroller, g_nStringIdregulStdby), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdthrottle, g_nStringIdcruiseOff), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdcontroller, g_nStringIdregulSet), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdthrottle, g_nStringIdcruiseOn), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdcontroller, g_nStringIdregulResume), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdthrottle, g_nStringIdcruiseOn), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdcontroller, g_nStringIdspeedSet), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdthrottle, g_nStringIdspeedSet), 2},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdaccelPressed), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdthrottle, g_nStringIdaccelPressed), 2},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdaccelReleased), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdthrottle, g_nStringIdaccelReleased), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdthrottle, g_nStringIdthrottleChg), 2, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdthrottleChg), -1},
};

const SCFB_FBFannedOutConnectionData FORTE_CruiseControl::scm_astFannedOutEventConnections[] = {
  {0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdcontroller, g_nStringIdcclock), 1},
  {0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdthrottle, g_nStringIdcclock), 2},
  {8, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdregulOff), -1},
  {9, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdregulStdby), -1},
  {10, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdregulSet), -1},
  {11, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdregulResume), -1},
  {12, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdspeedSet), -1},
};

const SCFB_FBConnectionData FORTE_CruiseControl::scm_astDataConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdtime), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdspeedo, g_nStringIdtime), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdrotaryCount), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdspeedo, g_nStringIdrotaryCount), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdspeedo, g_nStringIdspeedVal), 0, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdspeedVal), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdcontroller, g_nStringIdcruiseSpeed), 1, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdcruiseSpeed), -1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdthrottleOffset), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdthrottle, g_nStringIdthrottleOffset), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdthrottle, g_nStringIdthrottleVal), 2, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdthrottleVal), -1},
};

const SCFB_FBFannedOutConnectionData FORTE_CruiseControl::scm_astFannedOutDataConnections[] = {
  {2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdcontroller, g_nStringIdspeed), 1},
  {2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdthrottle, g_nStringIdspeed), 2},
  {3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdthrottle, g_nStringIdcruiseSpeed), 2},
};

const SCFB_FBNData FORTE_CruiseControl::scm_stFBNData = {
  3, scm_astInternalFBs,
  16, scm_astEventConnections,
  7, scm_astFannedOutEventConnections,
  6, scm_astDataConnections,
  3, scm_astFannedOutDataConnections,
  0, 0
};


