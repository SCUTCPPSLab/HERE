/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: DrillStation_FORTEInterface
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.2: 2003-12-04/JHC - Rockwell Automation - Renamed for better indexing.
 ***     0.1: 2002-11-05/JHC - Rockwell Automation - Corrected missing ST element in Algorithm REQ.
 ***     0.0: 2000-05-30/JHC - Rockwell Automation - 
 *************************************************************************/

#include "DrillStation_FORTEInterface.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "DrillStation_FORTEInterface_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_DrillStation_FORTEInterface, g_nStringIdDrillStation_FORTEInterface)

const TForteInt16 FORTE_DrillStation_FORTEInterface::scm_anEIWithIndexes[] = {-1};
const CStringDictionary::TStringId FORTE_DrillStation_FORTEInterface::scm_anEventInputNames[] = {g_nStringIdTest};

const TForteInt16 FORTE_DrillStation_FORTEInterface::scm_anEOWithIndexes[] = {-1, -1, -1, -1, -1, -1};
const CStringDictionary::TStringId FORTE_DrillStation_FORTEInterface::scm_anEventOutputNames[] = {g_nStringIdINIT, g_nStringIdREQ, g_nStringIdSlideTime, g_nStringIdDrillMove, g_nStringIdDrillDone};

const SFBInterfaceSpec FORTE_DrillStation_FORTEInterface::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  0,  scm_anEIWithIndexes,
  5,  scm_anEventOutputNames,  0, 0,  0,  0, 0, 
  0,  0, 0,
  0, 0
};
static int cnt =0;
void FORTE_DrillStation_FORTEInterface::alg_REQ(void){
/* 
File Code goes here
*/
	bool outputsent = false;
   char vector[12];
  char* token;
  if( !inited )
  {
	if ((vectorFile = fopen("/home/pi/tiibench/vectors/DrillStation_Vector.txt", "rb")) == NULL) 
	{
		printf("Cannot open file \"Vectors/DrillStation_Vector.txt\"\n");
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
			printf("#%d Finished: %ld\n", cnt++, timer.getTime());
			// Restart
			inited = false;
			timer.reset();
			enterStateREQ();
			return;
		}
	    token = strtok(vector, " ");
        if (*token == '1') {
           sendOutputEvent( scm_nEventINITID );
		   //printf("Send scm_nEventModeID \n");
		   outputsent = true;
        }
        token = strtok(NULL, " ");
        if (*token == '1') {
           sendOutputEvent( scm_nEventREQID );
		   //printf("Send scm_nEventSetID \n");
		   outputsent = true;
        }
        token = strtok(NULL, " ");
        if (*token == '1') {
            sendOutputEvent( scm_nEventSlideTimeID );
			//printf("Send scm_nEventButton1ID \n");
			outputsent = true;
        }
		token = strtok(NULL, " ");
        if (*token == '1') {
            sendOutputEvent( scm_nEventDrillMoveID );
			//printf("Send scm_nEventButton2ID \n");
			outputsent = true;
        }
		token = strtok(NULL, " ");
        if (*token == '1') {
            sendOutputEvent( scm_nEventDrillDoneID );
			//printf("Send scm_nEventButton2ID \n");
			outputsent = true;
        }
        token = strtok(NULL, " ");
        
	if( !outputsent ) enterStateREQ();
}


void FORTE_DrillStation_FORTEInterface::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_DrillStation_FORTEInterface::enterStateREQ(void){
  m_nECCState = scm_nStateREQ;
  alg_REQ();
}

void FORTE_DrillStation_FORTEInterface::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventTestID == pa_nEIID)
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


