#include <iostream>
#include <vector>


int factorial(int count)
{
	if (count <= 0)
		return 1;
	else
		return factorial (count - 1) * count;
}


int digits(int count)
{
	if (count <= 0)
		return 0;
	else
		return (count % 10) + digits(count / 10);
}

void printBinary(unsigned int count)
{
	if (count > 1)
		printBinary(count / 2);

	std::cout << count % 2;
}


int main()
{
	for (int i{ 0 }; i < 8; ++i)
	{
		std::cout << "Factorial of " << i << " is " <<  factorial(i) << '\n';
	}

	int count{ 93427 };

	std::cout << "Sum of digits of " << count << " is " << digits(count) << "\n\n";

	std::cout << "Enter an integer: ";
	std::cin >> count;

	std::cout << "Binary of " << count << " is: ";
	printBinary(count);
		   
	return 0;
}