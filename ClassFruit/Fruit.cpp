#include <iostream>
#include "Fruit.h"


const std::string& Fruit::getName() const
{
	return this->m_name;
}

const std::string& Fruit::getColour() const
{
	return this->m_colour;
}

double Apple::getFiber() const
{
	return this->m_fiber;
}

std::ostream& operator<< (std::ostream &out, const Apple &a)
{
	out << "Apple(" << a.getName() << ", " << a.getColour() << ", " << a.getFiber() << ")";

	return out;
}

std::ostream& operator<< (std::ostream &out, const Banana &b)
{
	out << "Banana(" << b.getName() << ", " << b.getColour() << ")";

	return out;
}

