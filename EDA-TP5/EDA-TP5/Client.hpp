#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "genericState.hpp"
#include <string>
#include <vector>
#include "curses.h"

#define FIRSTLINE 11    //primera linea del listado de eventos
#define INTERSPACING 2  //separacion utilizada en varias secciones de la pantalla
#define LEFTMARGIN1 1
#define LEFTMARGIN2 45
#define LEFTMARGIN3 70

using namespace std;

/* Clase Client:
 * Contiene la funcion eventGenerator() encargada de tomar los eventos de teclado
 * Contiene strings que guardan la informacion del evento recibido, el ultimo evento recibido, la accion
 * ejecutada, y el estado actual.
 */
class Client
{
public:

	Client();

	genericEvent* eventGenerator();
    void startScreen (void);
    
    //setters de los strings
	void setReceivedEvent(string receivedEvent);
	void setLastEvent(string lastEvent);
	void setExecutedAction(string executedAction);
	void setCurrentState(string currentState);

    //getters de los strings
	string getCurrentState();
	string getReceivedevent();
	string getLastEvent();
	string getExecutedAction();

protected:

	string receivedEvent;
	string lastEvent;
	string executedAction;
	string currentState;
	WINDOW * winTest;

};
#endif // !CLIENT_HPP
