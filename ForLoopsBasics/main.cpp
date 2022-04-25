// Write a function named sumTo() that takes an integer parameter named value, 
// and returns the sum of all the numbers from 1 to value.

// For example, sumTo(5) should return 15, which is 1 + 2 + 3 + 4 + 5.

// Hint: Use a non - loop variable to accumulate the sum as you iterate from 1 to the input value, 
// much like the pow() example above uses the total variable to accumulate the return value each iteration.


#include <iostream>

void printingEvens0to20()
{
	for (int i = 0; i <= 20; i += 2)
		std::cout << i << " ";
}

int sumTo(int value)
{
	if (value <= 0)
	{
		std::cout << "Error: Incorrect value entered\n";
		return 0;
	}
	int result{0};
	for (int i = 1; i <= value; ++i)
		result += i;

	return result;
}

int main()
{
	printingEvens0to20();
	std::cout << '\n';

	std::cout << "Enter an integer: ";
	int value{ 0 };
	std::cin >> value;

	std::cout << "Sum of all the numbers from 1 to " << value << " is " << sumTo(value) << '\n';

	return 0;
}