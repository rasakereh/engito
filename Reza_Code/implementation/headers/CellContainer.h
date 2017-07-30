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

class CellContainer: public QLabel
{
//friend std::vector<Cell*> SaverLoader::loadMap(std::string file_name);
friend class BoardToGUI;
friend class GameScreen;
friend class GraphicalUI;
Q_OBJECT

public:
    typedef enum{ORDINARY, TREASURE, INITIAL, DECISION, TRANSPORT, NOTYPE} CellType;
    CellContainer(CellType cellType, QWidget *parent = nullptr);
    unsigned long long int getCellID();
    bool isHighlighted();
    
private:
    typedef enum{GREEN, ORANGE, BLUE, RED, VIOLET} CellColor;
    static std::map <CellType, CellColor> colorTranslator;
    static std::map <CellType, std::string> iconTranslator;
    
    BoardCell *content;
    CellType cellType;
    CellColor cellColor;
    unsigned long long int cellID;
    bool isCellHighlighted;
    
    void setColor();
    void loadImage();
    void highlight();
    void normalize();
    
protected:
     void mousePressEvent(QMouseEvent *event) override;
     
signals:
     void clicked();
};

#endif // CELLCONTAINER_H
