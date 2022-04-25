// Bubble sort works by comparing adjacent pairs of elements, and swapping them if the criteria is met.

// A) Compare array element 0 with array element 1. If element 0 is larger, swap it with element 1.
// B) Now do the same for elements 1 and 2, and every subsequent pair of elements until you hit the end of the array.
//		At this point, the last element in the array will be sorted.
// C) Repeat the first two steps again until the array is sorted.

#include <iostream>
#include <algorithm>


void bubbleSort(int array[], int length)
{
	for (int bubbleEnd{ length - 1 }; bubbleEnd > 0; --bubbleEnd) 	
		// This "for" loop is outer, only defining bubble end point 
		// (sorting array from the end down)

		// Last loop will be for comparing elements 0 and 1, where bubble End is at 1, 
		// therefore "> 0" comparison is used
	{
		bool swapsMade{ false };

		for (int currentElement{ 0 }; currentElement < bubbleEnd; ++currentElement) 
			// if bubble is currently at elements (a, a + 1) - then currentElement = a
			// it goes from (0, 1) to (bubbleEnd - 1, bubbleEnd)
		{
			if (array[currentElement] > array[currentElement + 1])
			{
				std::swap(array[currentElement], array[currentElement + 1]);
				swapsMade = true;
			}
		}

		if (!swapsMade)
		{
			std::cout << "Final iteration: #" << (length - bubbleEnd) << '\n';
			return;
		}
	}

	std::cout << "Final iteration: #" << length << '\n';
}



int main()
{
	// Initialize the array
	const int	length			{ 9 };
	int			array[length]	{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };

	// Sort the array
	bubbleSort(array, length);

	// Print the array
	for (int index = 0; index < length; ++index)
		std::cout << array[index] << ' ';

	return 0;
}
