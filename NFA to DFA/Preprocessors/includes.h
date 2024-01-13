#pragma once

#include <iostream>
#include <array>
#include <cstring>
#include "Enums/Alphabet.h"
#include "Enums/States.h"
#include <vector>
#include "../functions/FillingTransition/fillTransitionFunction.h"
#include "../functions/PrintNFA/printNFA.h"
#include "../functions/PrintNFA/PrintELNFA.h"
#include "../functions/PrintNFA/printNewNFA.h"
#include "../functions/CreateNewStates/NewStatesCreator.h"
#include "../functions/EliminateLambda/LambdaElimination.h"
