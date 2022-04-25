// Create a short program 
// asking the user for two integer inputs 
// and a mathematical operation (‘+’, ‘-‘, ‘*’, ‘/’). 
// Ensure the user enters a valid operation.

// Write functions named add(), subtract(), multiply(), and divide().
// These should take two integer parameters and return an integer.

#include <iostream>
#include <functional>

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

using arithmeticFcn = std::function<int(int, int)>;

arithmeticFcn getArithmeticFunction(char oper)
{
	switch (oper)
	{
		case '+': return add;
		case '-': return subtract;
		case '*': return multiply;
		case '/': return divide;
		default: 
			std::cout << "Error in function getArithmeticFunction(): Invalid operator!";
			return nullptr;
	}
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

	int result{ getArithmeticFunction(oper)(a, b) };

	std::cout << a << " " << oper << " " << b << " = " << result << '\n';


	return 0;
}