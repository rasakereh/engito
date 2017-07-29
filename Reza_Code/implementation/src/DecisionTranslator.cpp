#include "../headers/DecisionTranslator.h"

CellDecision *DecisionTranslator::getDecisionFromUI(std::vector<CellDecision *> &availableOptions, UI *gameUI, Player *player)
{
	UI::OptionList optionList;
	std::ostringstream input;
	input << player -> location -> getCellNumber();
	optionList.listTitle = player -> getPlayerName() + " is in " + input.str() + "(Red), and can attempt to guess goal treasure's place:";
	optionList.options.push_back("I don't want to guess");
	for(int i = 1; i <= availableOptions.size(); i++)
	{
		std::string optionString = availableOptions[i - 1] -> getUIString();
		optionList.options.push_back(optionString);
	}
	int playerChoice = gameUI -> askForUserChoice(optionList);
	if(playerChoice == 0)
	{
		return nullptr;
	}
	else
	{
		return availableOptions[playerChoice - 1];
	}
}

DiceDecision *DecisionTranslator::getDecisionFromUI(std::vector<DiceDecision *> &availableOptions, UI *gameUI)
{
	UI::OptionList optionList;
	std::vector<DiceDecision *> distinctOptions;
	optionList.listTitle = "Player(name) Choices:";
	for(int i = 1; i <= availableOptions.size(); i++)
	{
		std::string optionString = availableOptions[i - 1] -> getUIString();
		if(std::find(optionList.options.begin(), optionList.options.end(), optionString) == optionList.options.end())
		{
			distinctOptions.push_back(availableOptions[i - 1]);
			optionList.options.push_back(optionString);
		}
	}
	int playerChoice = gameUI -> askForUserChoice(optionList);
	return distinctOptions[playerChoice];
}
