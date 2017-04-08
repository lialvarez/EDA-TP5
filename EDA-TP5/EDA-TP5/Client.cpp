#include "Client.hpp"


Client::Client()
{
	receivedEvent = "Esperando EVENTO";
	lastEvent = "N/A";
	executedAction = "N/A";
}

genericEvent* Client::eventGenerator()
{
	char c;
	nodelay(terminalScreen, true);
	noecho();
	
	while((c = getch()) != ERR)
	{
		c = tolower(c);
		switch (c)
		{
		case 'w':
			return ((genericEvent *) new (EV_SendWRQ));
			break;
		case 'r':
			return ((genericEvent *) new (EV_SendRRQ));;
			break;
		case 'e':
			return ((genericEvent *) new (EV_SendData));;
			break;
		case 'y':
			return ((genericEvent *) new (EV_SendLastData));
			break;
		case 'q':
			return ((genericEvent *) new (EV_SendAck));;
			break;
		case 'a':
			return ((genericEvent *) new (EV_ReceiveAck));;
			break;
		case 'd':
			return ((genericEvent *) new (EV_ReceiveData));;
			break;
		case 's':
			return ((genericEvent *) new (EV_ReceiveLastData));;
			break;
		case 't':
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
