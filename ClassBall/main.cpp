#include <iostream>
#include <string>

class Ball
{
	// default values: m_color (“black”) and m_radius (10.0)

	std::string m_color;
	double m_radius;
	int m_bit[2]{1, 2};

public:

	Ball(const std::string &color = "black", double radius = 10.0 )
	{
		m_color = color;
		m_radius = radius;
	}

	Ball(double radius)
	{
		m_color = "black";
		m_radius = radius;
	}

	Ball(const std::string &color, double radius, int bit[2])
	{
		m_color = color;
		m_radius = radius;
		m_bit[0] = bit[0];
		m_bit[1] = bit[1];
	}

	void print()
	{
		std::cout << "color: " << m_color << ", radius: " << m_radius << '\n' ;
	}
};


int main()
{
	Ball def;
	def.print();

	Ball blue("blue");
	blue.print();

	Ball twenty(20.0);
	twenty.print();

	Ball blueTwenty("blue", 20.0);
	blueTwenty.print();

	int bit[2]{ 3, 4 };

	Ball whatever{ "test", 14.1, bit };
	whatever.print();

	return 0;
}