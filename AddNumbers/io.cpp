#include "io.h"
#include <iostream>

int readNumber()
{
	std::cout << "Enter an Integer: ";
	int userInput;
	std::cin >> userInput;

	return userInput;
}

void writeAnswer(int value)
{
	std::cout << "The answer is: " << value << "\n";
}