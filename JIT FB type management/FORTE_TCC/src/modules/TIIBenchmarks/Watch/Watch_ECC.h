/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Watch_ECC
 *** Description: Composite Function Block Type
 *** Version: 
 ***     0.2: 2003-12-05/JHC - Rockwell Automation - Renamed from NEWCOMPFB.
 *************************************************************************/

#ifndef _WATCH_ECC_H_
#define _WATCH_ECC_H_

#include <cfb.h>
#include <typelib.h>
#include <forte_dint.h>
#include <forte_bool.h>

class FORTE_Watch_ECC: public CCompositeFB{
  DECLARE_FIRMWARE_FB(FORTE_Watch_ECC)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_DINT &CurrentTime() {
    return *static_cast<CIEC_DINT*>(getDI(0));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &AlarmOn() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  CIEC_BOOL &sASms() {
    return *static_cast<CIEC_BOOL*>(getDO(1));
  };

  static const TEventID scm_nEventInitID = 0;
  static const TEventID scm_nEventTimeChangeID = 1;
  static const TEventID scm_nEventB1ID = 2;
  static const TEventID scm_nEventB2ID = 3;
  static const TEventID scm_nEventB3ID = 4;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventAlarmIndicatorID = 0;
  static const TEventID scm_nEventShow24hID = 1;
  static const TEventID scm_nEventShow12hID = 2;
  static const TEventID scm_nEventShowTimerID = 3;
  static const TEventID scm_nEventFlashHourID = 4;
  static const TEventID scm_nEventFlashMinuteID = 5;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(6, 1, 2, 0);

virtual void setInitialValues();

  static const SCFB_FBInstanceData scm_astInternalFBs[];

  static const SCFB_FBConnectionData scm_astEventConnections[];

  static const SCFB_FBFannedOutConnectionData scm_astFannedOutEventConnections[];

  static const SCFB_FBConnectionData scm_astDataConnections[];
  static const SCFB_FBNData scm_stFBNData;

public:
  COMPOSITE_FUNCTION_BLOCK_CTOR(FORTE_Watch_ECC){
  };

  virtual ~FORTE_Watch_ECC(){};

};

#endif //close the ifdef sequence from the beginning of the file

