#include "Piece.h"
#include "Board.h"
#include "Utility.h"
#include <iostream>
using namespace std;

Piece::Piece(Color c, int sr, int sc, Board* Brd,char s)
{
	this->clr = c;
	this->r = sr;
	this->c = sc;
	this->B = Brd;
	this->sym = s;
}
Color Piece::getColor()
{
	return this->clr;
}
char Piece::getSym()
{
	return this->sym;
}
bool Piece::isValidmove(int i, int j, int n)
{
	if (this->dir == RIGHT  && i == 7 && j + n > 7)
	{
		return false;
	}
	else if (this->dir == LEFT && i == 7 && j - n > 7)
	{
		return false;
	}
	else if (this->dir == DOWN && j == 7 && i + n > 7)
	{
		return false;
	}
	else if (this->dir == UP && j == 7 && i - n > 7)
	{
		return false;
	}
	return true;
}
