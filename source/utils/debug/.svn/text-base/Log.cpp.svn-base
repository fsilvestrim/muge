/*
 *  Log.cpp
 *  MuGE-Prototype
 *
 *  Created by Filipe Silvestrim on 9/19/09.
 *  Copyright 2009 Filipe Silvestrim. All rights reserved.
 *
 */
#include "Log.h"
using namespace muge::utils::debug;

void Log::printLog(string value)
{
	cout << "[MuGE Logger] :: " << value << "\n";
}

void Log::lineBreak(int lines)
{
	for (int i = 0; i <= lines; i++) 
	{
		cout << "\n";
	}
}

void Log::print(string value, int blinesB, int blinesA)
{
	if(blinesB != 0) 
		lineBreak(blinesB);

	Log::printLog(value);

	if(blinesA != 0) 
		lineBreak(blinesA);
}

void Log::printf(int size, ... )
{
	va_list list;
	va_start(list, size);
	
	cout << "[MuGE Logger] :: ";
	
	for(int i = 0; i < size; i++)
	{
		cout << va_arg(list, char*) << " ";
	}
	
	va_end(list);
	
	cout << endl;
}