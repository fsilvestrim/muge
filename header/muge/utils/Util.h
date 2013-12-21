/*
 *  Util.h
 *  MuGE
 *
 *  Created by Filipe Silvestrim on 9/29/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __muge__utils__Util_h__
#define __muge__utils__Util_h__

#pragma GCC visibility push(default)
namespace muge
{
	namespace utils
	{

		template <class Type>
		inline const Type &min(const Type &a, const Type &b) {
			return (a < b) ? a : b;
		}

		template <class Type>
		inline const Type &max(const Type &a, const Type &b) {
			return (a > b) ? a : b;
		}

		template <class Type>
		inline void swap(Type &a, Type &b) {
			Type tmp(a);
			a = b;
			b = tmp;
		}
	}
}
#pragma GCC visibility pop
#endif