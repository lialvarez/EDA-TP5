#ifndef EV_R_ACK_HPP
#define EV_R_ACK_HPP

#include "GenericEvent.hpp"

class EV_ReceiveAckEvent:public genericEvent
{
public:
	EV_ReceiveAckEvent() { ev = R_ACK; }

private:

};

#endif // !EV_R_ACK_HPP