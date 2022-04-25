#ifndef GRADEMAP_H_56823412356
#define GRADEMAP_H_56823412356

#include <string>
#include <vector>

struct StudentGrade
{
	std::string studentName = "";
	char grade = char("");
};

class GradeMap
{
private:
	std::vector<StudentGrade> m_map;

public:
	GradeMap() : m_map{} {};

	char& operator[] (const std::string &p);

};



#endif