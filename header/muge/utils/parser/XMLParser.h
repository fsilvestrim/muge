/*
 *  XMLParser.h
 *  MuGE
 *
 *  Created by Filipe Silvestrim on 11/18/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __muge__utils__parser__XMLParser_h__
#define __muge__utils__parser__XMLParser_h__

#include "DIGEOGame.h"
using namespace muge::elements;

#pragma GCC visibility push(default)
namespace muge
{
	namespace utils
	{
		namespace parser
		{
			class XMLParser
			{
			public:
				static void load( const char *filename);
			};
		}
	}
}
#pragma GCC visibility pop
#endif