#include <iostream>
#include "FixedPoint2.h"

std::ostream& operator<< (std::ostream &out, const FixedPoint2 &point)
{
	out << static_cast<double>(point);

	return out;
}

FixedPoint2::operator double() const
{
	return double(m_integer) + double(m_fraction2) / 100;
}

bool operator== (const FixedPoint2 &a, const FixedPoint2 &b)
{
	return (a.m_integer == b.m_integer) && (a.m_fraction2 == b.m_fraction2);
}

std::istream& operator>> (std::istream &in, FixedPoint2 &point)
{
	double temp{ 0.0 };

	in >> temp;
	point = FixedPoint2(temp);

	return in;
}

FixedPoint2 FixedPoint2::operator-()
{
	return FixedPoint2(-m_integer, -m_fraction2);
}

FixedPoint2 operator+ (const FixedPoint2 &a, const FixedPoint2 &b)
{
	return FixedPoint2(static_cast<double>(a) + static_cast<double>(b));

}

/*
FixedPoint2 operator+ (const FixedPoint2 &a, const FixedPoint2 &b)
{
	int_least32_t temp_integer{ 0 };
	int_least8_t temp_fraction2{ 0 };

	temp_fraction2 = a.m_fraction2 + b.m_fraction2;

	if (temp_fraction2 > 99)
	{
		temp_fraction2 -= 100;
		temp_integer++;
	}

	if (temp_fraction2 < -99)
	{
		temp_fraction2 += 100;
		temp_integer--;
	}

	temp_integer += a.m_integer + b.m_integer;


	if (temp_integer > 0 && temp_fraction2 < 0)
	{
		temp_fraction2 += 100;
		temp_integer--;
	}

	if (temp_integer < 0 && temp_fraction2 > 0)
	{
		temp_fraction2 -= 100;
		temp_integer++;
	}

	assert("FixedPoint2 out of bounds after executing operator+" && temp_integer < 32768 && temp_integer > -32769);
	   
	return FixedPoint2(temp_integer, temp_fraction2);
}
*/