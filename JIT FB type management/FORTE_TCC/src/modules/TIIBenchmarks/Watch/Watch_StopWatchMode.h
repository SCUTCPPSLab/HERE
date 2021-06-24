/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Watch_StopWatchMode
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.2: 2003-12-04/JHC - Rockwell Automation - Renamed for better indexing.
 *************************************************************************/

#ifndef _WATCH_STOPWATCHMODE_H_
#define _WATCH_STOPWATCHMODE_H_

#include <basicfb.h>
#include <forte_bool.h>

class FORTE_Watch_StopWatchMode: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_Watch_StopWatchMode)

private:
  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &sASms() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  static const TEventID scm_nEventB1ID = 0;
  static const TEventID scm_nEventB2ID = 1;
  static const TEventID scm_nEventEnableID = 2;
  static const TEventID scm_nEventDisableID = 3;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventShowTimerID = 0;
  static const TEventID scm_nEventEnableNextID = 1;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const CStringDictionary::TStringId scm_anInternalsNames[];
  static const CStringDictionary::TStringId scm_anInternalsTypeIds[];
  CIEC_BOOL &AlarmOn() {
    return *static_cast<CIEC_BOOL*>(getVarInternal(0));
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(2, 0, 1, 1, 0);

virtual void setInitialValues();
  void alg_ToggleTimer(void);
  void alg_ResetTimer(void);
  void alg_ToggleUseSasMS(void);
  static const TForteInt16 scm_nStateDisabled = 0;
  static const TForteInt16 scm_nStateStopWatch = 1;
  static const TForteInt16 scm_nStateToggle = 2;
  static const TForteInt16 scm_nStateReset = 3;
  static const TForteInt16 scm_nStateTriggerNext = 4;

  void enterStateDisabled(void);
  void enterStateStopWatch(void);
  void enterStateToggle(void);
  void enterStateReset(void);
  void enterStateTriggerNext(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_Watch_StopWatchMode(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_Watch_StopWatchMode(){};

};

#endif //close the ifdef sequence from the beginning of the file

