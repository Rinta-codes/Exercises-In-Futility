/*
Write your own function to swap the value of two integer variables.
Write a main() function to test it.

Hint: Use reference parameters
*/

#include <iostream>

void swapInt(int &a, int &b)
{
	int temp{ a };
	a = b;
	b = temp;
}

void printTwoInt(int a, int b)
{
	std::cout << "First number is " << a << ", second number is " << b << ".\n";
}


int main()
{
	int a;
	int b;
	
	std::cout << "Enter first integer: ";
	std::cin >> a;

	std::cout << "Enter second integer: ";
	std::cin >> b;

	std::cout << '\n';

	printTwoInt(a, b);

	swapInt(a, b);

	printTwoInt(a, b);

	return 0;
}