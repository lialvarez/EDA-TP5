//
//  ev_s_ack.hpp
//  TP5
//
//  Created by faq on 4/5/17.
//  Copyright © 2017 faq. All rights reserved.
//

#ifndef ev_s_ack_hpp
#define ev_s_ack_hpp

#include <stdio.h>
#include "genericEvent.hpp"

class ev_s_ack : public genericEvent
{
public:
	ev_s_ack()	{ ev = S_ACK; }
};
#endif /* ev_s_ack_hpp */
