#include <ctime>
#include <fstream>
#include <stdexcept>
#include <string>
#include <typeinfo>
#include "Food.h"
#include "Environment.h"
#include "Ant.h"

using namespace std;

Ant::Ant(int height)
{
	played = 0; 
	foodLoaded = false;
	age = 0;
	lifeTime = height;
	x_axe = 0;
	y_axe = 0;


	ifstream infile("namen.txt", ios::in);
	int a;

	if (infile.is_open()) {
		a = (rand() % 100) + 1;
		for (int i = 1; i <= a; i++) {
			getline(infile, name);
		}
		infile.close();
	}
}

Ant::~Ant()
{
}

void Ant::foodcheck(Area * current, Environment* myEnvironment)
{
	list <Item*> *myList = current->getList();
	list <Item*>::iterator it;
	list <Item*>::iterator it_tmp;

	if (current->Pheromone == true)
		current->Pheromone == false;

	for (it = myList->begin(); it != myList->end(); it++)
	{
	
		//cout << typeid(Food).name() << " : " << typeid(**it).name() << endl; 
		if (typeid(**it) == typeid(Food)) {
			if (foodLoaded == false) {
				foodLoaded = true;
				myEnvironment->pickedFood++;
				it_tmp = it;
				it = findItemInList(this, myList);

				current->getList()->erase(it_tmp);

				if (current->getList()->size() == 0)
					return;
				it = current->getList()->begin();
				//cout << "found Something to eat"; 
			}
			else {
				current->Pheromone = true;
				return;
			}
		}
	}
}

void Ant::moveBack(Area * current, Environment* myEnvironment)
{
	int neighborArea = -1;
	if (this->x_axe > 0) {
		neighborArea = 2;
		current->Move(this, neighborArea);
		x_axe--;
	}
	else if (this->x_axe < 0) {
		neighborArea = 0;
		current->Move(this, neighborArea);
		x_axe++;
	}
	else if (this->y_axe > 0)
	{
		neighborArea = 3;
		current->Move(this, neighborArea);
		y_axe--;
	}
	else if (this ->y_axe < 0)
	{
		neighborArea = 1;
		current->Move(this, neighborArea);
		y_axe++;
	}

	//cout << " koordinaten: " << x_axe << " " << y_axe << endl;

	if((x_axe == 0) && (y_axe == 0)) {
		age = 0;
		myEnvironment->foodStock++;
		foodLoaded = false;
	}
}


int Ant::pheromoncheck(Area * current)
{
	if ((current->getNorth() != NULL) && (current->getNorth()->Pheromone == true))
	{
		return 0;
	}
	else if ((current->getEast() != NULL) && (current->getEast()->Pheromone == true))
	{
		return 1;
	}
	else if ((current->getSouth() != NULL) && (current->getSouth()->Pheromone == true))
	{
		return 2;
	}
	else if ((current->getWest() != NULL) && (current->getWest()->Pheromone == true))
	{
		return 3;
	}
	else
	{
		return -1;
	}
}

void Ant::act(Area * current, Environment* myEnvironment)
{
	try {
		age++;
		if (age >= lifeTime)
			throw exception();

		this->played++;

		int direction;

		//cout << "ich bin ameise auf area " << current << "\n";
		//cout << endl << " koordinaten: " << x_axe << " " << y_axe << " " << current << endl;

		try {
			if (foodLoaded == true)
				throw exception();

			direction =  pheromoncheck(current);

			if (direction == -1)
				direction = current->findWay();

			if (direction == 0)
			{
				x_axe++;
			}
			else if (direction == 1)
			{
				y_axe++;
			}
			else if (direction == 2)
			{
				x_axe--;
			}
			else if (direction == 3)
			{
				y_axe--;
			}

			current->Move(this, direction);
			//cout << " koordinaten Nach Zug: " << x_axe << " " << y_axe << endl;
			foodcheck(current, myEnvironment);
		}
		catch (exception) {
			moveBack(current, myEnvironment);
			//cout << " koordinaten Nach Zug: " << x_axe << " " << y_axe <<  endl;
		}
		//cout << "ich bin ameise auf area " << current << "\n";
	}
	catch (exception) {
		myEnvironment->antsDead++;
		//cout << "Die Ameise " << name << " ist verstorben" << endl;
		cout << "The ant " << name << " is deceased" << endl;
		current->getList()->remove(this);
		delete this;
	}
}

// * @brief area::getIterator
// * @return 
// */
list <Item*>::iterator Ant::findItemInList(Item* item, list <Item*>* myList) {
    list <Item*>::iterator it;
    for (it = myList->begin(); it != myList->end(); it++) {
        if ( (*it) == item ) {
            //cout << "I have found myself on area" << this << ": " << (*it) << " " << item << "\n";
            return it;
        }
    }
	return it;
}