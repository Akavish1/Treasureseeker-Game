#include "gamepiece.h"


//the required treasure class, with a bool variable to tell whether the treasure is real or fake.
class treasure : public gamepiece {
private:
	bool isreal;
public:
	treasure();
	~treasure();
	void print();
	int x, y;
};
