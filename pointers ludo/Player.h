#pragma once
#include <string>
#include "Utility.h"
using namespace std;
class Player
{
private:
	Color Clr;
	string name;
public:
	Player(Color clr, string _n);
	string getname();
	Color getclr();
};

