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
#include "DynBasicFunctionBlock.h"
#include "StateNode.h"
CDynBasicFunctionBlock::CDynBasicFunctionBlock(CResource *pa_poSrcRes,
	const SFBInterfaceSpec *pa_pstInterfaceSpec,
	const CStringDictionary::TStringId pa_nInstanceNameId,
	const SInternalVarsInformation *pa_pstVarInternals,
	TForteByte *pa_acFBConnData, TForteByte *pa_acBasicFBVarsData,
	TForteUInt8 pa_unStateNum, TForteUInt8 pa_unTransNum, TForteUInt8 pa_unLocalInstanceId
	):
	acFBConnData(pa_acFBConnData),
	acBasicFBVarsData(pa_acBasicFBVarsData),
	CBasicFB(pa_poSrcRes, pa_pstInterfaceSpec , pa_nInstanceNameId, pa_pstVarInternals, pa_acFBConnData, pa_acBasicFBVarsData)
	
{
	unLocalInstanceId = pa_unLocalInstanceId;
	//if (unLocalInstanceId==0)
	{
		unTransNum = pa_unTransNum;
		aTransits = new t_stateTransition[pa_unTransNum];
		unTransNum = 0;
		aStates = new CStateNode*[pa_unStateNum];
		unStateNum = pa_unStateNum;
		for (int i = 0; i < pa_unStateNum; i++)
		{
			aStates[i] = new CStateNode(i, this);
		}
	}
	unCurState = 0;
	bTransitCleared = false;
	m_FBInterf = (const SFBInterfaceSpecforGenerics*)pa_pstInterfaceSpec;
	m_bExtFreeData = true;
}


CDynBasicFunctionBlock::~CDynBasicFunctionBlock()
{
		if (unLocalInstanceId == 0)
		{
			SFBInterfaceSpec * fbInterf = const_cast<SFBInterfaceSpecforGenerics *>(m_FBInterf);
			fbInterf->m_nNumEIs = 0;
			fbInterf->m_nNumEOs = 0;
			fbInterf->m_nNumDIs = 0;
			fbInterf->m_nNumDOs = 0;
			delete[]m_FBInterf->m_anEIWith;
			delete[]m_FBInterf->m_anEIWithIndexes;
			delete[]m_FBInterf->m_anEOWith;
			delete[]m_FBInterf->m_anEOWithIndexes;
			delete[]m_FBInterf->m_aunDIDataTypeNames;
			delete[]m_FBInterf->m_aunDINames;
			delete[]m_FBInterf->m_aunDODataTypeNames;
			delete[]m_FBInterf->m_aunDONames;
			delete[]m_FBInterf->m_aunEINames;
			delete[]m_FBInterf->m_aunEONames;
			delete m_FBInterf;

			for (int i = 0; i < unStateNum; i++)
			{
				delete aStates[i];
				aStates[i] = NULL;
				//this->aStates[i]->~CStateNode();
			}
		}
		delete[]aStates;
		delete[]aTransits;
		delete[]acFBConnData;
		delete[]acBasicFBVarsData;
		//CFunctionBlock* fb = dynamic_cast<CFunctionBlock*>(this);
		//fb->hasFreeData = true;
		//m_FBInterf = NULL;
	//}

}
void CDynBasicFunctionBlock::executeEvent(int pa_nEIID)
{
	bTransitCleared = true;
	CStateNode* pState;
	while (bTransitCleared)
	{
		pState = aStates[unCurState];
		pState->doAction(pa_nEIID);
		pa_nEIID = 0XFF;
	}
}
void CDynBasicFunctionBlock::initState(TForteUInt8 pa_unStateId, TForteUInt8 pa_nActionNum)
{
	(aStates[pa_unStateId])->nActionNum = pa_nActionNum;
	if (pa_nActionNum != 0)
	{
		(aStates[pa_unStateId])->poAction = new t_stateAction[pa_nActionNum];
	}
}
void CDynBasicFunctionBlock::initTranstion(TForteUInt8 pa_unSrcStateId, TForteUInt8 pa_unDstStateId)
{
	((t_stateTransition*)aTransits)[unTransNum].m_unSrcStateId = pa_unSrcStateId;
	((t_stateTransition*)aTransits)[unTransNum].m_unDstStateId = pa_unDstStateId;
	((t_stateTransition*)aTransits)[unTransNum].m_unTransId = unTransNum;
	unTransNum++;
}
void CDynBasicFunctionBlock::bindStateAction(TForteUInt8 pa_unStateId, TForteUInt8 pa_unActionId, TForteUInt8 pa_unEOId, t_algFunc pa_vpFunc)
{
	if (pa_unStateId < unStateNum)
	{
		if (pa_unActionId < (aStates[pa_unStateId])->nActionNum)
		{
			((t_stateAction*)(aStates[pa_unStateId])->poAction)[pa_unActionId].m_nEOId = pa_unEOId;
			((t_stateAction*)(aStates[pa_unStateId])->poAction)[pa_unActionId].m_pAlgFunc = (t_algFunc)pa_vpFunc;
		}
	}
}
void CDynBasicFunctionBlock::bindStateTranstion(TForteUInt8 pa_unSrcStateId)
{
	int i;
	for (i = 0; i < unTransNum; i++)
	{
		if (((t_stateTransition*)aTransits)[i].m_unSrcStateId == pa_unSrcStateId)
		{
			t_StateTransitionEntry* poNewTrans = new t_StateTransitionEntry;
			poNewTrans->m_st = ((t_stateTransition*)aTransits) + i;
			(aStates[pa_unSrcStateId]->lstStateTransit).push_back(poNewTrans);
		}
	}
}