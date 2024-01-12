#include "Preprocessors/includes.h"
#include "Preprocessors/defines.h"

std::string** fillTransitionFunction(int&, int&);

int main()
{
	// First, let's define out input NFA.
	// 4 first tuple for the NFA:
	char states[] = {'A', 'B', 'C', 'D', 'E'};
	char alphabet[] = { 'a', 'b', 'c', LAMBDA};
	char starter = 'A';
	char finalStates[] = { 'B', 'D' };
	
	// for 5th tuple which is transition function, We are going to need an the number of states and alphabets:
	int numberOfStates = sizeof(states) / sizeof(states[0]);
	int numberOfAlphabets = sizeof(alphabet) / sizeof(alphabet[0]);

	// the 5th tuple:
	std::string** transitionFunction = fillTransitionFunction(numberOfStates, numberOfAlphabets);

	// Printing the Input NFA in a table format
	printNFA(transitionFunction);

	// Eliminating the Lambda closure

}