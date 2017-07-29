#include "../misc/safeInclusion.cpp"

#ifndef DICEDECISION_H
#define DICEDECISION_H

#include <sstream>

#include "../headers/Decision.h"

class DiceDecision : public Decision
{
	public:
		typedef enum{NOT_SET, PRAWL, MOVE_TO_ORANGE, MOVE_TO_VIOLET, SWITCH_TREASURE} DiceDecisionT;
		DiceDecisionT diceDecisionType;
		
		std::string getUIString();
		std::string getType();
		
	protected:
};

#endif
