#include "../misc/safeInclusion.cpp"

#ifndef PLAYER_H
#define PLAYER_H

#include <utility>
#include "../headers/BoardCell.h"
#include "../headers/Dice.h"
#include "../headers/Decision.h"
#include "../headers/Game.h"
#include "../headers/DecisionTranslator.h"

class Player
{
	friend class GameStatistics;
	private:
		virtual std::pair<Dice::DiceResult, Dice::DiceResult> rollDice() = 0;
		virtual void playDice() = 0;
		
	public:
		Game *activeGame;
		virtual std::string const &getPlayerName() = 0;
		virtual void takeDice() = 0;
		virtual void releaseDice() = 0;
		virtual CellDecision *selectOption(std::vector <CellDecision *> &decisionList) = 0;
		virtual DiceDecision *selectOption(std::vector <DiceDecision *> &decisionList) = 0;
		BoardCell *location;
	
	protected:
		std::string playerName;
};

#endif
