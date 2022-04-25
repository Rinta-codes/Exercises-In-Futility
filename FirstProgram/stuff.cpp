#include "stuff.h"

#include <iostream>

int getIntValue()
{
	int n{ 0 };
	std::cout << "Enter an Integer: ";
	std::cin >> n;

	return n;
}

void getIntValueDefined(int* iAmLink)
{
	std::cout << "Enter an Integer: ";
	std::cin >> *iAmLink;
}

int doubleNumber(int number)
{
	return number * 2;
}
