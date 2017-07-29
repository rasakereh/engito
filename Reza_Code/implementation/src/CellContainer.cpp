#include "../headers/CellContainer.h"

std::map <Cell::CellType, Cell::CellColor> Cell::colorTranslator = {
                                                            {Cell::DECISION, Cell::RED},
                                                            {Cell::TREASURE, Cell::ORANGE},
                                                            {Cell::INITIAL, Cell::BLUE},
                                                            {Cell::ORDINARY, Cell::GREEN},
                                                            {Cell::TRANSPORT, Cell::VIOLET},
                                                        };
std::map <Cell::CellType, std::string> Cell::iconTranslator = {
                                                            {Cell::DECISION, ":/icons/DecisionCell"},
                                                            {Cell::TREASURE, ":/icons/TreasureCell"},
                                                            {Cell::INITIAL, ":/icons/InitialCell"},
                                                            {Cell::ORDINARY, ":/icons/OrdinaryCell"},
                                                            {Cell::TRANSPORT, ":/icons/TransportCell"},
                                                        };

Cell::Cell(Cell::CellType cellType, QWidget *parent): QLabel(parent)
{
    int width = WIDTHCELL;
    int height = HEIGHTCELL;
    this -> setFixedSize(width, height);
    this -> setScaledContents(true);
    this -> cellType = cellType;
    this -> loadImage();
    this -> setColor();
}

void Cell::loadImage()
{
    this -> setPixmap(QPixmap(Cell::iconTranslator[this -> cellType].c_str()));
}

void Cell::setColor()
{
    this -> cellColor = Cell::colorTranslator[this -> cellType];
}

void Cell::highlight()
{
    this -> setPixmap(QPixmap(":/icons/highlight"));
}

bool Cell::addAdjacent(Cell *newCell)
{
    this -> adjacentList.push_back(newCell);
    return true;
}

bool Cell::removeAdjacent(Cell *oldAdjacent)
{
    auto oldAdjacentElement = std::find(this -> adjacentList.begin(), this -> adjacentList.end(), oldAdjacent);
    if(oldAdjacentElement == this -> adjacentList.end())
    {
        return false;
    }
    this -> adjacentList.erase(oldAdjacentElement);
    
    return true;
}

void Cell::setCellID(unsigned long long int cellID)
{
    this -> cellID = cellID;
}

void Cell::setAdjacentList(const std::vector<Cell *> &adjacentList)
{
    this -> adjacentList = adjacentList;
}

void Cell::setPos(const int &xPos, const int &yPos)
{
    this -> xPosition = xPos;
    this -> yPosition = yPos;
}

const std::vector<Cell *> &Cell::getAdjacentList()
{
    return this -> adjacentList;
}

const Cell::CellType &Cell::getCellType()
{
    return this -> cellType;
}

const unsigned long long &Cell::getCellID()
{
    return this -> cellID;
}

const int &Cell::getXPos()
{
    return this -> xPosition;
}

const int &Cell::getYPos()
{
    return this -> yPosition;
}
