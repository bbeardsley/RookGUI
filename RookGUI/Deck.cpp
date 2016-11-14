#include "Deck.h"

void Deck::ClearCardDeck()
{
	for (int i = 0; i < NUMBERCARDS; i++)
	{
		CardDeck[i].Clear();
	}
}

void Deck::InitializeCardDeck()
{
	for (int i = 0; i < NUMBERCARDS; i++)
	{
		if (i < NUMBERCARDS - 1)
		{
			CardDeck[i].Color = i / HIGHESTCARD;
			CardDeck[i].Number = i % HIGHESTCARD + 1;

			// assign points
			if (CardDeck[i].Number == 5) CardDeck[i].Points = 5;
			else if (CardDeck[i].Number == 10 || CardDeck[i].Number == 14) CardDeck[i].Points = 10;
			else CardDeck[i].Points = 0;
		}
		else // rook
		{
			CardDeck[i].Color = 4; // other
			CardDeck[i].Number = 0;

			CardDeck[i].Points = 20;
		}
	}
}

void Deck::ShuffleDeck() // Shuffles CardDeck
{
	// http://stackoverflow.com/questions/6127503/shuffle-array-in-c

	for (int i = 0; i < NUMBERCARDS - 1; i++)
	{
		int j = i + rand() / (RAND_MAX / (NUMBERCARDS - i) + 1);
		Card t = CardDeck[j];
		CardDeck[j] = CardDeck[i];
		CardDeck[i] = t;
	}
}

void Deck::DealDeck() // Changes card owner
{
	for (int i = 0; i < NUMBERCARDS; i++)
	{
		if (i < NUMBERCARDS - SIZENEST)
		{
			CardDeck[i].Owner = i % 4;
		}
		else
		{
			CardDeck[i].Owner = 4;
		}
	}
}