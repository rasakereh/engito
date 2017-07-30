#include <QDebug>

#include <QApplication>
#include <iostream>
#include "headers/ConsoleUI.h"
#include "headers/GraphicalUI.h"
#include "GameScreen.h"

int main(int argc, char** argv)
{
//	ConsoleUI gameUI;
//	gameUI.initiateGame();
//  #define __CONSOLE__ 1
    #define __GRAPHIC__ 1
    QApplication app(argc, argv);
    
    GraphicalUI gameUI;
    gameUI.initiateGame();
    
	return app.exec();
}
