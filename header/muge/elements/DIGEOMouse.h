/*
 *  DIGEOMouse.h
 *  MuGE
 *
 *  Created by Filipe Silvestrim on 11/26/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __muge__elements__Mouse_h__
#define __muge__elements__Mouse_h__

#include "DIGEOInput.h"
using namespace muge::elements;

#pragma GCC visibility push(default)
namespace muge
{
	namespace elements
	{
		class DIGEOMouse: public DIGEOInput
		{
		public:
			void mouseLeftPressed(EKEY_CODE key, DIGEOObject * target)
			{
				if(Kernel::getInstance()->receiver->leftMouseDown())
					for ( it_childrens = childrens.begin() ; it_childrens != childrens.end(); it_childrens++ )
						((DIGEOElement *)(*it_childrens).second)->changeState(DIGEOElement::ACTIVE);
			}
		};
	}
}
#pragma GCC visibility pop
#endif