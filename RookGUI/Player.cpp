#include "Player.h"

#include <algorithm>
#include <iostream>

using std::sort;
using std::cout;

HandInformation GetHandInformation(const vector<Card *> &OtherCards)
{
	HandInformation Info;

	if (OtherCards.size() == 0) return Info; // no Info

	Info.ColorLead = OtherCards[0]->Color;

	// At least one card has been played
	for (int i = 0; i < OtherCards.size(); i++)
	{
		Info.Points += OtherCards[i]->Points;

		if (!Info.IsTrumped)
		{
			Info.IsTrumped = OtherCards[i]->Trump;
		}
	}

	return Info;
}

bool HasColorInHand(vector <Card *>Hand, int Color)
{
	for (int i = 0; i < Hand.size(); i++)
	{
		if (Hand[i]->Color == Color) return true;
	}

	return false;
}

Card * GetHighestCardInHandByColor(vector <Card *>Hand, int Color)
{
	Card * HighestCard = nullptr;

	int Max = -1;
	int MaxIndex = -1;

	for (int i = 0; i < Hand.size(); i++)
	{
		if (Hand[i]->Color == Color)
		{
			if (Hand[i]->Number > Max)
			{
				Max = Hand[i]->Number;
				MaxIndex = i;
			}
		}
	}

	if (MaxIndex != -1)
	{
		HighestCard = Hand[MaxIndex];
	}

	return HighestCard;
}

void Player::GetPlayerCardsFromDeck(Deck &DeckUse)
{
	for (int i = 0; i < NUMBERCARDS; i++)
	{
		if (DeckUse.CardDeck[i].Owner == PlayerNumber)
		{
			PlayerCards.push_back(&DeckUse.CardDeck[i]);
		}
	}

	sort(PlayerCards.begin(), PlayerCards.end(), CardCompareNumber());
	sort(PlayerCards.begin(), PlayerCards.end(), CardCompareSuit());
}

void Player::PrintPlayerCards()
{
	for (unsigned int i = 0; i < PlayerCards.size(); i++)
	{
		cout << PlayerCards[i]->GetCardString() << " ";
	}
}

Card *Player::PlayCard(const vector<Card *> &OtherCards)
{
	Card *PlayedCard = PlayerCards[0]; // by default

	HandInformation Info = GetHandInformation(OtherCards);

	if (HasColorInHand(PlayerCards, Info.ColorLead)) // need to play color lead
	{
		// play highest card
		PlayedCard = GetHighestCardInHandByColor(PlayerCards, Info.ColorLead);
	}

	//PlayedCard->Owner = -1; // no longer in players hand

	PlayerCards.erase(std::remove(PlayerCards.begin(),
		PlayerCards.end(), PlayerCards[0]),
		PlayerCards.end()); // remove card from players hand

	return PlayedCard;
}