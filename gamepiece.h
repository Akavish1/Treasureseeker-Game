

//includes
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 9

#include <iostream>
#include <string>
#include <time.h>
#include <typeinfo>
using namespace std;

//the required methods and some get/set methods
class gamepiece {
protected:
	string name;
	char printindex;
public:
	gamepiece();
	gamepiece( gamepiece &newobj);
	~gamepiece();
	inline string getname();
	char getindex();
	inline void setname(string newname);
	void setindex(char newchar);
	virtual void move();
};
