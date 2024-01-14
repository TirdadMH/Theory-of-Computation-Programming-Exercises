#pragma once

enum States
{
	A = 0,
	B = 1,
	C = 2,
	D = 3,
	E = 4,
	F = 5,
	G = 6,
	H = 7
};


States mapStates(char input)
{
	States output;
	switch (input)
	{
		case 'A': output = States::A; break;
		case 'B': output = States::B; break;
		case 'C': output = States::C; break;
		case 'D': output = States::D; break;
		case 'E': output = States::E; break;
		case 'F': output = States::F; break;
		case 'G': output = States::G; break;
		case 'H': output = States::H; break;
	}
	return output;
}