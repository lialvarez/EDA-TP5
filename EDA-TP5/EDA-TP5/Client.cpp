#include "Client.hpp"

Client::Client()
{
	receivedEvent = "Esperando EVENTO";
	lastEvent = "N/A";
	executedAction = "N/A";
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
