#include "../headers/DiceDecision.h"

std::string DiceDecision::getUIString()
{
	const BoardCell::ColorRGB RED = {255, 0, 0}, BLUE = {0, 0, 255}, GREEN = {50, 255, 50}, ORANGE = {255, 140, 0}, PURPLE = {255, 0, 255};
	std::string result = "";
	if(this -> diceDecisionType == DiceDecision::NOT_SET)
		return "";
		
	if(this -> diceDecisionType == DiceDecision::SWITCH_TREASURE)
	{
		return "Change current round's goal treasure";
	}
	else
	{
		std::ostringstream destinationCellNumber;
		destinationCellNumber << this -> destination -> getCellNumber();
		result = "Move to " + destinationCellNumber.str();
	}
	if(this -> destination -> getColor() == ORANGE)
	{
		result += "(Orange)";
	}
	else if(this -> destination -> getColor() == PURPLE)
	{
		result += "(Violet)";
	}
	else if(this -> destination -> getColor() == RED)
	{
		result += "(Red)";
	}
	
	return result;
}

std::string DiceDecision::getType()
{
	return "DiceDecision";
}
