#pragma once

void printCleanDFA(std::vector<std::vector<char>> TransitionFunction, std::map<int, char> newStateMap)
{
	std::cout << "\n******************************************\n\n";
	std::cout << "Step 1: Eliminate any unreachable state.\n\n";
	std::cout << std::left;														// Align the values to the left
	std::cout << "+----------------+-------+-------+\n";						// Prints the top border
	std::cout << "| State - Symbol |   a   |   b   |\n";						// Prints the header row
	std::cout << "+----------------+-------+-------+\n";						// Prints the separator
	for (int i = 0; i < TransitionFunction.size(); i++)							// Loops through the states
	{
		std::cout << "|       " << std::setw(9) << newStateMap[i];				// Prints the state name
		for (int j = 0; j < TransitionFunction[i].size(); j++)					// Loops through the symbols
		{
			std::cout << "|   " << std::setw(4) << TransitionFunction[i][j];	// Print the transition value with a width of 4
		}
		std::cout << "|\n";														// Print the end of the row
		std::cout << "+----------------+-------+-------+\n";					// Print the separator
	}
}