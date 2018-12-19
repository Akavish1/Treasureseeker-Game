#include "treasureseeker.h"

//player class - several counters for the different aspects of the game, enemy and trap interraction methods
class player : public gamepiece {
private:
	string playername;
public:
	player();
	~player();
	int x, y;
	int throwingknives;
	int disarmedtraps;
	int enemieskilled;
	void playerdetails();
	bool spawnenemy();
	bool trapinteract();
	bool enemyinteract();
	//string move();
	void move(int px, int py);
	void findknives();
};