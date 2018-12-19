#define SIZE 9

#include "gamepiece.h"

//treasureseeker class, defining board as static so that other classes are able to access it.
class treasureseeker {
public:
	treasureseeker();
	~treasureseeker();
	int  exrestore, eyrestore;
	static gamepiece board[SIZE][SIZE];
	void print();
	bool play();
};
