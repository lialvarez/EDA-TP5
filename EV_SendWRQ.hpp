#ifndef EV_S_WRQ_HPP
#define EV_S_WRQ_HPP

#include "genericEvent.hpp"

class EV_SendWRQ:public genericEvent
{
public:
	EV_SendWRQ() { ev = S_WRQ; }

};


#endif // !EV_S_WRQ_HPP
