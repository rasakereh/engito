#include "../misc/safeInclusion.cpp"

#ifndef BOARDCELL_H
#define BOARDCELL_H

#include "../headers/Player.h"

class BoardCell
{
	friend class GameInitializer;
	friend class GameRuler;
	friend class MapLoader;
	public:
		typedef enum{ORDINARY, TREASURE, INITIAL, DECISION, TRANSPORT, NOTYPE} CellType;
		typedef unsigned char _COLOR8;		/* R/G/B Depth of a color */
		struct ColorRGB
		{
			_COLOR8 redDepth, greenDepth, blueDepth;
			bool operator==(ColorRGB const &color) const
			{
				return (this -> redDepth == color.redDepth)
						&& (this -> greenDepth == color.greenDepth)
						&& (this -> blueDepth == color.blueDepth);
			}
		};
		
	private:
		std::vector<BoardCell *> adjacentCells;
		Player *occupierPlayer;
		int cellNumber;
        int xPositison, yPosition;
		
		void evacuate();
		Player *inhabit(Player *newOccupier);
		void setCellNumber(int cellNumber);
		void addAsAdjacent(BoardCell *newAdjacent, bool applyMutually);
        void setPosition(int x, int y);
		
	public:
		virtual void setMyColor();
		std::vector<BoardCell *> nextCell(BoardCell *parentCell);
		std::vector<BoardCell *> passThrough(BoardCell *source, int distance);
		Player *const &getOccupier();
		int getCellNumber();
		ColorRGB const &getColor();
        std::pair<int, int> getPosition();
		
	protected:
		ColorRGB cellColor;
		void setColor(_COLOR8 redDepth,_COLOR8 greenDepth,_COLOR8 blueDepth);
};

#endif
