#include "Piece.h"
#include "Board.h"
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

