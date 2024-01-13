#pragma once
#include <iostream>
#include <iomanip>
#include "../../Enums/Alphabet.h"
#include "../../Enums/States.h"

void printELNFA(std::string** transitionFunction)
{
	std::cout << "***********************************************************\n";
	std::cout << "STEP 1: Eliminating the Lambda Transitions: \n";
	// Align the values to the left
	std::cout << std::left;
	std::cout << "+----+------------+------------+------------+\n";					// Prints the top border
	std::cout << "|    |  a         |  b         |  c         |\n";					// Prints the header row
	std::cout << "+----+------------+------------+------------+\n";					// Prints the separator
	for (int i = A; i <= E; i++)													// Loops through the states
	{
		std::cout << "| " << char('A' + i) << "  ";									// Prints the state name
		for (int j = a; j < lambda; j++)											// Loops through the symbols
		{
			std::cout << "| " << std::setw(10) << transitionFunction[i][j] << " ";	// Print the transition value with a width of 4
		}
		std::cout << "|\n";															// Print the end of the row
		std::cout << "+----+------------+------------+------------+\n";				// Print the separator
	}
}