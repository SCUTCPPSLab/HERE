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

#ifndef _WATCH_FORTEINTERFACE_H_
#define _WATCH_FORTEINTERFACE_H_

#include <basicfb.h>
#include <forte_dint.h>
#include "../BenchmarkTimer/BenchmarkTimer.h"

class FORTE_Watch_FORTEInterface: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_Watch_FORTEInterface)

private:
  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_DINT &CurrentTime() {
    return *static_cast<CIEC_DINT*>(getDO(0));
  };

  static const TEventID scm_nEventREQID = 0;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventInitID = 0;
  static const TEventID scm_nEventTimeChangeID = 1;
  static const TEventID scm_nEventB1ID = 2;
  static const TEventID scm_nEventB2ID = 3;
  static const TEventID scm_nEventB3ID = 4;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;
  FILE* vectorFile;
  bool inited=false;
  BenchmarkTimer timer;
   FORTE_BASIC_FB_DATA_ARRAY(5, 0, 1, 0, 0);
  void alg_REQ(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateREQ = 1;

  void enterStateSTART(void);
  void enterStateREQ(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_Watch_FORTEInterface(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
              0, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_Watch_FORTEInterface(){};

};

#endif //close the ifdef sequence from the beginning of the file

