/*******************************************************************************
 * Copyright (c) 2006 - 2015 ACIN, Profactor GmbH, fortiss GmbH
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *   Alois Zoitl, Thomas Strasser
 *    - initial API and implementation and/or initial documentation
 *******************************************************************************/
#ifndef _EMB_RES_H_
#define _EMB_RES_H_

#include <resource.h>
#ifdef FORTE_SUPPORT_CLASS2DEV
#include "modules/class2_device/XMLParser4FB.h"
#endif


class EMB_RES : public CResource{
  DECLARE_FIRMWARE_FB(EMB_RES);

  public:
    EMB_RES(CStringDictionary::TStringId pa_nInstanceNameId,
        CResource* pa_poDevice);
    virtual ~EMB_RES();

  private:
#ifdef FORTE_SUPPORT_CLASS2DEV
	  virtual CFunctionBlock* handleUnknownType(CStringDictionary::TStringId paNameId, CStringDictionary::TStringId paTypeId, bool bCreateInstance);
private:
	CXMLParser4FB m_xmlparser;
#endif
};

#endif //close the ifdef sequence from the beginning of the file

