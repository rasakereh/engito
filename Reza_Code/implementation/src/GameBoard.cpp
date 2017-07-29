#include "../headers/GameBoard.h"

std::vector<BoardCell *> const &GameBoard::getAllCells()
{
	return this -> allCells;
}

std::vector<InitialCell *> const &GameBoard::getInitialCells()
{
	return this -> initialCells;
}

std::vector<TreasureCell *> const &GameBoard::getTreasureCells()
{
	return this -> treasureCells;
}

std::vector<DecisionCell *> const &GameBoard::getDecisionCells()
{
	return this -> decisionCells;
}

std::vector<TransportCell *> const &GameBoard::getTransportCells()
{
	return this -> transportCells;
}

void GameBoard::loadInitialCells(std::vector<InitialCell *> const &initialCells)
{
	this -> initialCells.resize(initialCells.size());
	auto currentCell = this -> initialCells.begin();
	std::copy(initialCells.begin(), initialCells.end(), currentCell);
}

void GameBoard::loadTreasureCells(std::vector<TreasureCell *> const &treasureCells)
{
	this -> treasureCells.resize(treasureCells.size());
	auto currentCell = this -> treasureCells.begin();
	std::copy(treasureCells.begin(), treasureCells.end(), currentCell);
}

void GameBoard::loadDecisionCells(std::vector<DecisionCell *> const &decisionCells)
{
	this -> decisionCells.resize(decisionCells.size());
	auto currentCell = this -> decisionCells.begin();
	std::copy(decisionCells.begin(), decisionCells.end(), currentCell);
}

void GameBoard::loadTransportCells(std::vector<TransportCell *> const &transportCells)
{
	this -> transportCells.resize(transportCells.size());
	auto currentCell = this -> transportCells.begin();
	std::copy(transportCells.begin(), transportCells.end(), currentCell);
}

void GameBoard::loadAllCells(std::vector<BoardCell *> const &allCells,
                             std::vector<InitialCell *> const &initialCells,
							 std::vector<TreasureCell *> const &treasureCells,
							 std::vector<DecisionCell *> const &decisionCells,
							 std::vector<TransportCell *> const &transportCells,
							 BoardCell *firstCell)
{
    this -> allCells = allCells;
	this -> loadInitialCells(initialCells);
	this -> loadTreasureCells(treasureCells);
	this -> loadDecisionCells(decisionCells);
	this -> loadTransportCells(transportCells);
	this -> firstCell = firstCell;
}
