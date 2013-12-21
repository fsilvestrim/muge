/*
 *  Event.h
 *  MuGE-Prototype
 *
 *  Created by Filipe Silvestrim on 9/19/09.
 *  Copyright 2009 Filipe Silvestrim. All rights reserved.
 *
 */

#ifndef __muge__core__event__Event_h__
#define __muge__core__event__Event_h__

#include <string>
#include <vector>
#include <exception>
using namespace std;


#include "Object.h"
using namespace muge::core::kernel;

#pragma GCC visibility push(default)
namespace muge
{
	namespace core
	{
		namespace event
		{
			class Event : public Object
			{
			private:
				Object		*currentTarget;
				Object		*target;
				const char	*evtType;
				
			public:
				static const char *DEFAULT;
				static const char *MESSAGE;
				static const char *TRIGGER;
				
				Event(const char*);
				Event			clone();
				void			stopImmediatePropagation();
				void			stopPropagation();
				virtual string	toString () { return "[MuGE Event]"; };
				
				Object			*getCurrentTarget();
				Object			*getTarget();
				const char		*getType();
			};
		}
	}
}
#pragma GCC visibility pop
#endif