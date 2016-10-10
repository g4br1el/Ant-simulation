#include "AntHill.h"
#include "Factory.h"
#include "Environment.h"

AntHill::AntHill()
{
	played = 0;
	foodStock = 0;
}

AntHill::~AntHill()
{
}

void AntHill::act(Area * current, Environment* myEnvironment)
{
	this->played++;
	Factory* myFactory = new Factory;

	// Produzuere Ameisen --> 1 Food = 1 Ameise

	if (myEnvironment->foodStock >= 1) {
		Item* myAnt;

		while (myEnvironment->foodStock > 0)
		{
			myAnt = myFactory->addAnt(myEnvironment->heigth);
			myAnt->played = myEnvironment->roundCount;
			myEnvironment->antsCreated++;

			current->getList()->push_back(myAnt);

			myEnvironment->foodStock--;
		}
	}
	//cout << "ich bin Anthill auf area " << current << "\n";
}