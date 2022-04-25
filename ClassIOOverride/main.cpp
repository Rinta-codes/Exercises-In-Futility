#include "Point.h"


int main()
{
	Point point1;
	Point point2;

	std::cout << "Enter one 3D point: ";
	std::cin >> point1;

	std::cout << "Enter another 3D point: ";
	std::cin >> point2;

	std::cout << "Sum of these two points is: " << point1 + point2 << '\n';

	return 0;
}