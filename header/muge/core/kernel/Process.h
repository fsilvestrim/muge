#ifndef __muge__core__kernel__Process_h__
#define __muge__core__kernel__Process_h__

#include <string>
#include <map>
#include <exception>
using namespace std;

#include "Attribute.h"
using namespace muge::core::kernel;

#pragma GCC visibility push(default)
namespace muge
{
	namespace core
	{
		namespace kernel
		{
			class Process
			{
			private:
				int inputsCount;
				int outputsCount;
				
			protected:
				map<int, Attribute*>			inputs;
				map<int, Attribute*>::iterator	it_inputs;
				map<int, Attribute*>			outputs;
				map<int, Attribute*>::iterator	it_outputs;
				
			public:
				Process()
				{
					inputsCount = outputsCount = 0;
				};
				
				void					addInput(Attribute*);
				void					addInput(int, Attribute*);
				void					addOutput(Attribute*);
				void					addOutput(int, Attribute*);
				Attribute				*getInput(int);
				Attribute				*getOutput(int);
				map<int, Attribute*>	*getInputs();
				map<int, Attribute*>	*getOutputs();
				int						getInputsCount();
				int						getOutputsCount();
				
				virtual void	build()		{};
				virtual void	destroy()	{};
				virtual void	stop()		{};
				virtual void	execute()	{};
				virtual void	step()		{};
				virtual void	linkage()	{};
			};
		}
	}
}
#pragma GCC visibility pop
#endif
