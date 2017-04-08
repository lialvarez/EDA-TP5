#include "GenericFSM.hpp"

void genericFSM::Dispatch(genericEvent *ev)
{
	genericState *newState;

	switch (ev->getEventType())
	{
	case S_WRQ:
		newState = currentState->on_SendWRQ(ev);
		break;
	case S_RRQ:
		newState = currentState->on_SendRRQ(ev);
		break;
	case S_ACK:
		newState = currentState->on_SendAck(ev);
	default:
		break;
	}
}