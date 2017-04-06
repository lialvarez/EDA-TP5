//
//  ev_s_data.hpp
//  TP5
//
//  Created by faq on 4/5/17.
//  Copyright © 2017 faq. All rights reserved.
//

#ifndef ev_s_data_hpp
#define ev_s_data_hpp

#include <stdio.h>
#include "genericEvent.hpp"

class ev_s_data : public genericEvent
{
public:
	ev_s_data()	{ ev = S_DATA; }
};
#endif /* ev_s_data_hpp */
