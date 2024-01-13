#pragma once
#include "../../Preprocessors/defines.h"
/*
	the main reason for this hard-coded mess is that filling this array
	in a dynamic way is too much time consuming for a small project like this
	and simply it is not worth it.
*/
#pragma warning(disable:6385)
std::string** fillTransitionFunction(int& numberOfStates, int& numberOfAlphabets)
{
	std::string** transitionFunction = new std::string * [numberOfStates];
	for (int i = 0; i < numberOfStates; i++)
	{
		transitionFunction[i] = new std::string[numberOfAlphabets];
	}

	// Filling the Transition Function be like:
	transitionFunction[A][a] = 'B';
	transitionFunction[A][b] = NO_STATE;
	transitionFunction[A][c] = 'C';
	transitionFunction[A][lambda] = NO_STATE;

	transitionFunction[B][a] = 'A';
	transitionFunction[B][b] = "A, D";
	transitionFunction[B][c] = NO_STATE;
	transitionFunction[B][lambda] = 'E';

	transitionFunction[C][a] = "A, D";
	transitionFunction[C][b] = NO_STATE;
	transitionFunction[C][c] = 'D';
	transitionFunction[C][lambda] = 'E';

	transitionFunction[D][a] = 'E';
	transitionFunction[D][b] = NO_STATE;
	transitionFunction[D][c] = NO_STATE;
	transitionFunction[D][lambda] = "A, B, C";

	transitionFunction[E][a] = "A, E";
	transitionFunction[E][b] = 'B';
	transitionFunction[E][c] = NO_STATE;
	transitionFunction[E][lambda] = NO_STATE;

	return transitionFunction;
}