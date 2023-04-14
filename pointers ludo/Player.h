#pragma once
#include <string>
#include "Utility.h"
using namespace std;
enum Color { RED, GREEN, YELLOW, BLUE };
class Player
{
private:
	Color Clr;
	string name;
public:
	int* Num;
	int size;
	Player(Color clr, string _n);
	string getname();
	Color getclr();
};

