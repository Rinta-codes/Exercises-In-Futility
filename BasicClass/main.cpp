#include <iostream>

class IntPair
{
public:
	int m_a;
	int m_b;

	void set(int input_a, int input_b)
	{
		m_a = input_a;
		m_b = input_b;
	}

	void print()
	{
		std::cout << "Pair(" << m_a << ", " << m_b << ")\n";
	}
};


int main()
{
	IntPair p1;
	p1.set(1, 1); // set p1 values to (1, 1)

	IntPair p2{ 2, 2 }; // initialize p2 values to (2, 2)

	p1.print();
	p2.print();

	// Expected output:
	// Pair(1, 1)
	// Pair(2, 2)

	return 0;
}