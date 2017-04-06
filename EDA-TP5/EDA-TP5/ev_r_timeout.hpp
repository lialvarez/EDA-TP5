//
//  ev_r_timeout.hpp
//  TP5
//
//  Created by faq on 4/5/17.
//  Copyright © 2017 faq. All rights reserved.
//

#ifndef ev_r_timeout_hpp
#define ev_r_timeout_hpp

#include <stdio.h>
class ev_r_timeout : public genericEvent
{
public:
	ev_r_timeout()	{ ev = R_TIMEOUT; }
};
#endif /* ev_r_timeout_hpp */
