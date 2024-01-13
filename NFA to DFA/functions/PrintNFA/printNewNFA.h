#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include "../../Enums/Alphabet.h"


void printNewNFA(std::map<std::string, int> stateMap, std::vector<std::vector<std::string>> newStatesTransitionFunction, std::string** transitionFunction)
{
	std::cout << "\n*******************************************************************\n";
	std::cout << "\nSTEP 2: Creating New States according to multiple transitions: \n\n";
	printELNFA(transitionFunction, false);
	std::cout << std::left;
	for (int i = 0; i < stateMap.size(); i++)													// Loops through the states
	{
		std::string foundKey = "";																// Iterate through the map to find the key based on the value
		for (const auto& pair : stateMap)
		{
			if (pair.second == i)
			{
				foundKey = pair.first;
				break;																			// Stop the loop once the key is found
			}
		}
		std::cout << "| " << std::setw(14) << foundKey;											// Prints the state name
		for (int j = a; j < lambda; j++)																// Loops through the symbols
		{
			std::cout << "| " << std::setw(14) << newStatesTransitionFunction[i][j];			// Print the transition value with a width of 4
		}
		std::cout << "|\n";																		// Print the end of the row
		std::cout << "+---------------+---------------+---------------+---------------+\n";		// Print the separator
	}
}