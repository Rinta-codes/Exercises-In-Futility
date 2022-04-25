#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Car.h"

int main()
{
	std::vector<Car> v;
	v.push_back(Car("Toyota", "Corolla"));
	v.push_back(Car("Honda", "Accord"));
	v.push_back(Car("Toyota", "Camry"));
	v.push_back(Car("Honda", "Civic"));

	std::sort(v.begin(), v.end()); // requires an overloaded operator<

	for (auto &car : v)
		std::cout << car << '\n'; // requires an overloaded operator<<

	/*
	std::string a{ "Civic" };
	std::string b{ "Accord" };

	std::cout << (a > b) << " " << (b > a) << '\n';
	*/

	return 0;
}