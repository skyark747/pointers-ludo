#pragma once
#include "Utility.h"
class Board;
class Piece
{
private:
	Color clr;
	int r;
	int	c;
	Board* B;
	char sym;

public:
	Piece(Color c, int sr, int sc,Board*Brd,char s);
	Color getColor();
};

