#ifndef ST_IDLE_HPP
#define ST_IDLE_HPP

#include <iostream>
#include "genericEvent.hpp"
#include "genericState.hpp"

class ST_Idle:public genericState
{
public:

	ST_Idle();

	genericState* on_SendWRQ(genericEvent *ev);
	genericState* on_SendRRQ(genericEvent *ev);
	genericState* on_SendError(genericEvent* ev);
	genericState* on_CloseClient(genericEvent* ev);
};


#endif // !ST_IDLE_HPP

