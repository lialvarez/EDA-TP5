#ifndef ST_S_DATA_HPP
#define ST_S_DATA_HPP

#include "genericEvent.hpp"
#include "genericState.hpp"
#include "ST_ReceiveDataAck.hpp"
#include "ST_ReceiveLastDataAck.hpp"

class ST_SendData : public genericState
{
public:
    genericState* on_SendData(genericEvent* ev);
	genericState* on_SendLastData(genericEvent* ev);
};


#endif // !ST_S_DATA_HPP

