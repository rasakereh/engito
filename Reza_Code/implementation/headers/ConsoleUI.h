#include "../misc/safeInclusion.cpp"

#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include <iostream>
#include <cstdio>
#include "../headers/UI.h"
#include "../headers/GameInitializer.h"

class ConsoleUI : public UI
{
	friend class GameRuler;
	private:
		
	public:
		bool diceRollPermission();
		int initiateGame();
		void announceDice(int diceValue1, int diceValue2, std::string playerName);
		void expressNewRound(int roundCount, char treasureName);
		void expressTreasureChange(int roundCount, char treasureName);
		void updatePlayerPositions(std::map<std::string, int> &);
		void declareReset(std::string playerName);
		void playerWonRound(std::string playerName, int treasureLocation, char treasureName);
		void showTreasureTo(std::string playerName, char treasureName, int cellNumber);
		int askForUserChoice(UI::OptionList);
        std::pair<int, int> askUserForDice();
		
	protected:
};

#endif
