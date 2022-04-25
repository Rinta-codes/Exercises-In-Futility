#include "io.h"
#include <iostream>

int main()
{
	int userInput1{ readNumber() };
	int userInput2{ readNumber() };

	writeAnswer(userInput1 + userInput2);

	return 0;
}