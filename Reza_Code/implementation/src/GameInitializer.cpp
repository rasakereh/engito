#include <QDebug>

#include "../headers/GameInitializer.h"

GameInitializer::GameInitializer(std::string mapPath, std::vector<std::string> realPlayers, std::vector<std::string> networkPlayers, std::vector<std::string> robotPlayers, UI *caller)
{
	this -> gameUI = caller;
	this -> composeGame(mapPath, realPlayers, networkPlayers, robotPlayers);
	this -> locateTreasures();
	this -> locatePlayers();
	this -> gameStat -> changeGoalTreasure(false, false);	//false == current treasure is not collected
	this -> gameStat -> roundCounter = 1;
	this -> gameStat -> expressNewRound();
	this -> gameRuler -> keepGameAlive();
}

void GameInitializer::locatePlayers()
{
	std::function<void (Player *)> playerLocator = [&](Player *player)
													{
                                                        player -> location = this -> initiatedGame -> gameBoard -> initialCells[0];
														if(this -> initiatedGame -> gameBoard -> initialCells[0] -> occupierPlayer == nullptr)
														{
															this -> initiatedGame -> gameBoard -> initialCells[0] -> occupierPlayer = player;
														}
														else
														{
															this -> initiatedGame -> gameBoard -> initialCells[0] -> otherOccupiers.push_back(player);
														}
													};
	std::for_each(this -> gameStat -> players.begin(), this -> gameStat -> players.end(), playerLocator);
}

void GameInitializer::assembleGameBoard(std::string mapPath)
{
	this -> gameDice = new Dice;
	this -> gameMap = new MapLoader(mapPath);
	this -> gameBoard = new GameBoard;
	this -> gameBoard -> gameDice = this -> gameDice;
	this -> gameBoard -> gameDice -> gameBoard = this -> gameBoard;
	this -> gameBoard -> loadAllCells(this -> gameMap -> getAllCells(),this -> gameMap -> getInitialCells(), this -> gameMap -> getTreasureCells(), this -> gameMap -> getDecisionCells(), this -> gameMap -> getTransportCells(), this -> gameMap -> getFirstCell());
}

void GameInitializer::composeGame(std::string mapPath, std::vector<std::string> realPlayers, std::vector<std::string> networkPlayers, std::vector<std::string> robotPlayers)
{
	this -> assembleGameBoard(mapPath);
	this -> gameRuler = new GameRuler;
	this -> gameStat = new GameStatistics(realPlayers, networkPlayers, robotPlayers);
	this -> initiatedGame = new Game(this -> gameBoard, this -> gameRuler, this -> gameStat, this -> gameUI);
}

void GameInitializer::locateTreasures()
{
	std::function<void (Treasure *)> putInEmptyCell = [&](Treasure *treasure)
															{
																auto firstEmptyCell = std::find_if(this -> initiatedGame -> gameBoard -> treasureCells.begin(), this -> initiatedGame -> gameBoard -> treasureCells.end(), [](TreasureCell *treasureCell){return (treasureCell -> getCellTreasure() == nullptr);});
																if(firstEmptyCell != this -> initiatedGame -> gameBoard -> treasureCells.end())
																{
																	(*firstEmptyCell) -> cellTreasure = treasure;
																}
															};
	
	this -> defineTreasures();
	this -> shuffleTreasures();
	std::for_each(this -> treasures.begin(), this -> treasures.end(), putInEmptyCell);
}

void GameInitializer::defineTreasures()
{
	int neededTreasure = this -> initiatedGame -> gameBoard -> treasureCells.size();
	this -> treasures.resize(neededTreasure);
	char treasureLetter = 'A';
	for(int i = 0; i < neededTreasure; i++)
	{
		this -> treasures[i] = new Treasure;
		this -> treasures[i] -> treasureState = Treasure::UNREACHED;
		this -> treasures[i] -> treasureName = treasureLetter;
		treasureLetter++;
	}
}

void GameInitializer::shuffleTreasures()
{
	std::random_shuffle(this -> treasures.begin(), this -> treasures.end());
}
