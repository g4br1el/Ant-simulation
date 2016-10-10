#include <ctime>
#include <iostream>
#include <string>
#include "Area.h"
#include "Environment.h"
#include "Item.h"
#include "Factory.h"

#define ROUNDS 24

using namespace std;

int main(void) {

	srand(time(NULL));

	instance = false;
	int height = 0;
	int width = 0;
	try {
		cout << "Geben Sie die Seitenlaenge ein (min 10): "; cin >> height;
		width = height;

		if (height < 10)
			throw exception("Seitenaenge zu klein!");

		Environment * myEnviroment = Environment::Instrance();
		myEnviroment->heigth = height;

		if (myEnviroment == NULL) {
			cout << "Fehler";
			return 0;
		}

		myEnviroment->createEnviroment(height, width);
		myEnviroment->placeInitial(height, width);

		for (int i = 1; i <= ROUNDS; i++)
		{
			if (i % 5 == 0)
				myEnviroment->setFood((myEnviroment->antsAlive / 2), height);
			cout << endl << "ROUND: " << i << "------------------------------------------------------" << endl;
			myEnviroment->act_all();
            myEnviroment->antsCreatedTotal = myEnviroment->antsCreatedTotal + myEnviroment->antsCreated;
            myEnviroment->antsDeadTotal = myEnviroment->antsDeadTotal + myEnviroment->antsKilled + myEnviroment->antsDead;
            myEnviroment->antsAlive = myEnviroment->antsCreatedTotal - myEnviroment->antsDeadTotal;
            cout << endl << "Geborene Ameisen: " << myEnviroment->antsCreated << endl;
            cout << "Gestorbene Ameisen: " << myEnviroment->antsDead << endl;
            cout << "Getoete Ameisen: " << myEnviroment->antsKilled << endl;
            cout << "Verrottete Nahrung: " << myEnviroment->taintedFood << endl;
            cout << "Gefundenes Futter: " << myEnviroment->pickedFood << endl;
            cout << "Verstorbene Ameisen gesamt:" << myEnviroment->antsDeadTotal << endl;
            cout << "Geborene Ameisen gesamt:" << myEnviroment->antsCreatedTotal << endl;
            cout << "Lebendige Ameisen:" << myEnviroment->antsAlive << endl << endl;
            myEnviroment->antsCreated = 0;
            myEnviroment->antsDead = 0;
            myEnviroment->pickedFood = 0;
            myEnviroment->taintedFood = 0;
            myEnviroment->antsKilled = 0;

			//system("PAUSE");
		}

	}
	catch (exception& e) {
		cout << e.what() << endl;
	}

	system("PAUSE");
	return 0;
}