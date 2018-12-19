#include "player.h"

//the required enemy class with an additional enemylife bool variable to be able to decide if an enemy is dead or alive.
class enemy : public gamepiece {
public:
	enemy();
	~enemy();
	bool enemylife;
	static int enemies;
	void move(int px, int py);
	int planttrap();
	int x, y;
};