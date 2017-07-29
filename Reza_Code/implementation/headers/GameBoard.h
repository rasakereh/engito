#include "../misc/safeInclusion.cpp"

#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "../headers/MapLoader.h"
#include "../headers/DecisionCell.h"
#include "../headers/InitialCell.h"
#include "../headers/OrdinaryCell.h"
#include "../headers/TransportCell.h"
#include "../headers/TreasureCell.h"
#include "../headers/BoardCell.h"


class GameBoard
{
	friend class GameInitializer;
	friend class GameRuler;
	private:
        std::vector<BoardCell *> allCells;
		std::vector<InitialCell *> initialCells;
		std::vector<TreasureCell *> treasureCells;
		std::vector<DecisionCell *> decisionCells;
		std::vector<TransportCell *> transportCells;
		void loadInitialCells(std::vector<InitialCell *> const &initialCells);
		void loadTreasureCells(std::vector<TreasureCell *> const &treasureCells);
		void loadDecisionCells(std::vector<DecisionCell *> const &decisionCells);
		void loadTransportCells(std::vector<TransportCell *> const &transportCells);
		BoardCell *firstCell;
		
	public:
		Game *ownerGame;
		Dice *gameDice;
		void loadAllCells(std::vector<BoardCell *> const &allCells, std::vector<InitialCell *> const &initialCells, std::vector<TreasureCell *> const &treasureCells, 
							std::vector<DecisionCell *> const &decisionCells, std::vector<TransportCell *> const &transportCells, BoardCell *firstCell);
		std::vector<BoardCell *> const &getAllCells();
        std::vector<InitialCell *> const &getInitialCells();
		std::vector<TreasureCell *> const &getTreasureCells();
		std::vector<DecisionCell *> const &getDecisionCells();
		std::vector<TransportCell *> const &getTransportCells();
		
		
	protected:
};

#endif
