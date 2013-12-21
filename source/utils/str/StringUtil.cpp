/*
 *  StringUtil.cpp
 *  MuGE
 *
 *  Created by Filipe Silvestrim on 10/3/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "StringUtil.h"
using namespace muge::utils::str;

wstring StringUtil::widen( const string &str )
{
	wostringstream wstm ;
	const ctype<wchar_t>& ctfacet = 
	use_facet< ctype<wchar_t> >( wstm.getloc() ) ;
	for( size_t i=0 ; i<str.size() ; ++i ) 
		wstm << ctfacet.widen( str[i] ) ;
	return wstm.str() ;
};

string StringUtil::narrow( const wstring &str )
{
	ostringstream stm ;
	const ctype<char>& ctfacet = 
	use_facet< ctype<char> >( stm.getloc() ) ;
	for( size_t i=0 ; i<str.size() ; ++i ) 
		stm << ctfacet.narrow( str[i], 0 ) ;
	return stm.str() ;
};

void StringUtil::tokenize(const string& str, vector<string>& tokens, const string& delimiters)
{
    // Skip delimiters at beginning.
    string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    // Find first "non-delimiter".
    string::size_type pos     = str.find_first_of(delimiters, lastPos);
	
    while (string::npos != pos || string::npos != lastPos)
    {
        // Found a token, add it to the vector.
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        // Skip delimiters.  Note the "not_of"
        lastPos = str.find_first_not_of(delimiters, pos);
        // Find next "non-delimiter"
        pos = str.find_first_of(delimiters, lastPos);
    }
}

float StringUtil::str_to_float(const string &in)
{
    ostringstream o(in); 
	float f;
	o << f; 
	return f;
}

string StringUtil::float_to_str(float f)
{
    istringstream i; 
	i >> f; 
	return i.str();
}

int StringUtil::string_to_hex(const char *szBuf)
{
	char* szStop;
	strtol( szBuf, &szStop, 16 );
	
	return (int)szStop;
}