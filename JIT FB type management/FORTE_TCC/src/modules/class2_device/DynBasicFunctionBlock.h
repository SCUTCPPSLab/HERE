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
#pragma once
#include "basicfb.h"
class CStateNode;
typedef void(*t_algFunc)(void*);
typedef bool(*t_stateTransitEvalFunc)(void*, TForteInt16, TForteUInt8);

typedef struct t_stateAction
{
	t_algFunc m_pAlgFunc;
	TForteUInt32 m_nEOId;
}t_stateAction;

class CDynBasicFunctionBlock :
	public CBasicFB
{
public:
	CDynBasicFunctionBlock(CResource *pa_poSrcRes,
		const SFBInterfaceSpec *pa_pstInterfaceSpec,
		const CStringDictionary::TStringId pa_nInstanceNameId,
		const SInternalVarsInformation *pa_pstVarInternals,
		TForteByte *pa_acFBConnData, TForteByte *pa_acBasicFBVarsData,
		TForteUInt8 pa_unStateNum, TForteUInt8 pa_unTransNum, TForteUInt8 pa_unLocalInstanceId
		);
	~CDynBasicFunctionBlock();
	void setFBTypeId(CStringDictionary::TStringId pa_FBTypeId) { m_FBTypeId = pa_FBTypeId; }
	virtual CStringDictionary::TStringId getFBTypeId(void) const { return m_FBTypeId; };
	virtual void executeEvent(int pa_nEIID);
public :
	void initState(TForteUInt8 pa_unStateId, TForteUInt8 pa_nActionNum);
	void initTranstion(TForteUInt8 pa_unSrcStateId, TForteUInt8 pa_unDstStateId);
	void bindStateAction(TForteUInt8 pa_unStateId, TForteUInt8 pa_unActionId, TForteUInt8 pa_unEOId, t_algFunc pa_vpFunc);
	void bindStateTranstion(TForteUInt8 pa_unSrcStateId);
private:
	TForteUInt8 unStateNum;
	TForteUInt8 unTransNum;
	void* aTransits;
	TForteByte *acFBConnData;
	TForteByte *acBasicFBVarsData;
	CStringDictionary::TStringId m_FBTypeId;
	const SFBInterfaceSpecforGenerics* m_FBInterf;
	TForteUInt8 unLocalInstanceId;
public:
	bool bTransitCleared;
	TForteUInt8 unCurState;
	t_stateTransitEvalFunc pFuncEval;
	CStateNode** aStates;
};

