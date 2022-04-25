#include <string>
#include "GradeMap.h"

char& GradeMap::operator[] (const std::string &p)
{
	// first iterate through the vector to see if the student’s name already exists (you can use a for-each loop for this). 
	// If the student exists, return a reference to the grade and you’re done.

	for (auto &student : m_map)
	{
		if (student.studentName == p)
			return student.grade;
	};

	// Otherwise, use the std::vector::push_back() function to add a StudentGrade for this new student.
	// Finally, we need to return a reference to the grade for the student we just added to the std::vector. 
	// We can access the student we just added using the std::vector::back() function.

	StudentGrade temp{ p, };

	m_map.push_back(temp);
	return m_map.back().grade;
}