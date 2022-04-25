#include <iostream>

int binaryIncrement(int x, int Increment)
{
	if (x >= Increment)
	{
		std::cout << "1";
		x -= Increment;
	}
	else
	{
		std::cout << "0";
	}

	return x;
}



int main()
{
	std::cout << "Input an integer between 0 and 255: ";
	int x;
	std::cin >> x;

	x = binaryIncrement(x, 128);
	x = binaryIncrement(x, 64);
	x = binaryIncrement(x, 32);
	x = binaryIncrement(x, 16);

	std::cout << " ";

	x = binaryIncrement(x, 8);
	x = binaryIncrement(x, 4);
	x = binaryIncrement(x, 2);
	x = binaryIncrement(x, 1);


	return 0;
}