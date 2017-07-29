#include <QDialogButtonBox>
#include <QDialog>
#include <QInputDialog>
#include <QCheckBox>
#include <QFormLayout>
#include <QPushButton>
#include <QVBoxLayout>

#include "GameScreen.h"

GameScreen::GameScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameScreen), randomForEver(false), customForEver(false)
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
    bool permit = false;
    if((randomForEver || customForEver) == false)
    {
        QDialog askForPermission(this);
        askForPermission.setWindowModality(Qt::ApplicationModal);
        QFormLayout *layout = new QFormLayout(&askForPermission);
        layout -> addRow(new QLabel("Do you want to use custom dice?", &askForPermission));
        QDialogButtonBox buttonBox(QDialogButtonBox::Yes | QDialogButtonBox::No,
                                  Qt::Horizontal, &askForPermission);
        layout -> addRow(&buttonBox);
        QCheckBox *rememberChoice = new QCheckBox(&askForPermission);
        rememberChoice -> setText("Remember my choice");
        layout->addRow(rememberChoice);
        QObject::connect(&buttonBox, SIGNAL(accepted()), &askForPermission, SLOT(accept()));
        QObject::connect(&buttonBox, SIGNAL(rejected()), &askForPermission, SLOT(reject()));
        int customPermission = askForPermission.exec();
        permit = (customPermission == QDialog::Rejected);
        if(rememberChoice->checkState() == Qt::Checked)
        {
            randomForEver = permit;
            customForEver = !permit;
        }
    }
    
    return permit;
}

std::pair<int, int> GameScreen::askUserDice()
{
    int firstDie, secondDie;
    bool ok = false;
    do
    {
        firstDie = QInputDialog::getInt(this, "First Die", "Enter First Die:", 1, 1, 6, 1, &ok);
    }while(ok == false);
    
    do
    {
        secondDie = QInputDialog::getInt(this, "Second Die", "Enter Second Die:", 1, 1, 6, 1, &ok);
    }while(ok == false);
    
    return std::make_pair(firstDie, secondDie);
}

void GameScreen::showTreasureTo(std::string playerName, char treasureName, int cellNumber)
{
    this -> showPopupMessage("Cheshato beband amoo bebine, plz!", 1000);
    this -> showPopupMessage(QString("Amoo, bebine:\n\t%1 injast!").arg(treasureName), 1000);
}

int GameScreen::askForUserChoice(UI::OptionList optionList, int *answer, bool *readyState)
{
    QWidget *qwin = new QWidget(this);
    for(int i = 0; i < optionList.options.size(); i++)
    {
        QPushButton *btn = new QPushButton(QString("%1").arg(i + 1), qwin);
        btn->move(i*10, i*10);
        connect(btn, &QPushButton::clicked, [&, i](){*answer = i + 1; *readyState = true;});
    }
    qwin->show();
}

GameScreen::~GameScreen()
{
    delete ui;
}
