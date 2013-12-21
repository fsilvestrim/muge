/*
 *  Object.h
 *  MuGE-Prototype
 *
 *  Created by Filipe Silvestrim on 9/20/09.
 *  Copyright 2009 Filipe Silvestrim. All rights reserved.
 *
 */

#ifndef __muge__core__kernel__Object_h__
#define __muge__core__kernel__Object_h__

#include <string>
using namespace std;

#include "Log.h"
using namespace muge::utils::debug;

#pragma GCC visibility push(default)
namespace	muge
{
	namespace core
	{
		namespace kernel
		{
			class Object
			{
			public:
				string getClass();
				int hashCode();
				bool equals(Object);
				string toString();
				void notify();
				void notifyAll();
				void wait(long);
				void wait(long, int);
				void wait();
			};
		}
	}
}
#pragma GCC visibility pop
#endif