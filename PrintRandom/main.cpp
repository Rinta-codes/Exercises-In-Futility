#include "random.h"
#include <iostream>

int main()
{

	for (int count{ 0 }; count < 3; ++count)
	{
		std::cout << myRandomNumber(1000) << '\n';
		
		// std::cout << (count % 5 == 0) ? '\n' : '\t';
	};

	return 0;
}