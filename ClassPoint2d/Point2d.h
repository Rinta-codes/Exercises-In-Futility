#ifndef POINT2D_H_341615134123
#define POINT2D_H_341615134123

// Point2d should contain two member variables of type double: m_x, and m_y, both defaulted to 0.0. 
// Provide a constructor and a print function.

class Point2d
{
private:
	double m_x;
	double m_y;

public:
	Point2d(double x = 0.0, double y = 0.0) : m_x{ x }, m_y{ y } {}

	void print() const;

	double distanceTo(const Point2d &p) const;

	friend double distanceFrom(const Point2d &p1, const Point2d &p2);
};

#endif