#include "../headers/RobotPlayer.h"

void RobotPlayer::takeDice()
{
	if(this -> activeGame -> gameUI -> diceRollPermission())
	{
		this -> rollDice();
		this -> playDice();
	}
}

void RobotPlayer::playDice()
{
}

std::pair<Dice::DiceResult, Dice::DiceResult> RobotPlayer::rollDice()
{
	return this -> activeGame -> gameBoard -> gameDice -> roll();
}

CellDecision *RobotPlayer::selectOption(std::vector<CellDecision *> &decisionList)
{
}

DiceDecision *RobotPlayer::selectOption(std::vector<DiceDecision *> &decisionList)
{
}

std::string const &RobotPlayer::getPlayerName()
{
	return this -> playerName;
}

void RobotPlayer::releaseDice()
{
	
}
