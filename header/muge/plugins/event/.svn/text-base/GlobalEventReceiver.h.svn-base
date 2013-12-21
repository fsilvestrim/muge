/*
 *  MasterEventReceiver.h
 *  MuGE
 *
 *  Created by Filipe Silvestrim on 10/13/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __muge__plugins__event__GlobalEventReceiver_h__
#define __muge__plugins__event__GlobalEventReceiver_h__

#pragma GCC visibility push(default)
namespace muge 
{
	namespace plugins 
	{
		namespace event 
		{
			class GlobalEventReceiver
			{
			protected:
				static const int KEY_KEY_CODES_COUNT = 12;
				
				// Enumeration for UP, DOWN, PRESSED and RELEASED key states. Also used for mouse button states.
				enum keyStatesENUM {UP, DOWN, PRESSED, RELEASED};
				
				// Enumeration for Event Handling State.
				enum processStateENUM {STARTED, ENDED};
				
				// Mouse button states.
				keyStatesENUM mouseButtonState[2]; //Left(0), Middle(1) and Right(2) Buttons.
				
				// Keyboard key states.
				keyStatesENUM keyState[KEY_KEY_CODES_COUNT];
				
				// Mouse X/Y coordinates and Wheel data.
				struct mouseData
				{
					int X;
					int Y;
					float wheel; //wheel is how far the wheel has moved
				};
				
				struct mouseData mouse;
				
				processStateENUM processState; // STARTED = handling events, ENDED = not handling events
				
			public:				
				float mouseWheel()
				{
					return mouse.wheel;
				}
				
				int mouseX()
				{
					return mouse.X;
				}
				
				int mouseY()
				{
					return mouse.Y;
				}
				
				bool leftMouseReleased()
				{
					if (mouseButtonState[0] == RELEASED)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
				bool leftMouseUp()
				{
					if (mouseButtonState[0] == RELEASED || mouseButtonState[0] == UP)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
				
				bool leftMousePressed()
				{
					if (mouseButtonState[0] == PRESSED)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
				
				bool leftMouseDown()
				{
					if (mouseButtonState[0] == PRESSED || mouseButtonState[0] == DOWN)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
				
				bool middleMouseReleased()
				{
					if (mouseButtonState[1] == RELEASED)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
				bool middleMouseUp()
				{
					if (mouseButtonState[1] == RELEASED || mouseButtonState[1] == UP)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
				
				bool middleMousePressed()
				{
					if (mouseButtonState[1] == PRESSED)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
				
				bool middleMouseDown()
				{
					if (mouseButtonState[1] == PRESSED || mouseButtonState[1] == DOWN)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
				
				bool rightMouseReleased()
				{
					if (mouseButtonState[2] == RELEASED)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
				bool rightMouseUp()
				{
					if (mouseButtonState[2] == RELEASED || mouseButtonState[2] == UP)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
				
				bool rightMousePressed()
				{
					if (mouseButtonState[2] == PRESSED)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
				
				bool rightMouseDown()
				{
					if (mouseButtonState[2] == PRESSED || mouseButtonState[2] == DOWN)
					{
						return true;
					}
					else
					{
						return false;
					}
				}//
				
				bool keyPressed(char keycode)
				{
					if (keyState[keycode] == PRESSED)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
				
				bool keyDown(char keycode)
				{
					if (keyState[keycode] == DOWN || keyState[keycode] == PRESSED)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
				
				bool keyUp(char keycode)
				{
					if (keyState[keycode] == UP || keyState[keycode] == RELEASED)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
				
				bool keyReleased(char keycode)
				{
					if (keyState[keycode] == RELEASED)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
				
				
				// This is used so that the Key States will not be changed during execution of your Main game loop.
				// Place this at the very START of your Main Loop
				void endEventProcess()
				{
					processState = ENDED;
				}
				
				// This is used so that the Key States will not be changed during execution of your Main game loop.
				// Place this function at the END of your Main Loop.
				void startEventProcess()
				{
					processState = STARTED;
					
					//Keyboard Key States
					for (int i = 0; i < KEY_KEY_CODES_COUNT; i++)
					{
						if (keyState[i] == RELEASED)
						{
							keyState[i] = UP;
						}
						
						if (keyState[i] == PRESSED)
						{
							keyState[i] = DOWN;
						}
					}
					
					//Mouse Button States
					for (int i = 0; i <= 2; i++)
					{
						if (mouseButtonState[i] == RELEASED)
						{
							mouseButtonState[i] = UP;
						}
						
						if (mouseButtonState[i] == PRESSED)
						{
							mouseButtonState[i] = DOWN;
						}
					}
					
					//Mouse Wheel state
					mouse.wheel = 0.0f;
				}
				
				void init()
				{					
					//KeyBoard States.
					for (int i = 0; i <= KEY_KEY_CODES_COUNT; i++)
					{
						keyState[i] = UP;
					}
					
					//Mouse states
					for (int i = 0; i <= 2; i++)
					{
						mouseButtonState[i] = UP;
					}
					
					//Mouse X/Y coordenates.
					mouse.X = 0;
					mouse.Y = 0;
					mouse.wheel = 0.0f;
				}
			};			
		}
	}
}
#pragma GCC visibility pop
#endif