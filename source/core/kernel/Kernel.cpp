#include <string>
#include <vector>
#include <exception>
#include <iostream>
using namespace std;

#include "XMLParser.h"
using namespace muge::utils::parser;

#include "Kernel.h"
using namespace muge::core::kernel;

Kernel::Kernel ()
{
	TICKS_PER_SECOND	= 25;
	SKIP_TICKS			= 1000 / TICKS_PER_SECOND;
	MAX_FRAMESKIP		= 5;
}

Kernel::~Kernel ()
{
}

void Kernel::gameloop(void (*update)(), void (*display)(float)) 
{
	game_is_running = true;
	next_game_tick	= clock();

    while( game_is_running ) 
	{		
        loops = 0;
		
		while( clock() > next_game_tick && loops < MAX_FRAMESKIP) 
		{
			receiver->endEventProcess();
			
			DIGEOManager::getInstance()->game->recursiveOperation(Node::EXECUTE);
            update();
			
			receiver->startEventProcess();
			
            next_game_tick += SKIP_TICKS;
            loops++;
        }
		
        interpolation = float(clock() + SKIP_TICKS - next_game_tick ) / float( SKIP_TICKS );		
        display(interpolation);
    }
}

void Kernel::startup() {
	throw "Not yet implemented";
}

void Kernel::loadGame(char *path) 
{
	XMLParser::load(path);
}
