#pragma once
#include "Utility.h"
#include "Player.h"
class Board;
class Piece
{
protected:
	Color clr;
	int r;
	int	c;
	Board* B;
	char sym;

public:
	Piece(Color c, int sr, int sc,Board*Brd,char s);
	Color getColor();
	virtual void draw()=0;
};

