#include "Dice.h"
#include "Utility.h"
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

void Dice::DrawBox(int Sc, int Dc, int R, int C, int n)
{
    //for (int ri = 0; ri < R; ri++)
    //{
    //    for (int ci = 0; ci < C; ci++)
    //    {
    //        if (s == ' ' && (ri == 0 || ci == 0 || ri == R - 1 || ci == C - 1))
    //        {
    //            SetClr(2);
    //            gotoRowCol(ri + Sc, Dc + ci);
    //            cout << sym;
    //            SetClr(n);
    //        }
    //        else if (ri == R / 2 && ci == C / 2 && hs != '-')
    //        {
    //            //SetClr(CLR);
    //            gotoRowCol(ri + Sc, Dc + ci);
    //            cout << sym;
    //            //SetClr(n);
    //        }
    //        else
    //        {
    //            gotoRowCol(ri + Sc, Dc + ci);
    //            cout << sym;
    //        }

    //    }
    //}
}


void Dice::PrintDice()
{
    gotoRowCol((15 / 2) * 6, (15 / 2) * 6);
	cout << dicevalue;
}