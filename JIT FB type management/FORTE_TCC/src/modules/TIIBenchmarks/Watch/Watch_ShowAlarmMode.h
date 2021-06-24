/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Watch_ShowAlarmMode
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.2: 2003-12-04/JHC - Rockwell Automation - Renamed for better indexing.
 *************************************************************************/

#ifndef _WATCH_SHOWALARMMODE_H_
#define _WATCH_SHOWALARMMODE_H_

#include <basicfb.h>
#include <forte_bool.h>

class FORTE_Watch_ShowAlarmMode: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_Watch_ShowAlarmMode)

private:
  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &AlarmOn() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  static const TEventID scm_nEventB1ID = 0;
  static const TEventID scm_nEventB2ID = 1;
  static const TEventID scm_nEventEnableID = 2;
  static const TEventID scm_nEventDisableID = 3;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventAlarmIndicatorID = 0;
  static const TEventID scm_nEventFlashHourID = 1;
  static const TEventID scm_nEventFlashMinuteID = 2;
  static const TEventID scm_nEventEnableNextID = 3;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_BASIC_FB_DATA_ARRAY(4, 0, 1, 0, 0);
  void alg_ToggleAlarm(void);
  void alg_IncHour(void);
  void alg_IncMinute(void);
  static const TForteInt16 scm_nStateDisabled = 0;
  static const TForteInt16 scm_nStateShowAlarm = 1;
  static const TForteInt16 scm_nStateSetHour = 2;
  static const TForteInt16 scm_nStateIncrHour = 3;
  static const TForteInt16 scm_nStateSetMinute = 4;
  static const TForteInt16 scm_nStateIncrMinute = 5;
  static const TForteInt16 scm_nStateToggle = 6;
  static const TForteInt16 scm_nStateTriggerNext = 7;

  void enterStateDisabled(void);
  void enterStateShowAlarm(void);
  void enterStateSetHour(void);
  void enterStateIncrHour(void);
  void enterStateSetMinute(void);
  void enterStateIncrMinute(void);
  void enterStateToggle(void);
  void enterStateTriggerNext(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_Watch_ShowAlarmMode(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
              0, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_Watch_ShowAlarmMode(){};

};

#endif //close the ifdef sequence from the beginning of the file

