/*
Pretend you’re writing a game where the player can hold 3 types of items :
health potions, torches, and arrows.

Create an enum to identify the different types of items,

and a fixed array to store the number of each item the player is carrying
(use built - in fixed arrays, not std::array).

The player should start with 2 health potions, 5 torches, and 10 arrows.

Write a function called countTotalItems() that returns how many items the player has in total.

Have your main() function print the output of countTotalItems().
*/


#include <iostream>

// enum for Item types: health potions, torches, and arrows.
namespace ItemTypes
{
	enum ItemTypes
	{
		HEALTH_POTION,
		TORCH,
		ARROW,
		TOTAL_ITEMS
	};
}


int countTotalItems(int *playerItems)
{
	int totalItems{0};
	for (int i{0}; i < ItemTypes::TOTAL_ITEMS; ++i)
	{
		totalItems += playerItems[i];
	};

	return totalItems;
}



int main()
{
	// fixed array to store the number of each item the player is carrying
	// use built-in fixed arrays, not std::array
	int playerItems[3]{};

	// The player should start with 2 health potions, 5 torches, and 10 arrows.
	playerItems[ItemTypes::HEALTH_POTION] = 2;
	playerItems[ItemTypes::TORCH] = 5;
	playerItems[ItemTypes::ARROW] = 10;
	
	std::cout << "Total items held: " << countTotalItems(playerItems) << '\n';
	return 0;
}