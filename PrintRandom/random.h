#ifndef RANDOM_H_235235151516
#define RANDOM_H_235235151516

#include <random>

namespace MyRandom
{
	extern std::mt19937 mersenne_seed;
}

int myRandomNumber(int max);

#endif