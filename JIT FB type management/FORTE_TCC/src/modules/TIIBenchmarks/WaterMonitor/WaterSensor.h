/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: WaterSensor
 *** Description: null
 *** Version: 
 ***     0.2: 2003-12-04/JHC - Rockwell Automation - Renamed for better indexing.
 ***     0.1: 2002-11-05/JHC - Rockwell Automation - Corrected missing ST element in Algorithm REQ.
 ***     0.0: 2000-05-30/JHC - Rockwell Automation - 
 *************************************************************************/

#ifndef _WATERSENSOR_H_
#define _WATERSENSOR_H_

#include <basicfb.h>
#include <forte_usint.h>
#include <forte_bool.h>

class FORTE_WaterSensor: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_WaterSensor)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_USINT &waterLevel() {
    return *static_cast<CIEC_USINT*>(getDI(0));
  };

  CIEC_USINT &lowLimit() {
    return *static_cast<CIEC_USINT*>(getDI(1));
  };

  CIEC_USINT &highLimit() {
    return *static_cast<CIEC_USINT*>(getDI(2));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &withinLimits() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  CIEC_BOOL &withinHys() {
    return *static_cast<CIEC_BOOL*>(getDO(1));
  };

  static const TEventID scm_nEventmsID = 0;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventrangeID = 0;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_BASIC_FB_DATA_ARRAY(1, 3, 2, 0, 0);

virtual void setInitialValues();
  void alg_inHys(void);
  void alg_outHys(void);
  void alg_inLimits(void);
  void alg_outLimits(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateINHYS = 1;
  static const TForteInt16 scm_nStateINLIMITS = 2;
  static const TForteInt16 scm_nStateOUTLIMITS = 3;
  static const TForteInt16 scm_nStateOUTHYS = 4;

  void enterStateSTART(void);
  void enterStateINHYS(void);
  void enterStateINLIMITS(void);
  void enterStateOUTLIMITS(void);
  void enterStateOUTHYS(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_WaterSensor(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
              0, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_WaterSensor(){};

};

#endif //close the ifdef sequence from the beginning of the file

