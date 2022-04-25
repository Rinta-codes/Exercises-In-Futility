#include "TeacherDept.h"

void Department::add(Teacher *teacher)
{
	if (teacher) m_teachers.push_back(teacher);
}

std::ostream& operator<< (std::ostream &out, Department &dept)
{
	out << "Department:";

	for (Teacher *teacher : dept.m_teachers)
	{
		out << " " << teacher->getName();
	};

	out << '\n';

	return out;
}