/*
 *  DIGEOElements.h
 *  MuGE
 *
 *  Created by Filipe Silvestrim on 11/19/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef __muge__elements__core__DIGEOManager_h__
#define __muge__elements__core__DIGEOManager_h__

#include "AbstractManager.h"
using namespace muge::utils::manager;

#include "Singleton.h"
using namespace muge::utils::designpattern;

#include "StringUtil.h"
using namespace muge::utils::str;

#pragma GCC visibility push(default)
namespace muge
{
	namespace elements
	{
		namespace core
		{		
			class DIGEOElement;
		
			class DIGEOManager: public Singleton<DIGEOManager>, public AbstractManager<DIGEOElement>
			{
			public:
				void			buildElement(const char *);
				void			destroyElement(const char *);
				void			processElement(const char *);
				
				void addElement(DIGEOElement *elem, const char *id)
				{
					if (id)
						addChild(id, elem);
					else
						addChild(elem);
				};
				
				DIGEOElement *getElement(const char *name)
				{
					return getChildByName(name);
				};
				
				DIGEOElement *getRefByInputString(string s)
				{
					vector<string>				inputRef;
					StringUtil::tokenize(s, inputRef, ",");
					
					const char *idRef = ((string)inputRef[1]).c_str();
					
					if (inputRef.size() > 0) {
						return getElement(idRef);
					}
					
					return NULL;
				}
			};
		}
	}
}
#pragma GCC visibility pop
#endif
