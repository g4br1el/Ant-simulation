#include "Factory.h"

Factory::Factory()
{
}

Factory::~Factory()
{
}

Item * Factory::addAnt(int height)
{
	Item* ant = new Ant(height);
	return ant;
}

Item * Factory::addAntHill()
{
	Item* anthill = new AntHill;
	return anthill;
}

Item * Factory::addFood()
{
	Item* food = new Food;
	return food;
}

Item * Factory::addfatKid()
{
	Item* kid = new Fatkid;
	return kid;
}