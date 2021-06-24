/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Watch_WatchMode
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.2: 2003-12-04/JHC - Rockwell Automation - Renamed for better indexing.
 *************************************************************************/

#ifndef _WATCH_WATCHMODE_H_
#define _WATCH_WATCHMODE_H_

#include <basicfb.h>
#include <forte_bool.h>

class FORTE_Watch_WatchMode: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_Watch_WatchMode)

private:
  static const TEventID scm_nEventB1ID = 0;
  static const TEventID scm_nEventEnableID = 1;
  static const TEventID scm_nEventDisableID = 2;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventShow24hID = 0;
  static const TEventID scm_nEventShow12hID = 1;
  static const TEventID scm_nEventEnableNextID = 2;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const CStringDictionary::TStringId scm_anInternalsNames[];
  static const CStringDictionary::TStringId scm_anInternalsTypeIds[];
  CIEC_BOOL &AlarmOn() {
    return *static_cast<CIEC_BOOL*>(getVarInternal(0));
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(3, 0, 0, 1, 0);

virtual void setInitialValues();
  static const TForteInt16 scm_nStateDisabled = 0;
  static const TForteInt16 scm_nStateWatch24h = 1;
  static const TForteInt16 scm_nStateWatch12h = 2;
  static const TForteInt16 scm_nStateTriggerNext = 3;

  void enterStateDisabled(void);
  void enterStateWatch24h(void);
  void enterStateWatch12h(void);
  void enterStateTriggerNext(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_Watch_WatchMode(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_Watch_WatchMode(){};

};

#endif //close the ifdef sequence from the beginning of the file

