#include "../misc/safeInclusion.cpp"

#ifndef MAPLOADER_H
#define MAPLOADER_H

#include <cstdio>
#include <map>

#include "../headers/DecisionCell.h"
#include "../headers/InitialCell.h"
#include "../headers/OrdinaryCell.h"
#include "../headers/TransportCell.h"
#include "../headers/TreasureCell.h"
#include "../headers/BoardCell.h"


class MapLoader
{
	private:
		std::string lastError;
		std::vector<BoardCell *> allCells;					//boardCells["allCells"]
		std::vector<InitialCell *> initialCells;			//boardCells["initialCells"]
		std::vector<TreasureCell *> treasureCells;			//boardCells["treasureCells"]
		std::vector<DecisionCell *> decisionCells;			//boardCells["decisionCells"]
		std::vector<TransportCell *> transportCells;		//boardCells["transportCells"]
		BoardCell *firstCell;
		
	public:
		MapLoader(std::string);
		std::string const &getLastError();
		std::vector<BoardCell *> const &getAllCells();
        std::vector<InitialCell *> const &getInitialCells();
        std::vector<DecisionCell *> const &getDecisionCells();
		std::vector<TransportCell *> const &getTransportCells();
		std::vector<TreasureCell *> const &getTreasureCells();
		BoardCell *getFirstCell();
		
	protected:
};

#endif
