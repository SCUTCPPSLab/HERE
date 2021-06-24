/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Mp3Player_FBDKTestBench
 *** Description: Composite Function Block Type
 *** Version: 
 ***     0.2: 2003-12-05/JHC - Rockwell Automation - Renamed from NEWCOMPFB.
 ***     0.1: 2002-01-08/JHC - Rockwell Automation - Added DLY FB as example.
 ***     0.0: 2000-05-27/JHC - Rockwell Automation - 
 *************************************************************************/

#ifndef _MP3PLAYER_FBDKTESTBENCH_H_
#define _MP3PLAYER_FBDKTESTBENCH_H_

#include <cfb.h>
#include <typelib.h>

class FORTE_Mp3Player_FBDKTestBench: public CCompositeFB{
  DECLARE_FIRMWARE_FB(FORTE_Mp3Player_FBDKTestBench)

private:
  static const TEventID scm_nEventINITID = 0;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TForteInt16 scm_anEOWithIndexes[];
  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(0, 0, 0, 0);

  static const SCFB_FBInstanceData scm_astInternalFBs[];

  static const SCFB_FBConnectionData scm_astEventConnections[];
  static const SCFB_FBNData scm_stFBNData;

public:
  COMPOSITE_FUNCTION_BLOCK_CTOR(FORTE_Mp3Player_FBDKTestBench){
  };

  virtual ~FORTE_Mp3Player_FBDKTestBench(){};

};

#endif //close the ifdef sequence from the beginning of the file

