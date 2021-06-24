/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Activate
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.2: 2003-12-04/JHC - Rockwell Automation - Renamed for better indexing.
 ***     0.1: 2002-11-05/JHC - Rockwell Automation - Corrected missing ST element in Algorithm REQ.
 ***     0.0: 2000-05-30/JHC - Rockwell Automation - 
 *************************************************************************/

#ifndef _ACTIVATE_H_
#define _ACTIVATE_H_

#include <basicfb.h>
#include <forte_int.h>

class FORTE_Activate: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_Activate)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_INT &speedVal() {
    return *static_cast<CIEC_INT*>(getDI(0));
  };

  static const TEventID scm_nEventregulSetID = 0;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventviolatedID = 0;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_BASIC_FB_DATA_ARRAY(1, 1, 0, 0, 0);
  void alg_INIT(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateINIT = 1;

  void enterStateSTART(void);
  void enterStateINIT(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_Activate(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
              0, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_Activate(){};

};

#endif //close the ifdef sequence from the beginning of the file

