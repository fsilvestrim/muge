/*
 *  DIGEOBound.h
 *  MuGE
 *
 *  Created by Filipe Silvestrim on 11/24/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __muge__elements__Bound_h__
#define __muge__elements__Bound_h__

#include "DIGEOElement.h"
using namespace muge::core::kernel;


#pragma GCC visibility push(default)
namespace muge
{
	namespace elements
	{
		class DIGEOBound: public DIGEOElement
		{
//			<bound id="room" from="0,0,0" to="100,100,0" collision="true"/>
		public:
			DIGEOBound(const char* tagName, int index = 0, Node* node = NULL):DIGEOElement(tagName, index, node)  {};
			
			void build()
			{
				DIGEOElement::build();
				processType = PROCESS;
				changeState(ACTIVE);
			}
			
			void linkage()
			{
				vector<string> vecPosStr = getAttributeValues(DIGEOSintax::DIGEO_LanAttr_from);
				setProperty(DIGEOElement::POSITION, atof(vecPosStr[0].c_str()), atof(vecPosStr[1].c_str()), atof(vecPosStr[2].c_str()));
				
				vector<string> vecSizeStr = getAttributeValues(DIGEOSintax::DIGEO_LanAttr_to);
				setProperty(DIGEOElement::SIZE, atof(vecSizeStr[0].c_str()) - atof(vecPosStr[0].c_str()), atof(vecSizeStr[1].c_str()) - atof(vecPosStr[1].c_str()), atof(vecSizeStr[2].c_str()) - atof(vecPosStr[2].c_str()));
				
				DIGEOElement::linkage();
			}
			
			void step()
			{
				checkCollision();
			}
			
			void checkCollision()
			{
				DIGEOElement	*elem;
				float			radius, right, left, top, bottom;
				int				numObj = DIGEOObjectManager::getInstance()->getNumChildrens();
				
				for (int i = 0; i < numObj; i++)
				{
					elem	= (DIGEOElement*)DIGEOObjectManager::getInstance()->getChildAt(i);
					
					if (elem->getState() == ACTIVE) {
						radius	= elem->getProperty(SIZE, X);
						right	= getProperty(POSITION, X) + getProperty(SIZE, X);
						left	= getProperty(POSITION, X);
						top		= getProperty(POSITION, Y) + getProperty(SIZE, Y);
						bottom	= getProperty(POSITION, Y);
						
						if(elem->getProperty(POSITION, X) + radius > right)
						{
							elem->setPropertyByAxis(POSITION, X, right - radius);
							elem->setPropertyByAxis(VELOCITY, X, elem->getProperty(VELOCITY, X) * -1);
						}
						else if(elem->getProperty(POSITION, X) - radius < left)
						{
							elem->setPropertyByAxis(POSITION, X, left + radius);
							elem->setPropertyByAxis(VELOCITY, X, elem->getProperty(VELOCITY, X) * -1);
						}

						if(elem->getProperty(POSITION, Y) + radius < bottom)
						{
							elem->setPropertyByAxis(POSITION, Y, bottom - radius);
							elem->setPropertyByAxis(VELOCITY, Y, elem->getProperty(VELOCITY, Y) * -1);
						}
						else if(elem->getProperty(POSITION, Y) - radius > top)
						{
							elem->setPropertyByAxis(POSITION, Y, top + radius);
							elem->setPropertyByAxis(VELOCITY, Y, elem->getProperty(VELOCITY, Y) * -1);
						}
					}
				}
			}
		};
	}
}
#pragma GCC visibility pop
#endif