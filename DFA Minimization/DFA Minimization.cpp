#include "PreProcessors/Includes.h"

int main()
{
    /*
    * you can always change these states and TransitionFunction to convert or optimize another DFA.
    * everything works dynamically. Feel free to change the DFA.
    * To change a DFA, change the first 4 tuple, then change the Enums accordingly.
    * then head to the fillTransitionFunction to change the Transition Function for the 5th tuple.
    */

    // first 4 tuples of a DFA
    std::vector<char> states = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    char starter = 'A';
    char alphabets[] = { 'a', 'b' };
    std::vector<char> finalStates = {'A', 'D', 'E', 'H'};

    // Get the size of states and alphabets arrays
    int numberOfStates = states.size();
    int numberOfAlphabets = sizeof(alphabets) / sizeof(alphabets[0]);

    // 5th tuple
    char** transitionFunction = fillTransitionFunction(transitionFunction, numberOfStates, numberOfAlphabets);

    // Print the unoptimized DFA
    printRawDFA(transitionFunction, numberOfStates, numberOfAlphabets);

    // STEP 1: Eliminate any unreachable states & Print the new DFA
    std::vector<std::vector<char>> TransitionFunction = eliminateUnreachableStates(transitionFunction, starter, numberOfStates, numberOfAlphabets, finalStates, states);
    printCleanDFA(TransitionFunction, newStateMap);

    // STEP 2: Use Hopcroft's algorithm for DFA minimization
    std::vector<std::vector<char>> minimizedDFA = minimizeDFA(TransitionFunction, states, finalStates, numberOfAlphabets);
}

