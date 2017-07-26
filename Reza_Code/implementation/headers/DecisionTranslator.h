#include "../misc/safeInclusion.cpp"

#ifndef DECISIONTRANSLATOR_H
#define DECISIONTRANSLATOR_H

#include <string>
#include <sstream>

#include "../headers/ConsoleUI.h"
#include "../headers/CellDecision.h"
#include "../headers/DiceDecision.h"

class DecisionTranslator
{
	private:
		
		
	public:
		CellDecision *getDecisionFromUI(std::vector<CellDecision *> &availableOptions, UI *gameUI, Player *player);
		DiceDecision *getDecisionFromUI(std::vector<DiceDecision *> &availableOptions, UI *gameUI);
		
		
	protected:
};

#endif
