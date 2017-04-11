#include <stdio.h>
#include "ST_ReceiveWRQAck.hpp"
#include "ST_SendData.hpp"
#include "ST_Idle.hpp"

using namespace std;

ST_ReceiveWRQAck::ST_ReceiveWRQAck()
{
	currentState = "Waiting for WRQ Ack.";
}

genericState* ST_ReceiveWRQAck :: on_ReceiveAck(genericEvent* ev)
{
	genericState *ret = (genericState*) new ST_SendData();
	ret->executedAction = "N/A";
    return ret;
};
genericState* ST_ReceiveWRQAck :: on_timeout(genericEvent* ev)
{
	genericState *ret = (genericState*) new ST_ReceiveWRQAck();
	ret->executedAction = "N/A";
    return ret;
};

genericState* ST_ReceiveWRQAck::on_ReceiveError(genericEvent* ev)
{
	genericState *ret = (genericState*) new ST_Idle();
	ret->executedAction = "Error Received, Client Restarted";
	return ret;
}