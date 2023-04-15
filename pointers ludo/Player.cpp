#include "Player.h"
#include "Utility.h"
#include <iostream>
using namespace std;

Player::Player(Color C,string n)
{
	this->Clr = C;
	this->name = n;
	this->size = 0;
	this->Num = nullptr;
}
Player::Player(int s)
{
	this->size = s;
}
string Player::getname()
{
	return name;
}
Color Player::getclr()
{
	return this->Clr;
}

