#include "../headers/GameRuler.h"

void GameRuler::assignDice()
{
	Player *activePlayer = this -> ownerGame -> gameStat -> getActivePlayer();
	activePlayer -> takeDice();
}

void GameRuler::takeDiceBack()
{
	Player *activePlayer = this -> ownerGame -> gameStat -> getActivePlayer();
	activePlayer -> releaseDice();
}

void GameRuler::keepGameAlive()
{
	while(!(this -> isGameFinished()))
	{
		this -> ownerGame -> gameStat -> syncPlayersPositions();
		this -> runCurrentTurn();
	}
}

void GameRuler::setDice(std::pair<int, int> diceValues)
{
    Dice::DiceResult diceResult1, diceResult2;
	diceResult1.diceValue = diceValues.first;
	diceResult1.diceState = Dice::PERMITTED;
	diceResult2.diceValue = diceValues.second;
	diceResult2.diceState = Dice::PERMITTED;
	this -> ownerGame -> gameStat -> informAboutDice(diceResult1, diceResult2);
}

void GameRuler::runCurrentTurn()
{
	this -> assignDice();
	this -> applyPlayerChoice();
	this -> takeDiceBack();
	this -> ownerGame -> gameStat -> turnDone();
}

std::vector<Decision *> GameRuler::evaluateOptionList()
{
	std::vector<Decision *> availableOptions;
	std::function<void (BoardCell *, bool, DiceDecision::DiceDecisionT)> convertToDecision = [&](BoardCell *cell, bool condition, DiceDecision::DiceDecisionT decisionType)
													{
														if(!condition)
															return ;
														DiceDecision *newDecision = new DiceDecision;
														newDecision -> diceDecisionType = decisionType;
														newDecision -> destination = cell;
														availableOptions.push_back(newDecision);
													};
	std::function<bool (BoardCell *)> noOneIsHere = [](BoardCell *cell){return cell -> getOccupier() == nullptr;};
	for(int i = 0; i < 2; i++)
	{
		if(this -> ownerGame -> gameStat -> diceResult[i].diceState == Dice::PERMITTED)
		{
			Player *activePlayer = this -> ownerGame -> gameStat -> getActivePlayer();
			std::vector<BoardCell *> possibleCells = activePlayer -> location -> passThrough(nullptr, this -> ownerGame -> gameStat -> diceResult[i].diceValue);
			auto prawlPusher = std::bind(convertToDecision, std::placeholders::_1, true, DiceDecision::PRAWL);
			std::for_each(possibleCells.begin(), possibleCells.end(), prawlPusher);
			//set envoker die
			std::for_each(availableOptions.begin(), availableOptions.end(), [&](Decision *dd){if(dd -> envokers.size() == 0) dd -> envokers.push_back(&this -> ownerGame -> gameStat -> diceResult[i]);});
		}
	}
	if(this -> ownerGame -> gameStat -> diceResult[0] == this -> ownerGame -> gameStat -> diceResult[1] && this -> ownerGame -> gameStat -> diceResult[0].diceState == Dice::PERMITTED)
	{
		// pushing empty orange cells to decision vector
		auto treasurePusher = std::bind(convertToDecision, std::placeholders::_1, bind(noOneIsHere, std::placeholders::_1), DiceDecision::MOVE_TO_ORANGE);
		std::for_each(this -> ownerGame -> gameBoard -> getTreasureCells().begin(), this -> ownerGame -> gameBoard -> getTreasureCells().end(), treasurePusher);
		
		// pushing empty violet cells to decision vector
		auto transportPusher = std::bind(convertToDecision, std::placeholders::_1, bind(noOneIsHere, std::placeholders::_1), DiceDecision::MOVE_TO_VIOLET);
		std::for_each(this -> ownerGame -> gameBoard -> getTransportCells().begin(), this -> ownerGame -> gameBoard -> getTransportCells().end(), transportPusher);
		
		DiceDecision *newDecision = new DiceDecision;
		newDecision -> destination = nullptr;
		newDecision -> diceDecisionType = DiceDecision::SWITCH_TREASURE;
		availableOptions.push_back(newDecision);

		//set envoker dice
		std::for_each(availableOptions.begin(), availableOptions.end(), [&](Decision *dd){if(dd -> envokers.size() == 0){dd -> envokers.push_back(&this -> ownerGame -> gameStat -> diceResult[0]);dd -> envokers.push_back(&this -> ownerGame -> gameStat -> diceResult[1]);}});
	}
	return availableOptions;
}

