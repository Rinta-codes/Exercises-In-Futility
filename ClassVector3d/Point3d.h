#ifndef POINT3D_H_2352356261
#define POINT3D_H_2352356261

class Vector3d;

class Point3d
{
private:
	double m_x, m_y, m_z;

public:
	Point3d(double x = 0.0, double y = 0.0, double z = 0.0)
		: m_x(x), m_y(y), m_z(z) {}

	void print();

	void moveByVector(const Vector3d &v);
};

#endif