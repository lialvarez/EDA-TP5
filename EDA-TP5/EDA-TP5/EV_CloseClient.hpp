#ifndef EV_CLOSE_CLIENT_HPP
#define EV_CLOSE_CLIENT_HPP

#include "GenericEvent.hpp"

class EV_CloseClient:public genericEvent
{
public:
	EV_CloseClient() { ev = CLOSE_CLIENT; }

private:

};

#endif // !EV_CLOSE_CLIENT_HPP