void GameRuler::applyPlayerChoice()
{
	const BoardCell::ColorRGB RED = {255, 0, 0}, BLUE = {0, 0, 255}, GREEN = {50, 255, 50}, ORANGE = {255, 140, 0}, PURPLE = {255, 0, 255};
	Decision *playerChoice = this -> ownerGame -> gameStat -> retrievePlayerChoice();
	if(playerChoice -> getType() == "CellDecision")
	{
		
	}
	else if(playerChoice -> getType() == "DiceDecision")
	{
		if(static_cast<DiceDecision *>(playerChoice) -> diceDecisionType == DiceDecision::SWITCH_TREASURE)
		{
			this -> ownerGame -> gameStat -> changeGoalTreasure(false, true);
		}
		else if(static_cast<DiceDecision *>(playerChoice) -> diceDecisionType != DiceDecision::NOT_SET)
		{
			playerChoice -> envokers[0] -> diceState = Dice::PLAYED;
			if(playerChoice -> envokers.size() == 2)
				playerChoice -> envokers[1] -> diceState = Dice::PLAYED;
			Player *activePlayer = this -> ownerGame -> gameStat -> getActivePlayer();
			Player *oldOccupier = static_cast<DiceDecision *>(playerChoice) -> destination -> inhabit(activePlayer);
			if(oldOccupier != nullptr)
			{
				this -> ownerGame -> gameBoard -> initialCells[0] -> inhabit(oldOccupier);
				this -> ownerGame -> gameStat -> resetPlayer(oldOccupier);
			}
			if(static_cast<DiceDecision *>(playerChoice) -> destination -> getColor() == RED)
			{
				this -> playerGotRed();
			}
			if(this -> ownerGame -> gameStat -> diceResult[0].diceState == Dice::PERMITTED
				||
				this -> ownerGame -> gameStat -> diceResult[1].diceState == Dice::PERMITTED)
			{
				std::vector<Decision *> primaryOptionList = this -> evaluateOptionList();
				std::vector<DiceDecision *> optionList(primaryOptionList.size(), nullptr);
				std::transform(primaryOptionList.begin(), primaryOptionList.end(), optionList.begin(), [](Decision *option) -> DiceDecision *{return static_cast<DiceDecision *>(option);});
				activePlayer -> selectOption(optionList);
				this -> applyPlayerChoice();
			}
		}
	}
}

void GameRuler::playerGotRed()
{
	GameRuler::GuessResult guessResult;
	Player *activePlayer = this -> ownerGame -> gameStat -> getActivePlayer();
	std::vector<CellDecision *> optionList = this -> getCellDecisionList();
	CellDecision* playerGuess = activePlayer -> selectOption(optionList);
	guessResult = this -> checkGuess(playerGuess);
	if(guessResult == GameRuler::NO_GUESS)
	{
		return ;
	}
	while(guessResult == GameRuler::CORRECT_GUESS)
	{
		optionList = this -> getCellDecisionList(); // we can both set the function to retrieve only non-collected treasures or a complete list of them
		playerGuess = activePlayer -> selectOption(optionList);
		guessResult = this -> checkGuess(playerGuess);
	}
	if(guessResult == GameRuler::WRONG_GUESS)
	{
		this -> ownerGame -> gameBoard -> initialCells[0] -> inhabit(activePlayer);
		this -> ownerGame -> gameStat -> resetPlayer(activePlayer);
	}
	else if(guessResult == GameRuler::NO_GUESS)
	{
		this -> ownerGame -> gameStat -> giveAnotherChance();
	}
}

std::vector<CellDecision *> GameRuler::getCellDecisionList()
{
	std::vector<CellDecision *> availableOptions;
	std::function<void (BoardCell *)> treasurePusher = [&](BoardCell *cell)
													{
														CellDecision *newDecision = new CellDecision;
														newDecision -> destination = cell;
														availableOptions.push_back(newDecision);
													};
	std::for_each(this -> ownerGame -> gameBoard -> getTreasureCells().begin(), this -> ownerGame -> gameBoard -> getTreasureCells().end(), treasurePusher);
	return availableOptions;
}

GameRuler::GuessResult GameRuler::checkGuess(CellDecision *decision)
{
	if(decision == nullptr)
		return GameRuler::NO_GUESS;
	if(this -> ownerGame -> gameStat -> diceResult[0].diceState == Dice::PERMITTED)
		this -> ownerGame -> gameStat -> diceResult[0].diceState = Dice::CANCLED;
	if(this -> ownerGame -> gameStat -> diceResult[1].diceState == Dice::PERMITTED)
		this -> ownerGame -> gameStat -> diceResult[1].diceState = Dice::CANCLED;
	if(this -> ownerGame -> gameStat -> roundGoalTreasure == decision -> destination)
	{
		this -> ownerGame -> gameStat -> passRound();
		return GameRuler::CORRECT_GUESS;
	}
	else
	{
		return GameRuler::WRONG_GUESS;
	}
}

bool GameRuler::isGameFinished()
{
	return false;
}
