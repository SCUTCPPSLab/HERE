/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: DistributingStation
 *** Description: Composite Function Block Type
 *** Version: 
 ***     0.2: 2003-12-05/JHC - Rockwell Automation - Renamed from NEWCOMPFB.
 *************************************************************************/

#ifndef _DISTRIBUTINGSTATION_H_
#define _DISTRIBUTINGSTATION_H_

#include <cfb.h>
#include <typelib.h>
#include <forte_bool.h>

class FORTE_DistributingStation: public CCompositeFB{
  DECLARE_FIRMWARE_FB(FORTE_DistributingStation)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &PusherBack() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };

  CIEC_BOOL &PusherFront() {
    return *static_cast<CIEC_BOOL*>(getDI(1));
  };

  CIEC_BOOL &ArmAtPickup() {
    return *static_cast<CIEC_BOOL*>(getDI(2));
  };

  CIEC_BOOL &ArmAtDropoff() {
    return *static_cast<CIEC_BOOL*>(getDI(3));
  };

  CIEC_BOOL &CylinderEmpty() {
    return *static_cast<CIEC_BOOL*>(getDI(4));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &PusherForward() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  CIEC_BOOL &ArmSUCKING() {
    return *static_cast<CIEC_BOOL*>(getDO(1));
  };

  CIEC_BOOL &ArmRELEASE() {
    return *static_cast<CIEC_BOOL*>(getDO(2));
  };

  CIEC_BOOL &ArmPICKINGUP() {
    return *static_cast<CIEC_BOOL*>(getDO(3));
  };

  CIEC_BOOL &ArmDROPPINGOFF() {
    return *static_cast<CIEC_BOOL*>(getDO(4));
  };

  static const TEventID scm_nEventInputsChangeID = 0;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventOutputsChangeID = 0;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(1, 5, 5, 0);

virtual void setInitialValues();

  static const SCFB_FBInstanceData scm_astInternalFBs[];

  static const SCFB_FBConnectionData scm_astEventConnections[];

  static const SCFB_FBFannedOutConnectionData scm_astFannedOutEventConnections[];

  static const SCFB_FBConnectionData scm_astDataConnections[];
  static const SCFB_FBNData scm_stFBNData;

public:
  COMPOSITE_FUNCTION_BLOCK_CTOR(FORTE_DistributingStation){
  };

  virtual ~FORTE_DistributingStation(){};

};

#endif //close the ifdef sequence from the beginning of the file

