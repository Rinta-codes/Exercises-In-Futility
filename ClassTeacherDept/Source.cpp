#include "TeacherDept.h"

void Department::add(Teacher *teacher)
{
}

friend std::ostream& Department::operator<< (std::ostream &out, Department dept)
{
	return out;
}