#include <iostream>
#include <stdlib.h>
#include <curses.h>
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

	client.startScreen();														//Seteo pantalla inicial//
	while (true) //hacer el evento EXIT PARA SALIR DEL LOOP
	{
		//ESTO HAY QUE ACOMODARLO PARA QUE QUEDE EN EL CLIENT Y DESDE AHI PUEDA CAMBIAR LA INFORMACION//
		//ESTA ACA PARA TESTEAR//


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
	
		client.setLastEvent(client.getReceivedevent());
		client.setReceivedEvent("Esperando EVENTO");
		FSM.getCurrentState()->executedAction = "N/A";
	}
	return 0;
}


/* 
 Che pregunta. que pasa si yo soy cliente en rrq y mande el last data ack? si vuelvo a idle al toque, nunca me voy a enterar
 si el servidor quizas no le llego mi ack y me reenvia su last data. Importa? porque yo tengo todos los datos que queria, pero
 el servidor no sabe eso. PARA REFLEXIONAR NOSIERTO?
 */

/* Che pregunta 2. timeout es un evento que se envia a mano? no hace falta poner un timer que controle, no? */
