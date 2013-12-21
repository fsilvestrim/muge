/*
 *  Attribute.h
 *  MuGE
 *
 *  Created by Filipe Silvestrim on 10/3/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __muge__core__kernel__Attribute_h__
#define __muge__core__kernel__Attribute_h__

#include <string>
#include <exception>
using namespace std;

#pragma GCC visibility push(default)
namespace muge
{
	namespace core
	{
		namespace kernel
		{
			struct Attribute
			{
			private:
				const char *key;
				const char *value;
				
			public:
				void setKey(const char *val)
				{
					int size	= strlen(val);
					key		= new char[size+1];
					strcpy((char *)key,val);
				};
				
				void setValue(const char *val)
				{
					int size	= strlen(val);
					value		= new char[size+1];
					strcpy((char *)value,val);
				};
				
				const char * getKey()
				{
					return key;
				};

				const char * getValue()
				{
					return value;
				};
				
			};
		}
	}
}
#pragma GCC visibility pop
#endif
