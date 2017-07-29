#include "../headers/ConsoleUI.h"

int ConsoleUI::initiateGame()
{
	int const MIN_PLAYER_COUNT = 2, MAX_PLAYER_COUNT = 4;
	
	std::string mapPath = std::string("maps/default.ejm");
    int playerCount = 0;
	std::vector<std::string> players;
	
	if(false)
	{
		std::cin >> mapPath;
	}
	while(playerCount < MIN_PLAYER_COUNT || playerCount > MAX_PLAYER_COUNT)
	{
		std::cout << "How many players are going to play?" << std::endl;
		std::cin >> playerCount;
	}
	
	GameInitializer gameInitor(mapPath, players, std::vector<std::string>(), std::vector<std::string>(), this);
	
	return 0;
}

bool ConsoleUI::diceRollPermission()
{
	char permission = 0;
	while(permission != 'R' && permission != 'r')
	{
		std::cout << "Enter R/r to roll the dice!" << std::endl;
		std::cin >> permission;
	}
	return true;
}

void ConsoleUI::expressNewRound(int roundCount, char treasureName)
{
	std::cout << "Round number " << roundCount << " started, this round's goal treasure is " << treasureName << std::endl;
}

void ConsoleUI::expressTreasureChange(int roundCount, char treasureName)
{
	std::cout << "Round number " << roundCount << ", this round's goal treasure has changed to " << treasureName << std::endl;
}

void ConsoleUI::announceDice(int diceValue1, int diceValue2, std::string playerName)
{
	std::cout << "Dice Numbers for " << playerName << ": " << diceValue1 << " " << diceValue2 << std::endl;
}

int ConsoleUI::askForUserChoice(UI::OptionList optionList)
{
	int playerInput = 0;
	std::cout << optionList.listTitle << std::endl;
	for(int i = 1; i <= optionList.options.size(); i++)
	{
		std::cout << i << ". " << optionList.options[i - 1] << std::endl;
	}
	while(playerInput < 1 || playerInput > optionList.options.size())
	{
		std::cin >> playerInput;
	}
	return (playerInput - 1);
}

void ConsoleUI::updatePlayerPositions(std::map<std::string, int> &playersPositionData)
{
	std::cout << "Current Positions:";
	for(auto it = playersPositionData.begin(); it != playersPositionData.end(); it++)
	{
		std::cout << " " << it -> first << "->" << it -> second;
	}
	std::cout << std::endl;
}

void ConsoleUI::showTreasureTo(std::string playerName, char treasureName, int cellNumber)
{
	std::cout << "Cell " << cellNumber << "'s treasure as seen by " << playerName << " is " << treasureName << std::endl;
}

void ConsoleUI::declareReset(std::string playerName)
{
	std::cout << playerName << " is moved to Blue cells." << std::endl;
}

void ConsoleUI::playerWonRound(std::string playerName, int treasureLocation, char treasureName)
{
	std::cout << playerName << "’s guess, " << treasureLocation << ", was correct and he/she has won this round's goal treasure, " << treasureName << std::endl;
}
