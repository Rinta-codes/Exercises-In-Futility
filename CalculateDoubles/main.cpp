#include "calculate.h"
#include <iostream>

int main()
{
	double x{ userInputDouble() };
	double y{ userInputDouble() };
	char action{ userInputAction() };

	calculateAnswer(x, y, action);
		
	return 0;
}