#ifndef CAR_H_23535123
#define CAR_H_23535123

#include <iostream>
#include <string>

class Car
{
private:
	std::string m_make;
	std::string m_model;

public:
	Car(std::string make, std::string model):
		m_make{ make }, m_model{ model }
	{}

	friend bool operator== (const Car &c1, const Car &c2);
	friend bool operator!= (const Car &c1, const Car &c2);

	friend bool operator< (const Car &c1, const Car &c2);

	friend std::ostream& operator<< (std::ostream &out, const Car &c);
};

#endif