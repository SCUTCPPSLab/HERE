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
#include "funcbloc.h"
#include "DynBasicFunctionBlock.h"
#include "fortelist.h"

#define typeTransition 0
#define typeAction 1

typedef struct t_stateTransition
{
	TForteUInt8 m_unSrcStateId;
	TForteUInt8 m_unDstStateId;
	TForteUInt8 m_unTransId;
}t_stateTransition;

typedef struct t_StateTransitionEntry {
	t_stateTransition* m_st;
	//struct list_head list;
}t_StateTransitionEntry;

typedef CSinglyLinkedList<t_StateTransitionEntry*> TStateTransList;

class CStateNode 
{
public:
	CStateNode(TForteUInt16 pa_nId, CDynBasicFunctionBlock* pa_poSrcFB);
	~CStateNode();
	void doAction(TForteUInt16 pa_unCurEIId);
private:
	TForteUInt16 nId;
	CDynBasicFunctionBlock* poFB;
	
public:
	TForteUInt8 nActionNum;
	void* poAction;
	TStateTransList lstStateTransit;
};