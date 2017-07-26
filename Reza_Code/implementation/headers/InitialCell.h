#include "../misc/safeInclusion.cpp"

#ifndef INITIALCELL_H
#define INITIALCELL_H

#include "../headers/BoardCell.h"

class InitialCell : public BoardCell
{
	friend class GameInitializer;
	private:
		public:std::vector<Player *> otherOccupiers;
		
	public:
		void setMyColor();
		
	protected:
};

#endif
