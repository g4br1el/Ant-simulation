#ifndef FOOD_HEADER
#define FOOD_HEADER

#include <iostream>
#include <string>
#include "Item.h"
#include "Area.h"

using namespace std;

class Food :public Item {
public:
	void act(Area * current, Environment* myEnvironment);

	//Konstruktor
	Food();
	//Destruktor
	~Food();
};

#endif