#ifndef ST_S_LAST_DATA_ACK_HPP
#define ST_S_LAST_DATA_ACK_HPP

#include "GenericState.hpp"

class ST_SendLastDataAck:public genericState
{
public:
	genericState* on_s_data_ack(genericEvent* ev);
	genericState* on_timeout(genericEvent* ev);

private:

};

#endif // !ST_S_LAST_DATA_ACK_HPP
