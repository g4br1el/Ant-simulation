#include "Area.h"
#include "Factory.h"

Area::Area()
{
	north = NULL;
	east = NULL;
	south = NULL;
	west = NULL;
	itemList = new list <Item*>;
	Pheromone = false;
}

Area::~Area()
{
}

Area* Area::getNorth()
{
	return this->north;
}

Area* Area::setNorth(Area * ptr)
{
	if (NULL != ptr)
	{
		north = ptr;
		north->setSouth(this);
	}
	ptr = this;
	return ptr;
}

Area* Area::getEast()
{
	return this->east;
}

void Area::setEast(Area* elem)
{
	east = elem;
}

Area* Area::getSouth()
{
	return this->south;
}

void Area::setSouth(Area* setOn)
{
	south = setOn;
}

Area* Area::getWest()
{
	return this->west;
}

void Area::setWest(Area* N_W_Sptr )
{
	west = N_W_Sptr;
	west->setEast(this);
}

list<Item*>* Area::getList()
{
	return this->itemList;
}

void Area::set_to_List(Item * toSet)
{
	itemList->push_front(toSet);
}

int Area::findWay()
{
	//srand(time(NULL));
	int number = -1;

	while (number == -1)
	{
		number = (rand() % 4);
		switch (number)
		{
		case 0: //nach Norden
			if (getNorth() == NULL) {
				number = -1;
			}
			break;
		case 1: //nach Osten
			if (getEast() == NULL) {
				number = -1;
			}
			break;
		case 2: //nach Süden
			if (getSouth() == NULL) {
				number = -1;
			}
			break;
		case 3: //nach Westen
			if (getWest() == NULL) {
				number = -1;
			}
			break;
		default:
			cout << "Error: 1" << number << endl;
		}
	}

	return number;
}

void Area::Move(Item * tomove, int number)
{
	//cout << "before moving \n ============================\n";
	//this->printAllItems();

	Area* neighborArea = NULL;

	if (number == 0) {
		neighborArea = getNorth();
	}
	else if (number == 1) {
		neighborArea = getEast();
	}
	else if (number == 2) {
		neighborArea = getSouth();
	}
	else if (number == 3) {
		neighborArea = getWest();
	}
	else {
		//cout << "Error: 2" << endl;
	}

	//neighborArea->printAllItems();
	neighborArea->itemList->push_back(tomove);
	this->itemList->remove(tomove);

	//cout << "ant " << tomove << " moved from " << this << " to " << neighborArea << "\n";

	//cout << "after moving \n ============================\n";
	//this->printAllItems();

	//cout << "Neighbor after moving \n ============================\n";
	//neighborArea->printAllItems();
}

/**
* @brief internal debugging function, not used for productive
*/
void Area::printAllItems() {

	list <Item*>::iterator it;
	for (it = itemList->begin(); it != itemList->end(); it++) {
		cout << "Item " << (*it) << "and my played value is " << (*it)->played << "\n";
	}

}