#pragma once

/* This is Hopcroft's algorithm for DFA minimization */
std::vector<std::vector<char>> minimizeDFA(std::vector<std::vector<char>> TransitionFunction, std::vector<char> states, std::vector<char> finalStates, int numberOfAlphabets)
{
	// Create a new vector with non-final states
	std::vector<char> nonFinalStates;
	for (char state : states) 
		if (std::find(finalStates.begin(), finalStates.end(), state) == finalStates.end()) 
			nonFinalStates.push_back(state);

	// Initial partitions
	std::vector<std::vector<char>> partitions = {finalStates, nonFinalStates };

	// If a partition needs a refinement, Set this to true to refinement process continue
	bool refined = true;

	while (refined)
	{
		refined = false;
		
		// DEBUG: Insert print statements
		std::cout << "Entering refinement loop\n";

		// Iterate over partitions
		for (const auto& partition : partitions)
		{
			// DEBUG:
			std::cout << "Processing partition: ";
			for (char state : partition) 
			{
				std::cout << state << " ";
			}
			std::cout << "\n";
			
			
			// Iterate over symbols in the alphabet
			for (int symbol = 0; symbol < numberOfAlphabets; symbol++)
			{
				// Create new partitions
				std::vector<std::vector<char>> newPartitions;

				// DEBUG
				std::cout << "FLAG 1 | ";
				
				// Split the current partition based on transitions with the symbol
				for (char stateChar : partition)
				{
					
					// DEBUG
					std::cout << "FLAG 2 " << stateChar << " | ";

					// Cast the current state in the current partition into a States Enum data type
					States state = mapStates(stateChar);

					// Find the destination state for the given symbol
					char destination = TransitionFunction[state][symbol];

					std::cout << "DEBUG: Destination state: " << destination << "\n";

					// Find the partition that contains the destination state
					/*
					* The purpose of p is to check whether the destination state is present in the current partition.
					* The lambda function returns true if destination is found in the current partition (p), and false otherwise.
					*/
					auto it = std::find_if(newPartitions.begin(), newPartitions.end(), [destination](const std::vector<char>& p)
						{
							std::cout << "DEBUG: Checking partition: ";
							for (char state : p) {
								std::cout << state << " ";
							}
							std::cout << "\n";

							return std::find(p.begin(), p.end(), destination) != p.end();
						});

					/*
					* This condition checks whether the iterator it points to an existing partition in newPartitions.
					* If it does, it means that a partition containing the destination state was found.
					*/
					if (it != newPartitions.end())
					{
						/*
						* If an existing partition is found, it means that the destination state is reachable from the current state with the current symbol.
						* In this case, the current state (stateChar) is added to the existing partition.
						*/
						it->push_back(stateChar);
					}
					/*
					* If no existing partition is found, it means that
					* the destination state is not reachable from any state in the current partition with the current symbol.
					*/
					else
					{
						/*
						* In this case, a new partition is created with the current state (stateChar).
						* This new partition represents a set of states that are reachable from each other with the current symbol.
						*/
						newPartitions.push_back({ stateChar });
					}

					// DEBUG
					std::cout << "FLAG 3 | \n";

				}

				/*
				* After processing all symbols for a particular partition,
		        * the algorithm then checks if any new partitions were created.
				*/
				if (newPartitions.size() > 1)
				{
					/*
					* This deletion is done in the case where the current partition is refined into multiple partitions
					* based on transitions with different symbols.
					*/
					partitions.erase(std::find(partitions.begin(), partitions.end(), partition));

					// If new partitions were created, they are added to the set of partitions 
					partitions.insert(partitions.end(), newPartitions.begin(), newPartitions.end());

					// Set this to true to check new partitions for refinements
					refined = true;
					break;
				}

			}
		}
	}

	for (const auto& partition : partitions) 
	{
		std::cout << "Partition: ";
		for (char state : partition) 
		{
			std::cout << state << " ";
		}
		std::cout << "\n";
	}

	exit(589);
	return partitions;
}