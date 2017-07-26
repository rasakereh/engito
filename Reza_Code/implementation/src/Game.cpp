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
}
