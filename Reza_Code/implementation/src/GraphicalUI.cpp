#include "../headers/GraphicalUI.h"
#include <QDebug>
#include <QDialog>

int GraphicalUI::initiateGame()
{
	std::string mapPath = std::string("maps/default.ejm");
	int playerCount = 0;
    std::vector<std::string> playerNames;
    
    //Loading a map should be implemented here
    QDialog dialog;
    mainWindow = new MainWindow(playerNames, &dialog);
    mainWindow -> setAttribute(Qt::WA_DeleteOnClose);
    QObject::connect(mainWindow, &QMainWindow::destroyed, &dialog, &QDialog::accept);
    mainWindow -> show();
    dialog.exec();
	playerCount = playerNames.size();
	 
    gameScreen = new GameScreen;
    gameScreen -> show();
	
	GameInitializer gameInitor(mapPath, playerCount, 0, 0, this);
	
	return 0;
}

bool GraphicalUI::diceRollPermission()
{
    return this -> gameScreen -> diceRollPermission();
}

void GraphicalUI::announceDice(int diceValue1, int diceValue2, std::string playerName)
{
    return this -> gameScreen -> announceDice(diceValue1, diceValue2);
}

void GraphicalUI::expressNewRound(int roundCount, char treasureName)
{
    return this -> gameScreen -> expressNewRound(roundCount, treasureName);
}

void GraphicalUI::expressTreasureChange(int roundCount, char treasureName)
{
    return this -> gameScreen -> expressTreasureChange(roundCount, treasureName);
}

void GraphicalUI::updatePlayerPositions(std::map<std::string, int> &playersPosition)
{
    return this -> gameScreen -> updatePlayerPositions(playersPosition);
}

void GraphicalUI::declareReset(std::string playerName)
{
    return this -> gameScreen -> declareReset(playerName);
}

void GraphicalUI::playerWonRound(std::string playerName, int treasureLocation, char treasureName)
{
    return this -> gameScreen -> playerWonRound(playerName, treasureLocation, treasureName);
}

void GraphicalUI::showTreasureTo(std::string playerName, char treasureName, int cellNumber)
{
    return this -> gameScreen -> showTreasureTo(playerName, treasureName, cellNumber);
}

int GraphicalUI::askForUserChoice(UI::OptionList optionList)
{
    return this -> gameScreen -> askForUserChoice(optionList);
}
