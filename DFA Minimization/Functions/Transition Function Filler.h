#pragma once
#pragma warning(disable:6386)
char** fillTransitionFunction(char** &transitionFunction, int numberOfStates, int numberOfAlphabets)
{
	transitionFunction = new char * [numberOfStates];
	for (int i = 0; i < numberOfStates; i++)
	{
		transitionFunction[i] = new char[numberOfAlphabets];
	}

	// Filling Transition Function be like:
	transitionFunction[A][a] = 'B';
	transitionFunction[A][b] = 'F';

	transitionFunction[B][a] = 'G';
	transitionFunction[B][b] = 'E';
	
	transitionFunction[C][a] = 'B';
	transitionFunction[C][b] = 'D';
	
	transitionFunction[D][a] = 'H';
	transitionFunction[D][b] = 'G';
	
	transitionFunction[E][a] = 'A';
	transitionFunction[E][b] = 'F';
	
	transitionFunction[F][a] = 'G';
	transitionFunction[F][b] = 'E';
	
	transitionFunction[G][a] = 'F';
	transitionFunction[G][b] = 'F';
	
	transitionFunction[H][a] = 'G';
	transitionFunction[H][b] = 'D';
	
	return transitionFunction;
}