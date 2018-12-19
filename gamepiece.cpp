#include "gamepiece.h"

//trivial gamepiece class implementation as required
//i assumed that the print index for this class should be 'O' like in the first assignment - it originally says 'E' which seems more suitable for the enemy.
gamepiece::gamepiece()
{
	name = "Empty Cell";
	printindex = 'O';
}

gamepiece::gamepiece(gamepiece &newobj)
{
	name = newobj.name;
	printindex = newobj.printindex;
	cout << "In gamepiece cctor" << endl;
}

gamepiece::~gamepiece()
{
}

inline string gamepiece::getname()
{
	return name;
}

char gamepiece::getindex()
{
	return printindex;
}

inline void gamepiece::setname(string  newname)
{
	name = newname;
}

void gamepiece::setindex(char  newchar)
{
	printindex = newchar;
}

void gamepiece::move()
{
}



