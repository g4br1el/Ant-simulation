#ifndef ENVIROMENT_HEADER
#define ENVIROMENT_HEADER

#include <iostream>
#include <string>
#include "Area.h"
#include "Factory.h"

using namespace std;

static bool instance;

class Environment {
public:
	int antsDead;
	int pickedFood;
	int antsKilled;
	int taintedFood;
	int antsCreated;
	int antsDeadTotal;
	int antsCreatedTotal;
	int antsAlive;

	int heigth;
	int roundCount;
	int foodStock;

	Area *toArea;
	
	//Element Functions
	void createEnviroment(int height, int width);
	static Environment* Instrance();
	void placeInitial(int height, int width);
	void act_all();
	void setFood(int count, int height);

private:
	//Konstruktor
	Environment();
	//Destruktor
	~Environment();
	
};

#endif