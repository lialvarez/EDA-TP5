#include <iostream>
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


using namespace std;

int main()
{
	cout << "Hola, el codigo compila" << endl;
	Client client;
	genericFSM FSM;
	genericEvent *ev = nullptr;

	while (true) //hacer el evento EXIT PARA SALIR DEL LOOP
	{
		ev = client.eventGenerator();
		FSM.Dispatch(ev);
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
