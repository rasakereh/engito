#include "../misc/safeInclusion.cpp"

#ifndef ROBOTPLAYER_H
#define ROBOTPLAYER_H

#include "../headers/Player.h"

class RobotPlayer : public Player
{
	private:
		std::pair<Dice::DiceResult, Dice::DiceResult> rollDice();
		void playDice();
		
	public:
		void takeDice();
		void releaseDice();
		CellDecision *selectOption(std::vector <CellDecision *> &decisionList);
		DiceDecision *selectOption(std::vector <DiceDecision *> &decisionList);
		std::string const &getPlayerName();
		
	protected:
};

#endif
