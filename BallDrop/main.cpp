#include "balldrop.h"
#include "constants.h"
#include <iostream>

int main()
{
	double towerHeight{ inputHeight() };

	outputBallTrajectory(towerHeight);		// Output the height of the ball above the ground after 0, 1, 2, 3, 4, and 5 seconds. 
											// The ball should not go underneath the ground (height 0)

	return 0;
}