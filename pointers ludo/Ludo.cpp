#include "Ludo.h"
#include "Board.h"
#include "Utility.h"
#include "Dice.h"
#include <conio.h>
#include <iostream>
using namespace std;

Ludo::Ludo()
{

}
Ludo::~Ludo()
{

}
void Ludo::Play()
{
	srand(time(0));
	int a;
	cin >> a;
	Dice D;
	D.rolldice();
	gotoRowCol(0, 0);
	Board B{};
	B.PrintBoard();
	D.PrintDice();
	int r, c;
	getRowColbyLeftClick(r, c);
	std::cout << r << " " << c;
}