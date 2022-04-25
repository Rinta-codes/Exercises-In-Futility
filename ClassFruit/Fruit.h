#ifndef FRUIT_H_34167378124
#define FRUIT_H_34167378124

#include <string>
#include <iostream>

class Fruit
{
private:
	std::string m_name;
	std::string m_colour;

public:
	Fruit(const std::string &name = "", const std::string &colour = ""):
		m_name{ name }, m_colour{ colour }
	{}

	const std::string& getName() const;

	const std::string& getColour() const;
};

class Apple : public Fruit
{
private:
	double m_fiber;

public:
	Apple(const std::string &name = "", const std::string &colour = "", double fiber = 0.0):
		Fruit{ name, colour }, m_fiber{ fiber }
	{}

	double getFiber() const;
};

std::ostream& operator<< (std::ostream &out, const Apple &a);

class Banana : public Fruit
{
private:

public:
	Banana(const std::string &name, const std::string &colour) :
		Fruit{ name, colour }
	{}
};

std::ostream& operator<< (std::ostream &out, const Banana &b);

#endif