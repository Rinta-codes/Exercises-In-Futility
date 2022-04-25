#include <iostream>


int main()
{

	std::cout << "Enter an integer: ";			// Enter an integer : 4
	int x{ 0 };
	std::cin >> x;

	std::cout << "Enter a larger integer: "; 	// Enter a larger integer : 2
	int y{ 0 };
	std::cin >> y;

	if (y < x)
	{											// Swapping the values
		int z{ x };
		x = y;
		y = z;
	}											// z dies here
	
	std::cout << "The smaller value is: "		// The smaller value is 2
			  << x << '\n';
	std::cout << "The larger value is: "		// The larger value is 4
			  << y << '\n';

	return 0;
}												// x and y die here