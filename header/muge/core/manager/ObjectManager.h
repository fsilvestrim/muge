/*
 *  ObjectManager.h
 *  MuGE
 *
 *  Created by Filipe Silvestrim on 11/22/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __muge__core__manager__ObjectManager_h__
#define __muge__core__manager__ObjectManager_h__

#include "Singleton.h"
using namespace muge::utils::designpattern;

#include "Object.h"
using namespace muge::core::kernel;

#pragma GCC visibility push(default)
namespace	muge
{
	namespace core
	{
		namespace manager
		{
			class ObjectManager: public Singleton<ObjectManager>, public AbstractManager<Object> {};
		}
	}
}
#pragma GCC visibility pop
#endif