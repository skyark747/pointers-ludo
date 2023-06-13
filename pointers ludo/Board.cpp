#include "Board.h"
#include "Utility.h"
#include "Player.h"
#include "Giti.h"
#include <iostream>
using namespace std;


Board::Board(int D)
{
    this->dim = D;
      this->P = new Piece * *[dim];
    for (int i = 0; i < dim; i++)
    {
        this->P[i] = new Piece*[dim];
        for (int j = 0; j < dim; j++)
        {
            if (i == 1 && j == 1 || i == 1 && j == 4)
            {
                this->P[i][j] = new Giti(RED, i, j, this, 'R');
            }
            else if (i == 4 && j == 1 || i == 4 && j == 4)
            {
                this->P[i][j] = new Giti(RED, i, j, this, 'R');
            }
            else if (i == 1 && j == 10 || i == 1 && j == 13)
            {
                this->P[i][j] = new Giti(GREEN, i, j, this, 'G');
            }
            else if (i == 4 && j == 10 || i == 4 && j == 13)
            {
                this->P[i][j] = new Giti(GREEN, i, j, this, 'G');
            }
            else if ((i == 10 && j == 1) || (i == 13 && j == 1) || (i == 10 && j == 4) || (i == 13 && j == 4))
            {
                this->P[i][j] = new Giti(YELLOW, i, j, this, 'Y');
            }
            else if ((i == 10 && j == 10) || (i == 10 && j == 13) || (i == 13 && j == 10) || (i == 13 && j == 13))
            {
                this->P[i][j] = new Giti(BLUE, i, j, this, 'B');
            }
            else if (((i >= 6 && i <= 8) && (j >= 6 && j <= 8)))
            {
                this->P[i][j] = new Giti(RED, i, j, this, '*');
            }
            else if (((i >= 6 && i <= 8) || (j >= 6 && j <= 8)))
            {
                P[i][j] = nullptr;
            }
            else
                this->P[i][j] = new Giti(RED, i, j, this, '*');

        }
    }
}
Board::Board(const Board& B)
{
    this->dim = B.dim;
    this->R = B.R;
    this->C = B.C;
    this->P = new Piece * *[dim];
    for (int ri = 0; ri < dim; ri++)
    {
        this->P[ri] = new Piece * [dim];
        for (int ci = 0; ci < dim; ci++)
        {
            this->P[ri][ci] = B.P[ri][ci];
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
            SetClr(1);
            return true;
        }
    }
    if (i == 8)
    {
        if (j == 13)
        {
            SetClr(1);
            return true;
        }
        if (j == 2)
        {
            SetClr(4);
            return true;
        }
    }
    if (j == 8)
    {
        if (i == 1)
        {
            SetClr(2);
            return true;
        }
        if (i == 12)
        {
            SetClr(6);
            return true;
        }
    }
    if (j == 6)
    {
        if (i == 13)
        {
            SetClr(6);
            return true;
        }
        if (i == 2)
        {
            SetClr(2);
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
            SetClr(1);
            return true;
        }
    }
    if (j == 7)
    {
        if (i >= 1 && i <= 6)
        {
            SetClr(2);
            return true;
        }
        if (i >= 8 && i < 14)
        {
            SetClr(6);
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
bool Board::isvalidsc(int sri, int sci, int D, Player* Ps)
{
    if (sri < 0 || sri>D || sci < 0 || sci>D)
        return false;
    else
    {
        if (this->P[sri][sci] == nullptr)
            return false;
        else if (this->P[sri][sci]->getSym() == '*')
            return false;
        else if (this->P[sri][sci]->getColor() == Ps->getclr())
        {
            return true;
        }
    }
    return false;
}
void Board::DrawBox(int Sc, int Dc, int R, int C, int i, int j, int clr,Piece*Ps)
{
    for (int ri = 0; ri < R; ri++)
    {
        for (int ci = 0; ci < C; ci++)
        {
            if (ValidBox(i, j))
            {
                if (ri == 0 || ci == 0 || ri == R - 1 || ci == C - 1)
                {
                    SetClr(0);
                    gotoRowCol(ri + Sc, Dc + ci);
                    cout << char(-37);
                    SetClr(0);
                }
                else if (ri == R / 2 && ci == C / 2)
                {
                    gotoRowCol(ri + Sc, Dc + ci);
                    if (Ps == nullptr || Ps->getSym() == '*')
                        cout << char(-37);
                }
                else
                {
                    if (ValidBox(i, j))
                    {
                        cout << char(-37);
                    }
                }
            }
            /*if (ri == R / 2 && ci == C / 2)
            {
            */    if (Ps == nullptr || Ps->getSym() == '*')
                {
                    gotoRowCol(ri + Sc, Dc + ci);

                    cout << char(-37);
                }
                /*else if (Ps != nullptr && Ps->getSym() != '*')
                {
                    if (Ps->getColor() == RED)
                        SetClr(4);
                    else if (Ps->getColor() == GREEN)
                        SetClr(2);
                    else if (Ps->getColor() == YELLOW)
                        SetClr(6);
                    else if (Ps->getColor() == BLUE)
                        SetClr(1);

                    Ps->draw();
                    SetClr(clr);
                }
            }*/
            else
            {
                    gotoRowCol(ri + Sc, Dc + ci);
                    cout << char(-37);
            }
            
        }
    }
    if (Ps != nullptr && Ps->getSym() != '*')
    {
        if (Ps->getColor() == RED)
            SetClr(4);
        else if (Ps->getColor() == GREEN)
            SetClr(2);
        else if (Ps->getColor() == YELLOW)
            SetClr(6);
        else if (Ps->getColor() == BLUE)
            SetClr(1);

        Ps->draw();
        SetClr(clr);
    }
    SetClr(10);
}
void Board::Dead(int i, int j)
{
    if (this->P[i][j]->getColor() == RED)
    {
        if (this->P[1][1] == nullptr)
        {
            this->P[1][1] = new Giti(RED, 1, 1, this, 'R');
        }
        else if (this->P[1][4] == nullptr)
        {
            this->P[1][4] = new Giti(RED, 1, 4, this, 'R');
        }
        else if (this->P[4][1] == nullptr)
        {
            this->P[4][1] = new Giti(RED, 4, 1, this, 'R');
        }
        else if (this->P[4][4] == nullptr)
        {
            this->P[4][4] = new Giti(RED, 4, 4, this, 'R');
        }
    }
    if (this->P[i][j]->getColor() == GREEN)
    {
        if (this->P[1][10] == nullptr)
        {
            this->P[1][10] = new Giti(GREEN, 1, 10, this, 'G');
        }
        else if (this->P[1][13] == nullptr)
        {
            this->P[1][13] = new Giti(GREEN, 1, 13, this, 'G');
        }
        else if (this->P[4][10] == nullptr)
        {
            this->P[4][10] = new Giti(GREEN, 4, 10, this, 'G');
        }
        else if (this->P[4][13] == nullptr)
        {
            this->P[4][13] = new Giti(GREEN, 4, 13, this, 'G');
        }
    }
    if (this->P[i][j]->getColor() == YELLOW)
    {
        if (this->P[10][1] == nullptr)
        {
            this->P[10][1] = new Giti(YELLOW, 10, 1, this, 'Y');
        }
        else if (this->P[13][1] == nullptr)
        {
            this->P[13][1] = new Giti(YELLOW, 13, 1, this, 'Y');
        }
        else if (this->P[10][4] == nullptr)
        {
            this->P[10][4] = new Giti(YELLOW, 10, 4, this, 'Y');
        }
        else if (this->P[13][4] == nullptr)
        {
            this->P[13][4] = new Giti(YELLOW, 13, 4, this, 'Y');
        }
    }
    if (this->P[i][j]->getColor() == BLUE)
    {
        if (this->P[10][10] == nullptr)
        {
            this->P[10][10] = new Giti(BLUE, 10, 10, this, 'B');
        }
        else if (this->P[10][13] == nullptr)
        {
            this->P[10][13] = new Giti(BLUE, 10, 13, this, 'B');
        }
        else if (this->P[13][10] == nullptr)
        {
            this->P[13][10] = new Giti(BLUE, 13, 10, this, 'B');
        }
        else if (this->P[13][13] == nullptr)
        {
            this->P[13][13] = new Giti(BLUE, 13, 13, this, 'B');
        }
    }

}
void Board::updateBoard(int &sri, int &sci, int n, Piece*& Ps)
{
    int i = sri;
    int j = sci;
    this->P[sri][sci]->Move(i, j, n);
    if (this->P[i][j] != nullptr && (this->P[i][j]->getSym() == this->P[sri][sci]->getSym()))
    {
        Ps = this->P[i][j];
    }
    if (i != sri || j != sci)
    {
        if (this->P[i][j] == nullptr)
        {
            this->P[i][j] = this->P[sri][sci];
        }
        else if (this->P[i][j]->getSym() != '*' && this->P[sri][sci]->getSym() != this->P[i][j]->getSym() && !this->P[i][j]->OnStop(i, j))
        {
            Dead(i, j);
            this->P[i][j] = this->P[sri][sci];
            this->P[i][j]->Die(this->P[i][j]->getSym());
        }
        else
        {
            this->P[i][j] = this->P[sri][sci];
        }
        if (Ps != nullptr && ((i != Ps->Row() || j != Ps->Col())) && Ps->getSym() == this->P[sri][sci]->getSym())
        {
            this->P[i][j] = this->P[sri][sci];
            if (Ps == nullptr)
                this->P[sri][sci] = nullptr;
            else
                this->P[sri][sci] = Ps;
        }
        else
        {
            this->P[sri][sci] = nullptr;
        }
        if (this->P[i][j]->Row() == 15/2 && this->P[i][j]->Col() == 15/2)
        {
            this->P[i][j] = new Giti(this->P[i][j]->getColor(), 15/2, 15/2, this, this->P[i][j]->getSym());

        }
    }
}
void Board::drawpiece(int Sc, int Dc, int R, int C, int i, int j, int clr, Piece* Ps)
{
    for (int ri = 0; ri < R; ri++)
    {
        for (int ci = 0; ci < C; ci++)
        {
            if (ri == R / 2 && ci == C / 2 && Ps != nullptr)
            {
                if (ri == R / 2 && ci == C / 2 && Ps->getSym() == 'R')
                {
                    hollowbox(4, 4, Sc + ri - 2, Dc + ci - 2, -37, 15);
                    box(2, 2, Sc+ri-1, Dc+ci-1, -37, 4);
                }
                if (ri == R / 2 && ci == C / 2 && Ps->getSym() == 'G')
                {
                    hollowbox(4, 4, Sc + ri - 2, Dc + ci - 2, -37, 15);
                    box(2, 2, Sc+ri-1, Dc+ci-1, -37, 10);
                }
                if (ri == R / 2 && ci == C / 2 && Ps->getSym() == 'B')
                {
                    hollowbox(4, 4, Sc + ri - 2, Dc + ci - 2, -37, 15);
                    box(2, 2, Sc+ri-1, Dc+ci-1, -37, 9);
                }
                if (ri == R / 2 && ci == C / 2 && Ps->getSym() == 'Y')
                {
 
                    hollowbox(4, 4, Sc + ri - 2, Dc + ci - 2, -37, 15);
                    box(2, 2, Sc+ri-1, Dc+ci-1, -37, 6);
                }
            }
        }
    }
    SetClr(10);
}
void Board::PrintBoard()
{
    hollowbox(7, 13, 0, 115, -37, 2);
    box(3, 3, 2, 120, -37, 4);
    hollowbox(7, 13, 0, 130, -37, 1);
    box(3, 3, 2, 135, -37, 4);
    int clr = 8, Clr = 7, CLR = 15;
    for (int ri = 0; ri < dim; ri++)
    {
        for (int ci = 0; ci < dim; ci++)
        {
            if (!HollowBox(ri, ci))
            {
                if (ri <= 5 && ci <= 5)
                {

                    SetClr(4);
                    DrawBox(ri * 6, ci * 6, 6, 6, ri, ci, 4,this->getpiece(ri,ci));
                    //drawpiece(ri * 6, ci * 6, 6, 6, ri, ci, 4, this->getpiece(ri, ci));
                }
                else if ((ci > 7 && ci <= 14) && ri <= 5)
                {

                    SetClr(2);
                    DrawBox(ri * 6, ci * 6, 6, 6, ri, ci, 2, this->getpiece(ri, ci));
                    //drawpiece(ri * 6, ci * 6, 6, 6, ri, ci, 4, this->getpiece(ri, ci));
                }
                else if ((ri > 7 && ri <= 14) && ci <= 5)
                {

                    SetClr(6);
                    DrawBox(ri * 6, ci * 6, 6, 6, ri, ci, 6, this->getpiece(ri, ci));
                    //drawpiece(ri * 6, ci * 6, 6, 6, ri, ci, 4, this->getpiece(ri, ci));
                }
                else if ((ci > 7 && ci <= 14) && ri > 5)
                {
                    SetClr(1);
                    DrawBox(ri * 6, ci * 6, 6, 6, ri, ci, 1, this->getpiece(ri, ci));
                    //drawpiece(ri * 6, ci * 6, 6, 6, ri, ci, 4, this->getpiece(ri, ci));
                }
                else
                {
                    SetClr(12);
                    DrawBox(ri * 6, ci * 6, 6, 6, ri, ci, 12, this->getpiece(ri, ci));
                    //drawpiece(ri * 6, ci * 6, 6, 6, ri, ci, 4, this->getpiece(ri, ci));
                }
                if (ri > 5 && ri < 7 || ci>5 && ci < 9)
                {
                    SetClr(13);
                    DrawBox(ri * 6, ci * 6, 6, 6, ri, ci, 13, this->getpiece(ri, ci));
                    //drawpiece(ri * 6, ci * 6, 6, 6, ri, ci, 4, this->getpiece(ri, ci));
                }
            }
            else
            {
                SetClr(0);
                DrawBox(ri * 6, ci * 6, 6, 6, ri, ci, 0, this->getpiece(ri, ci));
               // drawpiece(ri * 6, ci * 6, 6, 6, ri, ci, 4, this->getpiece(ri, ci));
            }
        }
    }
    SetClr(6);
}

