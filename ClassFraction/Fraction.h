#ifndef FRACTION_H_25346146
#define FRACTION_H_25346146
#include <iostream>

class Fraction
{
private:
	int m_numerator{ 0 };
	int m_denominator{ 1 };

	static int gcd(int a, int b); // assisting function for finding common denominator for a and b

	void reduce();

public:
	Fraction(int n = 0, int d = 1) : m_numerator{ n }, m_denominator{ d } 
	{ 
		reduce(); 
	}

	void print();

	friend Fraction operator* (const Fraction &a, const Fraction &b);
	friend Fraction operator* (int a, const Fraction &b);
	friend Fraction operator* (const Fraction &a, int b);

	friend std::ostream& operator<< (std::ostream &out, const Fraction &f);
	friend std::istream& operator>> (std::istream &in, Fraction &f);

};



#endif