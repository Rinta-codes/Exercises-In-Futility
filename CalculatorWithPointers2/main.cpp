// Create a short program 
// asking the user for two integer inputs 
// and a mathematical operation (‘+’, ‘-‘, ‘*’, ‘/’). 
// Ensure the user enters a valid operation.

// Write functions named add(), subtract(), multiply(), and divide().
// These should take two integer parameters and return an integer.

#include <iostream>
#include <functional>
#include "calc.h"

// Create a typedef named arithmeticFcn for a pointer to a function that takes two integer parameters and returns an integer.

using arithmeticFcn = std::function<int(int, int)>;

// Create a struct named arithmeticStruct that has two members: a mathematical operator char, and an arithmeticFcn function pointer

struct arithmeticStruct
{
	char oper;
	arithmeticFcn fcnPoint;
};

// Create a static global array of arithmeticStruct named arithmeticArray, initialized with each of the four arithmetic functions.

static arithmeticStruct arithmeticArray[]
{
	{'+', add},
	{'-', subtract},
	{'*', multiply},
	{'/', divide},
};


int add(int a, int b)
{
	return a + b;
}


int subtract(int a, int b)
{
	return a - b;
}


int multiply(int a, int b)
{
	return a * b;
}


int divide(int a, int b)
{
	return a / b;
}

// Write a function named getArithmeticFunction() that takes an operator character and returns the appropriate function as a function pointer.

arithmeticFcn getArithmeticFunction(char oper)
{
	for (const auto &arithmeticDuo : arithmeticArray)
	{
		if (arithmeticDuo.oper == oper)
			return arithmeticDuo.fcnPoint;
	}

	std::cout << "Error in function getArithmeticFunction(): Invalid operator - no function defined!";
	return nullptr;
}


int inputInt()
{
	int a{};

	do
	{
		std::cout << "Enter an integer: ";
		std::cin >> a;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Invalid input, please try again.\n";
		}
		else
		{
			std::cin.ignore(32767, '\n');
			return a;
		}
	} while (true);
}


char inputOperation()
{
	char oper{};

	do
	{
		std::cout << "Enter an operation (+, -, *, /): ";
		std::cin >> oper;

		switch (oper)
		{
		case '+':
		case '-':
		case '*':
		case '/':
			std::cin.ignore(32767, '\n');
			return oper;
		default:
			std::cout << "Invalid input, please try again.\n";
			std::cin.ignore(32767, '\n');
			break;
		}
	} while (true);
}


int main()
{
	int a{ inputInt() };
	int b{ inputInt() };
	char oper{ inputOperation() };

	// Modify your main() function to call getArithmeticFunction(). Call the return value from that function with your inputs and print the result.

	int result{ getArithmeticFunction(oper)(a, b) };

	std::cout << a << " " << oper << " " << b << " = " << result << '\n';

	return 0;
}