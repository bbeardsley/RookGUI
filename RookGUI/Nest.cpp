#include "Nest.h"
#include "Deck.h"

#include <iostream>
using std::cout;

void Nest::GetNestCardsFromDeck(Deck &DeckUse)
{
	for (int i = 0; i < NUMBERCARDS; i++)
	{
		if (DeckUse.CardDeck[i].Owner == 4)
		{
			NestCards.push_back(&DeckUse.CardDeck[i]);
		}
	}
}

void Nest::PrintNestCards()
{
	for (unsigned int i = 0; i < NestCards.size(); i++)
	{
		cout << NestCards[i]->GetCardString() << " ";
	}
}

int Nest::GetNumberPoints()
{
	int TotalPoints = 0;

	for (unsigned int i = 0; i < NestCards.size(); i++)
	{
		TotalPoints += NestCards[i]->Points;
	}

	return TotalPoints;
}