#include "GameScreen.h"
#include "ui_GameScreen.h"

GameScreen::GameScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameScreen)
{
    ui->setupUi(this);
}

GameScreen::~GameScreen()
{
    delete ui;
}
