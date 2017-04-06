#ifndef ST_R_DATA_HPP
#define ST_R_DATA_HPP

#include "GenericState.hpp"

class ST_ReceiveData:public genericState
{
public:
	genericState* on_timeout(genericEvent* ev);
	genericState* on_r_data(genericEvent* ev);
	genericState* on_r_last_data(genericEvent* ev);

};


#endif // !ST_R_DATA_HPP
