#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "GenericState.hpp"
#include "GenericEvent.hpp"
#include "EV_SendWRQ.hpp"
#include "EV_SendRRQ.hpp"
#include "EV_SendData.hpp"
#include "EV_SendAck.hpp"
#include "EV_SendLastData.hpp"
#include "EV_ReceiveAck.hpp"
#include "EV_ReceiveData.hpp"
#include "EV_ReceiveLastData.hpp"
#include "EV_Timeout.hpp"
#include "Screen.hpp"
#include <string>
#include <ctime>

using namespace std;

class Client
{
public:
	Client();

	void setReceivedEvent(string receivedEvent);
	void setLastEvent(string lastEvent);
	void setExecutedAction(string executedAction);

	genericEvent* eventGenerator();

private:

	string receivedEvent;
	string lastEvent;
	string executedAction;

	

};
#endif // !CLIENT_HPP
