#ifndef ITEM_HEADER
#define ITEM_HEADER

#include <iostream>
#include <string>

using namespace std;

class Area;
class Environment;
class Item {
public:
	int played;
	virtual void act(Area* current, Environment* myEnvironment) = 0;
};

#endif