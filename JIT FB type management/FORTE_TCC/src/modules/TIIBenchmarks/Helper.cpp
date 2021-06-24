/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Helper
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2010-11-22/4DIAC-IDE - 4DIAC-Consortium - 
 *************************************************************************/

#include "Helper.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "Helper_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_Helper, g_nStringIdHelper)

const TForteInt16 FORTE_Helper::scm_anEIWithIndexes[] = {-1};
const CStringDictionary::TStringId FORTE_Helper::scm_anEventInputNames[] = {g_nStringIdREQ};

const TForteInt16 FORTE_Helper::scm_anEOWithIndexes[] = {-1, -1};
const CStringDictionary::TStringId FORTE_Helper::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_Helper::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  0,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  0, 0,  0,  0, 0, 
  0,  0, 0,
  0, 0
};


void FORTE_Helper::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_Helper::enterStateREQ(void){
  m_nECCState = scm_nStateREQ;
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_Helper::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventREQID == pa_nEIID)
          enterStateREQ();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateREQ:
        if(scm_nEventREQID == pa_nEIID)
          enterStateREQ();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 1.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


