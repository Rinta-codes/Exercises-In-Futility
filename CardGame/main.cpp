// A deck of cards has 52 unique cards (13 card ranks of 4 suits). 
// Create enumerations for the card ranks (2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace) and suits (clubs, diamonds, hearts, spades).

#include <iostream>
#include <array>
#include <ctime>
#include <random>
#include "cardgame.h"

void printCard(const Card &card)
{
	switch (card.rank)
	{
		case CardRank::RANK_2: std::cout << "2"; break;
		case CardRank::RANK_3: std::cout << "3"; break;
		case CardRank::RANK_4: std::cout << "4"; break;
		case CardRank::RANK_5: std::cout << "5"; break;
		case CardRank::RANK_6: std::cout << "6"; break;
		case CardRank::RANK_7: std::cout << "7"; break;
		case CardRank::RANK_8: std::cout << "8"; break;
		case CardRank::RANK_9: std::cout << "9"; break;
		case CardRank::RANK_10: std::cout << "0"; break;
		case CardRank::RANK_JACK: std::cout << "J"; break;
		case CardRank::RANK_QUEEN: std::cout << "Q"; break;
		case CardRank::RANK_KING: std::cout << "K"; break;
		case CardRank::RANK_ACE: std::cout << "A"; break;
		default: std::cout << "#";
	}

	switch (card.suit)
	{
	case CardSuit::SUIT_CLUBS: std::cout << "C"; break;
	case CardSuit::SUIT_DIAMONDS: std::cout << "D"; break;
	case CardSuit::SUIT_HEARTS: std::cout << "H"; break;
	case CardSuit::SUIT_SPADES: std::cout << "S"; break;
	default: std::cout << "#";
	}
}


void printDeck(const std::array<Card, 52> &deck)
{
	for (const Card &card : deck)
	{
		printCard(card);
		std::cout << " ";
	}
}


void swapCard(Card &a, Card &b)
{
	Card temp{a};

	a = b;
	b = temp;
}


int random52()
{
	std::uniform_int_distribution<> random52{0, 51};
	return random52(mersenne);
}


void shuffleDeck(std::array<Card, 52> &deck)
{
	for (Card &card : deck)
	{
		size_deck52 random_card{ static_cast<size_deck52>(random52()) };
		swapCard(card, deck[random_card]);
	}
}


int getCardValue(const Card &card)
{
	switch (card.rank)
	{
		case CardRank::RANK_2: return 2;
		case CardRank::RANK_3: return 3;
		case CardRank::RANK_4: return 4;
		case CardRank::RANK_5: return 5;
		case CardRank::RANK_6: return 6;
		case CardRank::RANK_7: return 7;
		case CardRank::RANK_8: return 8;
		case CardRank::RANK_9: return 9;
		case CardRank::RANK_10: 
		case CardRank::RANK_JACK: 
		case CardRank::RANK_QUEEN: 
		case CardRank::RANK_KING: return 10;
		case CardRank::RANK_ACE: return 11;
		default: return 0;
		
	}
};

void drawCard(const Card *&cardPtr, int &score)
{
	// Print the card that was drawn
	std::cout << "Card drawn: ";
	printCard(*cardPtr);
	std::cout << '\n';

	// Increase relevant score
	// Move card pointer to the next card in the deck
	// (no need for safety checks since game cannot last for whole 52 cards)
	score += getCardValue(*cardPtr++);
	std::cout << "Current score: " << score << '\n';
}

bool playBlackjack(const std::array<Card, 52> & deck)
{
	// Initialize a pointer to the first Card named cardPtr. This will be used to deal out cards from the deck.
	const Card *cardPtr = &(deck[static_cast<size_deck52>(0)]);

	int playerScore{ 0 };
	int dealerScore{ 0 };

	// The dealer gets one card to start.
	std::cout << "The dealer draws initial cards!\n"; 
	drawCard(cardPtr, dealerScore);
	
	// The player gets two cards to start.
	std::cout << "\nThe player draws initial cards!\n";
	drawCard(cardPtr, playerScore);
	drawCard(cardPtr, playerScore);

	// Player turn
	std::cout << "\n\nPlayer's turn!\n\n";
	// Repeat until Player "stands" or reaches >21 points
	char turn{ 'H' }; // H for "hit", S for "stand"
	while (turn != 'S' && turn != 's' && playerScore <= 21)
	{
		std::cout << "Do you hit or stand? (H/S): ";
		std::cin >> turn;

		switch (turn)
		{
			case 'H':
			case 'h': drawCard(cardPtr, playerScore); break;
			case 'S':
			case 's': std::cout << "You decided to stand.\n"; break;
			default: std::cout << "Invalid input, please try again.\n";
		}
		std::cin.ignore(100, '\n');
	}

	if (playerScore > 21)
		return false;

	// Dealer's turn
	std::cout << "\n\nDealer's turn!\n\n";
	while (dealerScore < 17 && dealerScore < playerScore)
		drawCard(cardPtr, dealerScore);
	
	if (dealerScore > 21)
		return true;
	   	
	return (playerScore > dealerScore ? true : false);
}

int main()
{
	std::array<Card, 52> deck{};

	size_deck52 index{ 0 };
	
	for (int rank{ 0 }; rank < CardRank::RANK_MAX; ++rank)
		for (int suit{ 0 }; suit < CardSuit::SUIT_MAX; ++suit)
		{
			deck[index].rank = static_cast<CardRank::CardRank>(rank);
			deck[index].suit = static_cast<CardSuit::CardSuit>(suit);
			++index;
		}

	printDeck(deck);
	std::cout << '\n';

	shuffleDeck(deck);
	printDeck(deck);
	std::cout << '\n';
	std::cout << '\n';

	std::cout << (playBlackjack(deck) ? "You won!\n" : "You lost!\n");

	return 0;
}