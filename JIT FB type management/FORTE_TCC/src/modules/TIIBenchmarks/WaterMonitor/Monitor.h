/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Monitor
 *** Description: null
 *** Version: 
 ***     0.2: 2003-12-04/JHC - Rockwell Automation - Renamed for better indexing.
 ***     0.1: 2002-11-05/JHC - Rockwell Automation - Corrected missing ST element in Algorithm REQ.
 ***     0.0: 2000-05-30/JHC - Rockwell Automation - 
 *************************************************************************/

#ifndef _MONITOR_H_
#define _MONITOR_H_

#include <basicfb.h>
#include <forte_bool.h>

class FORTE_Monitor: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_Monitor)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &withinLimits() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };

  CIEC_BOOL &withinHys() {
    return *static_cast<CIEC_BOOL*>(getDI(1));
  };

  static const TEventID scm_nEventslfTstIntervalID = 0;
  static const TEventID scm_nEventreset1ID = 1;
  static const TEventID scm_nEventtstIntervalID = 2;
  static const TEventID scm_nEventshutdownLockID = 3;
  static const TEventID scm_nEventrangeID = 4;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventstandbyID = 0;
  static const TEventID scm_nEventoperatingID = 1;
  static const TEventID scm_nEventshutdownID = 2;
  static const TEventID scm_nEventtestID = 3;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_BASIC_FB_DATA_ARRAY(4, 2, 0, 0, 0);

virtual void setInitialValues();
  static const TForteInt16 scm_nStateSTANDBY = 0;
  static const TForteInt16 scm_nStateSHUTDOWN = 1;
  static const TForteInt16 scm_nStateOPERATING = 2;
  static const TForteInt16 scm_nStateTEST = 3;

  void enterStateSTANDBY(void);
  void enterStateSHUTDOWN(void);
  void enterStateOPERATING(void);
  void enterStateTEST(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_Monitor(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
              0, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_Monitor(){};

};

#endif //close the ifdef sequence from the beginning of the file

