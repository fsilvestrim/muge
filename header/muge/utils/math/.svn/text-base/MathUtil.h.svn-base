/*
 *  MathUtils.h
 *  MuGE
 *
 *  Created by Filipe Silvestrim on 9/29/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef __muge__utils__math__Math_h__
#define __muge__utils__math__Math_h__

#define PI 3.14159265

#pragma GCC visibility push(default)
namespace muge
{
	namespace utils
	{
		namespace math
		{
			class Math 
			{
			public:
				static const float PI = 3.14159265f;
				static const float k2Pi = kPi * 2.0f;
				static const float kPiOver2 = kPi / 2.0f;
				static const float k1OverPi = 1.0f / kPi;
				static const float k1Over2Pi = 1.0f / k2Pi;
				static const float kPiOver180 = kPi / 180.0f;
				static const float k180OverPi = 180.0f / kPi;

				static float	normalize(float, float, float);
				static float	toRange(float, float, float);
				static float	sign(float, float);
				static float	trim(float, float, float, bool);
				static float	wrap(float, float, float, bool);
				static float	degToRad(float);
				static float	radToDeg(float);
				static float	precision(float, float);
				static float	uceil(float);
				static bool		isInRagne(float, float, float, bool);	
			};
		}
	}
}