#include "../headers/CellDecision.h"

std::string CellDecision::getUIString()
{
	std::string result = "";
	std::ostringstream destinationCellNumber;
	destinationCellNumber << this -> destination -> getCellNumber();
	result = "It's " + destinationCellNumber.str();
	return result;
}

std::string CellDecision::getType()
{
	return "CellDecision";
}
