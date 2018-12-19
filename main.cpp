#include "enemy.h"
#include "trap.h"
#include "treasure.h"


//the main functions - avoiding circular dependencies, running as long as play remains false.
int main() {
	treasureseeker game;
	while (1) {
		game.print();
		if (game.play() == true) {
			break;
		}
	}

}