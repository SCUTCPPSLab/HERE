/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: DistributingStation_FORTEInterface
 *** Description: Basic Function Block Type
 *** Version: 
 ***     0.2: 2003-12-04/JHC - Rockwell Automation - Renamed for better indexing.
 ***     0.1: 2002-11-05/JHC - Rockwell Automation - Corrected missing ST element in Algorithm REQ.
 ***     0.0: 2000-05-30/JHC - Rockwell Automation - 
 *************************************************************************/

#ifndef _DISTRIBUTINGSTATION_FORTEINTERFACE_H_
#define _DISTRIBUTINGSTATION_FORTEINTERFACE_H_

#include <basicfb.h>
#include <forte_bool.h>
#include "../BenchmarkTimer/BenchmarkTimer.h"

class FORTE_DistributingStation_FORTEInterface: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_DistributingStation_FORTEInterface)

private:
  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &PusherBack() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  CIEC_BOOL &PusherFront() {
    return *static_cast<CIEC_BOOL*>(getDO(1));
  };

  CIEC_BOOL &ArmAtPickup() {
    return *static_cast<CIEC_BOOL*>(getDO(2));
  };

  CIEC_BOOL &ArmAtDropoff() {
    return *static_cast<CIEC_BOOL*>(getDO(3));
  };

  CIEC_BOOL &CylinderEmpty() {
    return *static_cast<CIEC_BOOL*>(getDO(4));
  };

  static const TEventID scm_nEventREQID = 0;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventInputsChangeID = 0;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;
  FILE* vectorFile;
  bool inited=false;
  BenchmarkTimer timer;
   FORTE_BASIC_FB_DATA_ARRAY(1, 0, 5, 0, 0);
  void alg_REQ(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateREQ = 1;

  void enterStateSTART(void);
  void enterStateREQ(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_DistributingStation_FORTEInterface(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
              0, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_DistributingStation_FORTEInterface(){};

};

#endif //close the ifdef sequence from the beginning of the file

