/*******************************************************************************
 * Copyright (c) 2006 - 2011 Profactor GmbH, ACIN
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *   Thomas Strasser, Alois Zoitl, Gerhard Ebenhofer, Ingo Hegny,
 *   - initial API and implementation and/or initial documentation
 *******************************************************************************/
#ifndef _UDINT2UDINT_H_
#define _UDINT2UDINT_H_

#include <funcbloc.h>
#include <forte_udint.h>


class UDINT2UDINT: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(UDINT2UDINT)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[], scm_aunDIDataTypeIds[];
  static const CStringDictionary::TStringId scm_anDataOutputNames[], scm_aunDODataTypeIds[];
  static const TEventID scm_nEventREQID = 0;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventCNFID = 0;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

  FORTE_FB_DATA_ARRAY(1,1,1, 0);

  virtual void executeEvent(int pa_nEIID);

  CIEC_UDINT& IN() {
  	return *static_cast<CIEC_UDINT*>(getDI(0));
  }

  CIEC_UDINT& OUT() {
  	return *static_cast<CIEC_UDINT*>(getDO(0));
  }


public:
  FUNCTION_BLOCK_CTOR(UDINT2UDINT) {};
  virtual ~UDINT2UDINT();

};

#endif //close the ifdef sequence from the beginning of the file

