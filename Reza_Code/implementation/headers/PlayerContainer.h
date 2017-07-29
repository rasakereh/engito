#include "../misc/safeInclusion.cpp"

#ifndef PLAYERCONTAINER_H
#define PLAYERCONTAINER_H

#include <QWidget>

class PlayerContainer : public QLabel
{
public:
    PlayerContainer(QWidget *parent = 0);
};

#endif // PLAYERCONTAINER_H
