#ifndef CREATURE_H_823423637
#define CREATURE_H_823423637

#include <string>
#include <string_view>
#include <array>
#include <cstdlib>

class Creature
{
protected:
	std::string m_name;
	char m_symbol;
	int m_health;
	int m_attack;
	int m_gold;

public:
	Creature(const std::string& name, char symbol, int health, int attack, int gold) :
		m_name{ name }, m_symbol{ symbol }, m_health{ health }, m_attack{ attack }, m_gold{ gold }
	{};

	const std::string& getName() const { return m_name; }
	const char getSymbol() const { return m_symbol; }
	const int getHealth() const { return m_health; }
	const int getAttack() const { return m_attack; }
	const int getGold() const { return m_gold; }

	void reduceHealth(int damage) {	m_health -= damage;	}

	bool isDead() { return (m_health <= 0); }

	void addGold(int gold) { m_gold += gold; }

};

class Player : public Creature
{
private:
	int m_level{ 1 };

public:
	Player(const std::string& name) :
		Creature(name, '@', 15, 1, 0) {}

	void levelUp()
	{
		++m_level;
		++m_attack;
	}

	const int getLevel() const { return m_level; }

	bool hasWon() const { return (m_level >= 20); }

};

class Monster : public Creature
{
public:
	enum Type
	{
		DRAGON,
		ORC,
		SLIME,
		MAX_TYPES
	};

private:
	struct MonsterData
	{
		std::string_view name;
		char symbol;
		int health;
		int attack;
		int gold;
	};

	static constexpr std::array<MonsterData, Type::MAX_TYPES> monsterData {
		{	
			{ "dragon", 'D', 20, 4, 100 },
			{ "orc", 'o', 4, 2, 25 },
			{ "slime", 's', 1, 1, 10 },
		}
	};

	static Type getRandomType()
	{
		static constexpr double fraction{ 1.0 / (RAND_MAX + 1.0) };
		return static_cast<Type>(static_cast<int>(((Type::MAX_TYPES) * (std::rand() * fraction))));
	}

public:
	Monster(Type type) :
		Creature( monsterData[type].name.data(), monsterData[type].symbol, monsterData[type].health, monsterData[type].attack, monsterData[type].gold )
	{};

	static const Monster getRandomMonster()
	{
		return Monster(getRandomType());
	};

};


#endif