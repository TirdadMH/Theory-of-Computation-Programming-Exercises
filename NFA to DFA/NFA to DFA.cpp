﻿#include "Preprocessors/includes.h"
#include "Preprocessors/defines.h"

int main()
{
	/*
	* everything works dynamically. so feel free to change the NFA.
	* If you want to test another NFA, you need to adjust the TransitionFunction in the fillTransitionFunction function and 
		Enums referring to the states & alphabets. optionally, you can adjust the printing functions too.
	* IMPORTANT: HARD-CODDED labeled parts of LambdaElimination header file need to change according to the new input NFA
	*/
	
	// First, let's define out input NFA.
	// 3 first tuple for the NFA:
	char states[] = {'A', 'B', 'C', 'D', 'E'};
	char alphabet[] = { 'a', 'b', 'c', LAMBDA};
	char starter = 'A';

	// since the 4th tuple can change along the way of converting NFA to DFA, It's better to be a Vector.
	std::vector<char> finalStates = { 'B', 'D' };
	
	// for the 5th tuple which is transition function, We are going to need an the number of states and alphabets:
	int numberOfStates = sizeof(states) / sizeof(states[0]);
	int numberOfAlphabets = sizeof(alphabet) / sizeof(alphabet[0]);

	// the 5th tuple:
	std::string** transitionFunction = fillTransitionFunction(numberOfStates, numberOfAlphabets);

	// Printing the Input NFA in a table format
	printNFA(transitionFunction);

	// Step 1: Eliminating the Lambda closure
	transitionFunction = eliminateLambda(transitionFunction, finalStates, numberOfStates, numberOfAlphabets, states);
	printELNFA(transitionFunction, true);

	// Step 2: Creating New States according to a, b, c transitions
	std::vector<std::vector<std::string>> newStatesTransitionFunction = createNewStates(transitionFunction, numberOfStates, numberOfAlphabets);
	printNewNFA(stateMap, newStatesTransitionFunction, transitionFunction, true);

	// Step 3: Adding the Trap state to complete the Conversion from NFA to DFA and then Printing the Final DFA
	addTrapState(stateMap, newStatesTransitionFunction, transitionFunction, numberOfStates, numberOfAlphabets);
	printDFA(stateMap, newStatesTransitionFunction, transitionFunction);

	return 0;
}