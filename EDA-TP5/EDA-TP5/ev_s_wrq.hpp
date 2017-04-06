//
//  ev_s_wrq.hpp
//  TP5
//
//  Created by faq on 4/5/17.
//  Copyright © 2017 faq. All rights reserved.
//

#ifndef ev_s_wrq_hpp
#define ev_s_wrq_hpp

#include <stdio.h>
#include "genericEvent.hpp"

class ev_s_wrq : public genericEvent
{
public:
	ev_s_wrq()	{ ev = S_WRQ; }
};

#endif /* ev_s_wrq_hpp */
