#include "Player.h"
#include "Utility.h"
#include <iostream>
using namespace std;

Player::Player(Color C,string n)
{
	this->Clr = C;
	this->name = n;
}
string Player::getname()
{
	return name;
}
Color Player::getclr()
{
	return this->Clr;
}
