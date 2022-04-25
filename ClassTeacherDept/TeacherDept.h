#ifndef TEACHERDEPT_H_236163741234
#define TEACHERDEPT_H_236163741234

#include <string>
#include <iostream>
#include <vector>

class Teacher
{
private:
	std::string m_name;

public:
	Teacher(std::string name)
		: m_name(name)
	{}

	std::string getName() { return m_name; }
};

class Department
{
private:
	std::vector<Teacher*> m_teachers; // This dept holds only one teacher for simplicity, but it could hold many teachers

public:
	Department(Teacher *teacher = nullptr)
	{
		if (teacher) 
			m_teachers.push_back(teacher);
	}

	void add(Teacher *teacher);

	friend std::ostream& operator<< (std::ostream &out, const Department &dept);
};


#endif