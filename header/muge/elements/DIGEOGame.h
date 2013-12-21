/*
 *  Game.h
 *  MuGE
 *
 *  Created by Filipe Silvestrim on 11/24/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __muge__game__Game_h__
#define __muge__game__Game_h__

#include <map>
#include <iostream>
using namespace std;

#include "DIGEOElement.h"
using namespace muge::core::kernel;

#pragma GCC visibility push(default)
namespace muge
{
	namespace elements
	{
		class DIGEOGame: public DIGEOElement
		{	
		public:
			DIGEOGame(const char* tagName, int index = 0, Node* node = NULL):DIGEOElement(tagName, index, node)  {};

			void build()
			{
				DIGEOElement::build();
				
				changeState(ACTIVE);
				activateNodeChild();
			};			
		};
	}
}
#pragma GCC visibility pop
#endif
