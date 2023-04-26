
#include <conio.h>
#include <Windows.h>
#include <SFML/Graphics.hpp>
using namespace std;

//void InsertAtEnd(int* Num, int size, int T);
void getRowColbyLeftClick(int& rpos, int& cpos);
void gotoRowCol(int rpos, int cpos);
void SetClr(int clr);
void hollowbox(int R, int C, int sr, int sc, char sym,int clr);
void box(int R, int C, int sr, int sc, char sym,int clr);
void static GetRowColbyLeftClick(int& rpos, int& cpos, sf::RenderWindow& window);
void print(sf::RenderWindow& window, string fname);