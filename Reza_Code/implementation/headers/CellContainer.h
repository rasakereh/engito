#ifndef CELLCONTAINER_H
#define CELLCONTAINER_H

#include <algorithm>
#include <map>
#include <string>
#include <vector>

#include <QLabel>
#include "MapLoader.h"

#define WIDTHCELL 28
#define HEIGHTCELL 28

//class MapDraft;

class Cell: public QLabel
{
//friend std::vector<Cell*> SaverLoader::loadMap(std::string file_name);
//friend class MapDraft;

public:
    typedef enum{ORDINARY, TREASURE, INITIAL, DECISION, TRANSPORT, NOTYPE} CellType;
    Cell(CellType cellType, QWidget *parent = nullptr);
    const std::vector<Cell *> &getAdjacentList();
    const CellType &getCellType();
    const unsigned long long int &getCellID();
    const int &getXPos();
    const int &getYPos();
    
private:
    typedef enum{GREEN, ORANGE, BLUE, RED, VIOLET} CellColor;
    static std::map <CellType, CellColor> colorTranslator;
    static std::map <CellType, std::string> iconTranslator;
    
    unsigned long long int cellID;
    int xPosition, yPosition;
    CellType cellType;
    CellColor cellColor;
    std::vector<Cell *> adjacentList;
    
    void setCellID(unsigned long long int cellID);
    void setColor();
    void loadImage();
    void highlight();
    bool addAdjacent(Cell *newAdjacent);
    bool removeAdjacent(Cell *oldAdjacent);
    void setAdjacentList(const std::vector<Cell *> &adjacentList);
    void setPos(const int &xPos, const int &yPos);
    
    
};

#endif // CELLCONTAINER_H
