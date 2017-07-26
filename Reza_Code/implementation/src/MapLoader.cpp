#include "../headers/MapLoader.h"

MapLoader::MapLoader(std::string filePath)
{
	char cellType[15] = {};		//buffer-overflow mitigation
	int cellNumber = 0, adjacentCount = 0;
	std::function<BoardCell *(char *)> createCell = [&](char* cellType) -> BoardCell *
													{
														BoardCell *result;
														std::string strCellType(cellType);
														cellNumber++;
														if(strCellType == "initialCell")
														{
															cellNumber = 0;
															result = new InitialCell;
															result -> setMyColor();
															result -> cellNumber = cellNumber;
															this -> initialCells.push_back(dynamic_cast<InitialCell *>(result));
															if(this -> allCells.empty())
															{
																this -> allCells.push_back(result);
															}
															return result;
														}
														else if(strCellType == "decisionCell")
														{
															result = new DecisionCell;
															result -> cellNumber = cellNumber;
															this -> decisionCells.push_back(dynamic_cast<DecisionCell *>(result));
														}
														else if(strCellType == "transportCell")
														{
															result = new TransportCell;
															result -> cellNumber = cellNumber;
															this -> transportCells.push_back(dynamic_cast<TransportCell *>(result));
														}
														else if(strCellType == "treasureCell")
														{
															result = new TreasureCell;
															result -> cellNumber = cellNumber;
															this -> treasureCells.push_back(dynamic_cast<TreasureCell *>(result));
														}
														else if(strCellType == "ordinaryCell")
														{
															result = new OrdinaryCell;
															result -> cellNumber = cellNumber;
														}
														result -> setMyColor();
														result -> occupierPlayer = nullptr;
														this -> allCells.push_back(result);
														
														return result;
													};
	std::function<void(BoardCell *, char *, int)> MakeAdjacent = [&](BoardCell *cell, char *cellType, int adjID) -> void
													{
														if(std::string(cellType) == "initialCell")
															return;
														if(cell -> cellNumber >= adjID)
														{
															cell -> addAsAdjacent(this -> allCells[adjID], true);
														}
														if(cell -> cellNumber == 1)
														{
															this -> allCells[0] -> addAsAdjacent(cell, false);
														}
													};
	FILE *mapFile = fopen(filePath.c_str(), "r");
	if(mapFile == nullptr)
	{
		
	}
	else
	{
		int cellCount = 0;
		fscanf(mapFile, "%d\n", &cellCount);
		
		for(int fileRow = 1; fileRow <= cellCount; fileRow++)
		{
			fscanf(mapFile, "%s -> %d:\n", cellType, &adjacentCount);
			BoardCell *newCell = createCell(cellType);
			for(int adjacents = 0; adjacents < adjacentCount; adjacents++)
			{
				int adjacentCell = 0;
				fscanf(mapFile, "%d ", &adjacentCell);
				MakeAdjacent(newCell, cellType, adjacentCell);
			}
		}
		this -> firstCell = this -> allCells[1];
	}
}

std::string const &MapLoader::getLastError()
{
	return this -> lastError;
}

std::vector<InitialCell *> const &MapLoader::getInitialCells()
{
	return this -> initialCells;
}

std::vector<DecisionCell *> const &MapLoader::getDecisionCells()
{
	return this -> decisionCells;
}

std::vector<TransportCell *> const &MapLoader::getTransportCells()
{
	return this -> transportCells;
}

std::vector<TreasureCell *> const &MapLoader::getTreasureCells()
{
	return this -> treasureCells;
}

BoardCell *MapLoader::getFirstCell()
{
	return this -> firstCell;
}
