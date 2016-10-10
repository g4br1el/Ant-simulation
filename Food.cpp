#include "Food.h"
#include "environment.h"

#define AGELIMIT 22 // in Runden

Food::Food()
{
	//age = 0;
	played = 0;
}

Food::~Food()
{
}

void Food::act(Area * current, Environment* myEnvironment)
{
	played++;
	
	if (played > AGELIMIT) {		
		myEnvironment->taintedFood++;
		current->getList()->remove(this);
		delete this;
	}
	//cout << "ich bin food auf area " << current << "\n";
}