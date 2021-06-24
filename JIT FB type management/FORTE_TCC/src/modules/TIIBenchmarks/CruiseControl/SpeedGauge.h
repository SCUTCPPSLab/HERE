/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: SpeedGauge
 *** Description: Measures the linear speed from the rotary encoder count
 *** Version: 
 ***     0.2: 2003-12-04/JHC - Rockwell Automation - Renamed for better indexing.
 ***     0.1: 2002-11-05/JHC - Rockwell Automation - Corrected missing ST element in Algorithm REQ.
 ***     0.0: 2000-05-30/JHC - Rockwell Automation - 
 *************************************************************************/

#ifndef _SPEEDGAUGE_H_
#define _SPEEDGAUGE_H_

#include <basicfb.h>
#include <forte_usint.h>
#include <forte_int.h>
#include <forte_udint.h>
#include <forte_uint.h>

class FORTE_SpeedGauge: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_SpeedGauge)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_UDINT &time() {
    return *static_cast<CIEC_UDINT*>(getDI(0));
  };

  CIEC_UINT &rotaryCount() {
    return *static_cast<CIEC_UINT*>(getDI(1));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_INT &speedVal() {
    return *static_cast<CIEC_INT*>(getDO(0));
  };

  static const TEventID scm_nEventcclockID = 0;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventspeedID = 0;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const CStringDictionary::TStringId scm_anInternalsNames[];
  static const CStringDictionary::TStringId scm_anInternalsTypeIds[];
  CIEC_UINT &prevCount() {
    return *static_cast<CIEC_UINT*>(getVarInternal(0));
  };

  CIEC_UDINT &prevTime() {
    return *static_cast<CIEC_UDINT*>(getVarInternal(1));
  };

  CIEC_USINT &count() {
    return *static_cast<CIEC_USINT*>(getVarInternal(2));
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(1, 2, 1, 3, 0);

virtual void setInitialValues();
  void alg_calcSpeed(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateCALC = 1;

  void enterStateSTART(void);
  void enterStateCALC(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_SpeedGauge(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_SpeedGauge(){};

};

#endif //close the ifdef sequence from the beginning of the file

