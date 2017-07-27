#ifndef GAME_H
#define GAME_H

#include <cstdlib>
#include <ctime>

#include "../misc/safeInclusion.cpp"
#include "../headers/ConsoleUI.h"
#include "../headers/GameBoard.h"
#include "../headers/GameRuler.h"
#include "../headers/GameStatistics.h"
#include "../headers/BoardToGUI.h"

class Game
{
	public:
		GameBoard *gameBoard;
		GameRuler *gameRuler;
		GameStatistics *gameStat;
		UI *gameUI;
        BoardToGUI translator;
		
		Game(GameBoard *gameBoard, GameRuler *gameRuler, GameStatistics *gameStat, UI *gameUI);
		
	protected:
};

#endif
