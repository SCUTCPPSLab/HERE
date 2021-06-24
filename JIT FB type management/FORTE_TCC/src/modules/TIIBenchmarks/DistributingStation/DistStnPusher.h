/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: DistStnPusher
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.2: 2003-12-04/JHC - Rockwell Automation - Renamed for better indexing.
 *************************************************************************/

#ifndef _DISTSTNPUSHER_H_
#define _DISTSTNPUSHER_H_

#include <basicfb.h>
#include <forte_int.h>
#include <forte_bool.h>

class FORTE_DistStnPusher: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_DistStnPusher)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &PosBack() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };

  CIEC_BOOL &PosFront() {
    return *static_cast<CIEC_BOOL*>(getDI(1));
  };

  CIEC_BOOL &CylinderEmpty() {
    return *static_cast<CIEC_BOOL*>(getDI(2));
  };

  CIEC_BOOL &ArmClear() {
    return *static_cast<CIEC_BOOL*>(getDI(3));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &PusherForward() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  CIEC_BOOL &ItemPresent() {
    return *static_cast<CIEC_BOOL*>(getDO(1));
  };

  static const TEventID scm_nEventPosChangeID = 0;
  static const TEventID scm_nEventArmStatusChangeID = 1;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventPusherCtrlID = 0;
  static const TEventID scm_nEventItemStatusID = 1;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const CStringDictionary::TStringId scm_anInternalsNames[];
  static const CStringDictionary::TStringId scm_anInternalsTypeIds[];
  CIEC_INT &TimeoutCount() {
    return *static_cast<CIEC_INT*>(getVarInternal(0));
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(2, 4, 2, 1, 0);

virtual void setInitialValues();
  void alg_GoBack(void);
  void alg_GoForward(void);
  void alg_ItemPushedForward(void);
  static const TForteInt16 scm_nStateBACK = 0;
  static const TForteInt16 scm_nStateGOINGBACK = 1;
  static const TForteInt16 scm_nStateGOINGFORWARD = 2;
  static const TForteInt16 scm_nStateFRONT = 3;

  void enterStateBACK(void);
  void enterStateGOINGBACK(void);
  void enterStateGOINGFORWARD(void);
  void enterStateFRONT(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_DistStnPusher(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_DistStnPusher(){};

};

#endif //close the ifdef sequence from the beginning of the file

