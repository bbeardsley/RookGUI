#include "Card.h"

void Card::Clear()
{
	Number = -1; // not set
	Color = -1; // not set
	Owner = -1; // not set
	Points = -1; // not set

	Trump = false; // not sets
}

string Card::GetCardString() // length 3
{
	// First handle Rook special case
	if (Number == 0)
	{
		return "0RK";
	}
	else
	{
		// example: 14R, 01B, 02Y, 10G
		string CardString = (Number < 10) ? "0" + std::to_string(Number) : std::to_string(Number);

		if (Color == 0) return CardString + "R";
		if (Color == 1) return CardString + "Y";
		if (Color == 2) return CardString + "G";
		if (Color == 3) return CardString + "B";
	}

	return "BLANK!"; // error
}