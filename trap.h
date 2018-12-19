#include "gamepiece.h"

//the required trap class with a static integer to be able to tell how many traps are currently in the game.
class trap : public gamepiece {
private:
	static int traps;
public:
	trap();
	~trap();
	int x, y;
};