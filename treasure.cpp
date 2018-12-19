#include "treasure.h"

//default ctor that randomly calculates if the spawned treasure is real or fake.
treasure::treasure()
{
	name = "Treasure";
	printindex = 'X';
	srand((unsigned int)time(NULL));
	int check = rand() % 2;
	if (check == 0) {
		isreal = false;
	}
	if (check == 1) {
		isreal = true;
	}
	cout << "In treasure default ctor" << endl;
}


treasure::~treasure()
{
	cout << "In treasure dtor" << endl;
}

//prints the relevant info about the treasure once the player reaches it.
void treasure::print()
{
	if (isreal == 0) {
		cout << endl;
		cout << "Sorry - The treasure was fake! you lose!" << endl;
		cout << endl;
	}
	if (isreal == 1) {
		cout << endl;
		cout << "Congratsulations! you win!" << endl;
		cout << endl;
	}
}
