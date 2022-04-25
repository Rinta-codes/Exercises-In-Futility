#include <string>
#include <iostream>
#include <ctime> // for time()
#include <cstdlib> // for rand() and srand()

class Monster
{
public:
	enum MonsterType
	{
		DRAGON,
		GOBLIN,
		OGRE,
		ORC,
		SKELETON,
		TROLL,
		VAMPIRE,
		ZOMBIE,
		MAX_MONSTER_TYPES
	};

private:
	MonsterType m_type;
	std::string m_name;
	std::string m_roar;
	int m_HitPoints;

public:
	Monster(MonsterType type, std::string name, std::string roar, int hp)
		: m_type{ type }, m_name{ name }, m_roar{ roar }, m_HitPoints{ hp } {}

	void print() const
	{
		std::cout << m_name << " the " << getTypeString() << " has " << m_HitPoints << " hit points and says " << m_roar << '\n';
	}

	std::string getTypeString() const
	{
		switch (m_type)
		{
		case DRAGON: return "dragon";
		case GOBLIN: return "goblin";
		case OGRE: return "ogre";
		case ORC: return "orc";
		case SKELETON: return "skeleton";
		case TROLL: return "troll";
		case VAMPIRE: return "vampire";
		case ZOMBIE: return "zombie";
		default: return "unknown monster";
		};
	}

};


class MonsterGenerator
{
private:
	// Generate a random number between min and max (inclusive)
	// Assumes srand() has already been called
	static int getRandomNumber(int min, int max)
	{
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
		// static used for efficiency, so we only calculate this value once
		// evenly distribute the random number across our range
		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}


public:
	static Monster generateMonster()
	{
		static std::string names[6]
		{
			"Aubergin",
			"Boris",
			"Laika",
			"Johnny Depp",
			"Leviathan",
			"Bob",
		};

		static std::string roars[6]
		{
			"*AAARRRRRRRGHHHHH!*",
			"*rattle*",
			"*ROAAARRRRR!*",
			"*squeeek~*",
			"*piu-piu-piu!*",
			"*beep-boop!*",
		};
		
		return Monster(static_cast<Monster::MonsterType>(getRandomNumber(0, Monster::MonsterType::MAX_MONSTER_TYPES - 1)), 
			names[getRandomNumber(0, 5)], 
			roars[getRandomNumber(0, 5)], 
			getRandomNumber(1, 100));
	}
};


int main()
{
	srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
	rand(); // If using Visual Studio, discard first random value

	Monster m = MonsterGenerator::generateMonster();
	m.print();

	return 0;
}