#include "Board.h"
#include "Utility.h"
#include "Player.h"
#include "Redgiti.h"
#include <iostream>
using namespace std;


Board::Board()
{
      this->P = new Piece * *[dim];
    for (int i = 0; i < dim; i++)
    {
        this->P[i] = new Piece*[dim];
        for (int j = 0; j < dim; j++)
        {
            if (i == 1 && j == 1 || i == 1 && j == 4)
            {
                this->P[i][j] = new Redgiti(RED, i, j, this, 'R');
            }
            else if (i == 4 && j == 1 || i == 4 && j == 4)
            {
                this->P[i][j] = new Redgiti(RED, i, j, this, 'R');
            }
            else if (i == 1 && j == 10 || i == 1 && j == 13)
            {
                this->P[i][j] = new Redgiti(RED, i, j, this, 'G');
            }
            else if (i == 4 && j == 10 || i == 4 && j == 13)
            {
                this->P[i][j] = new Redgiti(RED, i, j, this, 'G');
            }
            else if ((i == 10 && j == 1) || (i == 13 && j == 1) || (i == 10 && j == 4) || (i == 13 && j == 4))
            {
                this->P[i][j] = new Redgiti(RED, i, j, this, 'Y');
            }
            else if ((i == 10 && j == 10) || (i == 10 && j == 13) || (i == 13 && j == 10) || (i == 13 && j == 13))
            {
                this->P[i][j] = new Redgiti(RED, i, j, this, 'B');
            }
            else if (((i >= 6 && i <= 8) && (j >= 6 && j <= 8)))
            {
                this->P[i][j] = new Redgiti(RED, i, j, this, '*');
            }
            else if (((i >= 6 && i <= 8) || (j >= 6 && j <= 8)))
            {
                P[i][j] = nullptr;
            }
            else
                this->P[i][j] = new Redgiti(RED, i, j, this, '*');

        }
    }
}
Piece* Board::getpiece(int r,int c)
{
    return P[r][c];
}
bool Board::CentralBox(int i, int j)
{
    if ((i >= 6 && i <= 8) && (j >= 6 && j <= 8))
    {
        SetClr(0);
        return true;
    }
}
bool Board::ValidBox(int i, int j)
{
    if ((i == 6 || i == 8) && (j == 6 || j == 8))
    {
        SetClr(8);
        return true;
    }
    if (i == 6)
    {
        if (j == 1)
        {
            SetClr(4);
            return true;
        }
        if (j == 12)
        {
            SetClr(6);
            return true;
        }
    }
    if (i == 8)
    {
        if (j == 13)
        {
            SetClr(2);
            return true;
        }
        if (j == 2)
        {
            SetClr(1);
            return true;
        }
    }
    if (j == 8)
    {
        if (i == 1)
        {
            SetClr(6);
            return true;
        }
        if (i == 12)
        {
            SetClr(2);
            return true;
        }
    }
    if (j == 6)
    {
        if (i == 13)
        {
            SetClr(1);
            return true;
        }
        if (i == 2)
        {
            SetClr(4);
            return true;
        }
    }
    if (i == 7)
    {
        if (j >= 1 && j <= 6)
        {
            SetClr(4);
            return true;
        }
        if (j >= 8 && j < 14)
        {
            SetClr(2);
            return true;
        }
    }
    if (j == 7)
    {
        if (i >= 1 && i <= 6)
        {
            SetClr(6);
            return true;
        }
        if (i >= 8 && i < 14)
        {
            SetClr(1);
            return true;
        }
    }
    if (i == 6 || i == 7 || j == 6 || j == 7 || i == 8 || j == 8)
    {
        SetClr(15);
        return true;
    }
    return false;
}
bool Board::HollowBox(int i, int j)
{
    if ((i == 1 && j == 1) || (i == 4 && j == 1) || (j == 4 && i == 1) || (i == 4 && j == 4) || (i == 1 && j == 10) || (i == 1 && j == 13) || (i == 4 && j == 10) || (i == 4 && j == 13) || (i == 10 && j == 1) || (i == 13 && j == 1) || (i == 10 && j == 4) || (i == 13 && j == 4) || (i == 10 && j == 10) || (i == 10 && j == 13) || (i == 13 && j == 10) || (i == 13 && j == 13))
        return true;
    return false;
}
void Board::DrawBox(int Sc, int Dc, int R, int C, int i, int j)
{
    for (int ri = 0; ri < R; ri++)
    {
        for (int ci = 0; ci < C; ci++)
        {
            if (ValidBox(i, j)/*i == 6 || i == 7 || j == 6 || j == 7 || i == 8 || j == 8*/)
            {
                if (ri == 0 || ci == 0 || ri == R - 1 || ci == C - 1)
                {
                    SetClr(0);
                    gotoRowCol(ri + Sc, Dc + ci);
                    cout << char(-37);
                    SetClr(0);
                }
                else
                {
                    if (ValidBox(i, j))
                    {
                        cout << char(-37);
                    }
                }
            }
            else if (ri == R / 2 && ci == C / 2)
            {
                //SetClr(15);
                gotoRowCol(ri + Sc, Dc + ci);
                cout << char(-37);
                //SetClr(n);
            }
            else
            {
                gotoRowCol(ri + Sc, Dc + ci);
                cout << char(-37);
            }

        }
    }
    SetClr(10);
}
void Board::PrintBoard()
{
    for (int ri = 0; ri < dim; ri++)
    {
        for (int ci = 0; ci < dim; ci++)
        {
            if (P[ri][ci] == nullptr)
                cout << '-';
            else
                P[ri][ci]->draw();
        }
        cout << endl;
    }
   /* int clr = 8, Clr = 7, CLR = 15;
    for (int ri = 0; ri < 15; ri++)
    {
        for (int ci = 0; ci < 15; ci++)
        {
            if (!HollowBox(ri, ci))
            {
                if (ri <= 5 && ci <= 5)
                {

                    SetClr(4);
                    DrawBox(ri * 6, ci * 6, 6, 6, ri, ci);
                }
                else if ((ci > 7 && ci <= 14) && ri <= 5)
                {

                    SetClr(6);
                    DrawBox(ri * 6, ci * 6, 6, 6, ri, ci);
                }
                else if ((ri > 7 && ri <= 14) && ci <= 5)
                {

                    SetClr(1);
                    DrawBox(ri * 6, ci * 6, 6, 6, ri, ci);
                }
                else if ((ci > 7 && ci <= 14) && ri > 5)
                {
                    SetClr(2);
                    DrawBox(ri * 6, ci * 6, 6, 6, ri, ci);
                }
                else
                {
                    SetClr(12);
                    DrawBox(ri * 6, ci * 6, 6, 6, ri, ci);
                }
                if (ri > 5 && ri < 7 || ci>5 && ci < 9)
                {
                    SetClr(13);
                    DrawBox(ri * 6, ci * 6, 6, 6, ri, ci);
                }
            }
        }
    }
    SetClr(6);*/
}