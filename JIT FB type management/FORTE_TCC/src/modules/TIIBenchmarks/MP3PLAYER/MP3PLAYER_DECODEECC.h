/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: MP3PLAYER_DECODEECC
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.2: 2003-12-04/JHC - Rockwell Automation - Renamed for better indexing.
 *************************************************************************/

#ifndef _MP3PLAYER_DECODEECC_H_
#define _MP3PLAYER_DECODEECC_H_

#include <basicfb.h>
#include <forte_int.h>
#include <forte_bool.h>

class FORTE_MP3PLAYER_DECODEECC: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_MP3PLAYER_DECODEECC)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &BufferFull() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_INT &DataToWrite() {
    return *static_cast<CIEC_INT*>(getDO(0));
  };

  static const TEventID scm_nEventPLAYID = 0;
  static const TEventID scm_nEventSTOPID = 1;
  static const TEventID scm_nEventPAUSEID = 2;
  static const TEventID scm_nEventBufferChangeID = 3;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventWriteOutID = 0;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const CStringDictionary::TStringId scm_anInternalsNames[];
  static const CStringDictionary::TStringId scm_anInternalsTypeIds[];
  CIEC_INT &BufferTail() {
    return *static_cast<CIEC_INT*>(getVarInternal(0));
  };

  CIEC_INT &BufferHead() {
    return *static_cast<CIEC_INT*>(getVarInternal(1));
  };

  CIEC_INT &BufferSize() {
    return *static_cast<CIEC_INT*>(getVarInternal(2));
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(1, 1, 1, 3, 0);

virtual void setInitialValues();
  void alg_DECODE(void);
  static const TForteInt16 scm_nStateSTOP = 0;
  static const TForteInt16 scm_nStatePLAY = 1;
  static const TForteInt16 scm_nStateDECODE_AND_BUFFER = 2;

  void enterStateSTOP(void);
  void enterStatePLAY(void);
  void enterStateDECODE_AND_BUFFER(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_MP3PLAYER_DECODEECC(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_MP3PLAYER_DECODEECC(){};

};

#endif //close the ifdef sequence from the beginning of the file

