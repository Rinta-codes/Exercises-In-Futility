#include <iostream>

void loop1()
{
	int outer = 1;
	while (outer <= 5)
	{
		// loop between 1 and outer
		int inner = 1;
		while (inner <= outer)
			std::cout << inner++ << " ";

		// print a newline at the end of each row
		std::cout << "\n";
		++outer;
	}
}

void loop2()
{
	int outer = 5;
	while (outer >= 1)
	{
		// loop between 1 and outer
		int inner = outer;
		while (inner >= 1)
			std::cout << inner-- << " ";

		// print a newline at the end of each row
		std::cout << "\n";
		--outer;
	}
}


void loop3()
{
	int outer { 1 };
	while (outer <= 5)
	{
		// loop between 1 and outer
		int inner { 5 };
		while (inner >= 1)
		{
			if (inner > outer)
				std::cout << "  ";
			else
				std::cout << inner << " ";
			--inner;
		}
		
		// print a newline at the end of each row
		
		std::cout << "\n";
		++outer;
	}
}



// Loop between 1 and 5
int main()
{
	loop1();

	std::cout << '\n';

	loop2();

	std::cout << '\n';

	loop3();

	return 0;
}