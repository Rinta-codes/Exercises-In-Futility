// Define an enum (or enum class, if using a C++11 capable compiler) named Animal that contains the following animals : 
// pig, chicken, goat, cat, dog, ostrich.

// Write a function named getAnimalName() that takes an Animal parameter
// and uses a switch statement to return the name for that animal as a std::string.

// Write another function named printNumberOfLegs() that uses a switch statement to print 
// the number of legs each animal walks on.

// Make sure both functions have a default case that prints an error message.

// Call printNumberOfLegs() from main() with a cat and a chicken.
// Your output should look like this:

//	A cat has 4 legs.
//	A chicken has 2 legs.

#include <iostream>
#include <string>

enum class Animal
{
	PIG,
	CHICKEN,
	GOAT,
	CAT,
	DOG,
	OSTRICH,
};

std::string getAnimalName(Animal animal)
{
	switch (animal)
	{
	case Animal::PIG:
		return "pig";
	case Animal::CHICKEN:
		return "chicken";
	case Animal::GOAT:
		return "goat";
	case Animal::CAT:
		return "cat";
	case Animal::DOG:
		return "dog";
	case Animal::OSTRICH:
		return "ostrich";
	default:
		std::cout << "getAnimalName(): Unidentified animal detected\n";
		return "unidentified animal";
	}
}

void printNumberOfLegs(Animal animal)
{
	switch (animal)
	{
	case Animal::PIG:
	case Animal::GOAT:
	case Animal::CAT:
	case Animal::DOG:
		std::cout << "A " << getAnimalName(animal) << " has 4 legs\n";
		break;
	case Animal::CHICKEN:
		std::cout << "A " << getAnimalName(animal) << " has 2 legs\n";
		break;
	case Animal::OSTRICH:
		std::cout << "An " << getAnimalName(animal) << " has 2 legs\n";
		break;
	default:
		std::cout << "printNumberOfLegs(): Unidentified animal detected\n";
	}
}


int main()
{
	printNumberOfLegs(Animal::CAT);
	printNumberOfLegs(Animal::CHICKEN);

	return 0;
}




