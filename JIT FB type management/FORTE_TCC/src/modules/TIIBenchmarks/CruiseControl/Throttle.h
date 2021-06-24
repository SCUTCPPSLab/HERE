/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Throttle
 *** Description: null
 *** Version: 
 ***     0.2: 2003-12-04/JHC - Rockwell Automation - Renamed for better indexing.
 ***     0.1: 2002-11-05/JHC - Rockwell Automation - Corrected missing ST element in Algorithm REQ.
 ***     0.0: 2000-05-30/JHC - Rockwell Automation - 
 *************************************************************************/

#ifndef _THROTTLE_H_
#define _THROTTLE_H_

#include <basicfb.h>
#include <forte_int.h>
#include <forte_sint.h>

class FORTE_Throttle: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_Throttle)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_INT &cruiseSpeed() {
    return *static_cast<CIEC_INT*>(getDI(0));
  };

  CIEC_INT &speed() {
    return *static_cast<CIEC_INT*>(getDI(1));
  };

  CIEC_SINT &throttleOffset() {
    return *static_cast<CIEC_SINT*>(getDI(2));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_SINT &throttleVal() {
    return *static_cast<CIEC_SINT*>(getDO(0));
  };

  static const TEventID scm_nEventcruiseOffID = 0;
  static const TEventID scm_nEventcruiseOnID = 1;
  static const TEventID scm_nEventspeedSetID = 2;
  static const TEventID scm_nEventcclockID = 3;
  static const TEventID scm_nEventaccelPressedID = 4;
  static const TEventID scm_nEventaccelReleasedID = 5;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventthrottleChgID = 0;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const CStringDictionary::TStringId scm_anInternalsNames[];
  static const CStringDictionary::TStringId scm_anInternalsTypeIds[];
  CIEC_SINT &prevOffset() {
    return *static_cast<CIEC_SINT*>(getVarInternal(0));
  };

  CIEC_SINT &tmp() {
    return *static_cast<CIEC_SINT*>(getVarInternal(1));
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(1, 3, 1, 2, 0);

virtual void setInitialValues();
  void alg_normal(void);
  void alg_accel(void);
  void alg_cruise(void);
  static const TForteInt16 scm_nStateNORMAL = 0;
  static const TForteInt16 scm_nStateCRUISE = 1;
  static const TForteInt16 scm_nStateACCEL = 2;

  void enterStateNORMAL(void);
  void enterStateCRUISE(void);
  void enterStateACCEL(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_Throttle(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_Throttle(){};

};

#endif //close the ifdef sequence from the beginning of the file

