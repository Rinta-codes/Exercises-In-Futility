#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Creature.h"

bool fightMonster(Player& p); // handles player encounter with a single monster 
void attackPlayer(Player& p, Monster& m); // handles monster attacking a player once
void attackMonster(Player& p, Monster& m); // handles player attacking a monster once
bool winCondition(Player& p); // checks for win condition
bool loseCondition(Player& p); // checks for loss condition

bool fightMonster(Player& p)
{
	Monster m{ Monster::getRandomMonster() };
	char action{};

	std::cout << "You have encountered a " << m.getName() << "(" << m.getSymbol() << ")" << '\n';

	// Single monster action loop
	// Fight until either monster or player dies; successfully fleeing = monster died, because I said so
	while (!m.isDead() && !p.isDead())
	{
		std::cout << "(R)un or (F)ight: ";
		std::cin >> action;

		switch (action)
		{
			case 'f':
			case 'F':
				attackMonster(p, m);
				break;
			case 'r':
			case 'R':
				if (static_cast<int>(2 * (std::rand() * (1.0 / (RAND_MAX + 1.0)))))
				{
					std::cout << "successfully fled" << '\n';
					m.reduceHealth(m.getHealth());
				}
				else
				{
					std::cout << "You failed to flee." << '\n';
					attackPlayer(p, m);
				}
				break;
			default:
				std::cout << "Unknown action." << '\n';
				break;
		}
	}

	return (winCondition(p) || loseCondition(p));
	/*
		You have encountered a slime(s).
		
		(R)un or (F)ight: f
		You hit the slime for 1 damage.
		You killed the slime.
		You are now level 2.
		You found 10 gold.

		You failed to flee.
		The dragon hit you for 4 damage.

		You successfully fled.
		*/

}

void attackPlayer(Player& p, Monster& m)
{
	std::cout << "The " << m.getName() << " hit you for " << m.getAttack() << " damage - your Health is now " << ((p.getHealth() > m.getAttack()) ? (p.getHealth() - m.getAttack()) : 0) << '\n';
	p.reduceHealth(m.getAttack());
}

void attackMonster(Player& p, Monster& m)
{
	std::cout << "You hit the " << m.getName() << " for " << p.getAttack() << " damage." << '\n';
	m.reduceHealth(p.getAttack());

	if (m.isDead())
	{
		std::cout << "You killed the " << m.getName() << '\n';
		std::cout << "You are now level " << p.getLevel() + 1 << '\n';
		std::cout << "You found " << m.getGold() << " gold." << '\n';

		p.levelUp();
		p.addGold(m.getGold());
	}
	else
		attackPlayer(p, m);
}

bool winCondition(Player& p) 
{
	if (p.getLevel() == 20) // win if player reached level 20
	{
		std::cout << "You have reached level 20 with " << p.getGold() << " gold!" << '\n'
			<< "Now you can comfortably retire and spend your time telling tales of your deeds!" << '\n';
		return true;
	}

	return false;
}

bool loseCondition(Player& p) 
{
	if (p.isDead()) // lose if player died
	{
		std::cout << "You died at level " << p.getLevel() << " with " << p.getGold() << " gold." << '\n'
			<< "Too bad you can't take it with you!" << '\n';
		return true;
	}

	return false;
}


int main()
{
	std::srand(static_cast<unsigned int>(std::time(nullptr))); // set initial seed value to system clock
	std::rand(); // get rid of first result

	// Create player

	std::cout << "Enter your name: ";
	std::string name{};
	std::cin >> name;

	Player p{ name };

	std::cout << "Welcome, " << p.getName() << '\n';

	// Game loop
	while (!fightMonster(p)) {}
	
	return 0;
}