#include "../headers/GraphicalUI.h"

int GraphicalUI::initiateGame()
{
    int const MIN_PLAYER_COUNT = 2, MAX_PLAYER_COUNT = 4;
	
	std::string mapPath = std::string("maps/default.ejm");
	int playerCount = 0;
    std::vector<std::string> playerNames;
    
    //Loading a map should be implemented here
    
    mainWindow = new MainWindow(playerNames);
    mainWindow -> exec();
	playerCount = playerNames.size();
	 
    gameScreen = new GameScreen;
    gameScreen -> show();
	
	GameInitializer gameInitor(mapPath, playerCount, 0, 0, this);
	
	return 0;
}

bool GraphicalUI::diceRollPermission()
{
    
}

void GraphicalUI::announceDice(int diceValue1, int diceValue2, std::string playerName)
{
    
}

void GraphicalUI::expressNewRound(int roundCount, char treasureName)
{
    
}

void GraphicalUI::expressTreasureChange(int roundCount, char treasureName)
{
    
}

void GraphicalUI::updatePlayerPositions(std::map<std::string, int>)
{
    
}

void GraphicalUI::declareReset(std::string playerName)
{
    
}

void GraphicalUI::playerWonRound(std::string playerName, int treasureLocation, char treasureName)
{
    
}

void GraphicalUI::showTreasureTo(std::string playerName, char treasureName, int cellNumber)
{
    
}

int GraphicalUI::askForUserChoice(UI::OptionList optionList)
{
    
}
