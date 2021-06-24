/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: MP3PLAYER_DISPLAYECC
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.2: 2003-12-04/JHC - Rockwell Automation - Renamed for better indexing.
 *************************************************************************/

#ifndef _MP3PLAYER_DISPLAYECC_H_
#define _MP3PLAYER_DISPLAYECC_H_

#include <basicfb.h>

class FORTE_MP3PLAYER_DISPLAYECC: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_MP3PLAYER_DISPLAYECC)

private:
  static const TEventID scm_nEventPLAYID = 0;
  static const TEventID scm_nEventSTOPID = 1;
  static const TEventID scm_nEventPAUSEID = 2;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventSHOWDEFAULTID = 0;
  static const TEventID scm_nEventSHOWPLAYID = 1;
  static const TEventID scm_nEventSHOWPAUSEID = 2;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_BASIC_FB_DATA_ARRAY(3, 0, 0, 0, 0);
  static const TForteInt16 scm_nStateDEFAULT = 0;
  static const TForteInt16 scm_nStatePLAYING = 1;
  static const TForteInt16 scm_nStatePAUSED = 2;
  static const TForteInt16 scm_nStateDEFAUL = 3;

  void enterStateDEFAULT(void);
  void enterStatePLAYING(void);
  void enterStatePAUSED(void);
  void enterStateDEFAUL(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_MP3PLAYER_DISPLAYECC(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
              0, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_MP3PLAYER_DISPLAYECC(){};

};

#endif //close the ifdef sequence from the beginning of the file

