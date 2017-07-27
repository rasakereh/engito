#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class GameScreen;
}

class GraphicalUI;

class GameScreen : public QMainWindow
{
    Q_OBJECT
    
    friend class GraphicalUI;
    
public:
    explicit GameScreen(QWidget *parent = 0);
    void announceDice(int diceValue1, int diceValue2);
    void expressNewRound(int roundCount, char treasureName);
    void expressTreasureChange(int roundCount, char treasureName);
    void updatePlayerPositions(std::map<std::string, int>);
    void declareReset(std::string playerName);
    void playerWonRound(std::string playerName, int treasureLocation, char treasureName);void GraphicalUI::showTreasureTo(std::string playerName, char treasureName, int cellNumber);
    int askForUserChoice(UI::OptionList optionList);
    
    
    ~GameScreen();
    
private:
    Ui::GameScreen *ui;
    QWidget *popupWindow;
    
    void showPopupMessage(QString, int);
};

#endif // GAMESCREEN_H
