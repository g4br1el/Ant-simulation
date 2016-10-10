#ifndef FACTORY_HEADER
#define FACTORY_HEADER

#include "Ant.h"
#include "AntHill.h"
#include "Food.h"
#include "Fatkkid.h"

class Factory {
public:
	//Konstruktor
	Factory();
	//Destruktor
	~Factory();

	Item* addAnt(int height);
	Item* addAntHill();
	Item* addFood();
	Item* addfatKid();
};

#endif