// Write a program that prints out the letters a through z along with their ASCII codes. 
// Hint: to print characters as integers, you have to use a static_cast.

#include <iostream>

int main()
{
	char letter{ 'a' };

	while (letter <= 'z')
	{
		std::cout << "Letter \'" << letter << "\' has ASCII code " << static_cast<int>(letter) << '\n';
		++letter;
	}


	return 0;
}