/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: CruiseControl
 *** Description: null
 *** Version: 
 ***     0.2: 2003-12-05/JHC - Rockwell Automation - Renamed from NEWCOMPFB.
 ***     0.1: 2002-01-08/JHC - Rockwell Automation - Added DLY FB as example.
 ***     0.0: 2000-05-27/JHC - Rockwell Automation - 
 *************************************************************************/

#ifndef _CRUISECONTROL_H_
#define _CRUISECONTROL_H_

#include <cfb.h>
#include <typelib.h>
#include <forte_int.h>
#include <forte_sint.h>
#include <forte_udint.h>
#include <forte_uint.h>

class FORTE_CruiseControl: public CCompositeFB{
  DECLARE_FIRMWARE_FB(FORTE_CruiseControl)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_UDINT &time() {
    return *static_cast<CIEC_UDINT*>(getDI(0));
  };

  CIEC_UINT &rotaryCount() {
    return *static_cast<CIEC_UINT*>(getDI(1));
  };

  CIEC_SINT &throttleOffset() {
    return *static_cast<CIEC_SINT*>(getDI(2));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_INT &speedVal() {
    return *static_cast<CIEC_INT*>(getDO(0));
  };

  CIEC_INT &cruiseSpeed() {
    return *static_cast<CIEC_INT*>(getDO(1));
  };

  CIEC_SINT &throttleVal() {
    return *static_cast<CIEC_SINT*>(getDO(2));
  };

  static const TEventID scm_nEventcclockID = 0;
  static const TEventID scm_nEventsetID = 1;
  static const TEventID scm_nEventoffID = 2;
  static const TEventID scm_nEventresumeID = 3;
  static const TEventID scm_nEventquickAccelID = 4;
  static const TEventID scm_nEventquickDecelID = 5;
  static const TEventID scm_nEventbrakePressedID = 6;
  static const TEventID scm_nEventaccelPressedID = 7;
  static const TEventID scm_nEventaccelReleasedID = 8;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventspeedID = 0;
  static const TEventID scm_nEventspeedSetID = 1;
  static const TEventID scm_nEventthrottleChgID = 2;
  static const TEventID scm_nEventregulOffID = 3;
  static const TEventID scm_nEventregulStdbyID = 4;
  static const TEventID scm_nEventregulSetID = 5;
  static const TEventID scm_nEventregulResumeID = 6;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(7, 3, 3, 0);

  static const SCFB_FBInstanceData scm_astInternalFBs[];

  static const SCFB_FBConnectionData scm_astEventConnections[];

  static const SCFB_FBFannedOutConnectionData scm_astFannedOutEventConnections[];

  static const SCFB_FBConnectionData scm_astDataConnections[];

  static const SCFB_FBFannedOutConnectionData scm_astFannedOutDataConnections[];
  static const SCFB_FBNData scm_stFBNData;

public:
  COMPOSITE_FUNCTION_BLOCK_CTOR(FORTE_CruiseControl){
  };

  virtual ~FORTE_CruiseControl(){};

};

#endif //close the ifdef sequence from the beginning of the file

