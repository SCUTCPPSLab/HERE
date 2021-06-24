/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: DistStnPusher
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.2: 2003-12-04/JHC - Rockwell Automation - Renamed for better indexing.
 *************************************************************************/

#include "DistStnPusher.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "DistStnPusher_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_DistStnPusher, g_nStringIdDistStnPusher)

const CStringDictionary::TStringId FORTE_DistStnPusher::scm_anDataInputNames[] = {g_nStringIdPosBack, g_nStringIdPosFront, g_nStringIdCylinderEmpty, g_nStringIdArmClear};

const CStringDictionary::TStringId FORTE_DistStnPusher::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL};

const CStringDictionary::TStringId FORTE_DistStnPusher::scm_anDataOutputNames[] = {g_nStringIdPusherForward, g_nStringIdItemPresent};

const CStringDictionary::TStringId FORTE_DistStnPusher::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL};

const TForteInt16 FORTE_DistStnPusher::scm_anEIWithIndexes[] = {0, 5};
const TDataIOID FORTE_DistStnPusher::scm_anEIWith[] = {0, 1, 2, 3, 255, 3, 255};
const CStringDictionary::TStringId FORTE_DistStnPusher::scm_anEventInputNames[] = {g_nStringIdPosChange, g_nStringIdArmStatusChange};

const TDataIOID FORTE_DistStnPusher::scm_anEOWith[] = {0, 1, 255, 0, 1, 255};
const TForteInt16 FORTE_DistStnPusher::scm_anEOWithIndexes[] = {0, 3, -1};
const CStringDictionary::TStringId FORTE_DistStnPusher::scm_anEventOutputNames[] = {g_nStringIdPusherCtrl, g_nStringIdItemStatus};

const CStringDictionary::TStringId FORTE_DistStnPusher::scm_anInternalsNames[] = {g_nStringIdTimeoutCount};

const CStringDictionary::TStringId FORTE_DistStnPusher::scm_anInternalsTypeIds[] = {g_nStringIdINT};

const SFBInterfaceSpec FORTE_DistStnPusher::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  4,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_DistStnPusher::scm_stInternalVars = {1, scm_anInternalsNames, scm_anInternalsTypeIds};


void FORTE_DistStnPusher::setInitialValues(){
  PosBack() = false;
  PosFront() = false;
  CylinderEmpty() = false;
  PusherForward() = false;
  ItemPresent() = false;
}

void FORTE_DistStnPusher::alg_GoBack(void){
PusherForward() = false;

}

void FORTE_DistStnPusher::alg_GoForward(void){
PusherForward() = true;

}

void FORTE_DistStnPusher::alg_ItemPushedForward(void){
ItemPresent() = true;

}


void FORTE_DistStnPusher::enterStateBACK(void){
  m_nECCState = scm_nStateBACK;
}

void FORTE_DistStnPusher::enterStateGOINGBACK(void){
  m_nECCState = scm_nStateGOINGBACK;
  alg_GoBack();
  sendOutputEvent( scm_nEventPusherCtrlID);
}

void FORTE_DistStnPusher::enterStateGOINGFORWARD(void){
  m_nECCState = scm_nStateGOINGFORWARD;
  alg_GoForward();
  sendOutputEvent( scm_nEventPusherCtrlID);
}

void FORTE_DistStnPusher::enterStateFRONT(void){
  m_nECCState = scm_nStateFRONT;
  alg_ItemPushedForward();
  sendOutputEvent( scm_nEventItemStatusID);
}

void FORTE_DistStnPusher::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateBACK:
        if((scm_nEventPosChangeID == pa_nEIID) && ((((!CylinderEmpty()) && (ArmClear())))))
          enterStateGOINGFORWARD();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateGOINGBACK:
        if((scm_nEventPosChangeID == pa_nEIID) && ((((!CylinderEmpty()) && (ArmClear())))))
          enterStateGOINGFORWARD();
        else
        if((scm_nEventPosChangeID == pa_nEIID) && (PosBack()))
          enterStateBACK();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateGOINGFORWARD:
        if((scm_nEventPosChangeID == pa_nEIID) && (PosFront()))
          enterStateFRONT();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateFRONT:
        if(1)
          enterStateGOINGBACK();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 3.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


