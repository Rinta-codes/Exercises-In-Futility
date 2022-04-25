#include "Average.h"

std::ostream& operator<< (std::ostream &out, const Average &avg)
{
	out << static_cast<double>(avg.m_total) / avg.m_count;

	return out;
}

Average& Average::operator+= (int value)
{
	m_total += value;
	++m_count;

	return *this;
}

