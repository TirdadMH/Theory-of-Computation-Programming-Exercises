#include "Preprocessors/includes.h"
#include "Preprocessors/defines.h"



int main()
{
	// First, let's define out input NFA.
	// 3 first tuple for the NFA:
	char states[] = {'A', 'B', 'C', 'D', 'E'};
	char alphabet[] = { 'a', 'b', 'c', LAMBDA};
	char starter = 'A';

	// since the 4th tuple can change along the way of converting NFA to DFA, It's better to be a Vector.
	std::vector<char> finalStates = { 'B', 'D' };
	
	// for 5th tuple which is transition function, We are going to need an the number of states and alphabets:
	int numberOfStates = sizeof(states) / sizeof(states[0]);
	int numberOfAlphabets = sizeof(alphabet) / sizeof(alphabet[0]);

	// the 5th tuple:
	std::string** transitionFunction = fillTransitionFunction(numberOfStates, numberOfAlphabets);

	// Printing the Input NFA in a table format
	printNFA(transitionFunction);

	// Step 1: Eliminating the Lambda closure
	transitionFunction = eliminateLambda(transitionFunction, finalStates, numberOfStates, numberOfAlphabets, states);

	// Printing the Input NFA in a table format with Lambda Transitions Eliminated.
	printELNFA(transitionFunction);
}