#ifdef _CLASS2_ENABLE
#ifndef   _STATENODE_H_
#define   _STATENODE_H_
#include  "ooc.h" 
#include  "HERE.h" 
#undef OBJECT
#define OBJECT CStateNode

#define typeTransition 0
#define typeAction 1

typedef struct t_stateTransition
{
	UINT8 m_unSrcStateId;
	UINT8 m_unDstStateId;
	UINT8 m_unTransId;
}t_stateTransition;

typedef struct t_StateTransitionEntry{
	t_stateTransition* m_st;
	struct list_head list;
}t_StateTransitionEntry;

BASEOBJECT_INTERFACE
	UINT16 public(nId);
	void* public(poFB);
	struct list_head public(lstStateTransit);
	UINT8 public(nActionNum);
	void* public(poAction);
BASEOBJECT_METHODS
	void method_(doAction) UINT16 pa_unCurEIId __ ;
ENDOF_INTERFACE
CLASS_INTERFACE
	t_CStateNode*const classMethod_(new)
		UINT16 pa_nId, void* pa_poSrcFB __;
	void method_(init)
		UINT16 pa_nId, void* pa_poSrcFB  __;
ENDOF_INTERFACE
#endif
#endif