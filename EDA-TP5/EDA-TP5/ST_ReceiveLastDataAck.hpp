#ifndef ST_R_LAST_DATA_ACK_HPP
#define ST_R_LAST_DATA_ACK_HPP

#include "GenericState.hpp"

class ST_ReceiveLastDataAck:public genericState
{
public:
	genericState* on_r_data_ack(genericEvent* ev);
	genericState* on_timeout(genericEvent* ev);

};


#endif // !ST_R_LAST_DATA_ACK_HPP
