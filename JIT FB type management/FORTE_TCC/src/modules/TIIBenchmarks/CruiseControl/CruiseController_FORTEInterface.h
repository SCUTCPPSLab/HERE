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

#ifndef _CRUISECONTROLLER_FORTEINTERFACE_H_
#define _CRUISECONTROLLER_FORTEINTERFACE_H_

#include <basicfb.h>
#include <forte_sint.h>
#include <forte_udint.h>
#include <forte_uint.h>
#include "../BenchmarkTimer/BenchmarkTimer.h"

class FORTE_CruiseController_FORTEInterface: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_CruiseController_FORTEInterface)

private:
  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_UDINT &time() {
    return *static_cast<CIEC_UDINT*>(getDO(0));
  };

  CIEC_UINT &rotaryCount() {
    return *static_cast<CIEC_UINT*>(getDO(1));
  };

  CIEC_SINT &throttleOffset() {
    return *static_cast<CIEC_SINT*>(getDO(2));
  };

  static const TEventID scm_nEventREQID = 0;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventcclockID = 0;
  static const TEventID scm_nEventsetID = 1;
  static const TEventID scm_nEventoffID = 2;
  static const TEventID scm_nEventresumeID = 3;
  static const TEventID scm_nEventquickAccelID = 4;
  static const TEventID scm_nEventquickDecelID = 5;
  static const TEventID scm_nEventbrakePressedID = 6;
  static const TEventID scm_nEventaccelPressedID = 7;
  static const TEventID scm_nEventaccelReleasedID = 8;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_BASIC_FB_DATA_ARRAY(9, 0, 3, 0, 0);
  void alg_REQ(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateREQ = 1;

  FILE* vectorFile;
  bool inited=false;
  BenchmarkTimer timer;

  void enterStateSTART(void);
  void enterStateREQ(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_CruiseController_FORTEInterface(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
              0, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_CruiseController_FORTEInterface(){};

};

#endif //close the ifdef sequence from the beginning of the file

