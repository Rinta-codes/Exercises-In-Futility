/*
Create a struct that holds a student’s first name and grade (on a scale of 0 - 100).

Ask the user how many students they want to enter.

Dynamically allocate an array to hold all of the students.
Then prompt the user for each name and grade.

Once the user has entered all the names and grade pairs, sort the list by grade(highest first).
Then print all the names and grades in sorted order.
*/

#include <string>
#include <iostream>

// Create a struct that holds a student’s first name and grade(on a scale of 0 - 100).
struct Students
{
	std::string name;
	int grade;
};

// Then prompt the user for each name and grade.
void userInput(Students *students, int numOfStudents)
{
	for (int index{ 0 }; index < numOfStudents; ++index)
	{
		std::cout << "For student #" << index + 1 << ", enter the name: ";
		std::cin >> students[index].name;

		std::cout << "For student #" << index + 1 << ", enter the grade: ";
		std::cin >> students[index].grade;

		std::cout << '\n';
	}
}

// Once the user has entered all the names and grade pairs, sort the list by grade(highest first).
void sortStudents(Students *students, int numOfStudents)
{
	for (int startIndex = 0; startIndex < numOfStudents - 1; ++startIndex)
	{
		int largestGrade = startIndex;

		for (int currentIndex = startIndex + 1; currentIndex < numOfStudents; ++currentIndex)
		{
			if (students[currentIndex].grade > students[largestGrade].grade)
				largestGrade = currentIndex;
		}

		std::swap(students[startIndex], students[largestGrade]);
	}
}

// Then print all the names and grades in sorted order.
void printStudents(Students *students, int numOfStudents)
{
	for (int index{ 0 }; index < numOfStudents; ++index)
		std::cout << students[index].name << " got a grade of " << students[index].grade << '\n';
}


int main()
{
	// Ask the user how many students they want to enter.
	int numOfStudents;
	std::cout << "Enter the number of students: ";
	std::cin >> numOfStudents;

	// Dynamically allocate an array to hold all of the students.
	Students *students = new Students[numOfStudents];

	// Then prompt the user for each name and grade.
	userInput(students, numOfStudents);

	// Once the user has entered all the names and grade pairs, sort the list by grade(highest first).
	sortStudents(students, numOfStudents);

	// Then print all the names and grades in sorted order.
	printStudents(students, numOfStudents);

	delete[] students;
	students = nullptr;

	return 0;
}