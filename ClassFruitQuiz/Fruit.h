#ifndef FRUIT_H_90234780
#define FRUIT_H_90234780

#include <iostream>
#include <string>

class Fruit
{
private:
	std::string m_name;
	std::string m_colour;

public:
	Fruit(const std::string& name, const std::string& colour):
		m_name{ name }, m_colour{ colour } {}

	const std::string& getName() const
	{
		return m_name;
	}
		
	const std::string& getColor() const
	{
		return m_colour;
	}
};



class Apple : public Fruit
{
protected:
	Apple(const std::string& name, const std::string& colour) :
		Fruit { name, colour } {}

public:
	Apple(const std::string& colour = "red") :
		Fruit{ "apple", colour } {}
};

class Banana : public Fruit
{
public:
	Banana() :
		Fruit{ "banana", "yellow" } {}
};

class GrannySmith : public Apple
{
public:
	GrannySmith() :
		Apple("granny smith apple", "green") {}
};


#endif