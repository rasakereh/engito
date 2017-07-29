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
		void composeGame(std::string mapPath, std::vector<std::string> realPlayers, std::vector<std::string> networkPlayers, std::vector<std::string> robotPlayers);
		void locatePlayers();
		GameInitializer(std::string mapPath, std::vector<std::string> realPlayers, std::vector<std::string> networkPlayers, std::vector<std::string> robotPlayers, UI *caller);
		
	public:
		
	protected:
};

#endif
