/*******************************************************************************
 * Copyright (c) 2016 fortiss GmbH
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *  Alois Zoitl - initial API and implementation and/or initial documentation
 *******************************************************************************/

#include "forte_sem.h"
#include "../devlog.h"
#include <errno.h>
#include <string.h>

namespace forte {
  namespace arch {

    CNetOSSemaphore::CNetOSSemaphore(unsigned int paInitialValue){
      tx_semaphore_create(&mSemaphore, "hugo", paInitialValue);
    }

    CNetOSSemaphore::~CNetOSSemaphore(){
      tx_semaphore_delete(&mSemaphore);
    }

    void CNetOSSemaphore::semInc(){
      tx_semaphore_put(&mSemaphore);
    }

    void CNetOSSemaphore::semWaitIndefinitly(){
      tx_semaphore_get(&mSemaphore, TX_WAIT_FOREVER);
    }

  } /* namespace arch */
} /* namespace forte */
