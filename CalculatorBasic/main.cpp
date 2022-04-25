// Write a function called calculate() 
// that takes two integersand a char 
// representing one of the following mathematical operations : +, -, *, / , or % (modulus).

// Use a switch statement to perform the appropriate mathematical operation on the integers, 
// and return the result.

// If an invalid operator is passed into the function, the function should print an error.

// For the division operator, do an integer division.

#include <iostream>
#include <cstdlib>

int calculate(int x, int y, char operation)
{
	switch (operation)
	{
		case '+':
			return (x + y);
		case '-':
			return (x - y);
		case '*':
			return (x * y);
		case '/':
			return (x / y);
		case '%':
			return (x % y);
		default:
			std::cout << "Invalid operation!\n";
		//	exit(0);
			return 0;

	}
}

int userValue()
{
	int x;
	std::cin >> x;
	return x;
};


int main()
{
	std::cout << "Enter first operand (int): ";
	int x{userValue()};

	std::cout << "Enter second operand (int): ";
	int y{ userValue() };

	std::cout << "Enter operation to perform (+, -, *, /, %): ";
	char operation;
	std::cin >> operation;
	
	int result{ calculate(x, y, operation) };
	std::cout << "Result is: " << result << '\n';

	std::cout << x << " " << operation << " " << y << " = " << calculate(x, y, operation) << '\n';

	return 0;
}