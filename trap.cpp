#include "trap.h"

//default ctor, incrementing the static traps variable for every trap object thats being created.
int trap::traps;
trap::trap()
{
	name = "Trap";
	printindex = 'T';
	trap::traps++;
	cout << "In trap default ctor" << endl;
}

trap::~trap()
{
	cout << "In trap dtor" << endl;
}
