#include "curses.h"
#include "Client.hpp"
#include "EV_SendWRQ.hpp"
#include "EV_SendRRQ.hpp"
#include "EV_SendData.hpp"
#include "EV_SendLastData.hpp"
#include "EV_SendAck.hpp"
#include "EV_SendAck.hpp"
#include "EV_ReceiveAck.hpp"
#include "EV_ReceiveData.hpp"
#include "EV_ReceiveLastData.hpp"
#include "EV_Timeout.hpp"

Client::Client()
{
	receivedEvent = "Esperando EVENTO";
	lastEvent = "N/A";
	executedAction = "N/A";
}

genericEvent* Client::eventGenerator()
{
	char c;
	nodelay(winTest, true);
	noecho();
	
	while((c = getch()) != ERR)
	{
		c = tolower(c);
		switch (c)
		{
		case 'w':
			receivedEvent = "Send WRQ";
			return ((genericEvent *) new (EV_SendWRQ));
			break;
		case 'r':
			receivedEvent = "Send RRQ";
			return ((genericEvent *) new (EV_SendRRQ));;
			break;
		case 'e':
			receivedEvent = "Send DATA";
			return ((genericEvent *) new (EV_SendData));;
			break;
		case 'y':
			receivedEvent = "Send LAST DATA";
			return ((genericEvent *) new (EV_SendLastData));
			break;
		case 'q':
			receivedEvent = "Send ACK";
			return ((genericEvent *) new (EV_SendAck));;
			break;
		case 'a':
			receivedEvent = "ACK";
			return ((genericEvent *) new (EV_ReceiveAck));;
			break;
		case 'd':
			receivedEvent = "DATA";
			return ((genericEvent *) new (EV_ReceiveData));;
			break;
		case 's':
			receivedEvent = "LAST DATA";
			return ((genericEvent *) new (EV_ReceiveLastData));;
			break;
		case 't':
			receivedEvent = "TIMEOUT";
			return ((genericEvent *) new (EV_Timeout));;
			break;
		default:
			return nullptr;
			break;
		}
	}
	return nullptr;
}

void Client::setReceivedEvent(string receivedEvent)
{
	this->receivedEvent = receivedEvent;
}

void Client::setLastEvent(string lastEvent)
{
	this->lastEvent = lastEvent;
}

void Client::setExecutedAction(string executedAction)
{
	this->executedAction = executedAction;
}

string Client::getExecutedAction()
{
	return executedAction;
}

string Client::getLastEvent()
{
	return lastEvent;
}

string Client::getReceivedevent()
{
	return receivedEvent;
}
