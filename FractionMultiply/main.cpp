// Create a struct to hold a fraction.
// The struct should have an integer numerator and an integer denominator member.

// Declare 2 fraction variables and read them in from the user.

// Write a function called multiply that takes both fractions, multiplies them together, 
// and prints the result out as a decimal number.

// You do not need to reduce the fraction to its lowest terms.

#include <iostream>

struct Fraction
{
	int numerator = 1;
	int denominator = 1;
};

Fraction readFraction()
{
	Fraction userInput;

	std::cout << "Enter numerator: ";
	std::cin >> userInput.numerator;

	std::cout << "Enter denominator: ";
	std::cin >> userInput.denominator;
	
	return userInput;
};

void multiplyFractions(Fraction x, Fraction y)
{
	double product;

	product = (static_cast<double>(x.numerator) * y.numerator) / (static_cast<double>(x.denominator) * y.denominator);
	std::cout << "Multiplication result is: " << product;

};

int main()
{
	Fraction var1{ readFraction() };
	Fraction var2{ readFraction() };

	multiplyFractions(var1, var2);

	return 0;
};