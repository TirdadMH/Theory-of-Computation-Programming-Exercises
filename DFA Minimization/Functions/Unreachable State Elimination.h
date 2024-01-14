#pragma once
#include <map>

std::map<int, char> newStateMap;
std::map<int, char> reindexStateMap();

std::vector<std::vector<char>> eliminateUnreachableStates(char** transitionFunction, char states[], int &numberOfStates, int numberOfAlphabets)
{
	// Hold the unreachable states in a vector array 
	std::vector<char> unreachableStates;
	// For every state
	for (int a = 0; a < numberOfStates; a++)
	{
		bool foundMatch = false;
		// For each destination in transition function
		for (int i = 0; i < numberOfStates; i++)
		{
			for (int j = 0; j < numberOfAlphabets; j++)
			{
				// if a match found for a state in the transition function, change foundMatch to true.
				if (transitionFunction[i][j] == states[a])
					foundMatch = true;
			}
		}
		// if foundMatch remains false, it means that the code couldn't find a destination for the current state.
		if (!foundMatch)
		{
			// push the unreachable state into the unreachableStates array
			unreachableStates.push_back(states[a]);
		}
	}
	// create a new Transition function to store clean DFA
	std::vector<std::vector<char>> cleanTransitionFunction;
	// for each state in transition function
	for (int i = 0; i < numberOfStates; i++)
	{
		// check if a state is unreachable
		bool isUnreachable = false;
		for (int r = 0; r < unreachableStates.size(); r++)
		{
			if (states[i] == unreachableStates[r])
				isUnreachable = true;
		}
		// if a state isn't unreachable, then add it to the cleanTransitionFunction
		if (!isUnreachable)
		{
			std::vector<char> eachState;
			for (int j = 0; j < numberOfAlphabets; j++)
			{
				eachState.push_back(transitionFunction[i][j]);
			}
			newStateMap[i] = states[i];
			cleanTransitionFunction.push_back(eachState);
		}
	}
	// Reindexing the newStateMap to exclude unreachable states.
	newStateMap = reindexStateMap();
	numberOfStates = numberOfStates - unreachableStates.size();
	return cleanTransitionFunction;
}

std::map<int, char> reindexStateMap()
{
	// Find the maximum key in the map
	int maxKey = 0;
	for (const auto& pair : newStateMap) 
	{
		if (pair.first > maxKey) 
		{
			maxKey = pair.first;
		}
	}

	// Create a new map with contiguous keys
	std::map<int, char> reindexedMap;
	int newIndex = 0;
	for (int i = 0; i <= maxKey; ++i) 
	{
		auto it = newStateMap.find(i);
		if (it != newStateMap.end()) 
		{
			reindexedMap[newIndex++] = it->second;
		}
	}
	return reindexedMap;
}