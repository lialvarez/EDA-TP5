#include <stdio.h>
#include "ST_SendDataAck.hpp"
#include "ST_ReceiveData.hpp"

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