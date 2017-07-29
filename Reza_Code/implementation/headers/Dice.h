#include "../misc/safeInclusion.cpp"

#ifndef DICE_H
#define DICE_H

#include <cstdlib>
#include <utility>

#include "../headers/GameBoard.h"

class Dice
{
	friend class GameInitializer;
	public:
		typedef enum{PERMITTED, PLAYED, CANCLED} DiceState;
	
	private:
		GameBoard *gameBoard;
		
	public:
		struct DiceResult
		{
			int diceValue;
			Dice::DiceState diceState;
			bool operator==(Dice::DiceResult const &counterDice);
		};
		std::pair <Dice::DiceResult, Dice::DiceResult> roll();
		
	protected:
};

#endif
