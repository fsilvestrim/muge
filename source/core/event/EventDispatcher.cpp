
#include "EventDispatcher.h"
#include "FastDelegate.h"
using namespace muge::core::event;
using namespace fastdelegate;

void EventDispatcher::addEventListener(const char *type, FastDelegate1<Event *> delegate)
{	
	//list -> push
	_mapListeners[type] = delegate;
}

bool EventDispatcher::dispatchEvent(Event *event)
{
	FastDelegate1<Event *> delegate;
	
	for ( _it_mapListeners = _mapListeners.begin(); _it_mapListeners != _mapListeners.end(); _it_mapListeners++ )
	{
		delegate = (*_it_mapListeners).second;
		delegate(event);
	}
	
	return 0;
}

bool EventDispatcher::hasEventListener(const char *type)
{
	return _mapListeners.count(type) > 0;
}

void EventDispatcher::removeEventListener(const char * type, void *handler)
{
	_mapListeners.erase(type);
}

bool EventDispatcher::willTrigger(const char * type)
{
	return 0;
}