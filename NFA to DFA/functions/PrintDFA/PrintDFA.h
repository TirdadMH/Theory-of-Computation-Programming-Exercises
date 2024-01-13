#pragma once

void printDFA(std::map<std::string, int>& stateMap, std::vector<std::vector<std::string>>& newStatesTransitionFunction, std::string**& transitionFunction)
{
	std::cout << "\n*********************************************************************************\n";
	std::cout << "\nSTEP 3: Adding the Trap state. Now the Conversion is Completed. : \n\n";
	printNewNFA(stateMap, newStatesTransitionFunction, transitionFunction, false);
}