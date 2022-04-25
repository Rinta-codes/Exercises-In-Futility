#include "stuff.h"
#include <iostream>


int userInput()
{
	std::cout << "Enter a single digit integer: ";
	int userInput;
	std::cin >> userInput;
	return userInput;
}

void checkPrime(int value)
{

	if ((value == 2) + (value == 3) + (value == 5) + (value == 7))
		std::cout << value << " is a single-digit Prime number" << "\n";
	else
		std::cout << value << " is NOT a single-digit Prime number" << "\n";
	
}

