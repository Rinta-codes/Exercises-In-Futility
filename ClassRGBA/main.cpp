#include <iostream>
#include <cstdint>

// Write a class named RGBA
// that contains 4 member variables of type std::uint_fast8_t 
// named m_red, m_green, m_blue, and m_alpha
// Assign default values of 0 to m_red, m_green, and m_blue, and 255 to m_alpha

// Create a constructor that uses a member initializer list
// that allows the user to initialize values for m_red, m_blue, m_green, and m_alpha

// Include a print() function that outputs the value of the member variables.
// Output sample: 
// r=0 g=127 b=127 a=255

// If your print() function isn’t working correctly, make sure you’re casting uint_fast8_t to an int.

class RGBA
{
	std::uint_fast8_t m_red;
	std::uint_fast8_t m_green;
	std::uint_fast8_t m_blue;
	std::uint_fast8_t m_alpha;

public:

	RGBA(std::uint_fast8_t red = 0, std::uint_fast8_t green = 0, std::uint_fast8_t blue = 0, std::uint_fast8_t alpha = 255) 
		: m_red{ red }, m_green{ green }, m_blue{ blue }, m_alpha{ alpha }
	{}

	void print()
	{
		std::cout << "r=" << static_cast<int>(m_red) << " g=" << static_cast<int>(m_green) 
			<< " b=" << static_cast<int>(m_blue) << " a=" << static_cast<int>(m_alpha) << '\n';
	}
};


int main()
{
	RGBA teal(0, 127, 127);
	teal.print();

	return 0;
}