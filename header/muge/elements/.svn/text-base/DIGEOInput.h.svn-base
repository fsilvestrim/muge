/*
 *  Input.h
 *  MuGE
 *
 *  Created by Filipe Silvestrim on 11/24/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __muge__elements__Input_h__
#define __muge__elements__Input_h__

#include "DIGEOObject.h"
using namespace muge::core::kernel;

#include "Kernel.h"
using namespace muge::core;

#pragma GCC visibility push(default)
namespace muge
{
	namespace elements
	{
		class DIGEOInput: public DIGEOElement
		{
		public:
			DIGEOInput(const char* tagName, int index = 0, Node* node = NULL):DIGEOElement(tagName, index, node)  {};
			
			void build()
			{
				DIGEOElement::build();
				processType			= PROCESS;
				
				changeState(ACTIVE);
				activateNodeChild();
			}
		};
	}
}
#pragma GCC visibility pop
#endif