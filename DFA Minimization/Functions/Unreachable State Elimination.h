#pragma once
#include <map>
#include <algorithm>

std::map<int, char> newStateMap;

// For this function, I have used the famous algorithm for eliminating unreachable states.
std::vector<std::vector<char>> eliminateUnreachableStates(char** transitionFunction, char starter, int& numberOfStates, int numberOfAlphabets)
{

    // Vector of reachable states
    std::vector<char> reachableStates = { starter };

    // Temporary vector to store newly reachable states
    std::vector<char> temp;

    do 
{
        temp.clear();

        // Iterate through reachable states
        for (char stateChar : reachableStates)
        {
            // cast state into States type
            States state = mapStates(stateChar);
            // Iterate through alphabet
            for (int symbol = 0; symbol < numberOfAlphabets; symbol++)
            {
                // Find the destination state for the given symbol
                char destination = transitionFunction[state][symbol];

                // If the destination is not in reachable states, add it to temp
                if (std::find(reachableStates.begin(), reachableStates.end(), destination) == reachableStates.end()) {
                    temp.push_back(destination);
                }
            }
        }

        // Add newly reachable states to the vector of reachable states
        reachableStates.insert(reachableStates.end(), temp.begin(), temp.end());

    } while (!temp.empty());

    // Sort and remove duplicates from the vector of reachable states
    std::sort(reachableStates.begin(), reachableStates.end());
    reachableStates.erase(std::unique(reachableStates.begin(), reachableStates.end()), reachableStates.end());
    
    numberOfStates = reachableStates.size();
    
	// create a new Transition function to store clean DFA
	std::vector<std::vector<char>> cleanTransitionFunction;

    for (int i = 0; i < numberOfStates; i++)
    {
        States state = mapStates(reachableStates[i]);
        std::vector<char> currentState;
        for (int j = 0; j < numberOfAlphabets; j++)
        {
            currentState.push_back(transitionFunction[state][j]);
        }
        cleanTransitionFunction.push_back(currentState);
        newStateMap[i] = reachableStates[i];
    }

	return cleanTransitionFunction;
}