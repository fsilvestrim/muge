/*
 *  Score.h
 *  MuGE
 *
 *  Created by Filipe Silvestrim on 11/24/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __muge__elements__Score_h__
#define __muge__elements__Score_h__

#include "DIGEOElement.h"
using namespace muge::core::kernel;


#pragma GCC visibility push(default)
namespace muge
{
	namespace elements
	{
		class DIGEOScore: public DIGEOElement
		{
//			<score id="scoreP1" type="int" input="0"/>
//			<score id="scoreP2" type="int" input="0"/>
		public:
			float value;
		};
	}
}
#pragma GCC visibility pop
#endif