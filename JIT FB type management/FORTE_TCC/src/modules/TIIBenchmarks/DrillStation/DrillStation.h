/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: DrillStation
 *** Description: null
 *** Version: 
 ***     0.2: 2003-12-05/JHC - Rockwell Automation - Renamed from NEWCOMPFB.
 ***     0.1: 2002-01-08/JHC - Rockwell Automation - Added DLY FB as example.
 ***     0.0: 2000-05-27/JHC - Rockwell Automation - 
 *************************************************************************/

#ifndef _DRILLSTATION_H_
#define _DRILLSTATION_H_

#include <cfb.h>
#include <typelib.h>
#include <forte_bool.h>

class FORTE_DrillStation: public CCompositeFB{
  DECLARE_FIRMWARE_FB(FORTE_DrillStation)

private:
  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &SliderOpenClose() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventREQID = 1;
  static const TEventID scm_nEventSlideTimeID = 2;
  static const TEventID scm_nEventDrillMoveID = 3;
  static const TEventID scm_nEventDrillDoneID = 4;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventSliderStatusID = 0;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(1, 0, 1, 0);

  static const SCFB_FBInstanceData scm_astInternalFBs[];

  static const SCFB_FBConnectionData scm_astEventConnections[];

  static const SCFB_FBConnectionData scm_astDataConnections[];
  static const SCFB_FBNData scm_stFBNData;

public:
  COMPOSITE_FUNCTION_BLOCK_CTOR(FORTE_DrillStation){
  };

  virtual ~FORTE_DrillStation(){};

};

#endif //close the ifdef sequence from the beginning of the file

