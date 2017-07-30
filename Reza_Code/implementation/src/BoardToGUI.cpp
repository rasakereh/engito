#include "../headers/BoardToGUI.h"

void BoardToGUI::translateBoardToUI(ConsoleUI *gameUI, GameBoard *gameBoard)
{
    return ;
}

void BoardToGUI::translateBoardToUI(GraphicalUI *gameUI, GameBoard *gameBoard)
{
    this -> packCells(gameUI, gameBoard);
    this -> packPlayers(gameUI, gameBoard);
    dynamic_cast<GraphicalUI *>(gameUI) -> cells = this -> cells;
    dynamic_cast<GraphicalUI *>(gameUI) -> players = this -> players;
    gameUI -> gameScreen -> ui -> frmMap -> show();
    return ;
}

void BoardToGUI::packCells(ConsoleUI *gameUI, GameBoard *gameBoard)
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
                            qDebug() << "Adding " << cell->cellColor.redDepth << ", " << cell->cellColor.greenDepth << ", " << cell->cellColor.blueDepth << "\t" << cell ->getPosition().first << "-" << cell -> getPosition().second;
                            CellContainer *container = new CellContainer(colorToType[cell->cellColor]);
                            container -> content = cell;
                            cell -> container = container;
                            container -> cellID = cell -> getCellNumber();
                            container -> setParent(gameUI -> gameScreen -> ui -> frmMap);
                            container -> move(cell->getPosition().first, cell->getPosition().second);
                            container -> show();
                            return container;
                        };
    this -> cells.resize(gameBoard -> getAllCells().size());
    std::transform(gameBoard -> getAllCells().begin(), gameBoard -> getAllCells().end(), cells.begin(), cellPacker);
}

void BoardToGUI::packPlayers(ConsoleUI *gameUI, GameBoard *gameBoard)
{
    auto playerPacker = [&](Player *player) -> PlayerContainer *
                        {
                            PlayerContainer *container = new PlayerContainer;
                            container -> content = player;
                            container -> show();
                            return container;
                        };
    this -> players.resize(gameBoard -> gameStat -> getAllPlayers().size());
    std::transform(gameBoard -> gameStat -> getAllPlayers().begin(), gameBoard -> gameStat -> getAllPlayers().end(), players.begin(), playerPacker);
}
