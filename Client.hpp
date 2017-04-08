#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "genericState.hpp"
#include <string>

using namespace std;

class Client
{
public:
	Client();

	genericEvent* eventGenerator();
	void setReceivedEvent(string receivedEvent);
	void setLastEvent(string lastEvent);
	void setExecutedAction(string executedAction);

private:

	string receivedEvent;
	string lastEvent;
	string executedAction;

};
#endif // !CLIENT_HPP
