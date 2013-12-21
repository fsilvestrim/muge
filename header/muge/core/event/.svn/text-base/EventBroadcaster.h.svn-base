/*
 *  EventBroadcaster.h
 *  MuGE-Prototype
 *
 *  Created by Filipe Silvestrim on 9/19/09.
 *  Copyright 2009 Filipe Silvestrim. All rights reserved.
 *
 */

#ifndef __muge__core__event__EventBroadcaster_h__
#define __muge__core__event__EventBroadcaster_h__

#include <string>
#include <vector>
#include <exception>
#include <map>

#include "EventDispatcher.h"
#include "Singleton.h"
#include "Object.h"

#pragma GCC visibility push(default)
namespace muge
{
	namespace core
	{
		namespace event
		{
			class EventBroadcaster: public Singleton<EventBroadcaster>, public EventDispatcher
			{	
			private:
				Object		*_source;
				bool		_wasInit;
				bool		_automaticInit;
				
				map<string, EventDispatcher *> mapEvts;
				
				static void internalBroadcastEvent( Event *holder, Event *e );
				
			public:
				void teste ();
				void init( Object *);
				bool isRegistered(Object *listener, string type = NULL );
				bool addEventListener( string type, Object listener, vector<string> rest );
				bool removeEventListener( string type, Object *listener );
				void dispatchEvent( Object *o );
				void broadcastEvent( Event *e );
			};
		}
	}
}
#pragma GCC visibility pop
#endif
