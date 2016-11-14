#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include "Deck.h"

#include <vector>
using std::vector;

struct HandInformation
{
	int Points; // Number of Points in Current Hand
	bool IsTrumped; // True if hand has been trumped
	int ColorLead; // Color of first card played in hand

	HandInformation() :
		Points(0),
		IsTrumped(false),
		ColorLead(-1)
	{
	}
};

HandInformation GetHandInformation(const vector<Card *> &OtherCards);

class Player
{
	// API decides what cards to play
	friend class API;
	friend class GameController;

private:

	int PlayerNumber;

public:

	vector<Card *> PlayerCards;

	Player() : PlayerNumber(-1)
	{
		ClearCards();
	}

	void SetPlayerNumber(int PlayerNumberUse)
	{
		PlayerNumber = PlayerNumberUse;
	}

	void ClearCards()
	{
		PlayerCards.resize(0);
	}

	vector <Card *> &GetPlayerCards()
	{
		return PlayerCards;
	}

	void GetPlayerCardsFromDeck(Deck &DeckUse);

	void PrintPlayerCards();

	Card *PlayCard(const vector<Card *> &OtherCards);
};

#endif