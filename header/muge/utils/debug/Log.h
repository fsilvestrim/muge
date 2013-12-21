/*
 *  Log.h
 *  MuGE-Prototype
 *
 *  Created by Filipe Silvestrim on 9/19/09.
 *  Copyright 2009 Filipe Silvestrim. All rights reserved.
 *
 */

#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>

#ifndef __muge__utils__debug__Log_h__
#define __muge__utils__debug__Log_h__

#pragma GCC visibility push(default)
using namespace std;
namespace muge
{
	namespace utils
	{
		namespace debug
		{
			class Log
			{
			private:
				static void printLog(string);
				static void lineBreak(int);
			public:
				static void print(string, int = 0, int = 0);
				static void printf(int size, ... );
				static const char *indet(int numTab );
			};
		}
	}
}
#pragma GCC visibility pop
#endif