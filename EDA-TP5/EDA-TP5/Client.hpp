#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "Screen.hpp"
#include "genericState.hpp"
#include <string>
#include <curses.h>

using namespace std;

class Client
{
public:
	Client();

	genericEvent* eventGenerator();
	void setReceivedEvent(string receivedEvent);
	void setLastEvent(string lastEvent);
	void setExecutedAction(string executedAction);
	void startScreen (void);

	string getReceivedevent();
	string getLastEvent();
	string getExecutedAction();

private:

	string receivedEvent;
	string lastEvent;
	string executedAction;
	WINDOW * winTest;

};
#endif // !CLIENT_HPP
