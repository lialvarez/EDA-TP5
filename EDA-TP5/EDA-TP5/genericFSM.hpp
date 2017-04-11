#ifndef genericFSM_hpp
#define genericFSM_hpp

#include <stdio.h>
#include "genericEvent.hpp"
#include "genericState.hpp"


class genericFSM
{
public:

	genericFSM();   //Crea un estado al que apunta curentState
	~genericFSM();  //Destruye el estado al que apunta currentState

	void Dispatch(genericEvent* ev);    //llama a la funcion del estado al que apunta current state que repsonde al evento recibido
	genericState* getCurrentState();
protected:
	genericState* currentState; //se usa para apuntar a los estados, que son objetos de una clase que hereda la clase genericState
};
#endif /* genericFSM_hpp */
