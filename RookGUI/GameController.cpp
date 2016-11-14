#include "GameController.h"
#include "Player.h"

#include <iostream>
using std::cout;

class GUI;
extern GUI *gui;

GameController::GameController()
{
	HumanPlayer = &GamePlayers[0];
}

void GameController::StartGame()
{
	GameDeck.InitializeCardDeck();
	GameDeck.ShuffleDeck();
	GameDeck.DealDeck();

	for (int i = 0; i < NUMBERPLAYERS; i++)
	{
		GamePlayers[i].SetPlayerNumber(i);
		GamePlayers[i].GetPlayerCardsFromDeck(GameDeck);
	}

	//PrintCards();

	gui->PrintHand(HumanPlayer->GetPlayerCards ());

	//BiddingRound(0); // for now, just let Player 0 start the bidding

	//MainRound();
}

void GameController::PrintCards()
{
	for (int i = 0; i < NUMBERPLAYERS; i++)
	{
		cout << "P" << i << " ";
		GamePlayers[i].PrintPlayerCards();
		cout << "\n";
	}
}

void GameController::BiddingRound(int StartingPlayerNumber) // StartingPlayerNumber starts bid
{

}

void GameController::MainRound()
{
	for (int i = 0; i < 3; i++)
	{
		// Simplest strategy - try to win every hand
		for (int j = 0; j < NUMBERPLAYERS; j++)
		{
			PlayedCards.push_back(GamePlayers[j].PlayCard(PlayedCards));
		}

		for (int i = 0; i < PlayedCards.size(); i++)
		{
			std::cout << PlayedCards[i]->GetCardString() << " ";
		}
		std::cout << std::endl;

		std::cout << "\nAfter Round " << i + 1 << "\n";
		for (int j = 0; j < NUMBERPLAYERS; j++)
		{
			std::cout << "P" << j << " ";
			GamePlayers[j].PrintPlayerCards();
			std::cout << "\n";
		}
	}
}


bool GameController::PlayHumanCard(Card *CardUse)
{
	// Check if the hand can be played
	HandInformation Info = GetHandInformation(PlayedCards);

	bool CanPlayCard = true;

	if (CanPlayCard)
	{
		vector<Card *> &PlayerCards = GamePlayers[0].GetPlayerCards();
		PlayerCards.erase(std::remove(PlayerCards.begin(), PlayerCards.end(), CardUse), PlayerCards.end());
	}

	return true;
}

void GameController::PlayRound(int StartingPlayerNumber) // StartingPlayerNumber starts round
{
	vector<Card> PlayedCards;


}

void GameController::PrintHand()
{
	gui->PrintHand(HumanPlayer->GetPlayerCards());
}