#include "../headers/TreasureCell.h"

void TreasureCell::setMyColor()
{
	this -> setColor(255, 140, 0);
}

const Treasure* TreasureCell::getCellTreasure()
{
	return this -> cellTreasure;
}
