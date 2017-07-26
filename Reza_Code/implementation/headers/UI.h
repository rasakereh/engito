#include "../misc/safeInclusion.cpp"

#ifndef UI_H
#define UI_H

#include <map>
#include <string>

#include "../headers/Game.h"

class UI
{
	friend class GameRuler;
	friend class GameStatistics;
	private:
		virtual void updatePlayerPositions(std::map<std::string, int>) = 0;
		
	public:
		struct OptionList
		{
			std::string listTitle;
			std::vector<std::string> options;
		};
		virtual bool diceRollPermission() = 0;
		virtual int initiateGame() = 0;
		virtual void announceDice(int diceValue1, int diceValue2, std::string playerName) = 0;
		virtual void expressNewRound(int roundCount, char treasureName) = 0;
		virtual void expressTreasureChange(int roundCount, char treasureName) = 0;
		virtual void declareReset(std::string playerName) = 0;
		virtual void playerWonRound(std::string playerName, int treasureLocation, char treasureName) = 0;
		virtual void showTreasureTo(std::string playerName, char treasureName, int cellNumber) = 0;
		virtual int askForUserChoice(UI::OptionList) = 0;
		
	protected:
};

#endif
