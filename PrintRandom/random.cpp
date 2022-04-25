#include "random.h"
#include <iostream>
#include <ctime>

namespace MyRandom
{
	std::mt19937 mersenne_seed{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
}

int myRandomNumber(int max)
{
	std::uniform_int_distribution<> die(1, max);
	std::cout << "LOL SEED:\n" << MyRandom::mersenne_seed << '\n' << "LOL OTHER SEED:\n" << static_cast<std::mt19937::result_type>(std::time(nullptr)) << "\n\n";

	return die(MyRandom::mersenne_seed);
}
