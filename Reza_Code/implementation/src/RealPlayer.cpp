#include "../headers/RealPlayer.h"

void RealPlayer::takeDice()
{
	if(this -> activeGame -> gameUI -> diceRollPermission())
	{
		this -> rollDice();
		this -> playDice();
	}
}

void RealPlayer::playDice()
{
	std::vector<Decision *> primaryOptionList = this -> activeGame -> gameRuler -> evaluateOptionList();
	std::vector<DiceDecision *> optionList(primaryOptionList.size(), nullptr);
	std::transform(primaryOptionList.begin(), primaryOptionList.end(), optionList.begin(), [](Decision *option) -> DiceDecision *{return static_cast<DiceDecision *>(option);});
	this -> selectOption(optionList);
}

std::pair<Dice::DiceResult, Dice::DiceResult> RealPlayer::rollDice()
{
	return this -> activeGame -> gameBoard -> gameDice -> roll();
}

std::string const &RealPlayer::getPlayerName()
{
	return this -> playerName;
}

CellDecision *RealPlayer::selectOption(std::vector<CellDecision *> &decisionList)
{
	DecisionTranslator translator;
	CellDecision *choice = translator.getDecisionFromUI(decisionList, this -> activeGame -> gameUI, this);
	this -> activeGame -> gameStat -> rememberPlayerChoice(choice);
	return choice;
}

DiceDecision *RealPlayer::selectOption(std::vector<DiceDecision *> &decisionList)
{
	DecisionTranslator translator;
	DiceDecision *choice = translator.getDecisionFromUI(decisionList, this -> activeGame -> gameUI);
	this -> activeGame -> gameStat -> rememberPlayerChoice(choice);
	return choice;
}

void RealPlayer::releaseDice()
{
	
}
