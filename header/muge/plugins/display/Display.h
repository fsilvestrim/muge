/*
 *  Library.h
 *  Library
 *
 *  Created by Filipe Silvestrim on 9/22/09.
 *  Copyright 2009 Filipe Silvestrim. All rights reserved.
 *
 */

#ifndef __muge__plugins__display__Display_h__
#define __muge__plugins__display__Display_h__

#include "Singleton.h"
using namespace muge::utils::designpattern;

#include "DIGEOElement.h"
using namespace muge::elements::core;

#include <MuGE/FastDelegate.h>
using namespace fastdelegate;

#pragma GCC visibility push(default)
namespace muge 
{
	namespace plugins 
	{
		namespace display 
		{
			class Display: public Singleton< Display >
			{
			private:
				enum primitiveTypeENUM {RECTANGLE, CIRCLE, LINE};
				
				struct primitiveData
				{
					int type;
					int X;
					int Y;
					float wheel; //wheel is how far the wheel has moved
				};
				
			public:
				void		*ref;
				const char	*LIBRARY;
				bool		defined;
				
				void init();
				void setup(int screenW, int screenH, const char *title);
				void config();
				void render();
				void shutDown();
				
				FastDelegate1<DIGEOElement *, void*>	callAddCamera;
				FastDelegate1<DIGEOElement *>			callUpdateCamera;
				void *addCamera(DIGEOElement *);
				void updateCamera(DIGEOElement *);

				FastDelegate1<DIGEOElement *, void*>	callAddGUI;
				FastDelegate1<DIGEOElement *>			callUpdateGUI;
				void *addGUI(DIGEOElement *);
				void updateGUI(DIGEOElement *);

				FastDelegate1<DIGEOElement *, void*>	callAddDisplay;
				FastDelegate1<DIGEOElement *>			callUpdateDisplay;
				void *addDisplay(DIGEOElement *);
				void updateDisplay(DIGEOElement *);
			};			
		}
	}
}
#pragma GCC visibility pop
#endif