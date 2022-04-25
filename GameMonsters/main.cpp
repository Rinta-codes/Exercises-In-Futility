/*
In designing a game, we decide we want to have monsters, because everyone likes fighting monsters. 

Declare a struct that represents your monster. 
The monster should have a type that can be one of the following: an ogre, a dragon, an orc, a giant spider, or a slime. 
If you’re using C++11, use an enum class for this. If you’re using an older compiler, use an enumeration for this.

Each individual monster should also have a name (use a std::string), 
as well as an amount of health that represents how much damage they can take before they die. 

Write a function named printMonster() that prints out all of the struct’s members. 

Instantiate an ogre and a slime, initialize them using an initializer list, and pass them to printMonster().

Your program should produce the following output:

This Ogre is named Torg and has 145 health.
This Slime is named Blurp and has 23 health.
*/

#include <iostream>
#include <string>

#include "monsters.h"

enum class MonsterType
{
	OGRE,
	DRAGON,
	ORC,
	GIANT_SPIDER,
	SLIME,
};

struct Monster
{
	MonsterType type;
	std::string name;
	int health;
};


void printMonster(Monster monster)
{
	// Write a function named printMonster() that prints out all of the struct’s members. 
	// This Ogre is named Torg and has 145 health.

	std::string typeFormatted{"Unknown Monster"};
	if (monster.type == MonsterType::OGRE)
		typeFormatted = "Ogre";
	else if (monster.type == MonsterType::DRAGON)
		typeFormatted = "Dragon";
	else if (monster.type == MonsterType::ORC)
		typeFormatted = "Orc";
	else if (monster.type == MonsterType::GIANT_SPIDER)
		typeFormatted = "Giant Spider";
	else if (monster.type == MonsterType::SLIME)
		typeFormatted = "Slime";

	std::cout << "This " << typeFormatted << " is named " << monster.name << " and has " << monster.health << " health.\n";
	std::string testPrint{""};
	testPrint = std::cout.rdbuf();
	std::cout << testPrint;

}

int main()
{
	// Instantiate an ogre and a slime, initialize them using an initializer list, and pass them to printMonster().
	Monster ogre{ MonsterType::OGRE, "Torg", 145 };
	Monster slime{ MonsterType::SLIME, "Blurp", 23 };

	printMonster(ogre);
	printMonster(slime);

	return 0;
}




