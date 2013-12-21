/*
 *  DIGEOCamera.h
 *  MuGE
 *
 *  Created by Filipe Silvestrim on 11/24/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __muge__elements__Camera_h__
#define __muge__elements__Camera_h__

#include "DIGEOElement.h"
using namespace muge::core::kernel;


#pragma GCC visibility push(default)
namespace muge
{
	namespace elements
	{
		class DIGEOCamera: public DIGEOElement
		{
		private:
			void *displayData;
			
		public:
			enum CAMERA_TYPE {
				FIXED,
				TRACKED,
				FREE,
				MOVABLE,
			} camType;
			
			float distance[3];
			
			DIGEOCamera(const char* tagName, int index = 0, Node* node = NULL):DIGEOElement(tagName, index, node) 
			{
				displayData = NULL;
			};
			
			void build()
			{
				DIGEOElement::build();				
				changeState(ACTIVE);
				
				if (displayData == NULL)
					displayData = Display::getInstance()->callAddCamera(this);
			}
			
			void linkage()
			{
				DIGEOElement::linkage();
				
				const char *atrType		= getAttributeByKey(DIGEOSintax::DIGEO_LanAttr_type);
				const char *atrPosition	= getAttributeByKey(DIGEOSintax::DIGEO_LanAttr_position);
				const char *atrTarget	= getAttributeByKey(DIGEOSintax::DIGEO_LanAttr_target);
				const char *atrDist		= getAttributeByKey(DIGEOSintax::DIGEO_LanAttr_distance);
				
				//position
				if (strcmp(atrPosition, "null")) {
					vector<string> vecPosition = getAttributeValues(DIGEOSintax::DIGEO_LanAttr_position);
					setProperty(DIGEOElement::POSITION, atof(vecPosition[0].c_str()), atof(vecPosition[1].c_str()), atof(vecPosition[2].c_str()));
				}
				
				//distance
				if (strcmp(atrDist, "null")) {
					vector<string> vecDist = getAttributeValues(DIGEOSintax::DIGEO_LanAttr_distance);
					distance[0] = atof(vecDist[0].c_str());
					distance[1] = atof(vecDist[1].c_str());
					distance[2] = atof(vecDist[2].c_str());
				}
				
				//target
				if (strcmp(atrTarget, "null")) {
					vector<string> vecTarget = getAttributeValues(DIGEOSintax::DIGEO_LanAttr_target);
					
					if (vecTarget.size() == 1)
						addTarget();
					else
						setProperty(DIGEOElement::TARGET3, atof(vecTarget[0].c_str()), atof(vecTarget[1].c_str()), atof(vecTarget[2].c_str()));
				}
				
				//type
				if (!strcmp (atrType, "fixed"))
					camType = FIXED;
				else if (!strcmp (atrType, "tracked"))
					camType = TRACKED;
				else if (!strcmp (atrType, "free"))
					camType = FREE;
				else if (!strcmp (atrType, "movable"))
					camType = MOVABLE;
				
			}
			
			void step ()
			{
				if (displayData != NULL)
					Display::getInstance()->callUpdateCamera(this);
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