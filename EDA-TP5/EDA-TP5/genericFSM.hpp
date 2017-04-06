//
//  genericFSM.hpp
//  TP5
//
//  Created by faq on 4/5/17.
//  Copyright © 2017 faq. All rights reserved.
//

#ifndef genericFSM_hpp
#define genericFSM_hpp

#include <stdio.h>
#include "genericEvent.hpp"
#include "genericState.hpp"

class genericFSM
{
public:
	void Dispatch(genericEvent* ev);
protected:
	genericState* currentState;
};
#endif /* genericFSM_hpp */