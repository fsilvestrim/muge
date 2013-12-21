/*
 *  Event.cpp
 *  MuGE-Prototype
 *
 *  Created by Filipe Silvestrim on 9/19/09.
 *  Copyright 2009 Filipe Silvestrim. All rights reserved.
 *
 */

#include "Event.h"

using namespace muge::core::event;

const char *Event::DEFAULT		= "event_default";
const char *Event::MESSAGE		= "event_message";
const char *Event::TRIGGER		= "event_trigger";

Event::Event (const char *type)
{
	evtType = type;
}

const char *Event::getType()
{
	return evtType;
}