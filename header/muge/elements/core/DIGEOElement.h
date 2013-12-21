/*
 *  Element.h
 *  MuGE
 *
 *  Created by Filipe Silvestrim on 11/19/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __muge__elements__Element_h__
#define __muge__elements__Element_h__

#include <iostream>
using namespace std;

#include "Node.h"
using namespace muge::core::kernel;

#include "AbstractManager.h"
using namespace muge::utils::manager;

#include "Singleton.h"
using namespace muge::utils::designpattern;

#include "StringUtil.h"
using namespace muge::utils::str;

#include "DIGEOSintax.h"
using namespace muge::elements::core;

#include <map>

#include <stdio.h>
#include <stdlib.h>

#pragma GCC visibility push(default)
namespace muge
{
	namespace elements
	{
		namespace core
		{	
			class DIGEOElement;
			
			class DIGEOObjectManager: public Singleton<DIGEOObjectManager>, public AbstractManager<DIGEOElement>
			{};	
			
			class DIGEOManager: public Singleton<DIGEOManager>, public AbstractManager<DIGEOElement>
			{
			public:
				DIGEOElement	*game;
			};			
			
			class DIGEOElement: public Node
			{			
			private:
				float			position[3], size[3], velocity[3], scale[3], rotation[3], acceleration[3], target3[3];
				
				const char		*filterExpression;
				char *elemValue;
				DIGEOElement	*target;
				DIGEOElement	*elemParent;
				
				void			parseType(const char*);
				
			protected:
				float			force, friction, mass;
				bool			collision;
				
			public:				
				enum VELOCITY_BY {
					ANGLE,
					AXI,
				};
				
				enum AXIS {
					X,
					Y,
					Z,
					AXIS_NONE
				} axis;
				
				enum PROPERTY {
					POSITION,
					SIZE,
					VELOCITY,
					SCALE,
					ROTATION,
					ACCELERATION,
					TARGET3,
					VALUE,
					PROPERTY_NONE
				} property;
				
				enum TYPE {
					DISPLAY,
					PROCESS,
					LOOP,
					TYPE_NONE
				} processType;
				
				DIGEOElement(const char* tagName, int index = 0, Node* node = NULL):Node(tagName, index, node)
				{					
					axis		= AXIS_NONE;
					property	= PROPERTY_NONE;
					processType	= TYPE_NONE;
					collision	= false;

					force			= mass				= friction			= 1;
					scale[0]		= scale[1]			= scale[2]			= 1;
					size[0]			= size[1]			= size[2]			= 1;
					position[0]		= position[1]		= position[2]		= 0;
					velocity[0]		= velocity[1]		= velocity[2]		= 0;
					acceleration[0] = acceleration[1]	= acceleration[2]	= 0;
					rotation[0]		= rotation[1]		= rotation[2]		= 0;
				};
				
				~DIGEOElement()
				{
					stop();
					destroy();
				}
				
				/********************** FILTER EXPRESSION *********************/
				void setFilterExpression(const char* str)
				{
					int size			= strlen(str);
					filterExpression	= new char[size+1];
					strcpy((char *)filterExpression,str);
				}
				
				const char* getFilterExpression()
				{
					return filterExpression;
				}
				
				bool evaluateFilterExpression()
				{
					///Parser
					return 0;
				}
				
				/********************** ATTRIBUTES *********************/
				void parseInputArray()
				{
					const char	*value = getAttributeByKey(DIGEOSintax::DIGEO_LanAttr_input);
					
					if(value) 
					{
						vector<string>				inputValues;
						vector<string>::iterator	itInputValues;
						const char					*inputIten;
						
						StringUtil::tokenize(value, inputValues, ",");
						
						//cout << "\nFOR ELEMENT ID >>> " << getId();
						
						for ( itInputValues = inputValues.begin() ; itInputValues < inputValues.end(); itInputValues++ )
						{
							inputIten		= ((string)*itInputValues).c_str();
							
							if (strcmp(inputIten, "null")) {
								Attribute *inputValue	= new Attribute;
								inputValue->setValue(inputIten);
								
								//cout << " -------- input >>> " << inputValue->getValue();
								addInput(inputValue);
							}
						}
					}
				}
				
				DIGEOElement *getRefByInputString(const char *target)
				{
					if (strcmp (target, "null")) 
					{
						char* result	= strstr( target, "#" );
						if(result)
						{
							int size		= strlen(result);
							strncpy(result,&result[1],size);							
							return (DIGEOElement *)DIGEOManager::getInstance()->game->getChildById(result);
						}
					}
					
					return NULL;
				}
				
				vector<string> getAttributeValues(const char *attributeName)
				{
					vector<string>	vecPosStr;
					const char *pos = getAttributeByKey(attributeName);
					StringUtil::tokenize(pos, vecPosStr, ",");
					
					return vecPosStr;
				}
				
				/********************** DISPLAY & TARGET *********************/
				void addTarget()
				{			
					const char	*idRef		= getAttributeByKey(DIGEOSintax::DIGEO_LanAttr_target);
					target					= getRefByInputString(idRef);
				};
				
				DIGEOElement *getTarget ()
				{
					return target;
				}
				
				
				/********************** PROPERTY *********************/
				float *getPropertyPtr (PROPERTY p)
				{
					float *receiver = NULL;

					switch (p) {
						case POSITION:
							receiver = position;
							break;
						case SIZE:
							receiver = size;
							break;
						case VELOCITY:
							receiver = velocity;
							break;
						case SCALE:
							receiver = scale;
							break;
						case ROTATION:
							receiver = rotation;
							break;
						case ACCELERATION:
							receiver = acceleration;
							break;
						case TARGET3:
							receiver = target3;
							break;
					}
					
					return receiver;
				};
				
				void setPropertyByAxis (PROPERTY p, AXIS axis, float value)
				{
					float *receiver	 = getPropertyPtr(p);
					float *&modifier = receiver;
					
					switch (axis) {
						case X:
							modifier[0] = value;
							break;
						case Y:
							modifier[1] = value;
							break;
						case Z:
							modifier[2] = value;
							break;
					}
				}
				
				void setProperty (PROPERTY p, float x, float y, float z)
				{
					float *receiver	 = getPropertyPtr(p);
					float *&modifier = receiver;
					
					modifier[0] = x;
					modifier[1] = y;
					modifier[2] = z;
				}
				
				float getProperty(PROPERTY p, AXIS axis)
				{
					float value = NULL;
					float *receiver	 = getPropertyPtr(p);
					
					switch (axis) {
						case X:
							value = receiver[0];
							break;
						case Y:
							value = receiver[1];
							break;
						case Z:
							value = receiver[2];
							break;
					}
					
					return value;
				}
				
				float	getForce()		{ return force; }
				float	getMass()		{ return mass; }
				float	getFriction()	{ return friction; }
				bool	getCollision()	{ return collision; }
				
				
				void setPropertySingleByAmmount(PROPERTY p, int ammount)
				{
					if (p == VALUE)
					{
						sprintf( elemValue, "%i", ammount );
					}
				}
				
				void setPropertySingle(PROPERTY p, const char *newValue)
				{
					if (p == VALUE)
					{
						int size	= strlen(newValue);
						elemValue		= new char[size+1];
						strcpy((char *)elemValue,newValue);
					}
				}
				
				const char *getPropertySingle(PROPERTY p)
				{
					const char * returnValue = "null";
					
					if (p == VALUE)
						returnValue = elemValue;
					
					return returnValue;
				}
				
				/********************** VELOCITY *********************/
				void updatePosition ()
				{
					velocity[0] += acceleration[0];
					velocity[1] += acceleration[1];
					velocity[2] += acceleration[2];
					
					velocity[0] *= friction;
					velocity[1] *= friction;
					velocity[2] *= friction;
					
					//if (velBy == AXI) 
					//					{
					//						velocity[0] = cos(rotation * 3.1415 / 180) * force;
					//						velocity[1] = sin(rotation * 3.1415 / 180) * force;
					//					}
					
					position[0] += velocity[0];
					position[1] += velocity[1];
					position[2] += velocity[2];
				}
				
				/********************** PARENT *********************/
				DIGEOElement *getParent()
				{
					return elemParent;
				}
				
				DIGEOElement *addChild(DIGEOElement* node)
				{
					Node::addChild(node);
					node->elemParent = this;
					
					return node;
				}
				
				/********************** PROCESS *********************/
				void linkage()
				{
					parseInputArray();
				}
				
				void execute()
				{					
					if (getOldState() != getState()) {
						linkage();
						updateState();
					}
					
					step();
				}
			};
		}
	}
}
#pragma GCC visibility pop
#endif
