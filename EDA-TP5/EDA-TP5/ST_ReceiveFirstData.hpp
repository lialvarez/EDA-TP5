#ifndef R_FIRST_DATA_HPP
#define R_FIRST_DATA_HPP

#include "GenericState.hpp"

class ST_ReceiveFirstData:public genericState 
{
public:
	genericState* on_timeout(genericEvent* ev);
	genericState* on_r_data(genericEvent* ev);
	
};

#endif // !R_FIRST_DATA_HPP
