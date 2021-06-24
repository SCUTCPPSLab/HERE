/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: DistStnArm
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.2: 2003-12-04/JHC - Rockwell Automation - Renamed for better indexing.
 *************************************************************************/

#include "DistStnArm.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "DistStnArm_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_DistStnArm, g_nStringIdDistStnArm)

const CStringDictionary::TStringId FORTE_DistStnArm::scm_anDataInputNames[] = {g_nStringIdPosReadyToSuck, g_nStringIdPosReadyToDrop, g_nStringIdItemNeedingPickup};

const CStringDictionary::TStringId FORTE_DistStnArm::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL};

const CStringDictionary::TStringId FORTE_DistStnArm::scm_anDataOutputNames[] = {g_nStringIdArmPICKINGUP, g_nStringIdArmDROPPINGOFF, g_nStringIdArmSUCKING, g_nStringIdArmRELEASE, g_nStringIdArmClear};

const CStringDictionary::TStringId FORTE_DistStnArm::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL};

const TForteInt16 FORTE_DistStnArm::scm_anEIWithIndexes[] = {0, 4};
const TDataIOID FORTE_DistStnArm::scm_anEIWith[] = {0, 1, 2, 255, 2, 255};
const CStringDictionary::TStringId FORTE_DistStnArm::scm_anEventInputNames[] = {g_nStringIdPosChange, g_nStringIdItemStatus};

const TDataIOID FORTE_DistStnArm::scm_anEOWith[] = {0, 1, 2, 3, 255, 4, 255};
const TForteInt16 FORTE_DistStnArm::scm_anEOWithIndexes[] = {0, 5, -1};
const CStringDictionary::TStringId FORTE_DistStnArm::scm_anEventOutputNames[] = {g_nStringIdArmCtrl, g_nStringIdArmStatus};

const CStringDictionary::TStringId FORTE_DistStnArm::scm_anInternalsNames[] = {g_nStringIdReleaseDelay};

const CStringDictionary::TStringId FORTE_DistStnArm::scm_anInternalsTypeIds[] = {g_nStringIdINT};

const SFBInterfaceSpec FORTE_DistStnArm::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  3,  scm_anDataInputNames, scm_anDataInputTypeIds,
  5,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_DistStnArm::scm_stInternalVars = {1, scm_anInternalsNames, scm_anInternalsTypeIds};


void FORTE_DistStnArm::setInitialValues(){
  PosReadyToSuck() = false;
  PosReadyToDrop() = false;
  ArmPICKINGUP() = false;
  ArmDROPPINGOFF() = false;
  ArmSUCKING() = false;
  ArmRELEASE() = false;
  ArmClear() = true;
}

void FORTE_DistStnArm::alg_GoToDropOff(void){
ArmPICKINGUP() = false;
ArmDROPPINGOFF() = true;

}

void FORTE_DistStnArm::alg_GoToPickup(void){
ArmPICKINGUP() = true;
ArmDROPPINGOFF() = false;

ArmClear() = false;

}

void FORTE_DistStnArm::alg_PickupItem(void){
ArmSUCKING() = true;
ArmRELEASE() = false;

}

void FORTE_DistStnArm::alg_DropItem(void){
ArmSUCKING() = false;
ArmRELEASE() = true;
ReleaseDelay() = 5;


ArmClear() = true;

}

void FORTE_DistStnArm::alg_DoNothing(void){
ArmPICKINGUP() = false;
ArmDROPPINGOFF() = false;
ArmSUCKING() = false;
ArmRELEASE() = false;
ArmClear() = true;

}

void FORTE_DistStnArm::alg_ReleaseWait(void){
if((ReleaseDelay() > 0)){
ReleaseDelay() = ReleaseDelay()-1;
};

}


void FORTE_DistStnArm::enterStateWAITING(void){
  m_nECCState = scm_nStateWAITING;
  alg_DoNothing();
  sendOutputEvent( scm_nEventArmCtrlID);
  sendOutputEvent( scm_nEventArmStatusID);
}

void FORTE_DistStnArm::enterStateDROPPINGOFF(void){
  m_nECCState = scm_nStateDROPPINGOFF;
  alg_GoToDropOff();
  sendOutputEvent( scm_nEventArmCtrlID);
}

void FORTE_DistStnArm::enterStateDROP(void){
  m_nECCState = scm_nStateDROP;
  alg_DropItem();
  sendOutputEvent( scm_nEventArmCtrlID);
  sendOutputEvent( scm_nEventArmStatusID);
}

void FORTE_DistStnArm::enterStatePICKINGUP(void){
  m_nECCState = scm_nStatePICKINGUP;
  alg_GoToPickup();
  sendOutputEvent( scm_nEventArmCtrlID);
  sendOutputEvent( scm_nEventArmStatusID);
}

void FORTE_DistStnArm::enterStateSUCK(void){
  m_nECCState = scm_nStateSUCK;
  alg_PickupItem();
  sendOutputEvent( scm_nEventArmCtrlID);
}

void FORTE_DistStnArm::enterStateReleaseWait(void){
  m_nECCState = scm_nStateReleaseWait;
  alg_ReleaseWait();
}

void FORTE_DistStnArm::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateWAITING:
        if((scm_nEventItemStatusID == pa_nEIID) && (ItemNeedingPickup()))
          enterStatePICKINGUP();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateDROPPINGOFF:
        if((scm_nEventPosChangeID == pa_nEIID) && (PosReadyToDrop()))
          enterStateDROP();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateDROP:
        if(1)
          enterStateReleaseWait();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStatePICKINGUP:
        if((scm_nEventPosChangeID == pa_nEIID) && (PosReadyToSuck()))
          enterStateSUCK();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateSUCK:
        if(1)
          enterStateDROPPINGOFF();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateReleaseWait:
        if(ReleaseDelay() == 0)
          enterStateWAITING();
        else
        if(ReleaseDelay() != 0)
          enterStateReleaseWait();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 5.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


