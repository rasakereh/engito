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
//  #define __CONSOLE__
    #define __GRAPHIC__
    QApplication app(argc, argv);
    
    GraphicalUI gameUI;
    gameUI.initiateGame();
    
	return app.exec();
}
