#include "ST_Idle.hpp"
#include "ST_ReceiveWRQAck.hpp"
#include "ST_ReceiveFirstData.hpp"

using namespace std;

ST_Idle::ST_Idle()
{
	currentState = "Idle";
}

genericState* ST_Idle::on_SendWRQ(genericEvent *ev)
{
	genericState *ret = (genericState*) new ST_ReceiveWRQAck();
	ret->executedAction = "WRQ Sent";
	return ret;
};

genericState* ST_Idle::on_SendRRQ(genericEvent *ev)
{
	genericState *ret = (genericState*) new ST_ReceiveFirstData();
	ret->executedAction = "RRQ Sent";
	return ret;
};

genericState* ST_Idle::on_SendError(genericEvent* ev)
{
	genericState* ret = (genericState*) new ST_Idle();
	ret->executedAction = "Error Sent, Client Restarted";
	return ret;
}

genericState* ST_Idle::on_CloseClient(genericEvent* ev)
{
	genericState* ret = (genericState*) new ST_Idle();
	ret->setLastEvent(CLOSE_CLIENT);
	ret->executedAction = "Client Closed";
	return ret;
}