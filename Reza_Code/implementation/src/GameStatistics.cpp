#include "../headers/GameStatistics.h"

GameStatistics::GameStatistics(std::vector<std::string> realPlayers, std::vector<std::string> networkPlayers, std::vector<std::string> robotPlayers)
{
	this -> roundCounter = 0;
	this -> playerMadeChoice = false;
	this -> activePlayerDecision = nullptr;
	
	for(int i = 0; i < realPlayers.size(); i++)
	{
		RealPlayer *newPlayer = new RealPlayer;
		newPlayer -> playerName = realPlayers[i];
		this -> players.push_back(newPlayer);
	}
	for(int i = 0; i < networkPlayers.size(); i++)
	{
		NetworkPlayer *newPlayer = new NetworkPlayer;
		newPlayer -> playerName = networkPlayers[i];
		this -> players.push_back(newPlayer);
	}
	for(int i = 0; i < robotPlayers.size(); i++)
	{
		RobotPlayer *newPlayer = new RobotPlayer;
		newPlayer -> playerName = robotPlayers[i];
		this -> players.push_back(newPlayer);
	}
}

void GameStatistics::changeGoalTreasure(bool collected, bool announce)
{
	if(collected)
	{
		this -> roundGoalTreasure -> cellTreasure -> treasureState = Treasure::COLLECTED;
		this -> ownerGame -> gameUI -> playerWonRound(this -> getActivePlayer() -> getPlayerName(), this -> roundGoalTreasure -> getCellNumber(), this -> roundGoalTreasure -> cellTreasure -> treasureName);
	}
	std::vector<TreasureCell *> const allTreasureCells = this -> ownerGame -> gameBoard -> getTreasureCells();
	std::vector<TreasureCell *> unreachedTreasures;
	unreachedTreasures.resize(allTreasureCells.size());
	auto lastCopiedCell = std::copy_if(allTreasureCells.begin(), allTreasureCells.end(), unreachedTreasures.begin(), [&](TreasureCell *cell) -> bool{return (cell -> cellTreasure -> treasureState == Treasure::UNREACHED);});
	unreachedTreasures.resize(std::distance(unreachedTreasures.begin(), lastCopiedCell));
	int randomTreasure = rand() % unreachedTreasures.size();
	this -> roundGoalTreasure = unreachedTreasures[randomTreasure];
	
	if(announce == true)
	{
		this -> ownerGame -> gameUI -> expressTreasureChange(this -> roundCounter, this -> roundGoalTreasure -> cellTreasure -> treasureName);
	}
}

void GameStatistics::expressNewRound()
{
	this -> ownerGame -> gameUI -> expressNewRound(this -> roundCounter, this -> roundGoalTreasure -> cellTreasure -> treasureName);
}

int GameStatistics::getRoundCount()
{
	return this -> roundCounter;
}

void GameStatistics::passRound()
{
	this -> roundCounter++;
	this -> changeGoalTreasure(true, false);
	this -> expressNewRound();
	
}

Player *GameStatistics::getActivePlayer()
{
	Player *activePlayer = *(this -> players.begin());
	return activePlayer;
}

void GameStatistics::turnDone()
{
	Player *activePlayer = *(this -> players.begin());
	this -> players.erase(this -> players.begin());
	this -> players.push_back(activePlayer);
	this -> playerMadeChoice = false;
}

void GameStatistics::rememberPlayerChoice(Decision *playerChoice)
{
	this -> activePlayerDecision = playerChoice;
	this -> playerMadeChoice = true;
}

Decision *GameStatistics::retrievePlayerChoice()
{
	if(this -> playerMadeChoice)
	{
		return this -> activePlayerDecision;
	}
	return nullptr;
}

void GameStatistics::informAboutDice(Dice::DiceResult diceResult1, Dice::DiceResult diceResult2)
{
	this -> ownerGame -> gameUI -> announceDice(diceResult1.diceValue, diceResult2.diceValue, this -> getActivePlayer() -> getPlayerName());
	this -> diceResult[0] = diceResult1;
	this -> diceResult[1] = diceResult2;
}

void GameStatistics::syncPlayersPositions()
{
	std::map<std::string, int> positioningData;
	for(auto it = this -> players.begin(); it != this -> players.end(); it++)
	{
		positioningData[(*it) -> getPlayerName()] = (*it) -> location -> getCellNumber();
	}
	this -> ownerGame -> gameUI -> updatePlayerPositions(positioningData);
}

void GameStatistics::giveAnotherChance()
{
	auto lastPlayerHandle = (this -> players.end() - 1);
	Player *lastPlayer = *lastPlayerHandle;
	this -> players.erase(lastPlayerHandle);
	this -> players.insert(this -> players.begin(), lastPlayer);
}

void GameStatistics::resetPlayer(Player *player)
{
	this -> ownerGame -> gameUI -> declareReset(player -> getPlayerName());
}

const std::vector<Player *> &GameStatistics::getAllPlayers()
{
    return this -> players;
}
