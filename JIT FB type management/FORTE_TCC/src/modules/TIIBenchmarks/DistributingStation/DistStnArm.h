/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: DistStnArm
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.2: 2003-12-04/JHC - Rockwell Automation - Renamed for better indexing.
 *************************************************************************/

#ifndef _DISTSTNARM_H_
#define _DISTSTNARM_H_

#include <basicfb.h>
#include <forte_int.h>
#include <forte_bool.h>

class FORTE_DistStnArm: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_DistStnArm)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &PosReadyToSuck() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };

  CIEC_BOOL &PosReadyToDrop() {
    return *static_cast<CIEC_BOOL*>(getDI(1));
  };

  CIEC_BOOL &ItemNeedingPickup() {
    return *static_cast<CIEC_BOOL*>(getDI(2));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &ArmPICKINGUP() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  CIEC_BOOL &ArmDROPPINGOFF() {
    return *static_cast<CIEC_BOOL*>(getDO(1));
  };

  CIEC_BOOL &ArmSUCKING() {
    return *static_cast<CIEC_BOOL*>(getDO(2));
  };

  CIEC_BOOL &ArmRELEASE() {
    return *static_cast<CIEC_BOOL*>(getDO(3));
  };

  CIEC_BOOL &ArmClear() {
    return *static_cast<CIEC_BOOL*>(getDO(4));
  };

  static const TEventID scm_nEventPosChangeID = 0;
  static const TEventID scm_nEventItemStatusID = 1;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventArmCtrlID = 0;
  static const TEventID scm_nEventArmStatusID = 1;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const CStringDictionary::TStringId scm_anInternalsNames[];
  static const CStringDictionary::TStringId scm_anInternalsTypeIds[];
  CIEC_INT &ReleaseDelay() {
    return *static_cast<CIEC_INT*>(getVarInternal(0));
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(2, 3, 5, 1, 0);

virtual void setInitialValues();
  void alg_GoToDropOff(void);
  void alg_GoToPickup(void);
  void alg_PickupItem(void);
  void alg_DropItem(void);
  void alg_DoNothing(void);
  void alg_ReleaseWait(void);
  static const TForteInt16 scm_nStateWAITING = 0;
  static const TForteInt16 scm_nStateDROPPINGOFF = 1;
  static const TForteInt16 scm_nStateDROP = 2;
  static const TForteInt16 scm_nStatePICKINGUP = 3;
  static const TForteInt16 scm_nStateSUCK = 4;
  static const TForteInt16 scm_nStateReleaseWait = 5;

  void enterStateWAITING(void);
  void enterStateDROPPINGOFF(void);
  void enterStateDROP(void);
  void enterStatePICKINGUP(void);
  void enterStateSUCK(void);
  void enterStateReleaseWait(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_DistStnArm(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_DistStnArm(){};

};

#endif //close the ifdef sequence from the beginning of the file

