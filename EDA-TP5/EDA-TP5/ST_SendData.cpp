#include <stdio.h>
#include "ST_SendData.hpp"
#include "ST_ReceiveDataAck.hpp"
#include "ST_ReceiveLastDataAck.hpp"
#include "ST_Idle.hpp"

using namespace std;

ST_SendData::ST_SendData()
{
	currentState = "Waiting to Send Data";
}

genericState* ST_SendData :: on_SendData(genericEvent* ev)
{
	genericState *ret = (genericState *) new ST_ReceiveDataAck();
	ret->executedAction = "Data Sent";
	return ret;
};

genericState* ST_SendData :: on_SendLastData(genericEvent* ev)
{
	genericState *ret = (genericState *) new ST_ReceiveLastDataAck();
	ret->executedAction = "Last Data Sent";
	return ret;
};

genericState* ST_SendData::on_SendError(genericEvent* ev)
{
	genericState* ret = (genericState*) new ST_Idle();
	ret->executedAction = "Error Sent, Client Restarted";
	return ret;
}

genericState* ST_SendData::on_CloseClient(genericEvent* ev)
{
	genericState* ret = (genericState*) new ST_Idle();
	ret->setLastEvent(CLOSE_CLIENT);
	ret->executedAction = "Client Closed";
	return ret;
}