#include <iostream>
#include <curses.h>
#include "genericFSM.hpp"
#include "genericState.hpp"
#include "genericEvent.hpp"
#include "st_idle.hpp"
#include "ST_ReceiveWRQAck.hpp"
#include "ST_SendData.hpp"
#include "ST_ReceiveDataAck.hpp"
#include "ST_SendLastDataAck.hpp"


using namespace std;

int main()
{
	cout << "Hola, el codigo compila" << endl;
	
	genericEvent* ev = nullptr;
	genericState* StateA = (genericState*) new ST_Idle();
	
	
/* prueba rustica para ver chequear que anden los cambios de estados (por ahora solo probe los de WRQ porque es la una de la maniana y me quiero ir a dormir)*/
	StateA = StateA->on_SendWRQ(ev);
	StateA = StateA->on_timeout(ev);
	StateA = StateA->on_ReceiveAck(ev);
	StateA = StateA->on_SendData(ev);
	StateA = StateA->on_timeout(ev);
	StateA = StateA->on_ReceiveAck(ev);
	StateA = StateA->on_SendLastData(ev);
	StateA = StateA->on_timeout(ev);
	StateA = StateA->on_ReceiveAck(ev);

	return 0;
}


/* 
 Che pregunta. que pasa si yo soy cliente en rrq y mande el last data ack? si vuelvo a idle al toque, nunca me voy a enterar
 si el servidor quizas no le llego mi ack y me reenvia su last data. Importa? porque yo tengo todos los datos que queria, pero
 el servidor no sabe eso. PARA REFLEXIONAR NOSIERTO?
 */

/* Che pregunta 2. timeout es un evento que se envia a mano? no hace falta poner un timer que controle, no? */
