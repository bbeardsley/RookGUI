#ifndef CARD_H
#define CARD_H

#include <string>
using std::string;

struct Card
{
	int Number;		// 1, 2, ..., 14, 0 (0: Rook)
	int Color;		// 0, 1, 2, 3, 4 (0: Red, 1: Yellow, 2: Green, 3: Black, 4: Other)

	int Owner;		// 0, 1, 2, 3, 4 (0: Player 0, 1: Player 1, 2: Player 2, 3: Player 3, 4: Nest
	int Points;		// Number of points card is worth (5: 5, 10: 10, 14: 10, Rook: 20)

	bool Trump;		// true if trump, false otherwise

	Card()
	{
		Clear();
	}

	void Clear();

	string GetCardString();
};

struct CardCompareNumber // for sorting based on number
{
	inline bool operator() (Card *Card1, Card *Card2)
	{
		return (Card1->Number < Card2->Number);
	}
};

struct CardCompareSuit // for sorting based on suit
{
	inline bool operator() (Card *Card1, Card *Card2)
	{
		return (Card1->Color < Card2->Color);
	}
};

#endif