#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int __id = 0;

class Cell
{
	public:
		int id;
		string type;
		bool hasLeft;
		bool hasRight;
		bool hasSpecial;
		vector<int> specials;
		
		Cell()
		{
			this -> id = __id++;
			this -> type = "ordinaryCell";
			this -> hasLeft = this -> hasRight = true;
			this -> hasSpecial = false;
		}
};

vector<Cell> cells;

void specialize(int a, int b)
{
	cells[a].hasSpecial = cells[b].hasSpecial = true;
	cells[a].specials.push_back(b);
	cells[b].specials.push_back(a);
}
void change(int *a, string type, int size)
{
	for(int i = 0; i < size; i++)
	{
		cells[a[i]].type = type;
	}
}

void print()
{
	printf("116\n");
	for(int i = 0; i < 4; i++)
	{
		printf("initialCell -> 1\n1\n");
	}
	for(int i = 1; i <= 116; i++)
	{
		int adjCount = cells[i].specials.size();
		printf("%s -> %d\n", cells[i].type.c_str(), (int)cells[i].hasLeft + (int)cells[i].hasRight + adjCount);
		if(cells[i].hasLeft)
			printf("%d ", i - 1);
		if(cells[i].hasRight)
			printf("%d ", i + 1);
			
		for(int j = 0; j < adjCount; j++)
		{
			printf("%d ", cells[i].specials[j]);
		}
		printf("\n");
	}
}

int main()
{
	cells.resize(117);
	cells[1].hasLeft = false;
	cells[34].hasRight = false;
	cells[35].hasLeft = false;
	cells[49].hasRight = false;
	cells[50].hasLeft = false;
	cells[53].hasRight = false;
	cells[54].hasLeft = false;
	cells[59].hasRight = false;
	cells[60].hasLeft = false;
	cells[67].hasRight = false;
	cells[68].hasLeft = false;
	cells[78].hasRight = false;
	cells[79].hasLeft = false;
	cells[93].hasRight = false;
	cells[94].hasLeft = false;
	cells[107].hasRight = false;
	cells[108].hasLeft = false;
	cells[109].hasRight = false;
	cells[110].hasLeft = false;
	cells[116].hasRight = false;
	
	specialize(4, 35);
	specialize(7, 79);
	specialize(10, 53);
	specialize(11, 109);
	specialize(15, 34);
	specialize(21, 116);
	specialize(29, 78);
	specialize(37, 49);
	specialize(46, 59);
	specialize(48, 50);
	specialize(51, 54);
	specialize(55, 60);
	specialize(57, 67);
	specialize(63, 68);
	specialize(81, 93);
	specialize(92, 94);
	specialize(95, 107);
	specialize(101, 110);
	specialize(106, 108);
	
	int transport[] = {15}, decision[] = {25}, treasure[] = {39, 43, 50, 58, 60, 66, 70, 82, 85, 88, 97, 103, 108};
	change(transport, "transportCell", 1);
	change(decision, "decisionCell", 1);
	change(treasure, "treasureCell", 13);
	
	print();
}
