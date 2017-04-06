//
//  genericEvent.hpp
//  TP5
//
//  Created by faq on 4/5/17.
//  Copyright © 2017 faq. All rights reserved.
//

#ifndef genericEvent_hpp
#define genericEvent_hpp

#include <stdio.h>

typedef enum {NO_EV, S_WRQ, S_RRQ, R_WRQ_ACK, S_DATA, R_DATA, S_ACK, R_ACK, S_LAST_DATA, R_LAST_DATA, R_TIMEOUT } event_t;

class genericEvent
{
public:
	genericEvent() { ev = NO_EV; }
	event_t getEvent() { return ev; }
protected:
	event_t ev;
};

#endif /* genericEvent_hpp */
