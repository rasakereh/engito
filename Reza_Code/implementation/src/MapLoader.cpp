#include "../headers/MapLoader.h"

MapLoader::MapLoader(std::string file_name){
    int cellNumber;
    // a function is stored here to create a new cell and categorize it;
    std::function<BoardCell *(BoardCell::CellType)> createCell = [&](BoardCell::CellType cellType) -> BoardCell *
													{
                                                        BoardCell *result;
														if(cellType == BoardCell::INITIAL)
														{
															result = new InitialCell;
															result -> setMyColor();
															result -> setCellNumber(cellNumber);
															this -> initialCells.push_back(dynamic_cast<InitialCell *>(result));
															if(this -> allCells.empty())
															{
																this -> allCells.push_back(result);
															}
															return result;
														}
														else if(cellType == BoardCell::DECISION)
														{
															result = new DecisionCell;
															result -> setCellNumber(cellNumber);
															this -> decisionCells.push_back(dynamic_cast<DecisionCell *>(result));
														}
														else if(cellType == BoardCell::TRANSPORT)
														{
															result = new TransportCell;
															result -> setCellNumber(cellNumber);
															this -> transportCells.push_back(dynamic_cast<TransportCell *>(result));
														}
														else if(cellType == BoardCell::TREASURE)
														{
															result = new TreasureCell;
															result -> setCellNumber(cellNumber);
                                                            static_cast<TreasureCell *> (result) -> cellTreasure = nullptr;
															this -> treasureCells.push_back(dynamic_cast<TreasureCell *>(result));
														}
														else if(cellType == BoardCell::ORDINARY)
														{
															result = new OrdinaryCell;
															result -> setCellNumber(cellNumber);
														}
														result -> setMyColor();
														result -> occupierPlayer = nullptr;
														this -> allCells.push_back(result);
														
														return result;
													};
    const char* char_file_name = file_name.c_str();
    FILE* fptr = fopen(char_file_name,"r");

    BoardCell* temp = nullptr;
    unsigned long long int size = 0;
    unsigned long long int ID = 0;
    unsigned long long int tempID = 0;
    std::vector<int> numAdj;
    int temp_numAdj = 0;
    int xPos = 0 , yPos = 0;
    BoardCell::CellType what_is_type = BoardCell::ORDINARY;
    int intTypeEquiv;
    
    fread(&size, sizeof(unsigned long long int), 1, fptr);
    for(unsigned long long int i = 0 ; i < size ; i++){

        fread(&ID, sizeof(unsigned long long int), 1, fptr);
        fread(&temp_numAdj, sizeof(int), 1, fptr);
        fread(&intTypeEquiv, sizeof(int), 1, fptr);
        fread(&xPos, sizeof(int), 1, fptr);
        fread(&yPos, sizeof(int), 1, fptr);
        what_is_type = static_cast<BoardCell::CellType> (intTypeEquiv);
        temp = createCell(what_is_type);
        cellNumber = ID;
        this -> allCells.push_back(temp);
        numAdj.push_back(temp_numAdj);
        temp->setPosition(xPos, yPos);
    }
    for(unsigned long long int i = 0 ; i < size ; i++){
        for(int j = 0 ; j < numAdj.at(i) ; j++){
            fread(&tempID, sizeof(unsigned long long int), 1, fptr);
            auto it = std::find_if(this -> allCells.begin(), this -> allCells.end(), [&tempID](BoardCell* goal) {return goal-> getCellNumber() == tempID;});
            this -> allCells.at(i)->addAsAdjacent(*it, false);
        }
    }
    fclose(fptr);
}

std::string const &MapLoader::getLastError()
{
	return this -> lastError;
}

std::vector<BoardCell *> const &MapLoader::getAllCells()
{
    return this -> allCells;
}

std::vector<InitialCell *> const &MapLoader::getInitialCells()
{
	return this -> initialCells;
}

std::vector<DecisionCell *> const &MapLoader::getDecisionCells()
{
	return this -> decisionCells;
}

std::vector<TransportCell *> const &MapLoader::getTransportCells()
{
	return this -> transportCells;
}

std::vector<TreasureCell *> const &MapLoader::getTreasureCells()
{
	return this -> treasureCells;
}

BoardCell *MapLoader::getFirstCell()
{
	return this -> firstCell;
}
