#include "../headers/NetworkPlayer.h"

void NetworkPlayer::takeDice()
{
	if(this -> activeGame -> gameUI -> diceRollPermission())
	{
		this -> rollDice();
		this -> playDice();
	}
}

void NetworkPlayer::playDice()
{
	
}

std::pair<Dice::DiceResult, Dice::DiceResult> NetworkPlayer::rollDice()
{
	return this -> activeGame -> gameBoard -> gameDice -> roll();
}

CellDecision *NetworkPlayer::selectOption(std::vector<CellDecision *> &decisionList)
{
}

DiceDecision *NetworkPlayer::selectOption(std::vector<DiceDecision *> &decisionList)
{
}

void NetworkPlayer::releaseDice()
{
	
}

std::string const &NetworkPlayer::getPlayerName()
{
	return this -> playerName;
}
