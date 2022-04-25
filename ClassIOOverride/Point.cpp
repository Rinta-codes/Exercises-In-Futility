#include <iostream>
#include "Point.h"

std::ostream& operator<< (std::ostream &out, const Point &point)
{
	out << "(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ")";
	
	return out;
}

std::istream& operator>> (std::istream &in, Point &point)
{
	in >> point.m_x >> point.m_y >> point.m_z;

	return in;
}

Point Point::operator+ (Point &point) const
{
	return Point(this->m_x + point.m_x, this->m_y + point.m_y, this->m_z + point.m_z);
}