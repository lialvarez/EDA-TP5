//
//  ev_r_data.hpp
//  TP5
//
//  Created by faq on 4/5/17.
//  Copyright © 2017 faq. All rights reserved.
//

#ifndef ev_r_data_hpp
#define ev_r_data_hpp

#include <stdio.h>
#include "genericEvent.hpp"

class ev_r_data : public genericEvent
{
public:
	ev_r_data()	{ ev = R_DATA; }
};
#endif /* ev_r_data_hpp */
