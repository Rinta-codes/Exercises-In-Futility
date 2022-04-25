#include <iostream>
#include <string>


int main()
{
	// Ask for full name - "Enter your full name: John Doe"
	std::string fullName{""};
	std::cout << "Enter your full name: ";
	std::getline(std::cin, fullName);

	// Ask for age - "Enter your age: 46"
	int age{ 0 };
	std::cout << "Enter your age: ";
	std::cin >> age;

	// Output years per letter - "You've lived 5.75 years for each letter in your name."
	std::cout << "You've lived " << static_cast<double>(age) / fullName.length() << " years for each letter in your name.";

	return 0;
}