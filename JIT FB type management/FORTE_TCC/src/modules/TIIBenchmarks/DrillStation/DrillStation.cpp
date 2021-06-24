/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: DrillStation
 *** Description: null
 *** Version: 
 ***     0.2: 2003-12-05/JHC - Rockwell Automation - Renamed from NEWCOMPFB.
 ***     0.1: 2002-01-08/JHC - Rockwell Automation - Added DLY FB as example.
 ***     0.0: 2000-05-27/JHC - Rockwell Automation - 
 *************************************************************************/

#include "DrillStation.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "DrillStation_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_DrillStation, g_nStringIdDrillStation)

const CStringDictionary::TStringId FORTE_DrillStation::scm_anDataOutputNames[] = {g_nStringIdSliderOpenClose};

const CStringDictionary::TStringId FORTE_DrillStation::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL};

const TForteInt16 FORTE_DrillStation::scm_anEIWithIndexes[] = {-1, -1, -1, -1, -1};
const CStringDictionary::TStringId FORTE_DrillStation::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ, g_nStringIdSlideTime, g_nStringIdDrillMove, g_nStringIdDrillDone};

const TDataIOID FORTE_DrillStation::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_DrillStation::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_DrillStation::scm_anEventOutputNames[] = {g_nStringIdSliderStatus};

const SFBInterfaceSpec FORTE_DrillStation::scm_stFBInterfaceSpec = {
  5,  scm_anEventInputNames,  0,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  0,  0, 0, 
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SCFB_FBInstanceData FORTE_DrillStation::scm_astInternalFBs[] = {
  {g_nStringIdDrill, g_nStringIdDrill},
  {g_nStringIdSlider, g_nStringIdSlider},
};

const SCFB_FBConnectionData FORTE_DrillStation::scm_astEventConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDrill, g_nStringIdStatus), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdSlider, g_nStringIdDrillStat), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDrill, g_nStringIdDone), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdSlider, g_nStringIdFinishDrill), 1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdREQ), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdSlider, g_nStringIdREQ), 1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdSlideTime), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdSlider, g_nStringIdSlideTime), 1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdDrillMove), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDrill, g_nStringIdDrillMove), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdDrillDone), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDrill, g_nStringIdDrillDone), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdSlider, g_nStringIdStatus), 1, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdSliderStatus), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdSlider, g_nStringIdInPlace), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDrill, g_nStringIdREQ), 0},
};

const SCFB_FBConnectionData FORTE_DrillStation::scm_astDataConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDrill, g_nStringIdUP_DOWN), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdSlider, g_nStringIdReadyNot), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdSlider, g_nStringIdOpenClose), 1, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdSliderOpenClose), -1},
};

const SCFB_FBNData FORTE_DrillStation::scm_stFBNData = {
  2, scm_astInternalFBs,
  8, scm_astEventConnections,
  0, 0,
  2, scm_astDataConnections,
  0, 0,
  0, 0
};


