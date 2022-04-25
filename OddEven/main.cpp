#include <iostream>

int intInput()
{
	std::cout << "Enter an integer: ";

	int input;
	std::cin >> input;
	return input;
}

bool isEven(int input)
{
	return input % 2 == 0;
}


int main()
{
	int input{ intInput() };
	
	if (isEven(input))
		std::cout << "Your number is even!\n";
	else
		std::cout << "Your number is odd!\n";

	return 0;
}