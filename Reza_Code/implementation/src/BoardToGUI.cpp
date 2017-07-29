#include "../headers/BoardToGUI.h"

void BoardToGUI::translateBoardToUI(ConsoleUI *gameUI, GameBoard *gameBoard)
{
    return ;
}

void BoardToGUI::translateBoardToUI(GraphicalUI *gameUI, GameBoard *gameBoard)
{
    auto cellPacker = [&](BoardCell *cell) -> CellContainer *
                        {
                            CellContainer *container = new CellContainer((CellContainer::CellType)cell->CellType);
                            container -> setParent(gameUI -> gameScreen -> ui -> frmMap);
                            return container;
                        };
    cells.resize(gameBoard -> getAllCells().size());
    std::transform(gameBoard -> getAllCells().begin(), gameBoard -> getAllCells().end(), cells.begin(), cellPacker);
    return ;
}
