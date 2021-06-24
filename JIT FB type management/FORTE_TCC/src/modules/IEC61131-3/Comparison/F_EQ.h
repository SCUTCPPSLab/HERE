/*******************************************************************************
 * Copyright (c) 2011 - 2013 ACIN
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *   Monika Wenger, Alois Zoitl
 *   - initial API and implementation and/or initial documentation
 *******************************************************************************/
#ifndef _F_EQ_H_
#define _F_EQ_H_

#include <funcbloc.h>
#include <forte_any_elementary.h>
#include <forte_bool.h>

class FORTE_F_EQ : public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_F_EQ)

  private:
    static const CStringDictionary::TStringId scm_anDataInputNames[];
    static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
    CIEC_ANY_ELEMENTARY &IN1(){
      return *static_cast<CIEC_ANY_ELEMENTARY*>(getDI(0));
    }
    ;

    CIEC_ANY_ELEMENTARY &IN2(){
      return *static_cast<CIEC_ANY_ELEMENTARY*>(getDI(1));
    }
    ;

    static const CStringDictionary::TStringId scm_anDataOutputNames[];
    static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
    CIEC_BOOL &OUT(){
      return *static_cast<CIEC_BOOL*>(getDO(0));
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

    FORTE_FB_DATA_ARRAY(1, 2, 1, 0)
    ;

    void executeEvent(int pa_nEIID);

  public:
    FUNCTION_BLOCK_CTOR(FORTE_F_EQ){
  };

  template<typename T> void calculateValue(){
    T oIn1;
    T oIn2;

    oIn1.saveAssign(IN1());
    oIn2.saveAssign(IN2());

    OUT().saveAssign(EQ(oIn1, oIn2));
  }

  template<typename T> void calculateValueString() {
    calculateValue<CIEC_STRING>();
  }

  virtual ~FORTE_F_EQ(){};

};

#endif //close the ifdef sequence from the beginning of the file
