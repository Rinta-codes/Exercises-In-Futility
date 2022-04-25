// Declare a fixed array with the following names : 
// Alex, Betty, Caroline, Dave, Emily, Fred, Greg, and Holly.

// Ask the user to enter a name.

// Use a for each loop to see if the name the user entered is in the array.

/*
Sample output :

Enter a name : Betty
Betty was found.

Enter a name : Megatron
Megatron was not found.
*/


#include <iostream>

int main()
{
	std::string array[]
	{
		"Alex",
		"Betty",
		"Caroline",
		"Dave",
		"Emily",
		"Fred",
		"Greg",
		"Holly",
	};

	std::cout << "Enter a name: ";
	std::string inputName{};
	std::cin >> inputName;

	for (std::string &arrayName: array)
		if (arrayName == inputName)
		{
			std::cout << inputName << " was found.\n";
			return 0;
		};

	std::cout << inputName << " was not found.\n";
	
	return 0;
}