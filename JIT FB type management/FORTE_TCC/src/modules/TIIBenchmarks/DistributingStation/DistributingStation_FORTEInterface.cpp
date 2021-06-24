/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: DistributingStation_FORTEInterface
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.2: 2003-12-04/JHC - Rockwell Automation - Renamed for better indexing.
 ***     0.1: 2002-11-05/JHC - Rockwell Automation - Corrected missing ST element in Algorithm REQ.
 ***     0.0: 2000-05-30/JHC - Rockwell Automation - 
 *************************************************************************/

#include "DistributingStation_FORTEInterface.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "DistributingStation_FORTEInterface_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_DistributingStation_FORTEInterface, g_nStringIdDistributingStation_FORTEInterface)

const CStringDictionary::TStringId FORTE_DistributingStation_FORTEInterface::scm_anDataOutputNames[] = {g_nStringIdPusherBack, g_nStringIdPusherFront, g_nStringIdArmAtPickup, g_nStringIdArmAtDropoff, g_nStringIdCylinderEmpty};

const CStringDictionary::TStringId FORTE_DistributingStation_FORTEInterface::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL};

const TForteInt16 FORTE_DistributingStation_FORTEInterface::scm_anEIWithIndexes[] = {-1};
const CStringDictionary::TStringId FORTE_DistributingStation_FORTEInterface::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_DistributingStation_FORTEInterface::scm_anEOWith[] = {0, 1, 2, 3, 4, 255};
const TForteInt16 FORTE_DistributingStation_FORTEInterface::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_DistributingStation_FORTEInterface::scm_anEventOutputNames[] = {g_nStringIdInputsChange};

const SFBInterfaceSpec FORTE_DistributingStation_FORTEInterface::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  0,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  0,  0, 0, 
  5,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

void FORTE_DistributingStation_FORTEInterface::alg_REQ(void){
/* 
File Code goes here
*/
	bool outputsent = false;
   char vector[14];
  char* token;
  short value = 0;
  if( !inited )
  {
	if ((vectorFile = fopen("/home/pi/tiibench/vectors/DistributingStation_Vector.txt", "rb")) == NULL) 
	{
		printf("Cannot open file \"Vectors/DistributingStation_Vector.txt\"\n");
		return;
	}
	inited = true;
	printf("Tester Inited\n");
	timer.start();
  }
  
  // Read inputs here
        if( !fgets(vector, 14, vectorFile) ){
			// END
			timer.stop();
			printf("\n\nFinished: %ld\n\n", timer.getTime());
			printf("\n\nclock per second: %ld\n\n", CLOCKS_PER_SEC);
			fclose(vectorFile);
			// Restart
			inited = false;
			timer.reset();
			enterStateREQ();
			//while(1){} // stop here
			return;
		}
        token = strtok(vector, " ");
        if (*token == '1') {
           sendOutputEvent( scm_nEventInputsChangeID );
		   outputsent = true;
        }
        token = strtok(NULL, " ");
        PusherBack() = strtol(token, NULL, 0);
        token = strtok(NULL, " ");
        PusherFront() = strtol(token, NULL, 0);
        token = strtok(NULL, " ");
        ArmAtPickup() = strtol(token, NULL, 0);
        token = strtok(NULL, " ");
        ArmAtDropoff() = strtol(token, NULL, 0);
        token = strtok(NULL, " ");
        CylinderEmpty() = strtol(token, NULL, 0);
        token = strtok(NULL, " ");
        
	if( !outputsent ) enterStateREQ();
}


void FORTE_DistributingStation_FORTEInterface::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_DistributingStation_FORTEInterface::enterStateREQ(void){
  m_nECCState = scm_nStateREQ;
  alg_REQ();
}

void FORTE_DistributingStation_FORTEInterface::executeEvent(int pa_nEIID){
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


