/*
 *  Action.h
 *  MuGE
 *
 *  Created by Filipe Silvestrim on 11/24/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __muge__elements__Action_h__
#define __muge__elements__Action_h__

#include "DIGEOElement.h"
using namespace muge::core::kernel;

#include "DIGEOVisual.h"
using namespace muge::elements;

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#pragma GCC visibility push(default)
namespace muge
{
	namespace elements
	{
		class DIGEOAction: public DIGEOElement
		{
//			<changeUserInterface input="#endScreen" /> 
//			<move target="#entityP1" axis="y" ammount="1"/>
//			<hit id="hitGoal1" input="#entityBall">
//			<changeValue id="scorePLayer2" input="#scoreP1" property="value" type="add" value="1" />
//			<move invert="true" />
			
		private:
			float		ammount, value[3];
			bool		hasValue;
			bool		invert;
			
			void parseInvert()
			{
				const char *ax = getAttributeByKey(DIGEOSintax::DIGEO_LanAttr_invert);
				invert =  (!strcmp(ax, "true"));
			}
			
			void parseAxisValue()
			{
				const char *ax = getAttributeByKey(DIGEOSintax::DIGEO_LanAttr_axis);
				
				if (!strcmp(ax, "x"))		axis = X;
				else if (!strcmp(ax, "y"))	axis = Y;
				else if (!strcmp(ax, "z"))	axis = Z;
				else						axis = AXIS_NONE;

			}
			
			void parseAmmountValue()
			{
				const char * amm = getAttributeByKey(DIGEOSintax::DIGEO_LanAttr_ammount);
				
				if(strcmp(amm, "null"))
				{
					if (!strcmp(amm, "rand"))	
						ammount = rand_FloatRange(-1,1);
					else				
						ammount = atof(getAttributeByKey(DIGEOSintax::DIGEO_LanAttr_ammount));
				}
				else
				{
					ammount = 0;
				}
			}
			
			void parsePropertyValue()
			{
				if(strcmp(getAttributeByKey(DIGEOSintax::DIGEO_LanAttr_property), "null"))
				{
					const char *ax = getAttributeByKey(DIGEOSintax::DIGEO_LanAttr_property);
					
					if (!strcmp(ax, "rotation"))		property = ROTATION;
					else if (!strcmp(ax, "scale"))		property = SCALE;
					else if (!strcmp(ax, "velocity"))	property = VELOCITY;
					else if (!strcmp(ax, "position"))	property = POSITION;
					else if (!strcmp(ax, "value"))		property = VALUE;
					else								property = PROPERTY_NONE;
				}
				else							
					property = PROPERTY_NONE;
				
			}
			
			float rand_FloatRange(float a, float b)
			{
				return ((b-a)*((float)rand()/RAND_MAX))+a;
			}
			
			void parseValueValue()
			{
				hasValue = strcmp(getAttributeByKey(DIGEOSintax::DIGEO_LanAttr_value), "null");
				
				if(hasValue)
				{
					float randValue;
					
					vector<string> vecPosStr = getAttributeValues(DIGEOSintax::DIGEO_LanAttr_value);
					
					const char * val0	= vecPosStr[0].c_str();
					const char * val1	= vecPosStr[1].c_str();
					const char * val2	= vecPosStr[2].c_str();
					
					randValue = rand_FloatRange(-1,1);
					if (!strcmp(val0, "rand"))	value[0] = randValue;
					else						value[0] = atof(val0);
					
					randValue = rand_FloatRange(-1,1);
					if (!strcmp(val1, "rand"))	value[1] = randValue;
					else						value[1] = atof(val1);
					
					randValue = rand_FloatRange(-1,1);
					if (!strcmp(val2, "rand"))	value[2] = randValue;
					else						value[2] = atof(val2);
				}
			}
			
			void changePropertyByAmmount()
			{
				if (property == VALUE) {
					getTarget()->setPropertySingleByAmmount(property, atoi(getTarget()->getPropertySingle(property)) + ammount);
				}
				else
				{
					if (axis != AXIS_NONE)
						getTarget()->setPropertyByAxis(property, axis, getTarget()->getProperty(property, axis) + ammount);
				}
			}
			
			void changePropertyByValue()
			{
				if (property == VALUE) {
//					getTarget()->setPropertyByAxis(property, axis, value[(int)axis]);
				}
				else
				{
					if (axis != AXIS_NONE)
						getTarget()->setPropertyByAxis(property, axis, value[(int)axis]);
					else
						getTarget()->setProperty(property, value[0], value[1], value[2]);
				}
			}
			
			bool checkBoxCollisionBetween (DIGEOElement *obj0, DIGEOElement *obj1)
			{
				int width1		= obj0->getProperty(SIZE, X);
				int width2		= obj1->getProperty(SIZE, X);
				int height1		= obj0->getProperty(SIZE, Y);
				int height2		= obj1->getProperty(SIZE, Y);
				
				int left1		= obj0->getProperty(POSITION, X) - width1/2;
				int left2		= obj1->getProperty(POSITION, X) - width2/2;
				int right1		= obj0->getProperty(POSITION, X) + width1/2;
				int right2		= obj1->getProperty(POSITION, X) + width2/2;
				int top1		= obj0->getProperty(POSITION, Y) - height1/2;
				int top2		= obj1->getProperty(POSITION, Y) - height2/2;
				int bottom1		= obj0->getProperty(POSITION, Y) + height1/2;
				int bottom2		= obj1->getProperty(POSITION, Y) + height2/2;
				
				return !((bottom1 < top2) || (top1 > bottom2) || (right1 < left2) || (left1 > right2));
			}	
		public:
			enum TYPE {
				CHANGE_VALUE,
				CHANGE_SCREEN,
				MOVE,
				HIT,
				NONE
			} actionType;
			
			DIGEOAction(const char* tagName, TYPE actionTp, int index = 0, Node* node = NULL):DIGEOElement(tagName, index, node)  
			{
				actionType	= actionTp;
			};
			
			void build()
			{
				DIGEOElement::build();
			}
						
			void step()
			{
				if (getTarget() != NULL) {
					switch (actionType) {
						case MOVE:
							if (getState() == ACTIVE)
								if (invert)
									getTarget()->setProperty(DIGEOElement::VELOCITY, -getTarget()->getProperty(DIGEOElement::VELOCITY, DIGEOElement::X), -getTarget()->getProperty(DIGEOElement::VELOCITY, DIGEOElement::Y), -getTarget()->getProperty(DIGEOElement::VELOCITY, DIGEOElement::Z));
							else
								getTarget()->setPropertyByAxis(DIGEOElement::POSITION, axis, getTarget()->getProperty(DIGEOElement::POSITION, axis) + ammount);
							break;
						case CHANGE_VALUE:
							if (getState() == ACTIVE) {
								if (ammount != 0)	changePropertyByAmmount();
								else if(hasValue)	changePropertyByValue();
							}
							break;
						case HIT:
							if (checkBoxCollisionBetween(getParent(), getTarget()))
								activateNodeChild();
							break;
						default:
							break;
					}
				}
				
				if (getState() == ACTIVE) {
					changeState(INACTIVE);
				}				
			}
			
			void linkage()
			{
				DIGEOElement::linkage();				

				if (getTarget() == NULL) {
					addTarget();
				}
				
				switch (actionType) {
					case MOVE:
						parseAxisValue();
						parseAmmountValue();
						parseInvert();
						break;
						
					case CHANGE_VALUE:
						parseAxisValue();
						parseAmmountValue();
						parsePropertyValue();
						parseValueValue();
						break;
				}
			}
		};
	}
}
#pragma GCC visibility pop
#endif