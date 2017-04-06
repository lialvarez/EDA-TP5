#ifndef EV_S_DATA_HPP
#define EV_S_DATA_HPP

#include "GenericEvent.hpp"

class EV_SendData:public genericEvent
{
public:
	EV_SendData() { ev = S_DATA; }

};

#endif // !EV_S_DATA_HPP
