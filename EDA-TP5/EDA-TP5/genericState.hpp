#ifndef genericState_hpp
#define genericState_hpp

#include <stdio.h>
#include "genericEvent.hpp"

class genericState
{
public:
	genericState* on_s_wrq(genericEvent* ev) { return nullptr; };
	genericState* on_s_rrq(genericEvent* ev) { return nullptr; };
	genericState* on_r_wrq_ack(genericEvent* ev) { return nullptr; };
	genericState* on_s_data(genericEvent* ev) { return nullptr; };
	genericState* on_r_data(genericEvent* ev) { return nullptr; };
	genericState* on_s_data_ack(genericEvent* ev) { return nullptr; };
	genericState* on_r_data_ack(genericEvent* ev) { return nullptr; };
	genericState* on_s_last_data(genericEvent* ev) { return nullptr; };
	genericState* on_r_last_data(genericEvent* ev) { return nullptr; };
	genericState* on_timeout(genericEvent* ev) { return nullptr; };
};

#endif /* genericState_hpp */
