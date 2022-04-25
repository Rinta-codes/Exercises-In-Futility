#include <iostream>
#include "Stringer.h"

int main()
{
	Stringer string{ "Hello, world!" };
	std::cout << string(7, 5) << '\n'; // start at index 7 and return 5 characters

	return 0;
}