/*
Write a program that:
* Asks the user how many names they wish to enter.
* Asks the user to enter each name.
* Calls a function to sort the names (modify the selection sort code from lesson 6.4 -- Sorting an array using selection sort)
* Prints the sorted list of names.
*/

#include <iostream>
#include <string>

int requestListSize()
{
	std::cout << "How many names would you like to enter? ";
	int listSize;
	std::cin >> listSize;

	return listSize;
}

void enterNames(std::string *namesList, int listSize)
{
	for (int i{ 0 }; i < listSize; ++i)
	{
		std::cout << "Enter name #" << i + 1 << ": ";
		std::cin >> namesList[i]; // this is a buggy implementation with no error handling; use getline instead
	}
}

void sortNames(std::string *namesList, int listSize)
{
	for (int startIndex = 0; startIndex < listSize - 1; ++startIndex)
	{
		// smallestIndex is the index of the smallest element we’ve encountered this iteration
		// Start by assuming the smallest element is the first element of this iteration
		int smallestIndex = startIndex;

		// Then look for a smaller element in the rest of the array
		for (int currentIndex = startIndex + 1; currentIndex < listSize; ++currentIndex)
		{
			// If we've found an element that is smaller than our previously found smallest
			if (namesList[currentIndex] < namesList[smallestIndex])
				// then keep track of it
				smallestIndex = currentIndex;
		}

		// smallestIndex is now the smallest element in the remaining array
				// swap our start element with our smallest element (this sorts it into the correct place)
		std::swap(namesList[startIndex], namesList[smallestIndex]);
	}
}

void printNames(std::string *namesList, int listSize)
{
	for (int i{ 0 }; i < listSize; ++i)
		std::cout << "Name #" << i + 1 << ": " << namesList[i] << '\n';
}


int main()
{
	// Ask the user how many names they wish to enter.
	int listSize{ requestListSize() };

	// Ask the user to enter each name.
	std::string *namesList = new std::string[listSize];
	enterNames(namesList, listSize);

	// Call a function to sort the names
	sortNames(namesList, listSize);

	// Print the sorted list of names.
	std::cout << "\nHere is your sorted list:\n";
	printNames(namesList, listSize);

	delete[] namesList;
	namesList = nullptr;

	return 0;
}