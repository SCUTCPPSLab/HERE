/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: MP3PLAYER_FORTEInterface
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.2: 2003-12-04/JHC - Rockwell Automation - Renamed for better indexing.
 ***     0.1: 2002-11-05/JHC - Rockwell Automation - Corrected missing ST element in Algorithm REQ.
 ***     0.0: 2000-05-30/JHC - Rockwell Automation - 
 *************************************************************************/

#include "MP3PLAYER_FORTEInterface.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "MP3PLAYER_FORTEInterface_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_MP3PLAYER_FORTEInterface, g_nStringIdMP3PLAYER_FORTEInterface)

const TForteInt16 FORTE_MP3PLAYER_FORTEInterface::scm_anEIWithIndexes[] = {-1};
const CStringDictionary::TStringId FORTE_MP3PLAYER_FORTEInterface::scm_anEventInputNames[] = {g_nStringIdINIT};

const TForteInt16 FORTE_MP3PLAYER_FORTEInterface::scm_anEOWithIndexes[] = {-1, -1, -1, -1};
const CStringDictionary::TStringId FORTE_MP3PLAYER_FORTEInterface::scm_anEventOutputNames[] = {g_nStringIdPLAY, g_nStringIdSTOP, g_nStringIdPAUSE};

const SFBInterfaceSpec FORTE_MP3PLAYER_FORTEInterface::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  0,  scm_anEIWithIndexes,
  3,  scm_anEventOutputNames,  0, 0,  0,  0, 0, 
  0,  0, 0,
  0, 0
};

void FORTE_MP3PLAYER_FORTEInterface::alg_REQ(void){
/* 
File Code goes here
*/
  bool outputsent = false;
  char vector[8];
  char* token;
  short value = 0;
  if( !inited )
  {
	if ((vectorFile = fopen("Vectors/MP3Player_Vector.txt", "rb")) == NULL) 
	{
		printf("Cannot open file \"Vectors/MP3Player_Vector.txt\"\n");
		return;
	}
	inited = true;
	printf("Inited\n");
	timer.start();
  }
  
  // Read inputs here
        if( !fgets(vector, 8, vectorFile) ){
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
           sendOutputEvent( scm_nEventPLAYID );
		   outputsent = true;
        }
        token = strtok(NULL, " ");
        if (*token == '1') {
           sendOutputEvent( scm_nEventSTOPID );
		   outputsent = true;
        }
        token = strtok(NULL, " ");
        if (*token == '1') {
            sendOutputEvent( scm_nEventPAUSEID );
			outputsent = true;
        }
        token = strtok(NULL, " ");
		
		if( !outputsent ) enterStateREQ();

}


void FORTE_MP3PLAYER_FORTEInterface::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_MP3PLAYER_FORTEInterface::enterStateREQ(void){
  m_nECCState = scm_nStateREQ;
  alg_REQ();
}

void FORTE_MP3PLAYER_FORTEInterface::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventINITID == pa_nEIID)
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


