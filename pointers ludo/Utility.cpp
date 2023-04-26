#include "Utility.h"
#include <conio.h>
#include <Windows.h>
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;


void InsertAtEnd(int*& Num, int& size, int T)
{
    int* HA = new int[size + 1];
    for (int i = 0; i < size; i++)
    {
        HA[i] = Num[i];
    }
    HA[size] = T;
    delete[]Num;
    size++;
    Num = HA;
}
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
void hollowbox(int R, int C, int sr, int sc, char sym, int clr)
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (i == 0 || i == R - 1 || j == 0 || j == C - 1)
            {
                SetClr(clr);
                gotoRowCol(sr + i, sc + j);
                cout << sym;
            }
        }
    }
}
void box(int R, int C, int sr, int sc, char sym,int clr)
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            SetClr(clr);
            gotoRowCol(sr + i, sc + j);
            cout << sym;
        }
    }
}
void print(sf::RenderWindow& window,string fname)
{
    sf::Texture temp;
    if (!temp.loadFromFile(fname)) // img ==> file name for image
    {
        throw("Unable to load img");
    }

    sf::Sprite s(temp);
    s.setScale(1, 1); // (width and heigth of image to be printed)
    int c, r;
    s.setPosition(0, 0); // position of image
    window.draw(s); // draw() will only draw image on backend, image will not display on screen
    window.display(); // display() will show image on screen
}
