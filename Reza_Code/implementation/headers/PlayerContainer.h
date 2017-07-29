#include "../misc/safeInclusion.cpp"

#ifndef PLAYERCONTAINER_H
#define PLAYERCONTAINER_H

#include <QWidget>

#include "Player.h"

class PlayerContainer : public QLabel
{
public:
    PlayerContainer(QWidget *parent = 0);
    Player *content;
    QString view;
};

#endif // PLAYERCONTAINER_H
