/*******************************************************************************
 * Copyright (c) 2013 ACIN
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *   Monika Wenger
 *   - initial API and implementation and/or initial documentation
 *******************************************************************************/

#ifndef _F_DT_TO_TOD_H_
#define _F_DT_TO_TOD_H_

#include <funcbloc.h>
#include <forte_date_and_time.h>
#include <forte_time_of_day.h>

class FORTE_F_DT_TO_TOD: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_F_DT_TO_TOD)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_DATE_AND_TIME &IN() {
    return *static_cast<CIEC_DATE_AND_TIME*>(getDI(0));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_TIME_OF_DAY &OUT() {
    return *static_cast<CIEC_TIME_OF_DAY*>(getDO(0));
  };

  static const TEventID scm_nEventREQID = 0;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventCNFID = 0;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(1, 1, 1, 0);

  void executeEvent(int pa_nEIID);

public:
  FUNCTION_BLOCK_CTOR(FORTE_F_DT_TO_TOD){
  };

  virtual ~FORTE_F_DT_TO_TOD(){};

};

#endif //close the ifdef sequence from the beginning of the file

