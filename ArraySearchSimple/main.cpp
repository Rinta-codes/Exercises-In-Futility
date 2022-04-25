#include <iostream>
#include <iterator>


int userInput(int min, int max)
{
	std::cout << "Enter an integer between " << min << " and " << max << ": ";
	
	int value{ 0 };

	while (true)
	{
		std::cin >> value;
		if (std::cin.fail() || value < min || value > max)
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Please try again: ";
			continue;
		}
		else
			break;
	};

	return value;
}


int findValue(int array[], int arraySize, int searchValue)
{
	for (int element{ 0 }; element < arraySize; ++element)
	{
		if (array[element] == searchValue)
			return element;
	};
	
	return arraySize;
}


int main()
{
	int array[] = { 4, 6, 7, 3, 8, 2, 1, 9, 5 };

	int searchValue{ userInput(1, 9) };

	const int arraySize{ std::size(array) };
	for (int element{ 0 }; element < arraySize; ++element)
		std::cout << "Element #" << element << " of the Array is " << array[element] << ".\n";

	std::cout << "\n\n";

	int searchResult{ findValue(array, arraySize, searchValue) };

	if (searchResult < arraySize)
		std::cout << "You entered Array's element #" << searchResult << '\n';
	else
		std::cout << "The number you entered is not found in the Array\n";

	return 0;
}