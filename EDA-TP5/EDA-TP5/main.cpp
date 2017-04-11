#include <stdlib.h>
#include "curses.h"
#include "Client.hpp"
#include "genericFSM.hpp"
#include "genericState.hpp"
#include "genericEvent.hpp"
#include "ST_Idle.hpp"
#include "ST_ReceiveWRQAck.hpp"
#include "ST_SendData.hpp"
#include "ST_ReceiveDataAck.hpp"
#include "ST_SendLastDataAck.hpp"
#include <string>
#include <windows.h>

using namespace std;

void refreshScreen(Client client);

void main()
{

	Client client;
	genericFSM FSM;
	genericEvent *ev = nullptr;

	client.startScreen();	//Seteo pantalla inicial//
	do 
	{

		client.setCurrentState(FSM.getCurrentState()->currentState);
		refreshScreen(client);

		ev = client.eventGenerator();
		FSM.Dispatch(ev);

		refreshScreen(client);
		Sleep(1000);

		client.setExecutedAction((FSM.getCurrentState())->executedAction);
		refreshScreen(client);
		Sleep(1000);

		client.setExecutedAction("N/A");
		client.setLastEvent(client.getReceivedevent());
		client.setReceivedEvent("Esperando EVENTO");
		Sleep(1000);

	} while ((FSM.getCurrentState())->getLastEvent() != CLOSE_CLIENT);
	Sleep(2000);
}

void refreshScreen(Client client)
{
	int currentLine = FIRSTLINE + 4;

	color_set(3, NULL);
	move(currentLine, LEFTMARGIN3);
	clrtoeol();
	printw("%s", client.getCurrentState().c_str());

	currentLine += INTERSPACING;
	move(currentLine, LEFTMARGIN3);
	clrtoeol();
	printw("%s", client.getReceivedevent().c_str());

	currentLine += INTERSPACING;
	move(currentLine, LEFTMARGIN3);
	clrtoeol();
	printw("%s", client.getLastEvent().c_str());

	currentLine += INTERSPACING;
	move(currentLine, LEFTMARGIN3);
	clrtoeol();
	printw("%s", client.getExecutedAction().c_str());

	refresh();
}

/* 
 Che pregunta. que pasa si yo soy cliente en rrq y mande el last data ack? si vuelvo a idle al toque, nunca me voy a enterar
 si el servidor quizas no le llego mi ack y me reenvia su last data. Importa? porque yo tengo todos los datos que queria, pero
 el servidor no sabe eso. PARA REFLEXIONAR NOSIERTO?
 */

/* Che pregunta 2. timeout es un evento que se envia a mano? no hace falta poner un timer que controle, no? */
