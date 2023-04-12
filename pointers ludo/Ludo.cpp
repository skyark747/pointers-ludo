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
	system("cls");
	gotoRowCol(20, 20);
	D.rolldice();
	cout << D.getdicevalue();
	cin >> a;
	Board B{};
	B.PrintBoard(); 
	int r, c;
	getRowColbyLeftClick(r, c);
	std::cout << r << " " << c;
}