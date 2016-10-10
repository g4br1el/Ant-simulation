#ifndef AREA_HEADER
#define AREA_HEADER

#include <iostream>
#include <string>
#include <list>
#include <stdlib.h>
#include "Item.h"
#include "Ant.h"

using namespace std;

class Area {
private:
	Area *north;
	Area *east;
	Area *south;
	Area *west;

	list <Item*>* itemList;

public:
	Area();
	~Area();

	Area* getNorth();
	Area* setNorth(Area * ptr);

	Area* getEast();
	void setEast(Area* elem);

	Area* getSouth();
	void setSouth(Area* setOn);

	Area* getWest();
	void setWest(Area* N_W_Sptr);

	list <Item*>* getList();
	void set_to_List(Item* toSet);
	
	int findWay();
	void Move(Item * tomove, int number);

	void printAllItems();

	bool Pheromone;
};

#endif