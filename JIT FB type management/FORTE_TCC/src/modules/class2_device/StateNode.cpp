/*******************************************************************************
* All rights reserved. This program and the accompanying materials
* are made available under the terms of the Eclipse Public License v1.0
* which accompanies this distribution, and is available at
* http://www.eclipse.org/legal/epl-v10.html
*
* Contributors:
*    #########
*      - initial implementation
*******************************************************************************/
#include "StateNode.h"

CStateNode::CStateNode(TForteUInt16 pa_nId, CDynBasicFunctionBlock* pa_poSrcFB):
	nId(pa_nId),poFB(pa_poSrcFB)
{

}
CStateNode::~CStateNode()
{
	if (nActionNum)
	{
		delete []poAction;
		poAction = NULL;
	}
	nActionNum = 0;
	lstStateTransit.clearAll();
}
void CStateNode::doAction(TForteUInt16 pa_unCurEIId)
{
	CFunctionBlock* pFB = dynamic_cast<CFunctionBlock*>(poFB);
	CStateNode* pstState = 0;
	t_StateTransitionEntry *tmp = 0;
	for (TStateTransList::Iterator itRunner(lstStateTransit.begin());
	itRunner != lstStateTransit.end(); ++itRunner)
	{
		if (poFB->pFuncEval)
		{
			if (true == (poFB->pFuncEval)(pFB, pa_unCurEIId, itRunner->m_st->m_unTransId))
			{
				pstState = (poFB->aStates[itRunner->m_st->m_unDstStateId]);
				poFB->unCurState = (pstState != 0 ? pstState->nId : 0);
				break;
			}
		}
	}
	if (pstState != 0)
	{
		TForteUInt8 i;
		for (i = 0; i < pstState->nActionNum; i++)
		{
			if ((((t_stateAction*)pstState->poAction)[i]).m_pAlgFunc)
			{
				(((t_stateAction*)pstState->poAction)[i]).m_pAlgFunc(pFB);
			}
			if ((((t_stateAction*)pstState->poAction)[i]).m_nEOId != 0xff)
			{
				pFB->sendOutputEvent((((t_stateAction*)pstState->poAction)[i]).m_nEOId);
			}
		}
	}
	else
	{
		poFB->bTransitCleared = false;
	}
}