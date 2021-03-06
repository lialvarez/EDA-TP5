#ifndef ST_R_WRQ_ACK_HPP
#define ST_R_WRQ_ACK_HPP

#include "genericState.hpp"

class ST_ReceiveWRQAck : public genericState
{
public:

	ST_ReceiveWRQAck();

	genericState* on_ReceiveAck(genericEvent* ev);
	genericState* on_timeout(genericEvent* ev);
	genericState* on_ReceiveError(genericEvent* ev);
};

#endif // !ST_R_WRQ_ACK_HPP
