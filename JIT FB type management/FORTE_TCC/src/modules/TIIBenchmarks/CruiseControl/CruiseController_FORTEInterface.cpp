/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: CruiseController_FORTEInterface
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.2: 2003-12-04/JHC - Rockwell Automation - Renamed for better indexing.
 ***     0.1: 2002-11-05/JHC - Rockwell Automation - Corrected missing ST element in Algorithm REQ.
 ***     0.0: 2000-05-30/JHC - Rockwell Automation - 
 *************************************************************************/

#include "CruiseController_FORTEInterface.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "CruiseController_FORTEInterface_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_CruiseController_FORTEInterface, g_nStringIdCruiseController_FORTEInterface)

const CStringDictionary::TStringId FORTE_CruiseController_FORTEInterface::scm_anDataOutputNames[] = {g_nStringIdtime, g_nStringIdrotaryCount, g_nStringIdthrottleOffset};

const CStringDictionary::TStringId FORTE_CruiseController_FORTEInterface::scm_anDataOutputTypeIds[] = {g_nStringIdUDINT, g_nStringIdUINT, g_nStringIdSINT};

const TForteInt16 FORTE_CruiseController_FORTEInterface::scm_anEIWithIndexes[] = {-1};
const CStringDictionary::TStringId FORTE_CruiseController_FORTEInterface::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_CruiseController_FORTEInterface::scm_anEOWith[] = {0, 1, 2, 255, 0, 1, 2, 255, 0, 1, 2, 255, 0, 1, 2, 255, 0, 1, 2, 255, 0, 1, 2, 255, 0, 1, 2, 255, 0, 1, 2, 255, 0, 1, 2, 255};
const TForteInt16 FORTE_CruiseController_FORTEInterface::scm_anEOWithIndexes[] = {0, 4, 8, 12, 16, 20, 24, 28, 32, -1};
const CStringDictionary::TStringId FORTE_CruiseController_FORTEInterface::scm_anEventOutputNames[] = {g_nStringIdcclock, g_nStringIdset, g_nStringIdoff, g_nStringIdresume, g_nStringIdquickAccel, g_nStringIdquickDecel, g_nStringIdbrakePressed, g_nStringIdaccelPressed, g_nStringIdaccelReleased};

const SFBInterfaceSpec FORTE_CruiseController_FORTEInterface::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  0,  scm_anEIWithIndexes,
  9,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  0,  0, 0, 
  3,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};
static int cnt=0;
#include <iostream>
#include <fstream>
void FORTE_CruiseController_FORTEInterface::alg_REQ(void){
/* 
File Code goes here
*/

/* 
File Code goes here
*/
  bool outputsent = false;
  char vector[34];
  char* token;
  if( !inited )
  {
	if ((vectorFile = fopen("/home/pi/tiibench/vectors/CruiseController_Vector.txt", "rb")) == NULL) 
	{
		printf("Cannot open file \"Vectors/CruiseControl_Vector.txt\"\n");
		return;
	}
	inited = true;
	//printf("Tester Inited\n");
	timer.start();
  }
  
  // Read inputs here
	if( !fgets(vector, 34, vectorFile) ){
		// END
		timer.stop();
		printf("#%d Finished: %ld\n", cnt++,timer.getTime());
		//printf("\n\nclock per second: %ld\n\n", CLOCKS_PER_SEC);
		// Restart
		inited = false;
		timer.reset();
		enterStateREQ();
		
		return;
	}
	token = strtok(vector, " ");
	if (*token == '1') {
	   sendOutputEvent( scm_nEventcclockID );
	   outputsent = true;
	}
	token = strtok(NULL, " ");
	if (*token == '1') {
	   sendOutputEvent( scm_nEventsetID );
	   outputsent = true;
	}
	token = strtok(NULL, " ");
	if (*token == '1') {
		sendOutputEvent( scm_nEventoffID );
		outputsent = true;
	}
	
	token = strtok(NULL, " ");
	if (*token == '1') {
		sendOutputEvent( scm_nEventresumeID );
		outputsent = true;
	}
	
	token = strtok(NULL, " ");
	if (*token == '1') {
		sendOutputEvent( scm_nEventquickAccelID );
		outputsent = true;
	}
	
	token = strtok(NULL, " ");
	if (*token == '1') {
		sendOutputEvent( scm_nEventquickDecelID );
		outputsent = true;
	}
	token = strtok(NULL, " ");
	if (*token == '1') {
		sendOutputEvent( scm_nEventbrakePressedID );
		outputsent = true;
	}
	token = strtok(NULL, " ");
	if (*token == '1') {
		sendOutputEvent( scm_nEventaccelPressedID );
		outputsent = true;
	}
	token = strtok(NULL, " ");
	if (*token == '1') {
		sendOutputEvent( scm_nEventaccelReleasedID );
		outputsent = true;
	}
	
	token = strtok(NULL, " ");
	time() = strtol(token, NULL, 0);

	token = strtok(NULL, " ");
	rotaryCount() = strtol(token, NULL, 0);
	
	token = strtok(NULL, " ");
	throttleOffset() = strtol(token, NULL, 0);
	
	token = strtok(NULL, " ");
        
	if( !outputsent ) enterStateREQ();
}



void FORTE_CruiseController_FORTEInterface::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_CruiseController_FORTEInterface::enterStateREQ(void){
  m_nECCState = scm_nStateREQ;
  alg_REQ();
}

void FORTE_CruiseController_FORTEInterface::executeEvent(int pa_nEIID){
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
        if(1)
          enterStateSTART();
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


