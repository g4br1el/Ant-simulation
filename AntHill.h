#ifndef ANTHILL_HEADER
#define ANTHILL_HEADER

#include <iostream>
#include <string>
#include "Item.h"
#include "Area.h"

using namespace std;

class AntHill:public Item{
public:
	int foodStock;
	void act(Area * current, Environment* myEnvironment);

	//Konstruktor
	AntHill();
	//Destruktor
	~AntHill();
};

#endif