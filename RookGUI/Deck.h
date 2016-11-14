#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include "GameVariables.h"

class Deck
{
	// The Nest and Player classes need access to the Deck
	friend class Nest;
	friend class Player;

private:

	Card CardDeck[NUMBERCARDS];

public:

	Deck() // initializes CardDeck
	{
		ClearCardDeck();
	}

	void ClearCardDeck();

	void InitializeCardDeck();

	void ShuffleDeck(); // Shuffles CardDeck

	void DealDeck(); // Changes card owner
};


#endif