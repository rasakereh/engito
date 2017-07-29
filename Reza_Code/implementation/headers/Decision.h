#include "../misc/safeInclusion.cpp"

#ifndef DECISION_H
#define DECISION_H

#include "../headers/Dice.h"

class Decision
{
	public:
		std::vector<Dice::DiceResult *> envokers;
		virtual std::string getUIString() = 0;
		virtual std::string getType() = 0;
		BoardCell *destination;
		
		
	protected:
};

#endif
