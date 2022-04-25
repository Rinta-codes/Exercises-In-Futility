#include <iostream>

int main()
{
	std::cout << "Let's slay some Evil today!\n";
	std::cout << "\nHow many Evils do you want to slay? (enter number 1-10 and press Enter): ";
	int numberOfEvils{};
	std::cin >> numberOfEvils;
	std::cout << "\nAffirmative! " << numberOfEvils << " Evils are going to be slain today!\n";
	
	char end;
	std::cin >> end;

	return 0;
}