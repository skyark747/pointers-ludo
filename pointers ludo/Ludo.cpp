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
	while (true)
	{
		_getch();
		Dice D;
		D.rolldice();
		gotoRowCol(0, (15 * 6) + 2);
		cout << D.getdicevalue();
		Board B{};
		B.PrintBoard();
		D.PrintDice(D.getdicevalue());
		int r, c;
		/*getRowColbyLeftClick(r, c);
		std::cout << r << " " << c;*/
	}
}