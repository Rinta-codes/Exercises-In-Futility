#include <iostream>
#include "Fraction.h"

void Fraction::print()
{
	std::cout << m_numerator << "/" << m_denominator << '\n';
}

Fraction operator* (const Fraction &a, const Fraction &b)
{
	return Fraction(a.m_numerator * b.m_numerator, a.m_denominator * b.m_denominator);
}

Fraction operator* (int a, const Fraction &b)
{
	return Fraction(a * b.m_numerator, b.m_denominator);
}

Fraction operator* (const Fraction &a, int b)
{
	return Fraction(a.m_numerator * b, a.m_denominator);
}

int Fraction::gcd(int a, int b) 
{
	return (b == 0) ? (a > 0 ? a : -a) : gcd(b, a % b);
}

void Fraction::reduce()
{
	int gcd{ Fraction::gcd(m_numerator, m_denominator) };

	m_numerator /= gcd;
	m_denominator /= gcd;
}


std::ostream& operator<< (std::ostream &out, const Fraction &f)
{
	out << f.m_numerator << "/" << f.m_denominator;

	return out;
}


std::istream& operator>> (std::istream &in, Fraction &f)
{
	char a{};

	do
	{
		in >> f.m_numerator;
		in >> a;
		if (a == '\/') 
		{
			in >> f.m_denominator;
		}
		else
		{
			in.clear();
			in.ignore(32767, '\n');
			std::cout << "Try again!" << '\n';
		}
	} while (a != '\/');

	f.reduce();

	return in;
}