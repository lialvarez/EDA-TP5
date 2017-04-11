#include "genericFSM.hpp"
#include "ST_Idle.hpp"

genericFSM::genericFSM()
{
	currentState = (genericState *) new ST_Idle();
	printf("Ejecuta el constructor\n");
}

genericFSM::~genericFSM()
{
	delete currentState;
}

void genericFSM::Dispatch(genericEvent *ev)
{
	genericState *newState = nullptr;

    
    //lamar a la funcion del estado actual correspondiente al evento recibido
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
		break;
	case S_DATA:
		newState = currentState->on_SendData(ev);
		break;
	case S_LAST_DATA:
		newState = currentState->on_SendLastData(ev);
		break;
	case R_ACK:
		newState = currentState->on_ReceiveAck(ev);
		break;
	case R_DATA:
		newState = currentState->on_ReceiveData(ev);
		break;
	case R_LAST_DATA:
		newState = currentState->on_ReceiveLastData(ev);
		break;
	case R_TIMEOUT:
		newState = currentState->on_timeout(ev);
		break;
	case R_ERROR:
		newState = currentState->on_ReceiveError(ev);
		break;
	case S_ERROR:
		newState = currentState->on_SendError(ev);
		break;
	case CLOSE_CLIENT:
		newState = currentState->on_CloseClient(ev);
		break;
	default:
		break;
	}
	if (newState != nullptr)    //si hubo nullptr
	{
		delete currentState;
		currentState = newState;
	}
}

genericState* genericFSM::getCurrentState()
{
	return currentState;
}
