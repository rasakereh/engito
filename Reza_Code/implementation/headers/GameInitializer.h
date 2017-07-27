#ifndef GAMEINITIALIZER_H
#define GAMEINITIALIZER_H

#include <algorithm>
#include <string>
#include "../headers/Game.h"

class GameInitializer
{
	friend class UI;
	friend class ConsoleUI;
    friend class GraphicalUI;
	
	private:
		std::vector<Treasure *> treasures;
		Dice *gameDice;
		MapLoader *gameMap;
		GameBoard *gameBoard;
		GameRuler *gameRuler;
		GameStatistics *gameStat;
		UI *gameUI;
		Game *initiatedGame;
		void locateTreasures();
		void defineTreasures();
		void shuffleTreasures();
		void assembleGameBoard(std::string mapPath);
		void composeGame(std::string mapPath, int realPlayerCount, int networkPlayerCount, int robotPlayerCount);
		void locatePlayers();
		GameInitializer(std::string mapPath, int realPlayerCount, int networkPlayerCount, int robotPlayerCount, UI *caller);
		
	public:
		
	protected:
};

#endif
