/*
 *  Singleton.h
 *  MuGE-Prototype
 *
 *  Created by Filipe Silvestrim on 9/19/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __muge__utils__designpattern__Singleton_h__
#define __muge__utils__designpattern__Singleton_h__

#include <string>
#include <vector>
#include <exception>
#include <stdio.h>
#include <assert.h>
using namespace std;

#pragma GCC visibility push(default)
namespace muge
{
	namespace utils
	{
		namespace designpattern
		{
			template <class C>
			class Singleton
			{
			private:
				static C *instance;
				Singleton(const Singleton& source){};
				
			protected:
				Singleton() {};
				virtual ~Singleton() {};
				
			public:
				static C *getInstance()
				{
					if(instance == 0)
						instance = new C;
					else
						assert(instance != NULL);
					
					return instance;
				}
				
				static void destroyInstance()
				{
					delete instance;
					instance = 0;
				};
			};
			
			//! static class member initialisation.
			template <typename C> C* Singleton<C>::instance = 0;
		}
	}
}

using namespace muge::utils::designpattern;
#pragma GCC visibility pop
#endif