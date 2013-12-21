#ifndef __muge__core__kernel__Kernel_h__
#define __muge__core__kernel__Kernel_h__

#include <string>
#include <time.h>
#include <exception>
using namespace std;

#include "Object.h"
using namespace muge::core::kernel;

#include "GlobalEventReceiver.h"
using namespace muge::plugins::event;

#include "Singleton.h"
using namespace muge::utils::designpattern;

#include "DIGEOGame.h"
using namespace muge::elements;

#pragma GCC visibility push(default)
namespace muge
{
	namespace core
	{
		namespace kernel
		{
			class Kernel: public Object, public Singleton< Kernel >
			{
			private:
				int TICKS_PER_SECOND;
				int SKIP_TICKS;
				int MAX_FRAMESKIP;

				bool		game_is_running;
				clock_t		next_game_tick;
				float		interpolation;
				int			loops;
				
			public:
				Kernel();
				~Kernel();
				
				GlobalEventReceiver *receiver;
				
				void startup();
				void gameloop(void (*update)(), void (*display)(float));
				void loadGame (char *path);
			};
		}
	}
}
#pragma GCC visibility pop
#endif
