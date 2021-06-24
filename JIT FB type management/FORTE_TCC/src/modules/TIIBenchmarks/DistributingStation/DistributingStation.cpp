/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: DistributingStation
 *** Description: Composite Function Block Type
 *** Version: 
 ***     0.2: 2003-12-05/JHC - Rockwell Automation - Renamed from NEWCOMPFB.
 *************************************************************************/

#include "DistributingStation.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "DistributingStation_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_DistributingStation, g_nStringIdDistributingStation)

const CStringDictionary::TStringId FORTE_DistributingStation::scm_anDataInputNames[] = {g_nStringIdPusherBack, g_nStringIdPusherFront, g_nStringIdArmAtPickup, g_nStringIdArmAtDropoff, g_nStringIdCylinderEmpty};

const CStringDictionary::TStringId FORTE_DistributingStation::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL};

const CStringDictionary::TStringId FORTE_DistributingStation::scm_anDataOutputNames[] = {g_nStringIdPusherForward, g_nStringIdArmSUCKING, g_nStringIdArmRELEASE, g_nStringIdArmPICKINGUP, g_nStringIdArmDROPPINGOFF};

const CStringDictionary::TStringId FORTE_DistributingStation::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL};

const TForteInt16 FORTE_DistributingStation::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_DistributingStation::scm_anEIWith[] = {0, 1, 2, 3, 4, 255};
const CStringDictionary::TStringId FORTE_DistributingStation::scm_anEventInputNames[] = {g_nStringIdInputsChange};

const TDataIOID FORTE_DistributingStation::scm_anEOWith[] = {0, 3, 4, 1, 2, 255};
const TForteInt16 FORTE_DistributingStation::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_DistributingStation::scm_anEventOutputNames[] = {g_nStringIdOutputsChange};

const SFBInterfaceSpec FORTE_DistributingStation::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  5,  scm_anDataInputNames, scm_anDataInputTypeIds,
  5,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_DistributingStation::setInitialValues(){
  PusherForward() = false;
  ArmSUCKING() = false;
  ArmRELEASE() = false;
  ArmPICKINGUP() = false;
  ArmDROPPINGOFF() = false;
}


const SCFB_FBInstanceData FORTE_DistributingStation::scm_astInternalFBs[] = {
  {g_nStringIdDistStnArm, g_nStringIdDistStnArm},
  {g_nStringIdDistStnPusher, g_nStringIdDistStnPusher},
};

const SCFB_FBConnectionData FORTE_DistributingStation::scm_astEventConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdInputsChange), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDistStnPusher, g_nStringIdPosChange), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDistStnArm, g_nStringIdArmCtrl), 0, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdOutputsChange), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDistStnPusher, g_nStringIdPusherCtrl), 1, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdOutputsChange), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDistStnPusher, g_nStringIdItemStatus), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDistStnArm, g_nStringIdItemStatus), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDistStnArm, g_nStringIdArmStatus), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDistStnPusher, g_nStringIdArmStatusChange), 1},
};

const SCFB_FBFannedOutConnectionData FORTE_DistributingStation::scm_astFannedOutEventConnections[] = {
  {0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDistStnArm, g_nStringIdPosChange), 0},
};

const SCFB_FBConnectionData FORTE_DistributingStation::scm_astDataConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdPusherBack), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDistStnPusher, g_nStringIdPosBack), 1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdPusherFront), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDistStnPusher, g_nStringIdPosFront), 1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdCylinderEmpty), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDistStnPusher, g_nStringIdCylinderEmpty), 1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdArmAtPickup), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDistStnArm, g_nStringIdPosReadyToSuck), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdArmAtDropoff), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDistStnArm, g_nStringIdPosReadyToDrop), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDistStnArm, g_nStringIdArmPICKINGUP), 0, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdArmPICKINGUP), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDistStnArm, g_nStringIdArmDROPPINGOFF), 0, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdArmDROPPINGOFF), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDistStnArm, g_nStringIdArmSUCKING), 0, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdArmSUCKING), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDistStnArm, g_nStringIdArmRELEASE), 0, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdArmRELEASE), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDistStnPusher, g_nStringIdPusherForward), 1, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdPusherForward), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDistStnPusher, g_nStringIdItemPresent), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDistStnArm, g_nStringIdItemNeedingPickup), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDistStnArm, g_nStringIdArmClear), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdDistStnPusher, g_nStringIdArmClear), 1},
};

const SCFB_FBNData FORTE_DistributingStation::scm_stFBNData = {
  2, scm_astInternalFBs,
  5, scm_astEventConnections,
  1, scm_astFannedOutEventConnections,
  12, scm_astDataConnections,
  0, 0,
  0, 0
};


