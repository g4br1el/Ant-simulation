#include <ctime>
#include "Environment.h"


Environment::Environment()
{
	toArea = new Area;
	antsCreated = 0;
	antsDead = 0;
	pickedFood = 0;
	antsKilled = 0;
	taintedFood = 0;
	roundCount = 0;
	antsCreatedTotal = 0;
	antsDeadTotal = 0;
	antsAlive = 0;
	heigth = 0;
}

Environment::~Environment()
{
}

void Environment::createEnviroment(int height, int width)
{
	Area* ptr = toArea;
	Area* Northprt = toArea;
	for (int i = 0; i < width; i++)
	{
		if (i != 0)
		{
			Area* myArea = new Area;
			myArea->setWest(ptr);
			ptr = ptr->getEast();
			Northprt = ptr;
		}
		for (int a = 0; a < height - 1; a++)
		{
			Area* myArea2 = new Area;
			Northprt = myArea2->setNorth(Northprt);
			if (i != 0){
				myArea2->setWest(myArea2->getNorth()->getWest()->getSouth());
			}	
		}
	}
}

Environment * Environment::Instrance()
{
	if (instance == false) {
		Environment* env = new Environment;
		instance = true;
		return env;
	}
	return NULL;
}

void Environment::placeInitial(int height, int width)
{
	Area* current = toArea;
	Factory* myFactory = new Factory;
	//srand(time(NULL));

	//AntHill in die mitte setzen
	for (int i = 0; i < (height / 2); i++)
	{
		current = current->getEast();
	}
	for (int a = 0; a < (width / 2); a++)
	{
		current = current->getSouth();
	}
	current->set_to_List(myFactory->addAntHill());
	
	//Ant setzen
	for (int i = 0; i <(height * width); i++)
	{
		current->set_to_List(myFactory->addAnt(height));
		antsCreated++;
	}
	
	//Food setzen
	setFood(height*width, height);

	//Fatkid setzen
	current = toArea;
	for (int a = 0; a < (rand() % width); a++)
	{
		current = current->getSouth();
	}
	for (int b = 0; b < (rand() % height); b++)
	{
		current = current->getEast();
	}
	current->set_to_List(myFactory->addfatKid());
}

void Environment::act_all()
{
	Area* current;
	Area* firstArea;

	//int col = 0;
	//int row = 0;

	
		//cout << "NEW ROUND\n==============================================\n";
		current = toArea;
		firstArea = toArea;
		while (firstArea != NULL)
		{
			//row++;
			while (current != NULL)
			{
				//col++;
				list <Item*>::iterator it;
				list <Item*>::iterator tmpIt;

				list <Item*> *myList = current->getList();
				//cout << "I am area " << current << " list size " << myList ->size() << "\n";

				it = myList->begin();
				while (it != myList->end()) {
					tmpIt = it;
					tmpIt++;
					//cout << "remembered item" << (*it) << "next one is " << (*tmpIt) << "\n";

					// do it
					if (myList->size() == 0)
						break;

					//cout << endl << myList->size() << endl;
					if ((*it)->played < roundCount) {
						(*it)->act(current, this);
						//cout << "\n==============================================\n";
						myList = current->getList();
						
					}
					// set iterator
					it = tmpIt;
				}
				current = current->getEast();
			}

			//cout << "arrived at last element of column " << col << " and row " << row << "\n";
			//col = 0;
			firstArea = firstArea->getSouth();
			current = firstArea;
		
		//row = 0;
	}
		roundCount++;
}

void Environment::setFood(int count, int height)
{
	Area* current = toArea;
	Factory* myFactory = new Factory;

	for (int i = 0; i < (count); i++)
	{
		current = toArea;
		for (int a = 0; a < (rand() % height); a++)
		{
			current = current->getSouth();
		}
		for (int b = 0; b < (rand() % height); b++)
		{
			current = current->getEast();
		}
		current->set_to_List(myFactory->addFood());
	}
}