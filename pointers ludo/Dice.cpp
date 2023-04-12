#include "Dice.h"
#include <iostream>
#include <conio.h>
#include <time.h>
using namespace std;

Dice::Dice()
{
	this->dicevalue = 0;
}
void Dice::rolldice()
{
	int N = rand() % 6;
	N = N + 1;
	dicevalue = N;
}
int Dice::getdicevalue()
{
	return this->dicevalue;
}