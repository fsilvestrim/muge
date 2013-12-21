/*
 *  StringConvert.h
 *  MuGE
 *
 *  Created by Filipe Silvestrim on 10/3/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __muge__utils__string__StringUtil_h__
#define __muge__utils__string__StringUtil_h__

#include <locale>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

#pragma GCC visibility push(default)
namespace muge
{
	namespace utils
	{
		namespace str
		{
			class StringUtil
			{
			public:
				static wstring		widen( const string& str );
				static string		narrow( const wstring& str );
				static void			tokenize(const string& str, vector<string>& tokens, const string& delimiters = " ");
				static float		str_to_float(const string &in);
				static string		float_to_str(float f);
				static int			string_to_hex(const char *szBuf);
			};
		}
	}
}
#pragma GCC visibility pop
#endif