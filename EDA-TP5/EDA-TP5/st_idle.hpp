//
//  st_idle.hpp
//  TP5
//
//  Created by faq on 4/5/17.
//  Copyright © 2017 faq. All rights reserved.
//

#ifndef st_idle_hpp
#define st_idle_hpp

#include <stdio.h>
#include <iostream>
#include "genericState.hpp"
#include "genericEvent.hpp"

#include "st_idle.hpp"

#include "st_r_wrq_ack.hpp"
#include "st_s_data.hpp"
#include "st_r_ack.cpp"
#include "st_r_last_data_ack.hpp"

#include "st_r_first_data.hpp"
#include "st_s_ack.hpp"
#include "st_r_data.hpp"
#include "st_s_last_data_ack.hpp"v

class st_idle : public genericState
{
public:
	virtual genericState* on_s_wrq(genericEvent* ev);
	virtual genericState* on_s_rrq(genericEvent* ev);
	virtual genericState* on_r_wrq_ack(genericEvent* ev);
	virtual genericState* on_s_data(genericEvent* ev);
	virtual genericState* on_r_data(genericEvent* ev);
	virtual genericState* on_s_data_ack(genericEvent* ev);
	virtual genericState* on_r_data_ack(genericEvent* ev);
	virtual genericState* on_s_last_data(genericEvent* ev);
	virtual genericState* on_r_last_data(genericEvent* ev);
	virtual genericState* on_timeout(genericEvent* ev);
};

#endif /* st_idle_hpp */
