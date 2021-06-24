/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: MP3PLAYER_BUFFER
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.2: 2003-12-04/JHC - Rockwell Automation - Renamed for better indexing.
 *************************************************************************/

#ifndef _MP3PLAYER_BUFFER_H_
#define _MP3PLAYER_BUFFER_H_

#include <basicfb.h>
#include <forte_int.h>
#include <forte_bool.h>
#include <forte_array.h>

class FORTE_MP3PLAYER_BUFFER: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_MP3PLAYER_BUFFER)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_INT &DataToWrite() {
    return *static_cast<CIEC_INT*>(getDI(0));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &BufferFull() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  CIEC_BOOL &BufferEmpty() {
    return *static_cast<CIEC_BOOL*>(getDO(1));
  };

  CIEC_INT &ReadData() {
    return *static_cast<CIEC_INT*>(getDO(2));
  };

  static const TEventID scm_nEventWriteID = 0;
  static const TEventID scm_nEventReadID = 1;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventDataOutID = 0;
  static const TEventID scm_nEventBufferChangeID = 1;
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

  CIEC_INT *Buffer() {
    return (CIEC_INT*)(*static_cast<CIEC_ARRAY *>(getVarInternal(3)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &Buffer_Array() {
    return *static_cast<CIEC_ARRAY*>(getVarInternal(3));
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(2, 1, 3, 4, 0);

virtual void setInitialValues();
  void alg_WRITE(void);
  void alg_READ(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateWRITE = 1;
  static const TForteInt16 scm_nStateREAD = 2;

  void enterStateSTART(void);
  void enterStateWRITE(void);
  void enterStateREAD(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_MP3PLAYER_BUFFER(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_MP3PLAYER_BUFFER(){};

};

#endif //close the ifdef sequence from the beginning of the file

