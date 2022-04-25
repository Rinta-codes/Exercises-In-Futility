#ifndef POINT_H_6241616515
#define POINT_H_6241616515

#include <iostream>

class Point
{
private:
	double m_x;
	double m_y;
	double m_z;

public:
	Point(double x = 0.0, double y = 0.0, double z = 0.0) :
		m_x{ x }, m_y{ y }, m_z{ z }
	{}

	friend std::ostream& operator<< (std::ostream &out, const Point &point);

	friend std::istream& operator>> (std::istream &in, Point &point);

	Point operator+ (Point &point) const;
};


#endif