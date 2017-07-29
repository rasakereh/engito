#include "../headers/BoardCell.h"

void BoardCell::setCellNumber(int cellNumber)
{
	this -> cellNumber = cellNumber;
}

void BoardCell::setMyColor()
{
    
}

void BoardCell::setPosition(int xPosition, int yPosition)
{
    this -> xPosition = xPosition;
    this -> yPosition = yPosition;
}

std::pair<int, int> BoardCell::getPosition()
{
    return std::make_pair(this -> xPosition, this -> yPosition);
}

int BoardCell::getCellNumber()
{
	return this -> cellNumber;
}

Player *const &BoardCell::getOccupier()
{
	return this -> occupierPlayer;
}

std::vector <BoardCell *> BoardCell::nextCell(BoardCell *parentCell)
{
	std::vector<BoardCell *> nextCells(this -> adjacentCells);
	if(parentCell != nullptr)
	{
		auto parentFinder = std::find(nextCells.begin(), nextCells.end(), parentCell);
		if(parentFinder != nextCells.end())
		{
			nextCells.erase(parentFinder);
		}
	}
	return nextCells;
}

BoardCell::ColorRGB const &BoardCell::getColor()
{
	return this -> cellColor;
}

void BoardCell::setColor(_COLOR8 redDepth, _COLOR8 greenDepth, _COLOR8 blueDepth)
{
	this -> cellColor.redDepth = redDepth;
	this -> cellColor.blueDepth = blueDepth;
	this -> cellColor.greenDepth = greenDepth;
}

Player *BoardCell::inhabit(Player *newOccupier)
{
	const BoardCell::ColorRGB RED = {255, 0, 0}, BLUE = {0, 0, 255}, GREEN = {50, 255, 50}, ORANGE = {255, 140, 0}, PURPLE = {255, 0, 255};
	newOccupier -> location -> evacuate();
	newOccupier -> location = this;
	Player *oldOccupier = this -> occupierPlayer;
	if(oldOccupier == nullptr)
	{
		this -> occupierPlayer = newOccupier;
	}
	else if(this -> cellNumber != 0)
	{
		this -> occupierPlayer = newOccupier;
	}
	else
	{
		static_cast<InitialCell *>(this) -> otherOccupiers.push_back(newOccupier);
		return nullptr;
	}
	
	if(this -> cellColor == ORANGE)
	{
		this -> occupierPlayer -> activeGame -> gameUI -> showTreasureTo(this -> occupierPlayer -> getPlayerName(), static_cast<TreasureCell *>(this) -> getCellTreasure() -> treasureName, this -> cellNumber);
	}
	
	return oldOccupier;
}

void BoardCell::evacuate()
{
	
}

void BoardCell::addAsAdjacent(BoardCell *newAdjacent, bool applyMutually)
{
	this -> adjacentCells.push_back(newAdjacent);
	if(applyMutually)
	{
		newAdjacent -> adjacentCells.push_back(this);
	}
}

std::vector<BoardCell *> BoardCell::passThrough(BoardCell *source, int distance)
{
	if(distance == 0)
	{
		std::vector<BoardCell *> me(1, this);
		return me;
	}
	std::vector<BoardCell *> result, nextCells;
	nextCells = this -> nextCell(source);
	for(auto adjacents = nextCells.begin(); adjacents != nextCells.end(); adjacents++)
	{
		std::vector<BoardCell *> throughCurrentAdj = (*adjacents) -> passThrough(this, distance - 1);
		result.insert(result.end(), throughCurrentAdj.begin(), throughCurrentAdj.end());
	}
	
	return result;
}
