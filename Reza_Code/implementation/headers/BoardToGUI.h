#include "misc/SafeInclusion.cpp"

#ifndef BOARDTOGUI_H
#define BOARDTOGUI_H

#include "ConsoleUI.h"
#include "GraphicalUI.h"
#include "GameBoard.h"
#include "CellContainer.h"
#include "GameStatistics.h"
#include "PlayerContainer.h"

class BoardToGUI
{
private:
    std::vector<CellContainer *> cells;
    std::vector<CellContainer *> players;
    
    void packCells(ConsoleUI *gameUI, GameBoard *gameBoard);
    void packPlayers(GraphicalUI *gameUI, GameBoard *gameBoard);
    
public:
    void translateBoardToUI(ConsoleUI *gameUI, GameBoard *gameBoard);
    void translateBoardToUI(GraphicalUI *gameUI, GameBoard *gameBoard);
};

#endif // BOARDTOGUI_H
