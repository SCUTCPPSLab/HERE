/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Slider
 *** Description: Slider for the drill
 *** Version: 
 ***     0.2: 2003-12-04/JHC - Rockwell Automation - Renamed for better indexing.
 ***     0.1: 2002-11-05/JHC - Rockwell Automation - Corrected missing ST element in Algorithm REQ.
 ***     0.0: 2000-05-30/JHC - Rockwell Automation - 
 *************************************************************************/

#include "Slider.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "Slider_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_Slider, g_nStringIdSlider)

const CStringDictionary::TStringId FORTE_Slider::scm_anDataInputNames[] = {g_nStringIdReadyNot};

const CStringDictionary::TStringId FORTE_Slider::scm_anDataInputTypeIds[] = {g_nStringIdBOOL};

const CStringDictionary::TStringId FORTE_Slider::scm_anDataOutputNames[] = {g_nStringIdOpenClose};

const CStringDictionary::TStringId FORTE_Slider::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL};

const TForteInt16 FORTE_Slider::scm_anEIWithIndexes[] = {-1, -1, -1, 0};
const TDataIOID FORTE_Slider::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId FORTE_Slider::scm_anEventInputNames[] = {g_nStringIdREQ, g_nStringIdSlideTime, g_nStringIdFinishDrill, g_nStringIdDrillStat};

const TDataIOID FORTE_Slider::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_Slider::scm_anEOWithIndexes[] = {0, -1, -1};
const CStringDictionary::TStringId FORTE_Slider::scm_anEventOutputNames[] = {g_nStringIdStatus, g_nStringIdInPlace};

const SFBInterfaceSpec FORTE_Slider::scm_stFBInterfaceSpec = {
  4,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_Slider::setInitialValues(){
  OpenClose() = true;
}

void FORTE_Slider::alg_INIT(void){
OpenClose() = true;

}

void FORTE_Slider::alg_REQ(void){
OpenClose() = false;

}


void FORTE_Slider::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
  alg_INIT();
  sendOutputEvent( scm_nEventStatusID);
}

void FORTE_Slider::enterStateREQ(void){
  m_nECCState = scm_nStateREQ;
  alg_REQ();
  sendOutputEvent( scm_nEventStatusID);
}

void FORTE_Slider::enterStateDrilling(void){
  m_nECCState = scm_nStateDrilling;
  sendOutputEvent( scm_nEventInPlaceID);
}

void FORTE_Slider::enterStateReturnSlide(void){
  m_nECCState = scm_nStateReturnSlide;
}

void FORTE_Slider::enterStateWaitForDrill(void){
  m_nECCState = scm_nStateWaitForDrill;
}

void FORTE_Slider::executeEvent(int pa_nEIID){
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
        if(scm_nEventSlideTimeID == pa_nEIID)
          enterStateDrilling();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateDrilling:
        if(scm_nEventFinishDrillID == pa_nEIID)
          enterStateReturnSlide();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateReturnSlide:
        if(scm_nEventSlideTimeID == pa_nEIID)
          enterStateWaitForDrill();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateWaitForDrill:
        if(ReadyNot())
          enterStateSTART();
        else
        if((scm_nEventDrillStatID == pa_nEIID) && (ReadyNot()))
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 4.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


