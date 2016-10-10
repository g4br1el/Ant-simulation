#include <typeinfo>
#include "Fatkkid.h"
#include "Ant.h"
#include "Environment.h"

Fatkid::Fatkid()
{
    played = 0;
}

Fatkid::~Fatkid()
{
}

void Fatkid::act(Area * current, Environment* myEnvironment)
{
	
	played++;
	//cout << "ich bin FatKid auf area " << current << "\n";
    int direction = current->findWay();
    current->Move(this, direction);
    
    list <Item*>::iterator it;
    list <Item*>::iterator it_tmp;
    
	for (it = current->getList()->begin(); it != current->getList()->end(); it++)
    {
        if(typeid(**it) == typeid(Ant))
        {
			myEnvironment->antsKilled++;
            it_tmp = it;
            //it = current->getList()->begin();
            //current->getList()->erase(it_tmp);
			if (current->getList()->size() == 0)
				return;
            //it = current->getList()->begin();
			//return;
        }
    }
}