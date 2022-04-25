#include "stuff.h"
#include <iostream>
#include <string> // for std::string
#include <type_traits> // is_integral?
#include <iterator> // for std::size() of the array[]
#include <array> // for std::array

enum EnumThing
{
	A,
	B,
	C,
	D,
};

enum class EnumThingButClass
{
	A,
	B,
	C,
	D,
};

struct Stuff
{
	std::string name;
	int birthYear;
	int birthMonth;
	int birthDate;

	bool isMarried;
};

void xorFunction(bool x, bool y)
{
	if (x ^ y)
		std::cout << "true ";
	else
		std::cout << "false ";
}

void printStuff(Stuff employee)
{
	std::cout << "Your name is " << employee.name << ", your date of birth is " << employee.birthDate << "."
		<< employee.birthMonth << "." << employee.birthYear << " and you " << (employee.isMarried ? "are" : "are not") << " married.\n";
}

// This program checks whether single digit Integer inputted by user is prime
// It is not expected to work for non-single digits
int main()
{ 
	/*
	int value { userInput() };
	checkPrime(value);
	*/

	/*
	int x = 012;
	std::cout << x << '\n';

	int y = 2'3'22'531'2;
	std::cout << y << '\n';

	return 0;
	*/

	/*
	std::cout << sizeof(int) << ", " << sizeof(float) << '\n';

	signed int x = 0b1000'0000'0000'0000'0000'0000'0000'0000;
	signed int y = 0b0111'1111'1111'1111'1111'1111'1111'1111;
	std::cout << x << '\n' << y << '\n';


	float z = 0b1100'0001'0001'1010'1000'0000'0000'0000;
	std::cout << z << '\n';

	return 0;
	*/

	/*
	bool x = true;
	bool y = false;

	std::cout << static_cast<bool>(x ^ x) << " " << static_cast<bool>(x ^ y) << " " << static_cast<bool>(y ^ x) << " " << static_cast<bool>(y ^ y) << '\n';

	xorFunction(x, x);
	xorFunction(x, y);
	xorFunction(y, x);
	xorFunction(y, y);

	std::cout << '\n';

	std::string words{"This is a word!\nThis is also a word!"};
	std::cout << words << '\n'; 

	std::string otherWords{ "" };
	std::cin >> otherWords; 
	std::cin.ignore(9999, '\n');

	std::getline(std::cin, words);
	std::cout << words << '\n';
	*/

	/*
	Stuff employee;

	std::cout << "Enter your full name, then press Enter: ";
	std::getline(std::cin, employee.name);

	std::cout << "Enter your date of birth in format YYYY MM DD, then press Enter: ";
	std::cin >> employee.birthYear >> employee.birthMonth >> employee.birthDate;

	{
		std::cout << "Are you married? Y/N: ";
		char isMarriedYN;
		std::cin >> isMarriedYN;

		employee.isMarried = isMarriedYN == 'Y' ? 1 : 0;
	}

	std::cout << "Your name is " << employee.name << ", your date of birth is " << employee.birthDate << "."
		<< employee.birthMonth << "." << employee.birthYear << " and you " << (employee.isMarried ? "are" : "are not") << " married.\n";

	Stuff employee2{ "Robert Baratheon", 217, 5, 14, true };
	std::cout << "\nNow in other news...\n\n";
	printStuff(employee2);
	*/

	/*
	std::cout << "is_integral:" << std::endl;
	std::cout << "char: " << std::is_integral<char>::value << std::endl;
	std::cout << "int: " << std::is_integral<int>::value << std::endl;
	std::cout << "float: " << std::is_integral<float>::value << std::endl;
	std::cout << "EnumThing: " << std::is_integral<EnumThing>::value << std::endl;
	std::cout << "EnumThingButClass: " << std::is_integral<EnumThingButClass>::value << std::endl;

	std::cout << "The End!\n";
	*/

	/*
	int testArray[5]{};
	std::cout << testArray[4];

	char testChar{};
	std::cout << "\"" << testChar << "\"\n";


	std::cout << std::size(testArray) << '\n';
	*/

	/*
	int *pointInt{new (std::nothrow) int};
	if (!pointInt)
	{
		std::cout << "Couldn't allocate memory for first pointer!";
	}
	else
	{
		*pointInt = 5;
		std::cout << *pointInt << '\n';

		delete pointInt;
		pointInt = nullptr;
	}

	int *pointInt2{ new (std::nothrow) int{10} };
	if (!pointInt2)
	{
		std::cout << "Couldn't allocate memory for second pointer!";
	}
	else
	{
		std::cout << *pointInt2 << '\n';

		delete pointInt2;
		pointInt2 = nullptr;
	}

	int* pointArray{ new int[100'000'000] }; // Allocating 500+ Mb of memory

	int pointArraySize{ 0 };
	while (pointArray[pointArraySize])
		++pointArraySize;
		
	std::cout << "Array size of pointArray is " << pointArraySize - 1 << '\n'; // Hey we can calculate Array size even if it's a pointer

	//									Just a stop point to check memory size
	// char stopSign{};
	// while (!(stopSign == 'S'))
	// 	std::cin >> stopSign;

	delete[] pointArray;				// De-allocate the memory
	pointArray = nullptr;

	//									Just a stop point to check memory size
	// stopSign = 'N';
	// while (!(stopSign == 'S'))
	//		std::cin >> stopSign;
	*/
		
	std::array<int, 3> stdArray{1, 2, 3};

	std::cout << stdArray[0] << '\n';

	return 0;
	
}