/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Watch_FORTEInterface
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.0: 2015-08-11/4DIAC-IDE - 4DIAC-Consortium - 
 *************************************************************************/

#include "Watch_FORTEInterface.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "Watch_FORTEInterface_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_Watch_FORTEInterface, g_nStringIdWatch_FORTEInterface)

const CStringDictionary::TStringId FORTE_Watch_FORTEInterface::scm_anDataOutputNames[] = {g_nStringIdCurrentTime};

const CStringDictionary::TStringId FORTE_Watch_FORTEInterface::scm_anDataOutputTypeIds[] = {g_nStringIdDINT};

const TForteInt16 FORTE_Watch_FORTEInterface::scm_anEIWithIndexes[] = {-1};
const CStringDictionary::TStringId FORTE_Watch_FORTEInterface::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_Watch_FORTEInterface::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_Watch_FORTEInterface::scm_anEOWithIndexes[] = {-1, 0, -1, -1, -1, -1};
const CStringDictionary::TStringId FORTE_Watch_FORTEInterface::scm_anEventOutputNames[] = {g_nStringIdInit, g_nStringIdTimeChange, g_nStringIdB1, g_nStringIdB2, g_nStringIdB3};

const SFBInterfaceSpec FORTE_Watch_FORTEInterface::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  0,  scm_anEIWithIndexes,
  5,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  0,  0, 0, 
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

void FORTE_Watch_FORTEInterface::alg_REQ(void){
bool outputsent = false;
   char vector[17];
  char* token;
  short value = 0;
  if( !inited )
  {
	if ((vectorFile = fopen("/home/pi/tiibench/vectors/Watch_ECC_Vector.txt", "rb")) == NULL) 
	{
		printf("Cannot open file \"Vectors/Watch_ECC_Vector.txt\"\n");
		return;
	}
	inited = true;
	printf("Tester Inited\n");
	timer.start();
  }
  
  // Read inputs here
        if( !fgets(vector, 17, vectorFile) ){
			// END
			timer.stop();
			printf("\n\nFinished: %ld\n\n", timer.getTime());
			printf("\n\nclock per second: %ld\n\n", CLOCKS_PER_SEC);
			// Restart
			inited = false;
			timer.reset();
			enterStateREQ();
			//while(1){} // stop here
			return;
		}
        token = strtok(vector, " ");
        if (*token == '1') {
           sendOutputEvent( scm_nEventInitID );
		   outputsent = true;
        }
        token = strtok(NULL, " ");
        if (*token == '1') {
           sendOutputEvent( scm_nEventTimeChangeID );
		   outputsent = true;
        }
        token = strtok(NULL, " ");
        if (*token == '1') {
            sendOutputEvent( scm_nEventB1ID );
			outputsent = true;
        }
		 token = strtok(NULL, " ");
        if (*token == '1') {
            sendOutputEvent( scm_nEventB2ID );
			outputsent = true;
        }
		token = strtok(NULL, " ");
        if (*token == '1') {
            sendOutputEvent( scm_nEventB3ID );
			outputsent = true;
        }
		token = strtok(NULL, " ");
        CurrentTime() = strtol(token, NULL, 0);

        token = strtok(NULL, " ");
        
	if( !outputsent ) enterStateREQ();
}


void FORTE_Watch_FORTEInterface::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_Watch_FORTEInterface::enterStateREQ(void){
  m_nECCState = scm_nStateREQ;
  alg_REQ();
}

void FORTE_Watch_FORTEInterface::executeEvent(int pa_nEIID){
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


