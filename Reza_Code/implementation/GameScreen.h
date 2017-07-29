#include "ui_GameScreen.h"
#include "misc/SafeInclusion.cpp"

#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class GameScreen;
}

//class GraphicalUI;

class GameScreen : public QMainWindow
{   
    //Q_OBJECT
    friend class BoardToGUI;
public:
    
    explicit GameScreen(QWidget *parent = 0);
    bool diceRollPermission();
    void announceDice(int diceValue1, int diceValue2);
    void expressNewRound(int roundCount, char treasureName);
    void expressTreasureChange(int roundCount, char treasureName);
    void updatePlayerPositions(std::map<std::string, int> &);
    void declareReset(std::string playerName);
    void playerWonRound(std::string playerName, int treasureLocation, char treasureName);
    void showTreasureTo(std::string playerName, char treasureName, int cellNumber);
    int askForUserChoice(UI::OptionList optionList, int *answer, bool *readyState);
    std::pair<int, int> askUserDice();
    
    virtual ~GameScreen();
    
private:
    Ui::GameScreen *ui;
    QWidget *popupWindow;
    bool randomForEver;
    bool customForEver;
    
    void showPopupMessage(QString, int);
};

#endif // GAMESCREEN_H
