/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: WaterSensor
 *** Description: null
 *** Version: 
 ***     0.2: 2003-12-04/JHC - Rockwell Automation - Renamed for better indexing.
 ***     0.1: 2002-11-05/JHC - Rockwell Automation - Corrected missing ST element in Algorithm REQ.
 ***     0.0: 2000-05-30/JHC - Rockwell Automation - 
 *************************************************************************/

#include "WaterSensor.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "WaterSensor_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_WaterSensor, g_nStringIdWaterSensor)

const CStringDictionary::TStringId FORTE_WaterSensor::scm_anDataInputNames[] = {g_nStringIdwaterLevel, g_nStringIdlowLimit, g_nStringIdhighLimit};

const CStringDictionary::TStringId FORTE_WaterSensor::scm_anDataInputTypeIds[] = {g_nStringIdUSINT, g_nStringIdUSINT, g_nStringIdUSINT};

const CStringDictionary::TStringId FORTE_WaterSensor::scm_anDataOutputNames[] = {g_nStringIdwithinLimits, g_nStringIdwithinHys};

const CStringDictionary::TStringId FORTE_WaterSensor::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL};

const TForteInt16 FORTE_WaterSensor::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_WaterSensor::scm_anEIWith[] = {0, 1, 2, 255};
const CStringDictionary::TStringId FORTE_WaterSensor::scm_anEventInputNames[] = {g_nStringIdms};

const TDataIOID FORTE_WaterSensor::scm_anEOWith[] = {0, 1, 255};
const TForteInt16 FORTE_WaterSensor::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_WaterSensor::scm_anEventOutputNames[] = {g_nStringIdrange};

const SFBInterfaceSpec FORTE_WaterSensor::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  3,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_WaterSensor::setInitialValues(){
  waterLevel() = 150;
  lowLimit() = 100;
  highLimit() = 200;
  withinLimits() = true;
  withinHys() = true;
}

void FORTE_WaterSensor::alg_inHys(void){
withinHys() = true;
withinLimits() = true;

}

void FORTE_WaterSensor::alg_outHys(void){
withinHys() = false;

}

void FORTE_WaterSensor::alg_inLimits(void){
withinLimits() = true;

}

void FORTE_WaterSensor::alg_outLimits(void){
withinLimits() = false;
withinHys() = false;

}


void FORTE_WaterSensor::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_WaterSensor::enterStateINHYS(void){
  m_nECCState = scm_nStateINHYS;
  alg_inHys();
  sendOutputEvent( scm_nEventrangeID);
}

void FORTE_WaterSensor::enterStateINLIMITS(void){
  m_nECCState = scm_nStateINLIMITS;
}

void FORTE_WaterSensor::enterStateOUTLIMITS(void){
  m_nECCState = scm_nStateOUTLIMITS;
}

void FORTE_WaterSensor::enterStateOUTHYS(void){
  m_nECCState = scm_nStateOUTHYS;
}

void FORTE_WaterSensor::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if((scm_nEventmsID == pa_nEIID) && ((((waterLevel() > ((lowLimit()+5))) && (waterLevel() < ((highLimit()-5)))))))
          enterStateINHYS();
        else
        if((scm_nEventmsID == pa_nEIID) && (((waterLevel() <= ((lowLimit()+5))) || (waterLevel() >= ((highLimit()-5))))))
          enterStateOUTHYS();
        else
        if((scm_nEventmsID == pa_nEIID) && ((((waterLevel() > lowLimit()) && (waterLevel() < highLimit())))))
          enterStateINLIMITS();
        else
        if((scm_nEventmsID == pa_nEIID) && (((waterLevel() <= lowLimit()) || (waterLevel() >= highLimit()))))
          enterStateOUTLIMITS();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateINHYS:
        if((scm_nEventmsID == pa_nEIID) && (((waterLevel() <= ((lowLimit()+5))) || (waterLevel() >= ((highLimit()-5))))))
          enterStateOUTHYS();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateINLIMITS:
        if((scm_nEventmsID == pa_nEIID) && (((waterLevel() <= ((lowLimit()+5))) || (waterLevel() >= ((highLimit()-5))))))
          enterStateOUTHYS();
        else
        if((scm_nEventmsID == pa_nEIID) && (((waterLevel() <= lowLimit()) || (waterLevel() >= highLimit()))))
          enterStateOUTLIMITS();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateOUTLIMITS:
        if((scm_nEventmsID == pa_nEIID) && ((((waterLevel() > lowLimit()) && (waterLevel() < highLimit())))))
          enterStateINLIMITS();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateOUTHYS:
        if((scm_nEventmsID == pa_nEIID) && ((((waterLevel() > ((lowLimit()+5))) && (waterLevel() < ((highLimit()-5)))))))
          enterStateINHYS();
        else
        if((scm_nEventmsID == pa_nEIID) && ((((waterLevel() > lowLimit()) && (waterLevel() < highLimit())))))
          enterStateINLIMITS();
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


