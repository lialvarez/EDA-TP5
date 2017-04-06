//
//  ev_s_rrq.hpp
//  TP5
//
//  Created by faq on 4/5/17.
//  Copyright © 2017 faq. All rights reserved.
//

#ifndef ev_s_rrq_hpp
#define ev_s_rrq_hpp

#include <stdio.h>
#include "genericEvent.hpp"

class ev_s_rrq : public genericEvent
{
public:
	ev_s_rrq()	{ ev = S_RRQ; }
};
#endif /* ev_s_rrq_hpp */
