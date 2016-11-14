#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "Deck.h"
#include "Nest.h"
#include "Player.h"
#include "GUI.h"

class GameController
{
private:

	vector<Card *> PlayedCards; // cards played in the current round

	Deck GameDeck;

	Nest GameNest;

public:

	Player GamePlayers[NUMBERPLAYERS];
	Player *HumanPlayer;

	GameController();

	void StartGame();

	void PrintCards();

	void BiddingRound(int StartingPlayerNumber); // StartingPlayerNumber starts bid

	void MainRound();

	bool PlayHumanCard(Card *CardUse);

	void PlayRound(int StartingPlayerNumber); // StartingPlayerNumber starts round

	void PrintHand();
};

#endif