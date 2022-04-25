/*
Write a function to print a C - style string character by character.

Use a pointer to step through each character of the string and print that character.
Stop when you hit a null terminator.

Write a main function that tests the function with the string literal “Hello, world!”.

Hint: Use the++ operator to advance the pointer to the next character.
*/

#include <iostream>

void printArray(const char *array)
{
	while (*array != '\0')
	{
		std::cout << *array;
		++array;
	}
}


int main()
{
	char array[]{"Hello, world!"};

	printArray(array);

	return 0;
}