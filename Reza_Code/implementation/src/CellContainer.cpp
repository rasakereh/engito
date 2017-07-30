#include "../headers/CellContainer.h"

std::map <CellContainer::CellType, CellContainer::CellColor> CellContainer::colorTranslator = {
                                                            {CellContainer::DECISION, CellContainer::RED},
                                                            {CellContainer::TREASURE, CellContainer::ORANGE},
                                                            {CellContainer::INITIAL, CellContainer::BLUE},
                                                            {CellContainer::ORDINARY, CellContainer::GREEN},
                                                            {CellContainer::TRANSPORT, CellContainer::VIOLET},
                                                        };
std::map <CellContainer::CellType, std::string> CellContainer::iconTranslator = {
                                                            {CellContainer::DECISION, ":/icons/Cells/DecisionCell"},
                                                            {CellContainer::TREASURE, ":/icons/Cells/TreasureCell"},
                                                            {CellContainer::INITIAL, ":/icons/Cells/InitialCell"},
                                                            {CellContainer::ORDINARY, ":/icons/Cells/OrdinaryCell"},
                                                            {CellContainer::TRANSPORT, ":/icons/Cells/TransportCell"},
                                                        };

CellContainer::CellContainer(CellContainer::CellType cellType, QWidget *parent): QLabel(parent)
{
    int width = WIDTHCELL;
    int height = HEIGHTCELL;
    this -> isCellHighlighted = false;
    this -> setFixedSize(width, height);
    this -> setScaledContents(true);
    this -> cellType = cellType;
    this -> loadImage();
    this -> setColor();
}

void CellContainer::loadImage()
{
    this -> setPixmap(QPixmap(CellContainer::iconTranslator[this -> cellType].c_str()));
}

void CellContainer::setColor()
{
    this -> cellColor = CellContainer::colorTranslator[this -> cellType];
}

void CellContainer::highlight()
{
    this -> setPixmap(QPixmap(":/icons/Cells/highlight"));
}

unsigned long long int CellContainer::getCellID()
{
    return this -> cellID;
}

bool CellContainer::isHighlighted()
{
    return this -> isCellHighlighted;
}

void CellContainer::mousePressEvent(QMouseEvent *event) override
{
    emit this -> clicked();
}
