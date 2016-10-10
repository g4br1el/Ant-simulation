#ifndef ANT_HEADER
#define ANT_HEADER

#include <iostream>
#include <string>
#include "Item.h"
#include "Area.h"
#include "AntHill.h"

using namespace std;

class Ant :public Item {
public:
	string name;
	int age;
	int lifeTime;
	int x_axe;
	int y_axe;
	bool foodLoaded;

	void act(Area * current, Environment* myEnvironment);

	//Konstruktor
	Ant(int height);
	//Destruktor
	~Ant();

private:
	void foodcheck(Area* current, Environment* myEnvironment);
	void moveBack(Area* current, Environment* myEnvironment);
	list <Item*>::iterator findItemInList(Item* item, list <Item*>* myList);
	int pheromoncheck(Area* current);
};

#endif