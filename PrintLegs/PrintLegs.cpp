/*
Set up an enum with the names of the following animals : chicken, dog, cat, elephant, duck, and snake.
Put the enum in a namespace.
Define an array with an element for each of these animals, and
use an initializer list to initialize each element to hold the number of legs that animal has.
Write a main function that prints the number of legs an elephant has, using the enumerator.
*/

#include <iostream>

namespace Animals
{
	enum Animals
	{
		CHICKEN,			// 2 legs
		DOG,				// 4 legs
		CAT,				// 4 legs
		ELEPHANT,			// 4 legs
		DUCK,				// 2 legs
		SNAKE,				// 0 legs
		TOTAL_ANIMALS,
	};
}



int main()
{
	int animalLegs[Animals::TOTAL_ANIMALS]{2, 4, 4, 4, 2, 0};

	std::cout << "Elephant has " << animalLegs[Animals::ELEPHANT] << " legs.\n";
		   
	return 0;
}

