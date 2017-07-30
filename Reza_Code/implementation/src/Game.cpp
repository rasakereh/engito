#include "../headers/Game.h"

Game::Game(GameBoard *gameBoard, GameRuler *gameRuler, GameStatistics *gameStat, UI *gameUI)
{
	// Seeding for the sake of dice and shuffling
	srand(time(nullptr));
	this -> gameBoard = gameBoard;
	this -> gameBoard -> ownerGame = this;
	this -> gameRuler = gameRuler;
	this -> gameRuler -> ownerGame = this;
	this -> gameStat = gameStat;
	this -> gameStat -> ownerGame = this;
	std::for_each(this -> gameStat -> players.begin(), this -> gameStat -> players.end(), [&](Player *player){player -> activeGame = this;});
	this -> gameUI = gameUI;
    
    if(dynamic_cast<GraphicalUI *>(this -> gameUI))
        translator.translateBoardToUI(dynamic_cast<GraphicalUI *>(this -> gameUI), this -> gameBoard);
    else if(dynamic_cast<ConsoleUI *>(this -> gameUI))
        translator.translateBoardToUI(dynamic_cast<ConsoleUI *>(this -> gameUI), this -> gameBoard);
}
