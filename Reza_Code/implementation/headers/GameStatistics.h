#include "../misc/safeInclusion.cpp"

#ifndef GAMESTATISTICS_H
#define GAMESTATISTICS_H

#include <algorithm>

#include "../headers/Dice.h"
#include "../headers/NetworkPlayer.h"
#include "../headers/RealPlayer.h"
#include "../headers/RobotPlayer.h"
#include "../headers/Decision.h"

class GameStatistics
{
	friend class Game;
	friend class GameRuler;
	friend class GameInitializer;
	private:
		Game *ownerGame;
		int roundCounter;
		bool playerMadeChoice;
		TreasureCell *roundGoalTreasure;
		Dice::DiceResult diceResult[2];
		std::vector <Player *> players;
		Decision *activePlayerDecision;
		void turnDone();
		void changeGoalTreasure(bool collected, bool announce);
		void passRound();
		void giveAnotherChance();
		
	public:
		GameStatistics(std::vector<std::string> realPlayers, std::vector<std::string> networkPlayers, std::vector<std::string> robotPlayers);
		void informAboutDice(Dice::DiceResult diceResult1, Dice::DiceResult diceResult2);
		Player *getActivePlayer();
		void syncPlayersPositions();
		void resetPlayer(Player *player);
		void rememberPlayerChoice(Decision *playerChoice);
		Decision *retrievePlayerChoice();
		int getRoundCount();
		void expressNewRound();
		
	protected:
};

#endif
