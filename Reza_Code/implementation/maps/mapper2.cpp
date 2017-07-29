#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

void map_writer()
{
	FILE *fptr = fopen("default.ejm", "w");
	typedef enum{ORDINARY, TREASURE, INITIAL, DECISION, TRANSPORT, NOTYPE} CellType;
	int ID;
    int temp_numAdj;
    int what_is_type;
    int xPos, yPos;
	vector< vector<unsigned long long int> > tempAdjID(10, vector<unsigned long long int>(1, 0));
	unsigned long long int size = 10;
	fwrite(&size, sizeof(unsigned long long int), 1, fptr);
    	
	ID = 7;
	temp_numAdj = 1;
	what_is_type = INITIAL;
	xPos = 50, yPos = 70;
	tempAdjID[0][0] = 1;
    fwrite(&ID, sizeof(unsigned long long int), 1, fptr);
    fwrite(&temp_numAdj, sizeof(int), 1, fptr);
    fwrite(&what_is_type, sizeof(int), 1, fptr);
    fwrite(&xPos, sizeof(int), 1, fptr);
    fwrite(&yPos, sizeof(int), 1, fptr);
    
    ID = 8;
	temp_numAdj = 1;
	what_is_type = INITIAL;
	xPos = 50, yPos = 120;
	tempAdjID[1][0] = 1;
    fwrite(&ID, sizeof(unsigned long long int), 1, fptr);
    fwrite(&temp_numAdj, sizeof(int), 1, fptr);
    fwrite(&what_is_type, sizeof(int), 1, fptr);
    fwrite(&xPos, sizeof(int), 1, fptr);
    fwrite(&yPos, sizeof(int), 1, fptr);
    
    ID = 9;
	temp_numAdj = 1;
	what_is_type = INITIAL;
	xPos = 50, yPos = 170;
	tempAdjID[2][0] = 1;
    fwrite(&ID, sizeof(unsigned long long int), 1, fptr);
    fwrite(&temp_numAdj, sizeof(int), 1, fptr);
    fwrite(&what_is_type, sizeof(int), 1, fptr);
    fwrite(&xPos, sizeof(int), 1, fptr);
    fwrite(&yPos, sizeof(int), 1, fptr);
    
    ID = 10;
	temp_numAdj = 1;
	what_is_type = INITIAL;
	xPos = 50, yPos = 220;
	tempAdjID[3][0] = 1;
    fwrite(&ID, sizeof(unsigned long long int), 1, fptr);
    fwrite(&temp_numAdj, sizeof(int), 1, fptr);
    fwrite(&what_is_type, sizeof(int), 1, fptr);
    fwrite(&xPos, sizeof(int), 1, fptr);
    fwrite(&yPos, sizeof(int), 1, fptr);
    
    ID = 1;
	temp_numAdj = 2;
	what_is_type = ORDINARY;
	xPos = 135, yPos = 150;
	tempAdjID[4][0] = 2;tempAdjID[4][0] = 6;
    fwrite(&ID, sizeof(unsigned long long int), 1, fptr);
    fwrite(&temp_numAdj, sizeof(int), 1, fptr);
    fwrite(&what_is_type, sizeof(int), 1, fptr);
    fwrite(&xPos, sizeof(int), 1, fptr);
    fwrite(&yPos, sizeof(int), 1, fptr);
    
    ID = 2;
	temp_numAdj = 2;
	what_is_type = ORDINARY;
	xPos = 200, yPos = 230;
	tempAdjID[5][0] = 1;tempAdjID[5][1] = 3;
    fwrite(&ID, sizeof(unsigned long long int), 1, fptr);
    fwrite(&temp_numAdj, sizeof(int), 1, fptr);
    fwrite(&what_is_type, sizeof(int), 1, fptr);
    fwrite(&xPos, sizeof(int), 1, fptr);
    fwrite(&yPos, sizeof(int), 1, fptr);
    
    ID = 3;
	temp_numAdj = 3;
	what_is_type = DECISION;
	xPos = 340, yPos = 210;
	tempAdjID[6][0] = 2;tempAdjID[6][1] = 4;tempAdjID[6][2] = 5;
    fwrite(&ID, sizeof(unsigned long long int), 1, fptr);
    fwrite(&temp_numAdj, sizeof(int), 1, fptr);
    fwrite(&what_is_type, sizeof(int), 1, fptr);
    fwrite(&xPos, sizeof(int), 1, fptr);
    fwrite(&yPos, sizeof(int), 1, fptr);
    
    ID = 4;
	temp_numAdj = 2;
	what_is_type = TRANSPORT;
	xPos = 490, yPos = 200;
	tempAdjID[7][0] = 3;tempAdjID[7][1] = 5;
    fwrite(&ID, sizeof(unsigned long long int), 1, fptr);
    fwrite(&temp_numAdj, sizeof(int), 1, fptr);
    fwrite(&what_is_type, sizeof(int), 1, fptr);
    fwrite(&xPos, sizeof(int), 1, fptr);
    fwrite(&yPos, sizeof(int), 1, fptr);
    
    ID = 5;
	temp_numAdj = 2;
	what_is_type = TREASURE;
	xPos = 390, yPos = 125;
	tempAdjID[8][0] = 3;tempAdjID[8][1] = 4;tempAdjID[8][2] = 6;
    fwrite(&ID, sizeof(unsigned long long int), 1, fptr);
    fwrite(&temp_numAdj, sizeof(int), 1, fptr);
    fwrite(&what_is_type, sizeof(int), 1, fptr);
    fwrite(&xPos, sizeof(int), 1, fptr);
    fwrite(&yPos, sizeof(int), 1, fptr);
    
    ID = 6;
	temp_numAdj = 2;
	what_is_type = ORDINARY;
	xPos = 280, yPos = 55;
	tempAdjID[9][0] = 1;tempAdjID[9][1] = 5;
    fwrite(&ID, sizeof(unsigned long long int), 1, fptr);
    fwrite(&temp_numAdj, sizeof(int), 1, fptr);
    fwrite(&what_is_type, sizeof(int), 1, fptr);
    fwrite(&xPos, sizeof(int), 1, fptr);
    fwrite(&yPos, sizeof(int), 1, fptr);
    
    for(unsigned long long int i = 0 ; i < size ; i++){
        for(int j = 0 ; j < tempAdjID[i].size() ; j++){
            fwrite(&tempAdjID[i][j], sizeof(unsigned long long int), 1, fptr);
        }
    }
}

int main()
{
	map_writer();
}
