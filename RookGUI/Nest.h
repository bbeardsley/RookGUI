#ifndef NEST_H
#define NEST_H

#include "Card.h"
#include "GameVariables.h"

#include <vector>
using std::vector;

class Deck; // forward declaration

class Nest
{
private:

	vector<Card *> NestCards;

public:

	Nest()
	{
		ClearCards();
	}

	void ClearCards()
	{
		NestCards.resize(0);
	}

	void GetNestCardsFromDeck(Deck &DeckUse);

	void PrintNestCards();

	int GetNumberPoints();
};

#endif