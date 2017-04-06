#ifndef ST_IDLE_HPP
#define ST_IDLE_HPP

#include "GenericState.hpp"

class ST_Idle:public genericState
{
public:
	
	genericState* on_s_wrq(genericEvent *ev);
	genericState* on_s_rrq(genericEvent *ev);

};

#endif // !ST_IDLE_HPP

