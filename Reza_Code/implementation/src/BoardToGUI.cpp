#include "../headers/BoardToGUI.h"

void BoardToGUI::translateBoardToUI(ConsoleUI *gameUI, GameBoard *gameBoard)
{
    return ;
}

void BoardToGUI::translateBoardToUI(GraphicalUI *gameUI, GameBoard *gameBoard)
{
    auto cellPacker = [&](BoardCell *cell) -> CellContainer *
                        {
                            struct comparer
                            {
                                bool operator()(BoardCell::ColorRGB const &a, BoardCell::ColorRGB const &b)
                                {
                                     return true;
                                }
                            };
                            
                            const BoardCell::ColorRGB RED = {255, 0, 0}, BLUE = {0, 0, 255}, GREEN = {50, 255, 50}, ORANGE = {255, 140, 0}, PURPLE = {255, 0, 255};
                            std::map<const BoardCell::ColorRGB, CellContainer::CellType, comparer> colorToType;
                            
                            colorToType[RED] = CellContainer::DECISION;
                            colorToType[GREEN] = CellContainer::ORDINARY;
                            colorToType[BLUE] = CellContainer::INITIAL;
                            colorToType[ORANGE] = CellContainer::TREASURE;
                            colorToType[PURPLE] = CellContainer::TRANSPORT;
                            
                            CellContainer *container = new CellContainer(colorToType[cell->cellColor]);
                            container -> content = cell;
                            cell -> container = container;
                            container -> setParent(gameUI -> gameScreen -> ui -> frmMap);
                            container -> move(cell->getPosition().first, cell->getPosition().second);
                            return container;
                        };
    cells.resize(gameBoard -> getAllCells().size());
    std::transform(gameBoard -> getAllCells().begin(), gameBoard -> getAllCells().end(), cells.begin(), cellPacker);
    return ;
}
