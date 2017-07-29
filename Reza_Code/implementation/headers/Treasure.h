#ifndef TREASURE_H
#define TREASURE_H

#include "../misc/safeInclusion.cpp"

class Treasure
{
	public:
		typedef enum{COLLECTED, UNREACHED} TreasureState;
		TreasureState treasureState;
		char treasureName;
		
	protected:
};

#endif
