#pragma once
#include <vector>
#include <map>
#include <algorithm>
#include "../../Enums/Alphabet.h"
#include "../../Enums/States.h"

std::string extractStateTransitions(std::string, Alphabet, std::string**);
States mapEnumStates(char target);
std::string formatToStandard(std::string);

std::map<std::string, int> stateMap = {}; // This map holds the keys for the new States.
int SMI = 0; // State Map Irritation.

std::vector<std::vector<std::string>> createNewStates(std::string** transitionFunction, int numberOfStates, int numberOfAlphabets)
{
	/* PHASE 1: Add new States according to the Transitions with multiply destinations.*/
	std::vector<std::vector<std::string>> newStatesTransitionFunction;
	for (int i = 0; i < numberOfStates; i++)
	{
		// for each destination state in the TransitionFunction
		for (int j = 0; j < numberOfAlphabets; j++) 
		{
			std::string newState;
			// If a destination state's length is more that 1, it means that the destination state is a new state.
			if (transitionFunction[i][j].length() > 1) 
			{
				// assigning the value for the destination state to a new string.
				newState = transitionFunction[i][j]; 
				// Check if The New State exists in the stateMap using find
				auto it = stateMap.find(newState); 
				// if the Key is found, It means that the NewState is already exists in our map of new states.
				if (it != stateMap.end()) 
					continue;
				// If key not found, It means that we can make a new state in out NFA that doesn't exists. 
				else
				{
					// we add the new state to the stateMap with It's key and value for that Key.
					stateMap[newState] = SMI; 
					// we create a new TransitionFunction for this new state.
					std::vector<std::string> newStateTransitions; 
					// for each symbol in the alphabet without Lambda
					for (int a = 0; a < (numberOfAlphabets - 1); a++) 
					{
						// we then get the union of every transition for that symbol for the new state.
						std::string newStateATransitions = extractStateTransitions(newState, (Alphabet)a, transitionFunction);
						// and then we add it to the transitionFunction for that symbol.
						newStateTransitions.push_back(newStateATransitions); 
					}
					// after creating the transitionFunction for the new state, we add it to the rest of new states.
					newStatesTransitionFunction.push_back(newStateTransitions);
					SMI++;
				}
			}
		}
	}

	/* PAHSE 2: check Every single state in the new stateMap to find new states that's been created during PHASE 1.*/
	for (int i = 0; i < SMI; i++)
	{
		// for each destination in the newStatesTransitionFunction:
		for (int j = 0; j < numberOfAlphabets - 1; j++)
		{
			bool foundMatch = false;
			// this is the currentDestination, where it's value is equal the current destination in the newStatesTransitionFunction array.
			std::string currentDestination = newStatesTransitionFunction[i][j];
			for (int k = 0; k < SMI; k++)
			{
				// iterate through the map to find the key based on the value
				std::string currentState = "";
				for (const auto& pair : stateMap)
				{
					if (pair.second == k)
					{
						// stop the loop once the key is found
						currentState = pair.first;
						break;
					}
				}
				// if foundMatch becomes true, it means that the currentDestination exists in the stateMap.
				if (currentDestination == currentState)
					foundMatch = true;
			}
			// if it stays false, it means that the currentDestination does not exist in the stateMap and it should be added.
			if (!foundMatch)
			{
				// checking if currentDestination is a single state.
				if (currentDestination.length() >= 4)
				{
					// we add the new state to the stateMap with It's key and value for that Key.
					stateMap[currentDestination] = SMI;
					// we create a new TransitionFunction for this new state.
					std::vector<std::string> newStateTransitions;
					// for each symbol in the alphabet without Lambda
					for (int a = 0; a < (numberOfAlphabets - 1); a++)
					{
						// we then get the union of every transition for that symbol for the new state.
						std::string newStateATransitions = extractStateTransitions(currentDestination, (Alphabet)a, transitionFunction);
						// and then we add it to the transitionFunction for that symbol.
						newStateTransitions.push_back(newStateATransitions);
					}
					// after creating the transitionFunction for the new state, we add it to the rest of new states.
					newStatesTransitionFunction.push_back(newStateTransitions);
					SMI++;
				}
			}
		}
	}
	return newStatesTransitionFunction;
}

/*
* this function gets a set of states and a transition symbol and returns a union of transitions
  for those set of states with that specific symbol.
*/
std::string extractStateTransitions(std::string newState, Alphabet alphabet, std::string** transitionFunction)
{
	std::vector<char> extractedFromNewState;
	std::string stateTransitions = "";
	for (int i = 0; i < newState.length(); i++)
	{
		if (isalpha(newState[i]))
		{
			extractedFromNewState.push_back(newState[i]);
		}
	}
	for (int i = 0; i < extractedFromNewState.size(); i++)
	{
		States targetIndex = mapEnumStates(extractedFromNewState[i]);
		stateTransitions.append(transitionFunction[targetIndex][alphabet]);
	}
	stateTransitions = formatToStandard(stateTransitions);
	return stateTransitions;
}

/*
* this function takes a messy string like : BC,FACB and erases the duplicates and sorts it and adds comma to them 
* too look like this: A, B, C, F
*/
std::string formatToStandard(std::string stateTransitions)
{
	std::vector<char> extractedFromStateTransitions;
	for (int i = 0; i < stateTransitions.length(); i++) // extracting States from the messy string,
	{
		if (isalpha(stateTransitions[i]))
		{
			extractedFromStateTransitions.push_back(stateTransitions[i]);
		}
	}
	
	// Sort the states to be formatted.
	std::sort(extractedFromStateTransitions.begin(), extractedFromStateTransitions.end());

	// Erase duplicates
	auto last = std::unique(extractedFromStateTransitions.begin(), extractedFromStateTransitions.end());
	extractedFromStateTransitions.erase(last, extractedFromStateTransitions.end());

	// Pass states to a string with a comma after each State.
	std::string formattedStates = "";
	int i = 0;
	for (auto each : extractedFromStateTransitions)
	{
		std::string temp(1, each);
		formattedStates.append(temp);
		if (i < (extractedFromStateTransitions.size() - 1))
		{
			formattedStates.append(", ");
		}
		i++;
	}
	return formattedStates;
}