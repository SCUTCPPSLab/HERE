/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Slider
 *** Description: Slider for the drill
 *** Version: 
 ***     0.2: 2003-12-04/JHC - Rockwell Automation - Renamed for better indexing.
 ***     0.1: 2002-11-05/JHC - Rockwell Automation - Corrected missing ST element in Algorithm REQ.
 ***     0.0: 2000-05-30/JHC - Rockwell Automation - 
 *************************************************************************/

#ifndef _SLIDER_H_
#define _SLIDER_H_

#include <basicfb.h>
#include <forte_bool.h>

class FORTE_Slider: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_Slider)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &ReadyNot() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &OpenClose() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  static const TEventID scm_nEventREQID = 0;
  static const TEventID scm_nEventSlideTimeID = 1;
  static const TEventID scm_nEventFinishDrillID = 2;
  static const TEventID scm_nEventDrillStatID = 3;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventStatusID = 0;
  static const TEventID scm_nEventInPlaceID = 1;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_BASIC_FB_DATA_ARRAY(2, 1, 1, 0, 0);

virtual void setInitialValues();
  void alg_INIT(void);
  void alg_REQ(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateREQ = 1;
  static const TForteInt16 scm_nStateDrilling = 2;
  static const TForteInt16 scm_nStateReturnSlide = 3;
  static const TForteInt16 scm_nStateWaitForDrill = 4;

  void enterStateSTART(void);
  void enterStateREQ(void);
  void enterStateDrilling(void);
  void enterStateReturnSlide(void);
  void enterStateWaitForDrill(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_Slider(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
              0, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_Slider(){};

};

#endif //close the ifdef sequence from the beginning of the file

