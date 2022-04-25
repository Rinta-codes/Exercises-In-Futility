#include "calculate.h"
#include <iostream>


double userInputDouble()
{
	std::cout << "Enter a floating point number (e.g. 6.784) and press Enter: ";

	double userInput;
	std::cin >> userInput;
	return userInput;
}


char userInputAction()
{
	std::cout << "Enter mathematical symbol (one of: +, -, * or /) and press Enter: ";
	
	char action;
	std::cin >> action;
	return action;
}


void calculateAnswer(double x, double y, char action)
{
	if (action == '+')
		std::cout << x << " " << action << " " << y << " = " << x + y << '\n';
	else
	if (action == '-')
		std::cout << x << " " << action << " " << y << " = " << x - y << '\n';
	else
	if (action == '*')
		std::cout << x << " " << action << " " << y << " = " << x * y << '\n';
	else
	if (action == '/')
		std::cout << x << " " << action << " " << y << " = " << x / y << '\n';
	else
		std::cout << "Invalid action was entered!" << '\n';
}