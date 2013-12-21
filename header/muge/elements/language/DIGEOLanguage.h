/*
 *  DIGEOScript.h
 *  MuGE
 *
 *  Created by Filipe Silvestrim on 11/26/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __muge__elements__language_Language_h__
#define __muge__elements__language_Language_h__

#include "DIGEOElement.h"
using namespace muge::elements;

#pragma GCC visibility push(default)
namespace muge
{
	namespace elements
	{
		namespace language
		{
			class DIGEOLanguage: public DIGEOElement
			{
			public:
				DIGEOLanguage(const char* tagName, int index = 0, Node* node = NULL):DIGEOElement(tagName, index, node)  {};
				
				void build()
				{
					DIGEOElement::build();
					
					changeState(ACTIVE);
					activateNodeChild();
				};
			};
		}
	}
}
#pragma GCC visibility pop
#endif