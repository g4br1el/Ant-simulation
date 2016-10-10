#ifndef fatkid_h
#define fatkid_h

#include <stdio.h>
#include "Area.h"
#include "Item.h"

using namespace std;

class Fatkid :public Item {
public:
    void act(Area * current, Environment* myEnvironment);
    
    //Konstruktor
    Fatkid();
    //Destruktor
    ~Fatkid();
    
};

#endif