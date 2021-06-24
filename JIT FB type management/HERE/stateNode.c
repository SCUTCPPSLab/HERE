#ifdef _CLASS2_ENABLE
#include "DynamicFB.h"
#define IMPLEMENTATION
#include "stateNode.h"
void methodDecl_(doAction) 
	UINT16 pa_unCurEIId __
{
	t_FUNCTIONBLOCK* pFB = &(((t_FB_DYNAMICBFB*)this->m.poFB)->m.FUNCTIONBLOCK);
	t_CStateNode* pstState = 0;
	t_StateTransitionEntry *tmp = 0;
	struct list_head * pos;
	t_stateTransitEvalFunc p = ((t_FB_DYNAMICBFB*)this->m.poFB)->m.pFuncEval;
	VAR* V=sendMsg_(pFB, getDI) 0 __;
	char* c=((t_FB_DYNAMICBFB*)this->m.poFB)->m.strTypeName;
	list_for_each(pos, &(this->m.lstStateTransit))
	{
		tmp = list_entry((pos), t_StateTransitionEntry, list);
		if (((t_FB_DYNAMICBFB*)this->m.poFB)->m.pFuncEval)
		{
			void* p = (((t_FB_DYNAMICBFB*)this->m.poFB)->m.pFuncEval);
			if (TRUE == (((t_FB_DYNAMICBFB*)this->m.poFB)->m.pFuncEval)(pFB, pa_unCurEIId, tmp->m_st->m_unTransId))
			{
				pstState = ((t_CStateNode*)((t_FB_DYNAMICBFB*)this->m.poFB)->m.aStates[tmp->m_st->m_unDstStateId]);
				((t_FB_DYNAMICBFB*)this->m.poFB)->m.unCurState = (pstState != 0 ? pstState->m.nId : 0);
				break;
			}
		}
	}
	if (pstState != 0)
	{
		UINT i;
		for (i = 0; i < pstState->m.nActionNum; i++)
		{
			if ((((t_stateAction*)pstState->m.poAction)[i]).m_pAlgFunc)
			{
				(((t_stateAction*)pstState->m.poAction)[i]).m_pAlgFunc(pFB);
			}
			if ((((t_stateAction*)pstState->m.poAction)[i]).m_nEOId != 0xff)
			{
				FUNCTIONBLOCK.queueOutputEvent(pFB, (((t_stateAction*)pstState->m.poAction)[i]).m_nEOId);
			}	
		}
	}
	else
	{
		((t_FB_DYNAMICBFB*)this->m.poFB)->m.bTransitCleared = FALSE;
	}
}
BASEOBJECT_IMPLEMENTATION
		methodName(doAction),
ENDOF_IMPLEMENTATION
initClassDecl()
{

}
dtorDecl()
{
	t_StateTransitionEntry *tmp = 0;
	struct list_head * pos;
	struct list_head *posNext;
	t_CStateNode* p = this;
	if (this->m.lstStateTransit.next)
	{
		list_for_each_safe(pos, posNext, &(this->m.lstStateTransit))
		{
			tmp = list_entry((pos), t_StateTransitionEntry, list);
			list_del(&((t_StateTransitionEntry*)tmp)->list);
			HERE_free(tmp);
		}
	}
	if (this->m.nActionNum)
	{
		HERE_free(this->m.poAction);
	}
	HERE_free(this);
}
t_CStateNode
classMethodDecl_(*const new)
	UINT16 pa_nId, void* pa_poSrcFB  __
{
	t_CStateNode *const this = CStateNode.alloc();
	if (this)CStateNode.init(this, pa_nId, pa_poSrcFB);
	return this;
}
void
methodDecl_(init)
	UINT16 pa_nId, void* pa_poSrcFB __
{
	INIT_LIST_HEAD(&(this->m.lstStateTransit));
	this->m.nId = pa_nId;
	this->m.poFB = pa_poSrcFB;
}
CLASS_IMPLEMENTATION
	methodName(new),
	methodName(init),
ENDOF_IMPLEMENTATION
#endif