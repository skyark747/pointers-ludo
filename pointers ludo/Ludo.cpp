#include "Ludo.h"
#include "Board.h"
#include "Utility.h"
#include "Dice.h"
#include "Player.h"
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
		for (int i = 0; i < 3; i++)
		{
			D.rolldice(P->Num, P->size);
		}
		gotoRowCol(0, (15 * 6) + 2);
		for (int i = 0; i < 3; i++)
		{
			cout << P->Num[i] << " ";
		}
		Board B{};
		B.PrintBoard();
		D.PrintDice(P->Num, P->size);
		int r, c;
		/*getRowColbyLeftClick(r, c);
		std::cout << r << " " << c;*/
	}
}