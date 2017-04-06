#ifndef ST_S_DATA_HPP
#define ST_S_DATA_HPP

#include "GenericEvent.hpp"
#include "GenericState.hpp"

class SendDataState:public genericState
{
public:
	
	virtual genericState* on_s_data(genericEvent* ev);
	virtual genericState* on_s_last_data(genericEvent* ev);
	virtual genericState* on_timeout(genericEvent* ev);

};


#endif // !ST_S_DATA_HPP

