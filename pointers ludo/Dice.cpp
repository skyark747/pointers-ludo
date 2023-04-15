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
    int N;
    N = rand() % 6;
    N = N + 1;
    dicevalue = N;
}
int Dice::getdicevalue()
{
	return this->dicevalue;
}
void Dice::DrawBox(int Sc, int Dc, int R, int C, int n, int clr)
{
    for (int ri = 0; ri < R; ri++)
    {
        for (int ci = 0; ci < C; ci++)
        {
            if (n == 1)
            {
                if (ri == R / 2 && ci == C / 2)
                {
                    SetClr(4);
                    gotoRowCol(ri + Sc, Dc + ci);
                    cout << char(-37);
                    SetClr(clr);
                }
                else
                {
                    gotoRowCol(ri + Sc, Dc + ci);
                    cout << char(-37);
                }
            }
            else if (n == 2)
            {
                if ((ri == 1 && ci == C / 2) || (ri == R - 2 && ci == C / 2))
                {
                    SetClr(4);
                    gotoRowCol(ri + Sc, Dc + ci);
                    cout << char(-37);
                    SetClr(clr);
                }
                else
                {
                    gotoRowCol(ri + Sc, Dc + ci);
                    cout << char(-37);
                }
            }
            else if (n == 3)
            {
                if (ri == ci && (ci==1 || ci == 3 || ci == 5))
                {
                    SetClr(4);
                    gotoRowCol(ri + Sc, Dc + ci);
                    cout << char(-37);
                    SetClr(clr);
                }
                else
                {
                    gotoRowCol(ri + Sc, Dc + ci);
                    cout << char(-37);
                }
            }
            else if (n == 4)
            {
                if ((ci == 1 || ci == C - 2) && (ri == 1 || ri == R - 2))
                {
                    SetClr(4);
                    gotoRowCol(ri + Sc, Dc + ci);
                    cout << char(-37);
                    SetClr(clr);
                }
                else
                {
                    gotoRowCol(ri + Sc, Dc + ci);
                    cout << char(-37);
                }
            }
            else if (n == 5)
            {
                if ((ci == 1 || ci == C - 2) && (ri == 1 || ri == R - 2))
                {
                    SetClr(4);
                    gotoRowCol(ri + Sc, Dc + ci);
                    cout << char(-37);
                    SetClr(clr);
                }
                else if (ci == C / 2 && ri == R / 2)
                {
                    SetClr(4);
                    gotoRowCol(ri + Sc, Dc + ci);
                    cout << char(-37);
                    SetClr(clr);
                }
                else
                {
                    gotoRowCol(ri + Sc, Dc + ci);
                    cout << char(-37);
                }
            }
            else if (n == 6)
            {
                if ((ci == 1 || ci == C - 2) && (ri == 1 || ri == R - 2 || ri== R / 2))
                {
                    SetClr(4);
                    gotoRowCol(ri + Sc, Dc + ci);
                    cout << char(-37);
                    SetClr(clr);
                }
                else
                {
                    gotoRowCol(ri + Sc, Dc + ci);
                    cout << char(-37);
                }
            }
           
        }
    }
}

void Dice::PrintDice(int n)
{
    SetClr(15);
    DrawBox(13 * 6, (15 * 6) + 2, 7, 7, n, 15);
}
bool Dice::isdiceclicked(int r,int c)
{
    for (int i = 0; i < 6; i++)
    {
        if (r == 13 * 6 && c == (15 * 6) + 2)
        {
            r + i; c + i;
        }
    }
    return false;
}