#ifndef EV_S_RRQ_HPP
#define EV_S_RRQ_HPP

#include "genericEvent.hpp"

class EV_SendRRQ: public genericEvent
{
public:
	EV_SendRRQ() { ev = S_RRQ; }

};



#endif // !EV_S_RRQ_HPP
