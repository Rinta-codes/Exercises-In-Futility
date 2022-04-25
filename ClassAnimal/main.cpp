#include <iostream>
#include "Animal.h"

int main()
{
	Cat fred{ "Fred" };
	Cat misty{ "Misty" };
	Cat zeke{ "Zeke" };

	Dog garbo{ "Garbo" };
	Dog pooky{ "Pooky" };
	Dog truffle{ "Truffle" };

	// Set up an array of pointers to animals, and set those pointers to our Cat and Dog objects
	Animal *animals[] { &fred, &garbo, &misty, &pooky, &truffle, &zeke };
	for (const auto animal : animals)
		std::cout << animal->getName() << " says " << animal->speak() << '\n';

	return 0;
}