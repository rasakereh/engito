#include "GameScreen.h"
#include "ui_GameScreen.h"

GameScreen::GameScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameScreen)
{
    ui->setupUi(this);
    this -> setWindowTitle(tr("Enchanted Forest"));
}

void GameScreen::announceDice(int diceValue1, int diceValue2)
{
    this -> ui -> lblDice1 -> setPixmap(QPixmap(QString(":/icon/Dice/%1.png").arg(diceValue1)));
    this -> ui -> lblDice1 -> repaint();
    this -> ui -> lblDice2 -> setPixmap(QPixmap(QString(":/icon/Dice/%1.png").arg(diceValue2)));
    this -> ui -> lblDice2 -> repaint();
}

void GameScreen::expressNewRound(int roundCount, char treasureName)
{
    this -> ui -> lblCurrentRoundNumber -> setText(QString("%1").arg(roundCount));
    this -> ui -> lblCurrentTreasureName -> setText(QString("%1").arg(treasureName));
}

void GameScreen::expressTreasureChange(int roundCount, char treasureName)
{
    this -> showPopupMessage("There is a treasure change!", 1500);
    this -> ui -> lblCurrentRoundNumber -> setText(QString("%1").arg(roundCount));
    this -> ui -> lblCurrentTreasureName -> setText(QString("%1").arg(treasureName));
}

void GameScreen::showPopupMessage(QString message, int intervalMiliSec)
{
    this -> popupWindow = new QWidget(this);
    this -> popupWindow -> setAttribute(Qt::WA_DeleteOnClose);
    QLabel *popupMSG = new QLabel(message, this -> popupWindow);
    QTimer::singleShot(intervalMiliSec, this, [&](){this -> popupWindow -> close();});
}

void GameScreen::updatePlayerPositions(std::map<std::string, int> &playersPosition)
{
    
}

void GameScreen::declareReset(std::string playerName)
{
    this -> showPopupMessage(QString("%1 experiensed a reset!").arg(playerName.c_str()), 1500);
}

void GameScreen::playerWonRound(std::string playerName, int treasureLocation, char treasureName)
{
    
}

bool GameScreen::diceRollPermission()
{
    return true;
}

void GameScreen::showTreasureTo(std::string playerName, char treasureName, int cellNumber)
{
    this -> showPopupMessage("Cheshato beband amoo bebine, plz!", 1000);
    this -> showPopupMessage(QString("Amoo, bebine:\n\t%1 injast!").arg(treasureName), 1000);
}

int GameScreen::askForUserChoice(UI::OptionList optionList)
{
    
}

GameScreen::~GameScreen()
{
    delete ui;
}
