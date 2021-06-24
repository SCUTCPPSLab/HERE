/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: MP3Player_WithECC
 *** Description: Composite Function Block Type
 *** Version: 
 ***     0.2: 2003-12-05/JHC - Rockwell Automation - Renamed from NEWCOMPFB.
 *************************************************************************/

#ifndef _MP3PLAYER_WITHECC_H_
#define _MP3PLAYER_WITHECC_H_

#include <cfb.h>
#include <typelib.h>
#include <forte_int.h>

class FORTE_MP3Player_WithECC: public CCompositeFB{
  DECLARE_FIRMWARE_FB(FORTE_MP3Player_WithECC)

private:
  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_INT &AudioData() {
    return *static_cast<CIEC_INT*>(getDO(0));
  };

  static const TEventID scm_nEventPLAYID = 0;
  static const TEventID scm_nEventSTOPID = 1;
  static const TEventID scm_nEventPAUSEID = 2;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventSHOWDEFAULTID = 0;
  static const TEventID scm_nEventSHOWPLAYID = 1;
  static const TEventID scm_nEventSHOWPAUSEID = 2;
  static const TEventID scm_nEventAUDIOID = 3;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(4, 0, 1, 0);

  static const SCFB_FBInstanceData scm_astInternalFBs[];

  static const SCFB_FBConnectionData scm_astEventConnections[];

  static const SCFB_FBFannedOutConnectionData scm_astFannedOutEventConnections[];

  static const SCFB_FBConnectionData scm_astDataConnections[];
  static const SCFB_FBNData scm_stFBNData;

public:
  COMPOSITE_FUNCTION_BLOCK_CTOR(FORTE_MP3Player_WithECC){
  };

  virtual ~FORTE_MP3Player_WithECC(){};

};

#endif //close the ifdef sequence from the beginning of the file

