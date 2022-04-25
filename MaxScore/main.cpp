// Modify the following program so that instead of having maxScore hold the largest score directly, 
// a variable named maxIndex holds the index of the largest score.

#include <iostream>
#include <iterator> // for std::size

int main()
{
	int scores[] = { 84, 92, 76, 81, 56 };
	const int numStudents = std::size(scores);

	int maxScoreIndex = 0; // keep track of our largest score

	// now look for a larger score
	for (int student = 0; student < numStudents; ++student)
		if (scores[student] > scores[maxScoreIndex])
			maxScoreIndex = student;

	std::cout << "The best score was score #" << maxScoreIndex << " with value: " << scores[maxScoreIndex] << '\n';

	return 0;
}