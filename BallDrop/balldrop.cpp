#include "balldrop.h"
#include "constants.h"
#include <iostream>

double inputHeight()
{
	std::cout << "Enter the height of the tower in meters (can have a floating point, e.g. 6.784): ";
	
	double inputDouble;
	std::cin >> inputDouble;
	return inputDouble;
}


double distanceFallenCalc(int seconds)
{
	long squareSeconds{ seconds * seconds };
	return (myConstants::gravity * squareSeconds / 2);
}


void printDistanceAtSeconds(int seconds, double towerHeight)
{
	double currentHeight = towerHeight - distanceFallenCalc(seconds);
	if (currentHeight > 0.0)
		std::cout << "At " << seconds << " seconds, the ball is at height: " << currentHeight << '\n';
	else
	{
		std::cout << "By " << seconds << " seconds, the ball reached the ground." << '\n';
		return;
	}

}


void outputBallTrajectory(double towerHeight)
{
		
	// 0 seconds
	printDistanceAtSeconds(0, towerHeight);

	// 1 seconds
	printDistanceAtSeconds(1, towerHeight);

	// 2 seconds
	printDistanceAtSeconds(2, towerHeight);

	// 3 seconds
	printDistanceAtSeconds(3, towerHeight);

	// 4 seconds
	printDistanceAtSeconds(4, towerHeight);

	// 5 seconds
	printDistanceAtSeconds(5, towerHeight);
	
}
