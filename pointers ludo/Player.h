#pragma once
#include <string>
#include "Utility.h"
using namespace std;
enum Color { RED, GREEN, YELLOW, BLUE};
class Player
{
private:
	Color Clr;
	string name;
public:
	int* Num;
	int size;
	Player(Color clr, string _n);
	Player(int s);
	string getname();
	Color getclr();
};

