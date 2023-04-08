// pointers ludo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

// ludo board.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
using namespace std;

void getRowColbyLeftClick(int& rpos, int& cpos)
{
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    DWORD Events;
    INPUT_RECORD InputRecord;
    SetConsoleMode(hInput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
    do
    {
        ReadConsoleInput(hInput, &InputRecord, 1, &Events);
        if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
        {
            cpos = InputRecord.Event.MouseEvent.dwMousePosition.X;
            rpos = InputRecord.Event.MouseEvent.dwMousePosition.Y;
            break;
        }
    } while (true);
}
void gotoRowCol(int rpos, int cpos)
{
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = cpos;
    scrn.Y = rpos;
    SetConsoleCursorPosition(hOuput, scrn);
}
void SetClr(int clr)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), clr);
}

bool CentralBox(int i, int j)
{
    if ((i >= 6 && i <= 8) && (j >= 6 && j <= 8))
    {
        SetClr(0);
        return true;
    }
}
bool ValidBox(int i, int j)
{
    if ((i == 6 || i == 8) && (j == 6 || j == 8))
    {
        SetClr(15);
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
        return true;
    }
    return false;
}
bool HollowBox(int i, int j)
{
    if ((i == 1 && j == 1) || (i == 4 && j == 1) || (j == 4 && i == 1) || (i == 4 && j == 4) || (i == 1 && j == 10) || (i == 1 && j == 13) || (i == 4 && j == 10) || (i == 4 && j == 13) || (i == 10 && j == 1) || (i == 13 && j == 1) || (i == 10 && j == 4) || (i == 13 && j == 4) || (i == 10 && j == 10) || (i == 10 && j == 13) || (i == 13 && j == 10) || (i == 13 && j == 13))
        return true;
    return false;
}
void DrawBox(int Sc, int Dc, int R, int C, int i, int j)
{
    for (int ri = 0; ri < R; ri++)
    {
        for (int ci = 0; ci < C; ci++)
        {
            if (ValidBox(i, j)/*i == 6 || i == 7 || j == 6 || j == 7 || i == 8 || j == 8*/)
            {
                if (ri == 0 || ci == 0 || ri == R - 1 || ci == C - 1)
                {
                    SetClr(15);
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
void PrintBoard(char** B, int Dim, int R, int C)
{
    int clr = 8, Clr = 7, CLR = 15;
    for (int ri = 0; ri < Dim; ri++)
    {
        for (int ci = 0; ci < Dim; ci++)
        {
            if (!HollowBox(ri, ci))
            {
                if (/*(ri + ci) % 2 == 0*/ri <= 5 && ci <= 5)
                {
                    /*if (B[ri][ci] >= 'a' && B[ri][ci] <= 'z')
                    {
                        CLR = 4;
                    }
                    else if (B[ri][ci] >= 'A' && B[ri][ci] <= 'Z')
                    {
                        CLR = 8;
                    }*/
                    SetClr(4);
                    DrawBox(ri * R, ci * C, R, C, ri, ci);
                }
                else if (/*(ri + ci) % 2 == 0*/(ci > 7 && ci <= 14) && ri <= 5)
                {
                    /*if (B[ri][ci] >= 'a' && B[ri][ci] <= 'z')
                    {
                        CLR = 4;
                    }
                    else if (B[ri][ci] >= 'A' && B[ri][ci] <= 'Z')
                    {
                        CLR = 8;
                    }*/
                    SetClr(6);
                    DrawBox(ri * R, ci * C, R, C, ri, ci);
                }
                else if (/*(ri + ci) % 2 == 0*/(ri > 7 && ri <= 14) && ci <= 5)
                {
                    /*if (B[ri][ci] >= 'a' && B[ri][ci] <= 'z')
                    {
                        CLR = 4;
                    }
                    else if (B[ri][ci] >= 'A' && B[ri][ci] <= 'Z')
                    {
                        CLR = 8;
                    }*/
                    SetClr(1);
                    DrawBox(ri * R, ci * C, R, C, ri, ci);
                }
                else if (/*(ri + ci) % 2 == 0*/(ci > 7 && ci <= 14) && ri > 5)
                {
                    /*if (B[ri][ci] >= 'a' && B[ri][ci] <= 'z')
                    {
                        CLR = 4;
                    }
                    else if (B[ri][ci] >= 'A' && B[ri][ci] <= 'Z')
                    {
                        CLR = 8;
                    }*/
                    SetClr(2);
                    DrawBox(ri * R, ci * C, R, C, ri, ci);
                }
                else
                {
                    /*if (B[ri][ci] >= 'a' && B[ri][ci] <= 'z')
                    {
                        CLR = 4;
                    }
                    else if (B[ri][ci] >= 'A' && B[ri][ci] <= 'Z')
                    {
                        CLR = 8;
                    }*/
                    SetClr(12);
                    DrawBox(ri * R, ci * C, R, C, ri, ci);
                }
            }
        }
    }
    SetClr(6);
}


void init(char**& B)
{
    B = new char* [14] {};
    for (int i = 0; i < 14; i++)
    {
        B[i] = new char[14] {};
    }
}

int main()
{
    char** B;
    init(B);
    PrintBoard(B, 15, 6, 6);
}
