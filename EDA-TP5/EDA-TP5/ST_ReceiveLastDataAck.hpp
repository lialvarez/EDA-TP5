#ifndef ST_R_LAST_DATA_ACK_HPP
#define ST_R_LAST_DATA_ACK_HPP

#include "genericEvent.hpp"
#include "genericState.hpp"
#include "st_idle.hpp"

class ST_ReceiveLastDataAck : public genericState
{
public:
	genericState* on_ReceiveAck(genericEvent* ev);
	genericState* on_timeout(genericEvent* ev);
};


#endif // !ST_R_LAST_DATA_ACK_HPP
