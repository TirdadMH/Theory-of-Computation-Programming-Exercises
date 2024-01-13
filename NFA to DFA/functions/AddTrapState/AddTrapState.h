#pragma once

void addTrapState(std::map<std::string, int> &stateMap, std::vector<std::vector<std::string>> &newStatesTransitionFunction, std::string** &transitionFunction, int numberOfStates, int numberOfAlphabets)
{
	// PHASE 1: change NO_STATE or null transitions in transitionFunction to Trap state
	for (int i = 0; i < numberOfStates; i++)
	{
		for (int j = 0; j < (numberOfAlphabets - 1); j++)
		{
			if (transitionFunction[i][j] == NO_STATE || transitionFunction[i][j] == "\0")
				transitionFunction[i][j] = "T";
		}
	}

	// PHASE 2: change NO_STATE or null transitions in newStatesTransitionFunction to Trap state
	for (int i = 0; i < SMI; i++)
	{
		for (int j = 0; j < (numberOfAlphabets - 1); j++)
		{
			if (newStatesTransitionFunction[i][j] == NO_STATE || newStatesTransitionFunction[i][j] == "\0")
				newStatesTransitionFunction[i][j] = "T";
		}
	}

	// PHASE 3: Add an actual Trap State.
	stateMap["T"] = SMI;
	std::vector<std::string> newStateTransitions;
	for (int a = 0; a < (numberOfAlphabets - 1); a++)
	{
		newStateTransitions.push_back("T");
	}
	newStatesTransitionFunction.push_back(newStateTransitions);

	printNewNFA(stateMap, newStatesTransitionFunction, transitionFunction, false);
}