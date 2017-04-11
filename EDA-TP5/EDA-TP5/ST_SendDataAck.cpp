#include <stdio.h>
#include "ST_SendDataAck.hpp"
#include "ST_ReceiveData.hpp"
#include "ST_Idle.hpp"

using namespace std;

ST_SendDataAck::ST_SendDataAck()
{
	currentState = "Waiting to Send Data Ack.";
}

genericState* ST_SendDataAck::on_SendAck(genericEvent *ev)
{
	genericState *ret = (genericState*) new ST_ReceiveData();
	ret->executedAction = "Ack. Sent";
	return ret;
}

genericState* ST_SendDataAck::on_SendError(genericEvent* ev)
{
	genericState* ret = (genericState*) new ST_Idle();
	ret->executedAction = "Error Sent, Client Restarted";
	return ret;
}

genericState* ST_SendDataAck::on_CloseClient(genericEvent* ev)
{
	genericState* ret = (genericState*) new ST_Idle();
	ret->setLastEvent(CLOSE_CLIENT);
	ret->executedAction = "Client Closed";
	return ret;
}
