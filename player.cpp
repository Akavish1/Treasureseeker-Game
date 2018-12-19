#include "player.h"


//default instance intialization
player::player()
{
	name = "Player";
	printindex = 'P';
	cout << "Enter your name " << endl;
	cin >> playername;
	throwingknives = 1;
	disarmedtraps = 0;
	enemieskilled = 0;
}


//dtor
player::~player()
{
	cout << "In player dtor" << endl;
}


//player details as required
void player::playerdetails()
{
	cout << endl;
	cout << "Player's details - " << endl << endl;
	cout << "Player name : " << name << endl;
	cout << "Throwing knives available : " << throwingknives << endl;
	cout << "Traps disarmed : " << disarmedtraps << endl;
	cout << "Enemies defeated " << enemieskilled << endl;
	cout << endl;
}


//a method that calculates whether the game should spawn an enemy after the player's recent movement
bool player::spawnenemy()
{
	srand((unsigned int)time(NULL));
	int newenemy = rand() % 20;
	if (newenemy == 19) {
		return true;
	}
	return false;
}


//the required trap interraction method, asks if the player wants to try to disarm and randomly checks if it should be disarmed according to the defined chances
//returns false if the player died, true if the trap will be disarmed
bool player::trapinteract()
{
	char input;
	cout << endl;
	cout << "Youve stepped on a trap!" << endl;
	cout << "Try to disarm it? if you fail to do so or pass, youll lose" << endl;
	cout << "Y to disarm, N to pass" << endl;
	cout << endl;
	while (1) {
		cin >> input;
		if (input != 'Y' && input != 'N' && input != 'y' && input != 'n') {
			cout << "Invalid input, enter Y or N only" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		break;
	}
	if (input == 'n' || input == 'N') {
		cout << endl;
		cout << "Game over - you gave up!";
		cout << endl;
			return false;
	}
	if (input == 'y' || input == 'Y') {
		srand((unsigned int)time(NULL));
		int disarm = rand() % 4;
		if (disarm == 3) {
			disarmedtraps++;
			cout << endl;
			cout << "Trap disarmed! total traps disarmed " << disarmedtraps << endl;
			cout << endl;
			return true;
		}
	}
	cout << endl;
	cout << "Game over - killed by a trap!" << endl;
	cout << endl;
	return false;
}


//enemy interraction method, randomly checks if the player will kill the enemy incase he has a throwing knife or decides that the player should die otherwise.
//returns false if the player dies, true if he kills an enemy.
bool player::enemyinteract()
{
	if (throwingknives > 0) {
		srand((unsigned int)time(NULL));
		int kill = rand() % 2;
		if (kill == 1) {
			enemieskilled++;
			cout << endl;
			cout << "You killed an enemy! total enemies killed : " << enemieskilled << endl;
			cout << endl;
			return true;
		}
	}
	cout << endl;
	cout << "Game over - enemy killed you!" << endl;
	cout << endl;
	return false;
}

//a method to calculate the chances for finding an additional throwing knife, incrementing the throwingknvies variable if so.
void player::findknives()
{
	srand((unsigned int)time(NULL));
	int findknife = rand() % 20;
	if (findknife == 19) {
		throwingknives++;
		cout << endl;
		cout << "Youve found a throwing knife! total knives : " << throwingknives << endl;
		cout << endl;
	}
}

//this method manages the player's movement.
//it might seem abit bloated, but every piece of input is being validated ,in every single way for any possible input, so that the program wont crush or behave in an undefined manner.
//this fuction gets the current player's coordinates and changes them according to the player's will, so that treasureseeker.cpp will simply use those values to reposition the player.
void player::move(int px, int py)
{
	int move;
	if (px == 0 && py == 0) {
		cout << "Youre in the uppermost left corner" << endl << "Enter 1 to go down, 2 to go right" << endl;
		cin >> move;
		while (cin.fail() || move > 2 || move < 1) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Incorrect input, must be a NUMBER between 1 and 4" << endl;
			cin >> move;
		}
		if (move == 1) {
			x += 1;
			return;
		}
		if (move == 2) {
			y += 1;
			return;
		}
	}
	if (px == 0 && py == 8) {
		cout << "Youre in the uppermost right corner" << endl << "Enter 1 to go down, 2 to go left" << endl;
		cin >> move;
		while (cin.fail() || move > 2 || move < 1) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Incorrect input, must be a NUMBER between 1 and 4" << endl;
			cin >> move;
		}
		if (move == 1) {
			x += 1;
			return;
		}
		if (move == 2) {
			y -= 1;
			return;
		}
	}
	if (px == 8 && py == 0) {
		cout << "Youre in the bottom left corner" << endl << "Enter 1 to go up, 2 to go right" << endl;
		cin >> move;
		while (cin.fail() || move > 2 || move < 1) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Incorrect input, must be a NUMBER between 1 and 4" << endl;
			cin >> move;
		}
		if (move == 1) {
			x -= 1;
			return;
		}
		if (move == 2) {
			y += 1;
			return;
		}
	}
	if (px == 8 && py == 8) {
		cout << "Youre in the bottom right corner" << endl << "Enter 1 to go up, 2 to go left" << endl;
		cin >> move;
		while (cin.fail() || move > 2 || move < 1) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Incorrect input, must be a NUMBER between 1 and 4" << endl;
			cin >> move;
		}
		if (move == 1) {
			x -= 1;
			return;
		}
		if (move == 2) {
			y -= 1;
			return;
		}
	}
	for (int i = 0; i < SIZE; i++) {
		if (px == 0 && py == i) {
			cout << "Youre in the uppermost line" << endl << "Enter 1 to go down, 2 to go left, 3 to go right" << endl;
			cin >> move;
			while (cin.fail() || move > 3 || move < 1) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Incorrect input, must be a NUMBER between 1 and 4" << endl;
				cin >> move;
			}
			if (move == 1) {
				x += 1;
				return;
			}
			if (move == 2) {
				y -= 1;
				return;
			}
			if (move == 3) {
				y += 1;
				return;
			}
		}
		if (px == 8 && py == i) {
			cout << "Youre in the bottom line" << endl << "Enter 1 to go up, 2 to go left, 3 to go right" << endl;
			cin >> move;
			while (cin.fail() || move > 3 || move < 1) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Incorrect input, must be a NUMBER between 1 and 4" << endl;
				cin >> move;
			}
			if (move == 1) {
				x -= 1;
				return;
			}
			if (move == 2) {
				y -= 1;
				return;
			}
			if (move == 3) {
				y += 1;
				return;
			}
		}
		if (px == i && py == 0) {
			cout << "Youre in the leftmost column" << endl << "Enter 1 to go down, 2 to go up, 3 to go right" << endl;
			cin >> move;
			while (cin.fail() || move > 3 || move < 1) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Incorrect input, must be a NUMBER between 1 and 4" << endl;
				cin >> move;
			}
			if (move == 1) {
				x += 1;
				return;
			}
			if (move == 2) {
				x -= 1;
				return;
			}
			if (move == 3) {
				y += 1;
				return;
			}
		}
		if (px == i && py == 8) {
			cout << "Youre in the rightmost column" << endl << "Enter 1 to go down, 2 to go up, 3 to go left" << endl;
			cin >> move;
			while (cin.fail() || move > 3 || move < 1) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Incorrect input, must be a NUMBER between 1 and 4" << endl;
				cin >> move;
			}
			if (move == 1) {
				x += 1;
				return;
			}
			if (move == 2) {
				x -= 1;
				return;
			}
			if (move == 3) {
				y -= 1;
				return;
			}
		}
	}
	cout << "Enter 1 to go down, 2 to go up, 3 to go left, 4 to go right" << endl;
	cin >> move;
	while (cin.fail() || move > 4 || move < 1) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Incorrect input, must be a NUMBER between 1 and 4" << endl;
		cin >> move;
	}
	if (move == 1) {
		x += 1;
		return;
	}
	if (move == 2) {
		x -= 1;
		return;
	}
	if (move == 3) {
		y -= 1;
		return;
	}
	if (move == 4) {
		y += 1;
		return;
	}
	return;
}





