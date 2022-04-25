#ifndef CARDGAME_H_34134151556
#define CARDGAME_H_34134151556

namespace CardRank
{
	enum CardRank
	{
		RANK_2,
		RANK_3,
		RANK_4,
		RANK_5,
		RANK_6,
		RANK_7,
		RANK_8,
		RANK_9,
		RANK_10,
		RANK_JACK,
		RANK_QUEEN,
		RANK_KING,
		RANK_ACE,
		RANK_MAX
	};
}

namespace CardSuit
{
	enum CardSuit
	{
		SUIT_CLUBS,
		SUIT_DIAMONDS,
		SUIT_HEARTS,
		SUIT_SPADES,
		SUIT_MAX
	};
}

struct Card
{
	CardRank::CardRank rank;
	CardSuit::CardSuit suit;
};

// alias for index of the 52-card deck array
using size_deck52 = std::array<Card, 52>::size_type;

// printCard() function takes a const Card reference as a parameter 
// and prints the card rank and value as a 2 - letter code
// (e.g.the jack of spades would print as JS).
void printCard(const Card &card);

// printDeck() takes the deck as a const reference parameter and prints the values in the deck.
void printDeck(const std::array<Card, 52> &deck);

// swapCard function takes two Cards and swaps their values
void swapCard(Card &a, Card &b);

// randomizer initialization
std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

// generates random int number between 0 and 51 inclusive
int random52();

// shuffleDeck() loops through each element of the array,
// picks a random number between 1 and 52, 
// and calls swapCard with the current card and the card picked at random. 
void shuffleDeck(std::array<Card, 52> &deck);

// getCardValue() returns the value of a Card (e.g. a 2 is worth 2, a ten, jack, queen, or king is worth 10. Assume an Ace is worth 11).
int getCardValue(const Card &card);

// plays Blackjack; returns true if player wins, false if dealer wins
// accepts shuffled deck of cards as a parameter
bool playBlackjack(const std::array<Card, 52> &deck);

// Print next card from the deck (and move pointer to the next card) and increase corresponding score by card value
void drawCard(const Card *&cardPtr, int &score);

#endif