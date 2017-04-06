//
//  ev_s_last_data.hpp
//  TP5
//
//  Created by faq on 4/5/17.
//  Copyright © 2017 faq. All rights reserved.
//

#ifndef ev_s_last_data_hpp
#define ev_s_last_data_hpp

#include <stdio.h>
class ev_s_last_data : public genericEvent
{
public:
	ev_s_last_data()	{ ev = S_LAST_DATA; }
};
#endif /* ev_s_last_data_hpp */
