#ifndef ANIMAL_H_35123516
#define ANIMAL_H_35123516

#include <iostream>
#include <string_view>
#include <string>

class Animal
{
protected:
	std::string m_name;
	std::string m_speak;
	
	Animal(const std::string &name, const std::string &speak = "???")
		: m_name{ name }, m_speak{ speak } {}

public:
	const std::string& getName() const { return m_name; }
	const std::string& speak() const { return m_speak; }
};

class Cat : public Animal
{
public:
	Cat(const std::string &name)
		: Animal{ name, "Meow" } {}
};

class Dog : public Animal
{
public:
	Dog(const std::string &name)
		: Animal{ name, "Woof" } {}
};


#endif