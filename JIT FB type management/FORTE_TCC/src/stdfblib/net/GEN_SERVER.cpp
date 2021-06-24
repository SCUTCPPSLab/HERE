/*******************************************************************************
 * Copyright (c) 2006 - 2011 ACIN, Profactor GmbH
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *   Rene Smodic, THomas Strasser, Alois Zoitl, Gerhard Ebenhofer,
 *   Ingo Hegny, Martin Melik Merkumians
 *    - initial API and implementation and/or initial documentation
 *******************************************************************************/
#include "GEN_SERVER.h"

DEFINE_GENERIC_FIRMWARE_FB(GEN_SERVER, g_nStringIdGEN_SERVER)

GEN_SERVER::GEN_SERVER(const CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) :
      forte::com_infra::CCommFB(pa_nInstanceNameId, pa_poSrcRes, forte::com_infra::e_Server){

  //CNetCommFB( pa_nInstanceNameId, pa_poSrcRes, false, scm_nSendBufferSize, scm_nRecvBufferSize, CCommFB::e_Server) {
}