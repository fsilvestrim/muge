/*
 *  DIGEOVisual.h
 *  MuGE
 *
 *  Created by Filipe Silvestrim on 11/25/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __muge__elements__Visual_h__
#define __muge__elements__Visual_h__

#include "DIGEOResource.h"
using namespace muge::core::kernel;

#include "Display.h"
using namespace muge::plugins::display;

#include <MuGE/FastDelegate.h>
using namespace fastdelegate;

#pragma GCC visibility push(default)
namespace muge
{
	namespace elements
	{
		class DIGEOVisual: public DIGEOElement
		{
			//				<level id="mainLevel" input="#mainScreen, #mainDisplay">
		private:
			DIGEOResource	*display;
			void			*displayData;
			bool			haveDisplay;
			
			void addDisplay()
			{			
				const char		*idRef		= getAttributeByKey(DIGEOSintax::DIGEO_LanAttr_display);				
				DIGEOElement	*tesDisplay	= getRefByInputString(idRef);
				
				if (tesDisplay != NULL) {
					haveDisplay = true;
					display		= static_cast<DIGEOResource *>(tesDisplay);
					
					setProperty(SIZE, display->getProperty(SCALE, X), display->getProperty(SCALE, Y),display->getProperty(SCALE, Z));
					displayData = Display::getInstance()->callAddDisplay(this);
				}
			};
			
		public:
			
			DIGEOVisual(const char* tagName, int index = 0, Node* node = NULL):DIGEOElement(tagName, index, node) 
			{
				haveDisplay	= false;
				display		= NULL;
				displayData = NULL;
			};
			
			bool getHaveDisplay()
			{
				return haveDisplay;
			}
			
			void build()
			{
				DIGEOElement::build();
				
				if (getDisplay() == NULL) {
					addDisplay();
				}
			}
			
			void linkage()
			{
				DIGEOElement::linkage();
				changeState(ACTIVE);
			}
			
			void step ()
			{
				if (getHaveDisplay())
					if (haveDisplay)
						Display::getInstance()->callUpdateDisplay(this);
			}
			
			DIGEOResource *getDisplay()
			{
				return display;
			}
			
			template<typename T>
			T *getDisplayData()
			{
				return reinterpret_cast<T*>(displayData);
			}
		};
	}
}
#pragma GCC visibility pop
#endif