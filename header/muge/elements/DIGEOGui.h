/*
 *  DIGEOGui.h
 *  MuGE
 *
 *  Created by Filipe Silvestrim on 12/13/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __muge__elements__GUI_h__
#define __muge__elements__GUI_h__

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
		class DIGEOGui: public DIGEOElement
		{
		private:
			void *displayData;
			
		public:
			enum GUI_TYPE {
				TEXT,
			} guiType;
			
			DIGEOGui(const char* tagName, int index = 0, Node* node = NULL):DIGEOElement(tagName, index, node) 
			{
			};
			
			void build()
			{
				DIGEOElement::build();				
				changeState(ACTIVE);
			}
			
			void linkage()
			{
				DIGEOElement::linkage();
				
				const char *atrType		= getAttributeByKey(DIGEOSintax::DIGEO_LanAttr_type);
				const char *atrPosition	= getAttributeByKey(DIGEOSintax::DIGEO_LanAttr_position);
				const char *atrValue	= getAttributeByKey(DIGEOSintax::DIGEO_LanAttr_value);
				
				//position
				if (strcmp(atrPosition, "null")) {
					vector<string> vecPosition = getAttributeValues(DIGEOSintax::DIGEO_LanAttr_position);
					setProperty(DIGEOElement::POSITION, atof(vecPosition[0].c_str()), atof(vecPosition[1].c_str()), atof(vecPosition[2].c_str()));
				}
				
				//size
				if(strcmp(getAttributeByKey(DIGEOSintax::DIGEO_LanAttr_size), "null"))
				{
					vector<string> vecSizeStr = getAttributeValues(DIGEOSintax::DIGEO_LanAttr_size);
					setProperty(DIGEOElement::SIZE, atof(vecSizeStr[0].c_str()), atof(vecSizeStr[1].c_str()), atof(vecSizeStr[2].c_str()));
				}
				
				//value
				if (strcmp(atrValue, "null")) {
					setPropertySingle(VALUE, atrValue);
				}
				
				//type
				if (!strcmp (atrType, "textField"))
					guiType = TEXT;
				
				if (displayData == NULL)
					displayData = Display::getInstance()->callAddGUI(this);
			}
			
			void step ()
			{
				if (displayData != NULL)
					Display::getInstance()->callUpdateGUI(this);
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