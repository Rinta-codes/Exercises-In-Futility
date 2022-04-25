#include <iostream>
#include <sstream>


int main(int argc, char *argv[])
{
	std::cout << "There are " << argc << " agruements.\n";

	for (int i{ 0 }; i < argc; ++i)
	{
		std::cout << "Arguement #" << i << " is \"" << argv[i] << "\"\n";
	}

	std::stringstream convert{argv[3]};
	int convertedInt{0};
	convert >> convertedInt;

	std::cout << "Converted Arguement #3 minus 100: " << convertedInt - 100;

}