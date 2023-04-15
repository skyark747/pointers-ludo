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
void Dice::rolldice(int*& Num, int& size)
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
            //if (s == ' ' && (ri == 0 || ci == 0 || ri == R - 1 || ci == C - 1))
            //{
            //    SetClr(2);
            //    gotoRowCol(ri + Sc, Dc + ci);
            //    cout << char(-37);
            //    SetClr(n);
            //}
            //else if (ri == R / 2 && ci == C / 2)
            //{
            //    //SetClr(CLR);
            //    gotoRowCol(ri + Sc, Dc + ci);
            //    cout << char(-37);
            //    //SetClr(n);
            //}
            //else
            //{
            //    gotoRowCol(ri + Sc, Dc + ci);
            //    cout << char(-37);
            //}
        }
    }
}

void Dice::PrintDice(int* Num, int size)
{
    SetClr(15);
    for (int i = 0; i < size; i++)
    {
        DrawBox(1 * 6, (15 * 6) + 2, 7, 7, Num[i], 15);
    }
}