#pragma once
#include <iomanip>

void printRawDFA(char** transitionFunction, int numberOfStates, int numberOfAlphabets)
{
	std::cout << "The Raw DFA: \n";
	std::cout << std::left;														// Align the values to the left
	std::cout << "+----------------+-------+-------+\n";						// Prints the top border
	std::cout << "| State - Symbol |   a   |   b   |\n";						// Prints the header row
	std::cout << "+----------------+-------+-------+\n";						// Prints the separator
	for (int i = 0; i < numberOfStates; i++)									// Loops through the states
	{
		std::cout << "|       " << std::setw(9)  << char('A' + i);				// Prints the state name
		for (int j = 0; j < numberOfAlphabets; j++)								// Loops through the symbols
		{
			std::cout << "|   " << std::setw(4) << transitionFunction[i][j];	// Print the transition value with a width of 4
		}
		std::cout << "|\n";														// Print the end of the row
		std::cout << "+----------------+-------+-------+\n";					// Print the separator
	}
}