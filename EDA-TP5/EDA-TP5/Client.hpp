#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "GenericState.hpp"
#include <string>

using namespace std;

class Client
{
public:
	Client();

	void setReceivedEvent(string receivedEvent);
	void setLastEvent(string lastEvent);
	void setExecutedAction(string executedAction);

private:

	string receivedEvent;
	string lastEvent;
	string executedAction;

};
#endif // !CLIENT_HPP
