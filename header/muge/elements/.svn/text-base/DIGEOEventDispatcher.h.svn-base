/*
 *  Listener.h
 *  MuGE
 *
 *  Created by Filipe Silvestrim on 11/24/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __muge__elements__EventDispatcher_h__
#define __muge__elements__EventDispatcher_h__

#include "DIGEOElement.h"
using namespace muge::core::kernel;


#pragma GCC visibility push(default)
namespace muge
{
	namespace elements
	{
		class DIGEOEventDispatcher: public DIGEOElement
		{
		private:
			Event *event;
			
		public:
			DIGEOEventDispatcher(const char* tagName, int index = 0, Node* node = NULL):DIGEOElement(tagName, index, node)  {};
			
			void build()
			{
				DIGEOElement::build();
			};		
			
			void linkage()
			{	
				DIGEOElement::linkage();
				
				event = new Event(getId());
			}
			
			void step()
			{
				if (getState() == ACTIVE) {
					dispatchEvent(event);
					changeState(INACTIVE);
				}				
			}
		};
	}
}
#pragma GCC visibility pop
#endif