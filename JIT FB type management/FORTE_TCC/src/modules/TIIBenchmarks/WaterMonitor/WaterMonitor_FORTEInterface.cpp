/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: WaterMonitor_FORTEInterface
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.2: 2003-12-04/JHC - Rockwell Automation - Renamed for better indexing.
 ***     0.1: 2002-11-05/JHC - Rockwell Automation - Corrected missing ST element in Algorithm REQ.
 ***     0.0: 2000-05-30/JHC - Rockwell Automation - 
 *************************************************************************/

#include "WaterMonitor_FORTEInterface.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "WaterMonitor_FORTEInterface_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_WaterMonitor_FORTEInterface, g_nStringIdWaterMonitor_FORTEInterface)

const CStringDictionary::TStringId FORTE_WaterMonitor_FORTEInterface::scm_anDataOutputNames[] = {g_nStringIdwaterLevel};

const CStringDictionary::TStringId FORTE_WaterMonitor_FORTEInterface::scm_anDataOutputTypeIds[] = {g_nStringIdUSINT};

const TForteInt16 FORTE_WaterMonitor_FORTEInterface::scm_anEIWithIndexes[] = {-1};
const CStringDictionary::TStringId FORTE_WaterMonitor_FORTEInterface::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_WaterMonitor_FORTEInterface::scm_anEOWith[] = {0, 255, 0, 255, 0, 255};
const TForteInt16 FORTE_WaterMonitor_FORTEInterface::scm_anEOWithIndexes[] = {0, 2, 4, -1};
const CStringDictionary::TStringId FORTE_WaterMonitor_FORTEInterface::scm_anEventOutputNames[] = {g_nStringIdms, g_nStringIdtstButton, g_nStringIdresetButton};

const SFBInterfaceSpec FORTE_WaterMonitor_FORTEInterface::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  0,  scm_anEIWithIndexes,
  3,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  0,  0, 0, 
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};
static int cnt=0;
void FORTE_WaterMonitor_FORTEInterface::alg_REQ(void){
/* 
File Code goes here
*/
  bool outputsent = false;
  char vector[12];
  char* token;
  if( !inited )
  {
	if ((vectorFile = fopen("/home/pi/tiibench/vectors/WaterMonitor_Vector.txt", "rb")) == NULL) 
	{
		printf("Cannot open file \"Vectors/WaterMonitor_Vector.txt\"\n");
		return;
	}
	inited = true;
	//printf("Tester Inited\n");
	timer.start();
  }
  
  // Read inputs here
        if( !fgets(vector, 12, vectorFile) ){
			// END
			timer.stop();
			printf("#%d Finished: %ld\n", cnt++,timer.getTime());
		//	printf("\n\nclock per second: %ld\n\n", CLOCKS_PER_SEC);
			// Restart
			inited = false;
			timer.reset();
			enterStateREQ();
			//while(1){} // stop here
			return;
		}
        token = strtok(vector, " ");
        if (*token == '1') {
           sendOutputEvent( scm_nEventmsID );
		   //printf("Send scm_nEventModeID \n");
		   outputsent = true;
        }
        token = strtok(NULL, " ");
        if (*token == '1') {
           sendOutputEvent( scm_nEventtstButtonID );
		   //printf("Send scm_nEventSetID \n");
		   outputsent = true;
        }
        token = strtok(NULL, " ");
        if (*token == '1') {
            sendOutputEvent( scm_nEventresetButtonID );
			//printf("Send scm_nEventButton1ID \n");
			outputsent = true;
        }
		
		token = strtok(NULL, " ");
        waterLevel() = strtol(token, NULL, 0);
        
		token = strtok(NULL, " ");
        
	if( !outputsent ) enterStateREQ();
}


void FORTE_WaterMonitor_FORTEInterface::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_WaterMonitor_FORTEInterface::enterStateREQ(void){
  m_nECCState = scm_nStateREQ;
  alg_REQ();
}

void FORTE_WaterMonitor_FORTEInterface::executeEvent(int pa_nEIID){
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


