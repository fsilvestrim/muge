#include <string>
#include <vector>
#include <exception>
#include <map>
using namespace std;

#ifndef __muge__core__event__EventDispatcher_h__
#define __muge__core__event__EventDispatcher_h__

#include "Object.h"
#include "Event.h"
#include "FastDelegate.h"
using namespace muge::core::kernel;
using namespace muge::core::event;
using namespace fastdelegate;

#pragma GCC visibility push(default)
namespace muge
{
	namespace core
	{
		namespace event
		{
			class EventDispatcher: public Object
			{
			private:
				map<string, FastDelegate1<Event*, void> >				_mapListeners;
				map<string, FastDelegate1<Event*, void> >::iterator		_it_mapListeners;
				map<string, FastDelegate1<Event*, void> >::key_compare	_comp_mapListeners;
				
			public:
				/**
				 * Registers an event listener object with an EventDispatcher object so that the listener receives notification of an event.
				 */
				virtual void addEventListener(const char *, FastDelegate1<Event *> delegate);
				
				/**
				 * Dispatches an event into the event flow.
				 */
				virtual bool dispatchEvent(Event *);
				
				/**
				 * Checks whether the EventDispatcher object has any listeners registered for a specific type of event.
				 */
				virtual bool hasEventListener(const char *);
				
				/**
				 * Removes a listener from the EventDispatcher object.
				 */
				virtual void removeEventListener(const char *, void *);
				
				/**
				 * Checks whether an event listener is registered with this EventDispatcher object or any of its ancestors for the specified event type.
				 */
				virtual bool willTrigger(const char *);
			};
		}
	}
}
#pragma GCC visibility pop
#endif
