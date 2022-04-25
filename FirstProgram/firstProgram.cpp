#include "stuff.h"

#include <iostream>

int main()
{
	
	std::cout << doubleNumber(getIntValue()) << "\n";

	int n{ getIntValue() };

	int m{};
	getIntValueDefined(&m);
	
	std::cout << n << " + " << m << " is: " << n + m << "\n";
	std::cout << n << " - " << m << " is: " << n - m << "\n";
	
	return 0;
}