//
//  ev_r_wrq_ack.hpp
//  TP5
//
//  Created by faq on 4/5/17.
//  Copyright © 2017 faq. All rights reserved.
//

#ifndef ev_r_wrq_ack_hpp
#define ev_r_wrq_ack_hpp

#include <stdio.h>
#include "genericEvent.hpp"

class ev_r_wrq_ack : public genericEvent
{
public:
	ev_r_wrq_ack()	{ ev = R_WRQ_ACK; }
};
#endif /* ev_r_wrq_ack_hpp */
