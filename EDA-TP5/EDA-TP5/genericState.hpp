#ifndef GENERIC_STATE_H
#define GENERIC_STATE_H

#include "GenericEvent.hpp"

class genericState
{
public:

	virtual genericState* on_s_wrq(genericEvent* ev) { return nullptr; };
	virtual genericState* on_s_rrq(genericEvent* ev) { return nullptr; };
	virtual genericState* on_r_wrq_ack(genericEvent* ev) { return nullptr; };
	virtual genericState* on_s_data(genericEvent* ev) { return nullptr; };
	virtual genericState* on_r_data(genericEvent* ev) { return nullptr; };
	virtual genericState* on_s_data_ack(genericEvent* ev) { return nullptr; };
	virtual genericState* on_r_data_ack(genericEvent* ev) { return nullptr; };
	virtual genericState* on_s_last_data(genericEvent* ev) { return nullptr; };
	virtual genericState* on_r_last_data(genericEvent* ev) { return nullptr; };
	virtual genericState* on_timeout(genericEvent* ev) { return nullptr; };

	event_t previousActionExecuted;

protected:



};

#endif // !GENERIC_STATE_H
