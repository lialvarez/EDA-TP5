#include <iostream>
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

int main()
{

	cout << "Hola, el codigo compila" << endl;
	Client client;
	genericFSM FSM;
	genericEvent *ev = nullptr;
	WINDOW * winTest=NULL;   

	char *Events[30] = {"W = SEND WRQ","R = SEND RRQ","E = SEND DATA","Y = SEND LAST DATA","Q = SEND ACK","A = ACK","D = DATA","S = LAST DATA","T = TIMEOUT"};
	char *fsmStates[30] = {"Evento Recibido: ","Ultimo Evento Recibido: ","Accion Ejecutada: "};
	
	winTest = initscr();

	if(winTest != NULL)
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

	while (true) //hacer el evento EXIT PARA SALIR DEL LOOP
	{

		//"Evento Recibido" = client.getReceivedevent();
		//"Ultimo Evento Recibido" = client.getLastEvent();
		//"Accion Ejecutada" = FSM.getCurrentState()->executedAction;

		ev = client.eventGenerator();
		FSM.Dispatch(ev);

		move (12,70);														//Actualiza evento recibido//
		printw ("%s", client.getReceivedevent());
		//"Evento Recibido" = client.getReceivedevent();
		
		Sleep (500);
		move (16,70);
		printw ("%s", FSM.getCurrentState()->executedAction);				//Actualiza la accion ejecutada//
		//Simular un delay
		//Actualizar accion ejecutada
		//"Accion Ejecutada" = FSM.getCurrentState()->executedAction;
		Sleep (500);
		move (14,70);														
		printw ("%s", client.getReceivedevent());							//Actualiza evento anterior//
		move (12,70);
		printw ("Esperando Evento");										//Actualiza evento actual//
		move (16,70);
		printw ("N/A");														//Actualiza accion derivada del evento//
		//Simular delay
		//Actualizar "Ultimo Evento Recibido" al evento anterior
		//Reestablecer "Evento Recibido" a "Esperando EVENTO"
		//Reestablecer "Accion Ejecutada" a "N/A"
	/*
		client.setLastEvent(client.getReceivedevent());
		client.setReceivedEvent("Esperando EVENTO");
		FSM.getCurrentState()->executedAction = "N/A";*/

		

	}
//	cin.get();
	return 0;
}


/* 
 Che pregunta. que pasa si yo soy cliente en rrq y mande el last data ack? si vuelvo a idle al toque, nunca me voy a enterar
 si el servidor quizas no le llego mi ack y me reenvia su last data. Importa? porque yo tengo todos los datos que queria, pero
 el servidor no sabe eso. PARA REFLEXIONAR NOSIERTO?
 */

/* Che pregunta 2. timeout es un evento que se envia a mano? no hace falta poner un timer que controle, no? */
