/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: MP3PLAYER_PLAYERECC
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.2: 2003-12-04/JHC - Rockwell Automation - Renamed for better indexing.
 *************************************************************************/

#ifndef _MP3PLAYER_PLAYERECC_H_
#define _MP3PLAYER_PLAYERECC_H_

#include <basicfb.h>
#include <forte_int.h>

class FORTE_MP3PLAYER_PLAYERECC: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_MP3PLAYER_PLAYERECC)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_INT &DecodedData() {
    return *static_cast<CIEC_INT*>(getDI(0));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_INT &AudioData() {
    return *static_cast<CIEC_INT*>(getDO(0));
  };

  static const TEventID scm_nEventPLAYID = 0;
  static const TEventID scm_nEventSTOPID = 1;
  static const TEventID scm_nEventPAUSEID = 2;
  static const TEventID scm_nEventIncomingDataID = 3;
  static const TEventID scm_nEventDataAvailableID = 4;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventGetDataID = 0;
  static const TEventID scm_nEventAUDIOID = 1;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_BASIC_FB_DATA_ARRAY(2, 1, 1, 0, 0);
  void alg_PLAYAUDIO(void);
  static const TForteInt16 scm_nStateSTOPPED = 0;
  static const TForteInt16 scm_nStateWAIT = 1;
  static const TForteInt16 scm_nStatePLAY = 2;
  static const TForteInt16 scm_nStatePAUSE = 3;

  void enterStateSTOPPED(void);
  void enterStateWAIT(void);
  void enterStatePLAY(void);
  void enterStatePAUSE(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_MP3PLAYER_PLAYERECC(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
              0, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_MP3PLAYER_PLAYERECC(){};

};

#endif //close the ifdef sequence from the beginning of the file

