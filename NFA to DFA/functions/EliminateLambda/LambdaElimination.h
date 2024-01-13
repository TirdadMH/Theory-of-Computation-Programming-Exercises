#pragma once
#include <iostream>
#include "../../Enums/Alphabet.h"
#include "../../Enums/States.h"

int getNumber0fTargetStates(char*, int);
States mapEnumStates(char);
char mapEnumStates(States);
std::string* getTargetTransitions(std::string*, std::string*, int, int, int);
bool isFinalState(char, std::vector<char>);
bool isCurrentStateInFinalStates(std::vector<char>, char);
std::string formatToStandard(std::string);

#pragma warning(disable:6386)
#pragma warning(disable:6385)
std::string** eliminateLambda(std::string** transitionFunction, std::vector<char> finalStates, int numberOfStates, int numberOfAlphabets, char states[])
{
	int potentialNumberOfStates = ((numberOfStates - 1) * 2) + numberOfStates;
	for (int i = 0; i < numberOfStates; i++)
	{
		char* targetStates = new char[numberOfStates]();
		if (!(transitionFunction[i][lambda] == "-"))
		{
			int l = 0;
			for (int j = 0; j < potentialNumberOfStates; j += 3)
			{
				if (j > transitionFunction[i][lambda].length())
					break;
				char temp = transitionFunction[i][lambda][j];
				targetStates[l] = temp;
				l++;
			}
		}

		int numberOfTargetStates = getNumber0fTargetStates(targetStates, numberOfStates);
		if (numberOfTargetStates == 0)
			continue;
		for (int j = 0; j < numberOfTargetStates; j++)
		{
			States targetState = mapEnumStates(targetStates[j]);
			transitionFunction[i] = getTargetTransitions(transitionFunction[i], transitionFunction[targetState], numberOfAlphabets, potentialNumberOfStates, numberOfStates);
			if (isFinalState(targetStates[j], finalStates))
			{
				States currentState = (States)i;
				char currentStateChar = mapEnumStates(currentState);
				if (!(isCurrentStateInFinalStates(finalStates, currentStateChar)))
					finalStates.push_back(targetStates[j]);
			}
		}
		transitionFunction[i][lambda] = "-";
	}
	return transitionFunction;
}

int getNumber0fTargetStates(char* targetStates, int numberOfStates)
{
	int number0fTargetStates = 0;
	for (int i = 0; i < numberOfStates; i++)
		if (targetStates[i] != '\0')
			number0fTargetStates++;
	return number0fTargetStates;
}
States mapEnumStates(char target) // HARD-CODDED
{
	States s;
	switch (target) 
	{
	case 'A': s = States::A; break;
	case 'B': s = States::B; break;
	case 'C': s = States::C; break;
	case 'D': s = States::D; break;
	case 'E': s = States::E; break;
	}
	return s;
}
char mapEnumStates(States state) // HARD-CODDED
{
	char ch;
	switch (state)
	{
	case States::A: ch = 'A'; break;
	case States::B: ch = 'B'; break;
	case States::C: ch = 'C'; break;
	case States::D: ch = 'D'; break;
	case States::E: ch = 'E'; break;
	}
	return ch;
}
std::string* getTargetTransitions(std::string* currentTransitions, std::string* targetTransitions, int numberOfAlphabets, int potentialNumberOfStates, int numberOfStates)
{
	for (int i = 0; i < numberOfAlphabets - 1; i++)
	{
		int l = 0;
		int Csize = 0;
		int Tsize = 0;
		char CurrentStateTransitions[5] = {}; // HARD-CODDED
		char TargetStateTransitions[5] = {};  // HARD-CODDED
		for (int j = 0; j < potentialNumberOfStates; j += 3)
		{
			if (j > currentTransitions[i].length())
				break;
			if (currentTransitions[i][j] != '=')
			{
				CurrentStateTransitions[l] = currentTransitions[i][j];
				Csize++;
				l++;
			}

		}
		int u = 0;
		for (int j = 0; j < potentialNumberOfStates; j += 3)
		{
			if (j > targetTransitions[i].length())
				break;
			if (targetTransitions[i][j] != '=')
			{
				TargetStateTransitions[u] = targetTransitions[i][j];
				Tsize++;
				u++;
			}
		}
		for (int j = 0; j < Csize; j++)
		{
			for (int k = 0; k < Tsize; k++)
			{
				if (CurrentStateTransitions[j] == TargetStateTransitions[k])
				{
					TargetStateTransitions[k] = '\0';
				}
			}
		}
		std::string toAppend = "";
		for (int a = 0; a < Tsize; a++)
		{
			if (TargetStateTransitions[a] != '\0')
			{
				std::string tempString(1, TargetStateTransitions[a]);
				toAppend.append(tempString);
			}
			if (a == (Tsize - 1))
				break;
			else if (TargetStateTransitions[a + 1] != '\0')
				toAppend.append(", ");
		}
		if (toAppend.length() == 1)
		{
			if (!(currentTransitions[i] == NO_STATE))
			{
				std::string s = ", ";
				s.append(toAppend);
				toAppend = s;
			}
		}
		if (toAppend != ", ")
		{
			if (currentTransitions[i] == NO_STATE)
			{
				currentTransitions[i] = '\0';
				currentTransitions[i] = toAppend;
			}
			else
				currentTransitions[i].append(toAppend);
		}
		currentTransitions[i] = formatToStandard(currentTransitions[i]);
	}
	return currentTransitions;
}
bool isFinalState(char targetState, std::vector<char> finalStates)
{
	for (int i = 0; i < finalStates.size(); i++)
		if (targetState == finalStates[i])
			return true;
	return false;
}
bool isCurrentStateInFinalStates(std::vector<char> finalStates, char currentState)
{
	for (int i = 0; i < finalStates.size(); i++)
	{
		if (finalStates[i] == currentState)
			return true;
	}
	return false;
}