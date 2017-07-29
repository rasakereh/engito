#include "misc/SafeInclusion.cpp"

#ifndef GRAPHICALUI_H
#define GRAPHICALUI_H

#include <string>
#include <vector>

#include "UI.h"
#include "../MainWindow.h"
#include "../GameScreen.h"

class GraphicalUI: public UI
{
friend class GameRuler;

public:
    int initiateGame();
    bool diceRollPermission();
    void announceDice(int diceValue1, int diceValue2, std::string playerName);
    void expressNewRound(int roundCount, char treasureName);
    void expressTreasureChange(int roundCount, char treasureName);
    void updatePlayerPositions(std::map<std::string, int> &);
    void declareReset(std::string playerName);
    void playerWonRound(std::string playerName, int treasureLocation, char treasureName);
    void showTreasureTo(std::string playerName, char treasureName, int cellNumber);
    int askForUserChoice(UI::OptionList);
    std::pair<int, int> askUserForDice();
    
private:
    MainWindow *mainWindow;
    GameScreen *gameScreen;
    
};

#endif // GRAPHICALUI_H
