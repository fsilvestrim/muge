/*
 *  DigeoEventListener.h
 *  MuGE
 *
 *  Created by Filipe Silvestrim on 12/3/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __muge__elements__EventListener_h__
#define __muge__elements__EventListener_h__

#include "DIGEOElement.h"
using namespace muge::core::kernel;


#pragma GCC visibility push(default)
namespace muge
{
	namespace elements
	{
		class DIGEOEventListener: public DIGEOElement
		{
			//			<listener id="winCondition" input="#collisionGoal1, #collisionGoal2" filterExpression="#scoreP1.value > 9 || #scoreP2.value > 9">
			//			<eventDispatcher id="collisionGoal1" />
		public:
			DIGEOEventListener(const char* tagName, int index = 0, Node* node = NULL):DIGEOElement(tagName, index, node)  {};
			
			void build()
			{
				DIGEOElement::build();
				
				changeState(ACTIVE);
			};		
			
			void eventHandler (Event *e)
			{
				for ( it_childrens = childrens.begin() ; it_childrens != childrens.end(); it_childrens++ )
					((DIGEOElement *)(*it_childrens).second)->changeState(DIGEOElement::ACTIVE);
			}
			
			void linkage()
			{	
				DIGEOElement::linkage();
				
				int len = getInputsCount();
				const char		*attrValue;
				DIGEOElement	*elem;
				
				//typedef void (*MyFuncPtrType)(Event *);
				
				FastDelegate1<Event *> delegate;
				delegate.bind(&*this, &DIGEOEventListener::eventHandler);
				
				
				for (int i = 0; i < len; i++) {
					attrValue = getInput(i)->getValue();
					elem = getRefByInputString(attrValue);
					if (elem != NULL) {
						elem->addEventListener(attrValue, delegate);
					}
				}
			}
		};
	}
}
#pragma GCC visibility pop
#endif