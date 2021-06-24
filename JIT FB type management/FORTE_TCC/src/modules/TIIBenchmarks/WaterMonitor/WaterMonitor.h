/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: WaterMonitor
 *** Description: null
 *** Version: 
 ***     0.2: 2003-12-05/JHC - Rockwell Automation - Renamed from NEWCOMPFB.
 *************************************************************************/

#ifndef _WATERMONITOR_H_
#define _WATERMONITOR_H_

#include <cfb.h>
#include <typelib.h>
#include <forte_usint.h>
#include <forte_bool.h>

class FORTE_WaterMonitor: public CCompositeFB{
  DECLARE_FIRMWARE_FB(FORTE_WaterMonitor)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_USINT &waterLevel() {
    return *static_cast<CIEC_USINT*>(getDI(0));
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
  static const TEventID scm_nEventtstButtonID = 1;
  static const TEventID scm_nEventresetButtonID = 2;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventstandbyID = 0;
  static const TEventID scm_nEventoperatingID = 1;
  static const TEventID scm_nEventshutdownID = 2;
  static const TEventID scm_nEventtestID = 3;
  static const TEventID scm_nEventslfTstIntervalID = 4;
  static const TEventID scm_nEventreset1ID = 5;
  static const TEventID scm_nEventtstIntervalID = 6;
  static const TEventID scm_nEventshutdownLockID = 7;
  static const TEventID scm_nEventrangeID = 8;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(9, 1, 2, 0);

  static const SCFB_FBInstanceData scm_astInternalFBs[];

  static const SCFB_FBParameter scm_astParamters[];

  static const SCFB_FBConnectionData scm_astEventConnections[];

  static const SCFB_FBFannedOutConnectionData scm_astFannedOutEventConnections[];

  static const SCFB_FBConnectionData scm_astDataConnections[];

  static const SCFB_FBFannedOutConnectionData scm_astFannedOutDataConnections[];
  static const SCFB_FBNData scm_stFBNData;

public:
  COMPOSITE_FUNCTION_BLOCK_CTOR(FORTE_WaterMonitor){
  };

  virtual ~FORTE_WaterMonitor(){};

};

#endif //close the ifdef sequence from the beginning of the file

