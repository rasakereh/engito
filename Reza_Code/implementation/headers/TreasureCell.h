#include "../misc/safeInclusion.cpp"

#ifndef TREASURECELL_H
#define TREASURECELL_H

#include "../headers/BoardCell.h"
#include "../headers/Treasure.h"

class TreasureCell : public BoardCell
{
	friend class GameInitializer;
	friend class GameStatistics;
	private:
		Treasure *cellTreasure;
		
	public:
		void setMyColor();
		const Treasure* getCellTreasure();
		
	protected:
};

#endif
