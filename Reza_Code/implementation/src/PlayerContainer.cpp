#include "../headers/PlayerContainer.h"

PlayerContainer::PlayerContainer(QWidget *parent)
{
    
}

void PlayerContainer::loadImage()
{
    this -> setPixmap(QPixmap(QString(":/icon/players/player%1.png").arg(rand() % 4 + 1)));
}

void PlayerContainer::loadID()
{
    if(this -> content -> getPlayerName().length() >= 1)
    {
        this -> setText(QString("%1").arg(this -> content -> getPlayerName().at(0)));
    }
}

const std::string &PlayerContainer::getPlayerName()
{
    return this -> content -> getPlayerName();
}
