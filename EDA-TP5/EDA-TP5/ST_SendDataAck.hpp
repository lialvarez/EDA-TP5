#ifndef ST_S_DATA_ACK_HPP
#define ST_S_DATA_ACK_HPP

#include "GenericState.hpp"

class ST_SendDataAck:public genericState
{
public:
	genericState* on_s_data(genericEvent* ev);

};
#endif // !ST_S_DATA_ACK_HPP
