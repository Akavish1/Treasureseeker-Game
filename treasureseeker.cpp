
#include "enemy.h"
#include "trap.h"
#include "treasure.h"


//object declarations.
player p;
treasure x;
enemy e;
trap *t, newtrap;
gamepiece gp, gt, ge;
gamepiece treasureseeker::board[SIZE][SIZE];

//a very advanced and sophisticated default ctor - now thats high tech!
treasureseeker::treasureseeker()
{
	//randomly spawning the player in the required manner.
	srand((unsigned int)time(NULL));
	int playerspawn = rand() % 4;
	if (playerspawn == 0) {
		board[0][0] = p;
		p.x = 0;
		p.y = 0;
	}
	if (playerspawn == 1) {
		board[0][8] = p;
		p.x = 0;
		p.y = 8;
	}
	if (playerspawn == 2) {
		board[8][0] = p;
		p.x = 8;
		p.y = 0;
	}
	if (playerspawn == 3) {
		board[8][8] = p;
		p.x = 8;
		p.y = 8;
	}
	//randomly spawning the treasure in the required manner.
	while (1) {
		x.x = rand() % 9;
		x.y = rand() % 9;
		if (board[x.x][x.y].getindex() != 'O') {
			continue;
		}
		if (board[x.x - 1][x.y].getindex() == 'P' || board[x.x + 1][x.y].getindex() == 'P' || board[x.x][x.y - 1].getindex() == 'P' || board[x.x][x.y + 1].getindex() == 'P') {
			continue;
		}
		board[x.x][x.y] = x;
		break;
	}
	//randomly spawning the enemy in the required manner.
	while (1) {
		e.x = rand() % 9;
		e.y = rand() % 9;
		if (board[e.x][e.y].getindex() != 'O') {
			continue;
		}
		if (board[e.x - 1][e.y].getindex() == 'P' || board[e.x + 1][e.y].getindex() == 'P' || board[e.x][e.y - 1].getindex() == 'P' || board[e.x][e.y + 1].getindex() == 'P') {
			continue;
		}
		board[e.x][e.y] = e;
		break;
	}
	//randomly calculating the amount of traps to spawn and then spawning them.
	int amountoftraps = rand() % 4 + 1;
	t = new trap[amountoftraps];
	for (int i = 0; i < amountoftraps; i++) {
		while (1) {
			t[i].x = rand() % 9;
			t[i].y = rand() % 9;
			if (board[t[i].x][t[i].y].getindex() != 'O') {
				continue;
			}
			board[t[i].x][t[i].y] = t[i];
			break;
		}
	}
}

//freeing memory
treasureseeker::~treasureseeker()
{
	delete[] t;
}

//printing the game's board
void treasureseeker::print()
{
	cout << endl;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cout << treasureseeker::board[i][j].getindex();
		}
		cout << endl;
	}
	cout << endl;
}


//the game management method - using various object methods to manage the player and enemy movements and interactions with other objects.
//returns true when the game ends.
bool treasureseeker::play() {
	board[p.x][p.y] = gp;
	gp = gt;
    p.move(p.x, p.y);
	p.findknives();
	gp = board[p.x][p.y];
	if (board[p.x][p.y].getindex() == 'T') {
		if (p.trapinteract() == false) {
			return true;
		}
		gp = gt;
	}
	if (board[p.x][p.y].getindex() == 'X') {
		x.print();
		return true;
	}
	board[p.x][p.y] = p;
	if (e.enemylife == true) {
		board[e.x][e.y] = ge;
		ge = gt;
		e.move(p.x, p.y);
		ge = board[e.x][e.y];
		if (board[e.x][e.y].getindex() == 'P') {
			if (p.enemyinteract() == false) {
				return true;
			}
			board[e.x][e.y] = p;
			e.enemylife = false;
		}
		board[e.x][e.y] = e;
	}
}