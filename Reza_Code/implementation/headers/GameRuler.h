#include "../misc/safeInclusion.cpp"

#ifndef GAMERULER_H
#define GAMERULER_H

#include "../headers/Game.h"
#include "../headers/DiceDecision.h"
#include "../headers/CellDecision.h"
#include "../headers/RealPlayer.h"
#include "../headers/NetworkPlayer.h"
#include "../headers/RobotPlayer.h"
#include "../headers/Player.h"
#include "../headers/DecisionTranslator.h"

class GameRuler
{
	friend class Game;
	friend class GameInitializer;
	private:
		typedef enum {NO_GUESS, WRONG_GUESS, CORRECT_GUESS} GuessResult;
		Game *ownerGame;
		
		void assignDice();
		void applyPlayerChoice();
		void playerGotRed();
		void takeDiceBack();
		void runCurrentTurn();
		void keepGameAlive();
		bool isGameFinished();
		GuessResult checkGuess(CellDecision *decision);
		
	public:
		std::vector<Decision *> evaluateOptionList();
		std::vector<CellDecision *> getCellDecisionList();
        void setDice(std::pair<int, int> diceValues);
		
	protected:
};

#endif
