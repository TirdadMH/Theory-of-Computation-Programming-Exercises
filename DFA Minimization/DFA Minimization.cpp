#include "PreProcessors/Includes.h"

int main()
{
    /*
    * you can always change these states and TransitionFunction to convert or optimize another DFA.
    * everything works dynamically. Feel free to change the DFA.
    * To change a DFA, change the first 4 tuple, then change the Enums accordingly.
    * then head to the fillTransitionFunction to change the Transition Function for the 5th tuple.
    */

    // first 3 tuples of a DFA
    char states[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    char starter = 'A';
    char alphabets[] = { 'a', 'b' };

    // 4th tuple
    std::vector<char> finalStates = {'A', 'D', 'E', 'H'};

    // Get the size of states and alphabets arrays
    int numberOfStates = sizeof(states) / sizeof(states[0]);
    int numberOfAlphabets = sizeof(alphabets) / sizeof(alphabets[0]);

    // 5th tuple
    char** transitionFunction = fillTransitionFunction(transitionFunction, numberOfStates, numberOfAlphabets);

    // Print the unoptimized DFA
    printRawDFA(transitionFunction, numberOfStates, numberOfAlphabets);

    // STEP 1: Eliminate any unreachable states & Print the new DFA
    std::vector<std::vector<char>> TransitionFunction = eliminateUnreachableStates(transitionFunction, states, numberOfStates, numberOfAlphabets);
    printCleanDFA(TransitionFunction, newStateMap);
}
