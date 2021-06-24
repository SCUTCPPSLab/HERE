/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: CruiseManager
 *** Description: Manages the state of the cruise control
 *** Version: 
 ***     0.2: 2003-12-04/JHC - Rockwell Automation - Renamed for better indexing.
 ***     0.1: 2002-11-05/JHC - Rockwell Automation - Corrected missing ST element in Algorithm REQ.
 ***     0.0: 2000-05-30/JHC - Rockwell Automation - 
 *************************************************************************/

#ifndef _CRUISEMANAGER_H_
#define _CRUISEMANAGER_H_

#include <basicfb.h>
#include <forte_int.h>

class FORTE_CruiseManager: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_CruiseManager)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_INT &speed() {
    return *static_cast<CIEC_INT*>(getDI(0));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_INT &cruiseSpeed() {
    return *static_cast<CIEC_INT*>(getDO(0));
  };

  static const TEventID scm_nEventsetID = 0;
  static const TEventID scm_nEventoffID = 1;
  static const TEventID scm_nEventresumeID = 2;
  static const TEventID scm_nEventquickAccelID = 3;
  static const TEventID scm_nEventquickDecelID = 4;
  static const TEventID scm_nEventbrakePressedID = 5;
  static const TEventID scm_nEventcclockID = 6;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventregulOffID = 0;
  static const TEventID scm_nEventregulSetID = 1;
  static const TEventID scm_nEventregulStdbyID = 2;
  static const TEventID scm_nEventregulResumeID = 3;
  static const TEventID scm_nEventspeedSetID = 4;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const CStringDictionary::TStringId scm_anInternalsNames[];
  static const CStringDictionary::TStringId scm_anInternalsTypeIds[];
  CIEC_INT &desiredSpeed() {
    return *static_cast<CIEC_INT*>(getVarInternal(0));
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(5, 1, 1, 1, 0);

virtual void setInitialValues();
  void alg_off(void);
  void alg_set(void);
  void alg_resume(void);
  void alg_standby(void);
  void alg_accel(void);
  void alg_decel(void);
  static const TForteInt16 scm_nStateOFF = 0;
  static const TForteInt16 scm_nStateSET = 1;
  static const TForteInt16 scm_nStateSTDBY = 2;
  static const TForteInt16 scm_nStateRESUME = 3;
  static const TForteInt16 scm_nStateACCEL = 4;
  static const TForteInt16 scm_nStateDECEL = 5;

  void enterStateOFF(void);
  void enterStateSET(void);
  void enterStateSTDBY(void);
  void enterStateRESUME(void);
  void enterStateACCEL(void);
  void enterStateDECEL(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_CruiseManager(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_CruiseManager(){};

};

#endif //close the ifdef sequence from the beginning of the file

