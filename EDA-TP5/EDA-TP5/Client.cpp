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
#include <curses.h>

Client::Client()
{
	receivedEvent = "Esperando EVENTO";
	lastEvent = "N/A";
	executedAction = "N/A";
	WINDOW * winTest = initscr();
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

//GRAFICA LA PANTALLA INICIAL CORRESPONDIENTE A LA SIMULACION DEL CLIENTE//
void Client::startScreen ()
{   
	char *Events[30] = {"W = SEND WRQ","R = SEND RRQ","E = SEND DATA","Y = SEND LAST DATA","Q = SEND ACK","A = ACK","D = DATA","S = LAST DATA","T = TIMEOUT"};
	char *fsmStates[30] = {"Evento Recibido: ","Ultimo Evento Recibido: ","Accion Ejecutada: "};

	{
		start_color();
		init_pair(1,COLOR_WHITE, COLOR_BLACK);
		init_pair(2,COLOR_BLUE, COLOR_WHITE);
		init_pair(3,COLOR_RED, COLOR_BLACK);
		immedok(winTest,TRUE);
	}

	//Se imprime la pantalla inicial que mostrara el estado de la FSM y las teclas correspondientes a los eventos//
	color_set (2,NULL);
	printw("Instituto Tecnologico de Buenos Aires");
	color_set (1,NULL); move (1,0);
	printw("Grupo 4 : Lisando Alvarez, Maria Luz Stewart Harris y Nicolas Mestanza");
	move(3,0); color_set (3,NULL);
	printw("Client.exe");
	move(4,0);
	printw("Programa de simulacion de cliente TFTP implementado con FSM");
	move (6,0); color_set (1,NULL);
	printw("Cuando el usuario presiona las teclas de eventos entiende que se genero un nuevo evento");
	move (7,0);
	printw ("y responde ante ese evento realizando una accion y cambiando el estado.");
	move (10,0);color_set (3,NULL);
	printw ("Eventos:"); move (10,45); printw ("Status de la FSM:");
	color_set (1,NULL);

	for(int i=6;i<(9+6);i++)
	{
		move (i*2,0);
		printw ("%s",Events[i-6]);
	}
		
	for(int i=6;i<(9);i++)
	{
		move (i*2,45);
		printw ("%s",fsmStates[i-6]);
	}
	return;
}