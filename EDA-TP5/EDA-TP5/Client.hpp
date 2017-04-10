#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "genericState.hpp"
#include <string>
#include <vector>
#include "curses.h"

using namespace std;



class Client
{
public:
	Client();

	genericEvent* eventGenerator();
	void setReceivedEvent(string receivedEvent);
	void setLastEvent(string lastEvent);
	void setExecutedAction(string executedAction);
	void setCurrentState(string currentState);
	void startScreen (void);

	string getCurrentState();
	string getReceivedevent();
	string getLastEvent();
	string getExecutedAction();


private:


	string receivedEvent;
	string lastEvent;
	string executedAction;
	string currentState;
	WINDOW * winTest;

};
#endif // !CLIENT_HPP
