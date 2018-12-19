#include "enemy.h"

//initializing the enemy counter, default ctor setting enemy to 'E' rather than gamepiece.
int enemy::enemies;
enemy::enemy()
{
	name = "Enemy";
	printindex = 'E';
	enemy::enemies++;
	enemylife = true;
	cout << "In enemy default ctor" << endl;
}

enemy::~enemy()
{
	cout << "In enemy dtor" << endl;
}


//enemy movement managing method which works very similiarly to the player's one, but with this one also taking the player's coordinates as variables 
//to be able to effectively move the enemy in accordance with the player.
void enemy::move(int px, int py)
{
	if (x < px) {
		x += 1;
		return;
	}
	if (x > px) {
		x -= 1;
		return;
	}
	if (y < py) {
		y += 1;
		return;
	}
	if (y > py) {
		y -= 1;
		return;
	}
	if (x == px && y == py) {
		return;
	}
}


//a method that calculates the chances for an enemy to plant a trap before he moves next.
//retuns 3 if the enemy should plant a trap, 2 if the enemy died while failing to plant one, or 1 in any other case.
int enemy::planttrap()
{
	srand((unsigned int)time(NULL));
	int planted = rand() % 4;
	if (planted == 3) {
		cout << "Watch out! enemy successfully planted a trap!" << endl;
		return 3;
	}
	int isdead = rand() % 20;
	if (isdead == 0){
		cout << "One down! " << enemies << "To go" << endl;
		enemy::enemies--;
		return 2;
	}
	return 1;
}
