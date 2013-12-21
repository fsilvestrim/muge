/*
 *  DIGEOScript.h
 *  MuGE
 *
 *  Created by Filipe Silvestrim on 11/26/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __muge__elements__language_Config_h__
#define __muge__elements__language_Config_h__

#include "DIGEOLanguage.h"


#pragma GCC visibility push(default)
namespace muge
{
	namespace elements
	{
		namespace language
		{
			class DIGEOConfig: public DIGEOLanguage
			{
			private:
				int countActivate;
				
			public:
				DIGEOConfig(const char* tagName, int index = 0, Node* node = NULL):DIGEOLanguage(tagName, index, node)  
				{
					countActivate = 0;
				};
				
				void build()
				{
					DIGEOLanguage::build();

					changeState(ACTIVE);
					activateNodeChild();
				};
			};
		}
	}
}
#pragma GCC visibility pop
#endif