#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "Process.h"
using namespace muge::core::kernel;


void Process::addInput(Attribute* atr)
{
	inputs[inputsCount++] = atr;
}

void Process::addInput(int index, Attribute* atr)
{
	inputs[index] = atr;	
	inputsCount++;
}

void Process::addOutput(Attribute* atr)
{
	outputs[outputsCount++] = atr;
}

void Process::addOutput(int index, Attribute* atr)
{
	outputs[index] = atr;
	outputsCount++;
}


Attribute *Process::getInput(int index)
{
	return inputs[index];
}

Attribute *Process::getOutput(int index)
{
	return outputs[index];
}

int	Process::getInputsCount()
{
	return inputsCount;
}

int	Process::getOutputsCount()
{
	return outputsCount;
}