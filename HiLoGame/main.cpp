// Implement a game of hi - lo.

// First, your program should pick a random integer between 1 and 100. 
// "Let's play a game.  I'm thinking of a number.  You have 7 tries to guess what it is."

// The user is given 7 tries to guess the number.
// "Guess #3: "

// If the user does not guess the correct number, the program should tell them whether they guessed too high or too low.
// "Your guess is too high. / Your guess is too low."

// If the user guesses the right number, the program should tell them they won.
// "Correct!You win!"

// If they run out of guesses, the program should tell them they lost, and what the correct number is.
// "Sorry, you lose.  The correct number was 49." 

// At the end of the game, the user should be asked if they want to play again.
// If the user doesn’t enter ‘y’ or ‘n’, ask them again.
// "Would you like to play again (y/n)? n"
// "Thank you for playing." 

// Note: You do not need to implement error handling for the user’s guess.

#include <iostream>
#include <cstdlib>
#include <ctime>

int generateRandom(int min, int max)
{
	static const double fraction{ 1.0 / (RAND_MAX + 1.0) };
	return (min + static_cast<int>((max - min + 1) * std::rand() * fraction));
}

bool userGuess(int randomNumber) // in which user attempts to guess a number
{
	int userGuessNumber{ 0 }; 

	while (true) // prevent user from failing to enter a number
	{
		std::cin >> userGuessNumber;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Something went wrong! Try again: ";
		}
		else
		{
			std::cin.ignore(32767, '\n'); // clear the buffer in case something got stuck
			break;
		}
	};

	if (randomNumber > userGuessNumber)
	{
		std::cout << "Your guess (" << userGuessNumber << ") is too low.\n";
		return false;

	}
	else if (randomNumber < userGuessNumber)
	{
		std::cout << "Your guess (" << userGuessNumber << ") is too high.\n";
		return false;
	}
	else if (randomNumber == userGuessNumber)
	{
		// If the user guesses the right number, the program should tell them they won.
		std::cout << "Correct! You win!\n";
		return true;
	};
}

void gameBody()
{
	// First, your program should pick a random integer between 1 and 100. 
	std::cout << "Let's play a game. I'm thinking of a number. You have 7 tries to guess what it is.\n";

	int randomNumber{ generateRandom(1, 100) }; // Might be cool to send the limits from main, but at the same time - why
	
	// The user is given 7 tries to guess the number.

	for (int attempt{ 1 }; attempt <= 7; ++attempt)
	{
		std::cout << "Guess #" << attempt << ": ";
		if (userGuess(randomNumber))
			return;
	};

	// If they run out of guesses, the program should tell them they lost, and what the correct number is.
	std::cout << "Sorry, you lose.The correct number was " << randomNumber << ".\n";
}

bool playAgain()
{
	char playAgain{};

	while (true)
	{
		std::cout << "Would you like to play again (y/n)? ";
		std::cin >> playAgain;

		switch (playAgain)
		{
		case 'n':
			std::cout << "Thank you for playing.\n";
			return false;
		case 'y':
			std::cin.ignore(32767, '\n'); // clear the buffer in case something got stuck
			return true;
		default:
			std::cin.ignore(32767, '\n'); // clear the buffer in case something got stuck
			continue;
		}

	}
}

void gameLoop()
{
	do
	{
		gameBody();
	} 
	while (playAgain()); // At the end of the game, the user should be asked if they want to play again.
}

int main()
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));	// Initialize random number generator out of the loop
	std::rand();												// Discard first random number because it is repetitive

	gameLoop();													// Run the game
	return 0;
}
