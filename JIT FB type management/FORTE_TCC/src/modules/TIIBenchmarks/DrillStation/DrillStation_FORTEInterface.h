/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: DrillStation_FORTEInterface
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.2: 2003-12-04/JHC - Rockwell Automation - Renamed for better indexing.
 ***     0.1: 2002-11-05/JHC - Rockwell Automation - Corrected missing ST element in Algorithm REQ.
 ***     0.0: 2000-05-30/JHC - Rockwell Automation - 
 *************************************************************************/

#ifndef _DRILLSTATION_FORTEINTERFACE_H_
#define _DRILLSTATION_FORTEINTERFACE_H_

#include <basicfb.h>
#include "../BenchmarkTimer/BenchmarkTimer.h"

class FORTE_DrillStation_FORTEInterface: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_DrillStation_FORTEInterface)

private:
  static const TEventID scm_nEventTestID = 0;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventREQID = 1;
  static const TEventID scm_nEventSlideTimeID = 2;
  static const TEventID scm_nEventDrillMoveID = 3;
  static const TEventID scm_nEventDrillDoneID = 4;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;
  FILE* vectorFile;
  bool inited=false;
  BenchmarkTimer timer;

   FORTE_BASIC_FB_DATA_ARRAY(5, 0, 0, 0, 0);
  void alg_REQ(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateREQ = 1;

  void enterStateSTART(void);
  void enterStateREQ(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_DrillStation_FORTEInterface(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
              0, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_DrillStation_FORTEInterface(){};

};

#endif //close the ifdef sequence from the beginning of the file

