#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(std::vector<std::string> &playerNames, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this -> groupWidgets();
    this -> monitorEvents(playerNames);
}

void MainWindow::groupWidgets()
{
    lblPlayers.push_back(this -> ui -> lblPlayer1);
    lblPlayers.push_back(this -> ui -> lblPlayer2);
    lblPlayers.push_back(this -> ui -> lblPlayer3);
    lblPlayers.push_back(this -> ui -> lblPlayer4);
    
    txtPlayers.push_back(this -> ui -> txtPlayer1);
    txtPlayers.push_back(this -> ui -> txtPlayer2);
    txtPlayers.push_back(this -> ui -> txtPlayer3);
    txtPlayers.push_back(this -> ui -> txtPlayer4);
}

void MainWindow::monitorEvents(std::vector<std::string> &playerNames)
{
    connect(this -> ui -> btnGo, &QPushButton::clicked, [&](){this -> startGame(playerNames);});
}

void MainWindow::startGame(std::vector<std::string> &playerNames)
{
     for(int i = 0; i < this -> ui -> spinPlayerCount -> value(); i++)
    {
        this -> playerNames.push_back(this -> txtPlayers[i] -> text().toStdString());
    }
     getPlayerNames(playerNames);
}

void MainWindow::getPlayerNames(std::vector<std::string> &playerNames)
{
    playerNames = this -> playerNames;
}

MainWindow::~MainWindow()
{
    delete ui;
}
