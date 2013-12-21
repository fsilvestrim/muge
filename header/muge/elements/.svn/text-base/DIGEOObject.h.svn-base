/*
 *  Object.h
 *  MuGE
 *
 *  Created by Filipe Silvestrim on 11/24/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __muge__elements__Object_h__
#define __muge__elements__Object_h__

#include "DIGEOVisual.h"
using namespace muge::elements;

#include <math.h>
#include <string>
using namespace std;

#pragma GCC visibility push(default)
namespace muge
{
	namespace elements
	{
		class DIGEOObject: public DIGEOVisual
		{
		private:
			void reactBoxCollisionBetween (DIGEOObject *obj0, DIGEOObject *obj1)
			{
				int left1		= obj0->getProperty(POSITION, X);
				int left2		= obj1->getProperty(POSITION, X);
				int right1		= obj0->getProperty(POSITION, X) + obj0->getProperty(SIZE, X);
				int right2		= obj1->getProperty(POSITION, X) + obj1->getProperty(SIZE, X);
				int top1		= obj0->getProperty(POSITION, Y);
				int top2		= obj1->getProperty(POSITION, Y);
				int bottom1		= obj0->getProperty(POSITION, Y) + obj0->getProperty(SIZE, Y);
				int bottom2		= obj1->getProperty(POSITION, Y) + obj1->getProperty(SIZE, Y);
				
				bool collides	= !((bottom1 < top2) || (top1 > bottom2) || (right1 < left2) || (left1 > right2));
					
				/*
				var nX1:Number = MCBallA.x;
				var nY1:Number = MCBallA.y;
				var nDistX:Number = MCBallB.x - nX1;
				var nDistY:Number = MCBallB.y - nY1;
				
				var nDistance:Number = Math.sqrt ( nDistX * nDistX + nDistY * nDistY );
				var nRadiusA:Number = MCBallA.width/2;
				var nRadiusB:Number = MCBallB.width/2;
				
				var nNormalX:Number = nDistX/nDistance;
				var nNormalY:Number = nDistY/nDistance;
				
				var nMidpointX:Number = ( nX1 + MCBallB.x )/2;
				var nMidpointY:Number = ( nY1 + MCBallB.y )/2;
				
				MCBallA.x = nMidpointX - nNormalX * nRadiusA;
				MCBallA.y = nMidpointY - nNormalY * nRadiusA;
				MCBallB.x = nMidpointX + nNormalX * nRadiusB;
				MCBallB.y = nMidpointY + nNormalY * nRadiusB;
				
				var nVector:Number = ( ( MCBallA.nSpeedX - MCBallB.nSpeedX ) * nNormalX )+ ( ( MCBallA.nSpeedY - MCBallB.nSpeedY ) * nNormalY );
				var nVelX:Number = nVector * nNormalX;
				var nVelY:Number = nVector * nNormalY;
				
				MCBallA.nSpeedX -= nVelX;
				MCBallA.nSpeedY -= nVelY;
				MCBallB.nSpeedX += nVelX;
				MCBallB.nSpeedY += nVelY;
				
				*/
				
				if (collides) {
					float m1 = obj0->getMass();
					float m2 = obj1->getMass();
					float v1 = obj0->getProperty(VELOCITY, X);
					float v2 = obj1->getProperty(VELOCITY, X);

					// momentum equation P=SUM(m*v)
					float P	= m1*v1+m2*v2;
					float diff	= v1-v2;	

					// Newtons second law says all forces will be kept 
					float dv2 = (P+m1*diff)/(m1+m2);
					float dv1 = dv2-v1+v2;			

					//take the new speeds and put them in the objects
					if (obj0->objType == STATIC)
					{	
						obj1->setPropertyByAxis(VELOCITY, X, dv1);
					}
					else if (obj1->objType == STATIC)
					{
						obj0->setPropertyByAxis(VELOCITY, X, dv2);
					}
					else
					{
						obj0->setPropertyByAxis(VELOCITY, X, dv1);
						obj1->setPropertyByAxis(VELOCITY, X, dv2);
					}
				}
			}
			
			void checkSphereCollisionBetween (DIGEOObject *obj0, DIGEOObject *obj1)
			{
				float dx	= obj1->getProperty(POSITION, X) - obj0->getProperty(POSITION, X);
				float dy	= obj1->getProperty(POSITION, Y) - obj0->getProperty(POSITION, Y);
				float dist	= sqrt(dx*dx + dy*dy);
				
				if(dist < obj0->getProperty(SIZE, X) / 2 + obj1->getProperty(SIZE, X) / 2)
				{
					float angle		= atan2(dy, dx);
					float sine		= sin(angle);
					float cosine	= cos(angle);
					
					// rotate obj0's position
					float pos0[2] = {0, 0};
					
					// rotate obj1's position
					float *pos1 = rotate(dx, dy, sine, cosine, true);
					
					// rotate obj0's velocity
					float *vel0 = rotate(obj0->getProperty(VELOCITY, X), obj0->getProperty(VELOCITY, Y), sine, cosine, true);
					
					// rotate obj1's velocity
					float *vel1 = rotate(obj1->getProperty(VELOCITY, X), obj1->getProperty(VELOCITY, Y), sine, cosine, true);
					
					// collision reaction
					float vxTotal = vel0[0] - vel1[0];
					vel0[0] = ((obj0->getMass() - obj1->getMass()) * vel0[0] + 2 * obj1->getMass() * vel1[0]) / (obj0->getMass() + obj1->getMass());
					vel1[0] = vxTotal + vel0[0];
					
					// update position
					float absV		= fabs(vel0[0]) + fabs(vel1[0]);
					float overlap	= (obj0->getProperty(SIZE, X) / 2 + obj1->getProperty(SIZE, X) / 2) - fabs(pos0[0] - pos1[0]);
					pos0[0] += vel0[0] / absV * overlap;
					pos1[0] += vel1[0] / absV * overlap;
					
					// rotate positions back
					float *pos0F = rotate(pos0[0], pos0[1], sine, cosine, false);
					float *pos1F = rotate(pos1[0], pos1[1], sine, cosine, false);
					// rotate velocities back
					float *vel0F = rotate(vel0[0], vel0[1], sine, cosine, false);
					float *vel1F = rotate(vel1[0], vel1[1], sine, cosine, false);
										
						obj1->setProperty(POSITION, obj0->getProperty(POSITION, X) + pos1F[0], obj0->getProperty(POSITION, Y) + pos1F[1], 0);
						obj1->setProperty(VELOCITY, vel1F[0], vel1F[1], 0);

						obj0->setProperty(POSITION, obj0->getProperty(POSITION, X) + pos0F[0], obj0->getProperty(POSITION, Y) + pos0F[1], 0);
						obj0->setProperty(VELOCITY, vel0F[0], vel0F[1], 0);
				}
			}
			
			float *rotate(float x, float y, float sine, float cosine, bool reverse)
			{
				
				float* pointer;
				float result[2];
				
				pointer = result;
				
				if(reverse)
				{
					result[0] = x * cosine + y * sine;
					result[1] = y * cosine - x * sine;
				}
				else
				{
					result[0] = x * cosine - y * sine;
					result[1] = y * cosine + x * sine;
				}
				
				return pointer;
			}
			
		public:
			enum OBJ_TYPE {
				STATIC,
				DYNAMIC
			} objType;
			
			DIGEOObject(const char* tagName, OBJ_TYPE type, int index = 0, Node* node = NULL):DIGEOVisual(tagName, index, node) 
			{
				objType = type;
				DIGEOObjectManager::getInstance()->addChild(this);
			};
			
			void build()
			{
				DIGEOVisual::build();
				processType			= DISPLAY;

				changeState(ACTIVE);
				activateNodeChild();
			}

			void linkage()
			{
				if(strcmp(getAttributeByKey(DIGEOSintax::DIGEO_LanAttr_position), "null"))
				{
					vector<string> vecPosStr = getAttributeValues(DIGEOSintax::DIGEO_LanAttr_position);
					setProperty(DIGEOElement::POSITION, atof(vecPosStr[0].c_str()), atof(vecPosStr[1].c_str()), atof(vecPosStr[2].c_str()));
				}
				
				if(strcmp(getAttributeByKey(DIGEOSintax::DIGEO_LanAttr_size), "null"))
				{
					vector<string> vecSizeStr = getAttributeValues(DIGEOSintax::DIGEO_LanAttr_size);
					setProperty(DIGEOElement::SIZE, atof(vecSizeStr[0].c_str()), atof(vecSizeStr[1].c_str()), atof(vecSizeStr[2].c_str()));
				}
				
				const char * coll = getAttributeByKey(DIGEOSintax::DIGEO_LanAttr_collision);
				if(strcmp(coll, "null"))
					collision = !strcmp(coll, "true");
				
				DIGEOVisual::linkage();
			}
			
			void step ()
			{
				checkCollision();
				updatePosition();
				
				DIGEOVisual::step();
			}
			
			void checkCollision()
			{
				DIGEOElement	*elem;
				int				numObj = DIGEOObjectManager::getInstance()->getNumChildrens();
				
				for (int i = 0; i < numObj; i++)
				{
					elem	= (DIGEOElement*)DIGEOObjectManager::getInstance()->getChildAt(i);
					
					if (elem->getState() == ACTIVE && elem != this && elem->getCollision())
						checkSphereCollisionBetween(this, (DIGEOObject*)elem);
				}
			}
			
		};
	}
}
#pragma GCC visibility pop
#endif