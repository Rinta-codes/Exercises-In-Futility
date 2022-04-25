#include <iostream>

class Something
{	
	int m_a = 1;

public:
	Something() 
	{
		std::cout << "Init";
	}

	Something(const Something& a)
	{
		std::cout << "Init";
	}
};

Something& foo()
{
	Something s_temp;
	std::cout << "Funct";
	return s_temp;
}

int main()
{
	Something s = foo();
}