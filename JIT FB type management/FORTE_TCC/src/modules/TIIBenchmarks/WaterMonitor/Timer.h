/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Timer
 *** Description: null
 *** Version: 
 ***     0.2: 2003-12-04/JHC - Rockwell Automation - Renamed for better indexing.
 ***     0.1: 2002-11-05/JHC - Rockwell Automation - Corrected missing ST element in Algorithm REQ.
 ***     0.0: 2000-05-30/JHC - Rockwell Automation - 
 *************************************************************************/

#ifndef _TIMER_H_
#define _TIMER_H_

#include <basicfb.h>
#include <forte_uint.h>

class FORTE_Timer: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_Timer)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_UINT &timeout() {
    return *static_cast<CIEC_UINT*>(getDI(0));
  };

  static const TEventID scm_nEventmsID = 0;
  static const TEventID scm_nEventstartStopID = 1;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventtimedID = 0;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const CStringDictionary::TStringId scm_anInternalsNames[];
  static const CStringDictionary::TStringId scm_anInternalsTypeIds[];
  CIEC_UINT &count() {
    return *static_cast<CIEC_UINT*>(getVarInternal(0));
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(1, 1, 0, 1, 0);

virtual void setInitialValues();
  void alg_count(void);
  static const TForteInt16 scm_nStateSTOP = 0;
  static const TForteInt16 scm_nStateSTART = 1;
  static const TForteInt16 scm_nStateCOUNT = 2;
  static const TForteInt16 scm_nStateDONE = 3;

  void enterStateSTOP(void);
  void enterStateSTART(void);
  void enterStateCOUNT(void);
  void enterStateDONE(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_Timer(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_Timer(){};

};

#endif //close the ifdef sequence from the beginning of the file

