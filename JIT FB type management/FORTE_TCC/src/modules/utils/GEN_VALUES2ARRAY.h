/*******************************************************************************
 * Copyright (c) 2014 Profactor GmbH, fortiss GmbH
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *   Matthias Plasch, Alois Zoitl
 *   - initial API and implementation and/or initial documentation
 *******************************************************************************/
#ifndef _GEN_VALUES2ARRAY_H_
#define _GEN_VALUES2ARRAY_H_

#include <funcbloc.h>
#include <forte_array.h>

class GEN_VALUES2ARRAY : public CFunctionBlock{
  DECLARE_GENERIC_FIRMWARE_FB(GEN_VALUES2ARRAY)

  private:
    CStringDictionary::TStringId *m_anDataInputNames;
    CStringDictionary::TStringId *m_anDataInputTypeIds;

    static const CStringDictionary::TStringId scm_anDataOutputNames[];
    CStringDictionary::TStringId *m_anDataOutputTypeIds;

    CIEC_ARRAY &OUT_Array(){
      return *static_cast<CIEC_ARRAY *>(getDO(0));
    }
    ;

    static const TEventID scm_nEventREQID = 0;
    static const TForteInt16 scm_anEIWithIndexes[];
    TDataIOID *m_anEIWith;
    static const CStringDictionary::TStringId scm_anEventInputNames[];

    static const TEventID scm_nEventCNFID = 0;
    static const TForteInt16 scm_anEOWithIndexes[];
    static const TDataIOID scm_anEOWith[];
    static const CStringDictionary::TStringId scm_anEventOutputNames[];

    //self-defined members
    unsigned int m_nDInputs;
    CStringDictionary::TStringId m_ValueTypeID;

    CStringDictionary::TStringId m_nConfiguredFBTypeNameId;
    virtual void executeEvent(int pa_nEIID);

    GEN_VALUES2ARRAY(const CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes);
    virtual ~GEN_VALUES2ARRAY();

  public:
    CStringDictionary::TStringId getFBTypeId(void) const{
      return m_nConfiguredFBTypeNameId;
    }

    bool configureFB(const char *pa_acConfigString);
};

#endif //close the ifdef sequence from the beginning of the file

