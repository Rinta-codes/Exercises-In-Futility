#include <iostream>
#include "IntArray.h"


int main()
{
	IntArray array{ 5, 4, 3, 2, 1 }; // initializer list
	for (int count = 0; count < array.getLength(); ++count)
		std::cout << array[count] << ' ';

	std::cout << '\n';

	array = { 1, 3, 5, 7, 9, 11 };

	for (int count = 0; count < array.getLength(); ++count)
		std::cout << array[count] << ' ';

	std::cout << '\n';

	IntArray array2(3);

	for (int count = 0; count < array2.getLength(); ++count)
		std::cout << array2[count] << ' ';

	std::cout << '\n';

	IntArray array3{ 3 };

	for (int count = 0; count < array3.getLength(); ++count)
		std::cout << array3[count] << ' ';


	return 0;
}