#include "../headers/Dice.h"

bool Dice::DiceResult::operator==(Dice::DiceResult const &counterDice)
{
	return this -> diceValue == counterDice.diceValue;
}

std::pair <Dice::DiceResult, Dice::DiceResult> Dice::roll()
{
	int diceValue1 = (rand() % 6) + 1;
	int diceValue2 = (rand() % 6) + 1;
	Dice::DiceResult diceResult1, diceResult2;
	diceResult1.diceValue = diceValue1;
	diceResult1.diceState = PERMITTED;
	diceResult2.diceValue = diceValue2;
	diceResult2.diceState = PERMITTED;
	std::pair<Dice::DiceResult, Dice::DiceResult> diceResult = std::make_pair(diceResult1, diceResult2);
	this -> gameBoard -> ownerGame -> gameStat -> informAboutDice(diceResult1, diceResult2);
	
	return diceResult;
}
