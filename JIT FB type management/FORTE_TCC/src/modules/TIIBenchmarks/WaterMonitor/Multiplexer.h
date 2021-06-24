/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Multiplexer
 *** Description: null
 *** Version: 
 ***     0.2: 2003-12-04/JHC - Rockwell Automation - Renamed for better indexing.
 ***     0.1: 2002-11-05/JHC - Rockwell Automation - Corrected missing ST element in Algorithm REQ.
 ***     0.0: 2000-05-30/JHC - Rockwell Automation - 
 *************************************************************************/

#ifndef _MULTIPLEXER_H_
#define _MULTIPLEXER_H_

#include <basicfb.h>

class FORTE_Multiplexer: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_Multiplexer)

private:
  static const TEventID scm_nEventstandbyID = 0;
  static const TEventID scm_nEventoperatingID = 1;
  static const TEventID scm_nEventshutdownID = 2;
  static const TEventID scm_nEventtestID = 3;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventtestTimerID = 0;
  static const TEventID scm_nEventshutdownTimerID = 1;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_BASIC_FB_DATA_ARRAY(2, 0, 0, 0, 0);
  static const TForteInt16 scm_nStateDONTCARE = 0;
  static const TForteInt16 scm_nStateSHUTDOWN = 1;
  static const TForteInt16 scm_nStateTEST = 2;

  void enterStateDONTCARE(void);
  void enterStateSHUTDOWN(void);
  void enterStateTEST(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_Multiplexer(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
              0, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_Multiplexer(){};

};

#endif //close the ifdef sequence from the beginning of the file

