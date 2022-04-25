#ifndef FIXEDPOINT_H_23416357241
#define FIXEDPOINT_H_23416357241

#include <stdint.h>
#include <cassert>
#include <iostream>
#include <cmath>

class FixedPoint2
{
private:
	int_least16_t m_integer;
	int_least8_t m_fraction2;

public:
	FixedPoint2(int_least16_t integer = 0, int_least8_t fraction2 = 0):
		m_integer{ integer }, m_fraction2{ fraction2 }
	{
		assert("Fractional component for FixedPoint2 class can only have 2 digits!" && fraction2 > -100 && fraction2 < 100);

		if (m_integer < 0 || m_fraction2 < 0)
		{
			if (m_integer > 0)
				m_integer = -m_integer;
			if (m_fraction2 > 0)
				m_fraction2 = -m_fraction2;
		}
	}

	
	FixedPoint2(double dbl)
	{
		assert("FixedPoint2 class can only store values between -32768.99 and 32767.99" && dbl < 32768 && dbl > -32769);

		m_integer = static_cast<int_least32_t>(round(dbl * 100)) / 100;
	
		m_fraction2 = static_cast<int_least16_t>(round(dbl * 100)) % 100;
	}
	
	/*
	FixedPoint2(double d) :
		m_integer{ static_cast<int_least16_t>(d) },
		m_fraction2{ static_cast<std::int_least8_t>(round((d - m_integer) * 100)) }
	{}
	*/

	friend bool operator== (const FixedPoint2 &a, const FixedPoint2 &b);

	friend std::istream& operator>> (std::istream &in, FixedPoint2 &point);

	FixedPoint2 operator-();

	friend FixedPoint2 operator+ (const FixedPoint2 &a, const FixedPoint2& b);

	operator double() const;
};

std::ostream& operator<< (std::ostream &out, const FixedPoint2 &point);

// operator==, operator >>, operator- (unary), and operator+ (binary).


#endif