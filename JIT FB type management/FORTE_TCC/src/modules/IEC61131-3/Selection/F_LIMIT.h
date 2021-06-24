/*******************************************************************************
 * Copyright (c) 2011 - 2013 ACIN, Profactor GmbH
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *   Monika Wenger, Alois Zoitl, Matthias Plasch, Gerhard Ebenhofer
 *   - initial API and implementation and/or initial documentation
 *******************************************************************************/
#ifndef _F_LIMIT_H_
#define _F_LIMIT_H_

#include <funcbloc.h>
#include <forte_any_elementary.h>

class FORTE_F_LIMIT : public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_F_LIMIT)

  private:
    static const CStringDictionary::TStringId scm_anDataInputNames[];
    static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
    CIEC_ANY_ELEMENTARY &MN(){
      return *static_cast<CIEC_ANY_ELEMENTARY*>(getDI(0));
    }
    ;

    CIEC_ANY_ELEMENTARY &IN(){
      return *static_cast<CIEC_ANY_ELEMENTARY*>(getDI(1));
    }
    ;

    CIEC_ANY_ELEMENTARY &MX(){
      return *static_cast<CIEC_ANY_ELEMENTARY*>(getDI(2));
    }
    ;

    static const CStringDictionary::TStringId scm_anDataOutputNames[];
    static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
    CIEC_ANY_ELEMENTARY &OUT(){
      return *static_cast<CIEC_ANY_ELEMENTARY*>(getDO(0));
    }
    ;

    static const TEventID scm_nEventREQID = 0;
    static const TForteInt16 scm_anEIWithIndexes[];
    static const TDataIOID scm_anEIWith[];
    static const CStringDictionary::TStringId scm_anEventInputNames[];

    static const TEventID scm_nEventCNFID = 0;
    static const TForteInt16 scm_anEOWithIndexes[];
    static const TDataIOID scm_anEOWith[];
    static const CStringDictionary::TStringId scm_anEventOutputNames[];

    static const SFBInterfaceSpec scm_stFBInterfaceSpec;

    FORTE_FB_DATA_ARRAY(1, 3, 1, 0)
    ;

    void executeEvent(int pa_nEIID);

  public:
    FUNCTION_BLOCK_CTOR(FORTE_F_LIMIT){
  };

  template<typename T> void calculateValue(){
    T oMin;
    T oMax;

    oMin.saveAssign(MN());
    oMax.saveAssign(MX());

    OUT().saveAssign(LIMIT<T> (oMin, static_cast<T &> (IN()), oMax));
  }

  template<typename T> void calculateValueString(){
    //TODO fill this function
  }
  virtual ~FORTE_F_LIMIT(){};
};

#endif //close the ifdef sequence from the beginning of the file
