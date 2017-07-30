#include "../misc/safeInclusion.cpp"

#ifndef PLAYERCONTAINER_H
#define PLAYERCONTAINER_H

#include <QWidget>

#include "Player.h"

class PlayerContainer : public QLabel
{
private:
    void loadImage();
    void loadID();
    
public:
    PlayerContainer(QWidget *parent = 0);
    Player *content;
    QString view;
    std::string const &getPlayerName();
};

#endif // PLAYERCONTAINER_H
