#pragma once
#include "Utility.h"
#include "Player.h"

enum Direction { UP, DOWN, LEFT, RIGHT };

class Board;
class Piece
{
protected:
	Color clr;
	int r;
	int	c;
	Board* B;
	char sym;
	Direction dir;

public:
	Piece(Color c, int sr, int sc,Board*Brd,char s);
	Color getColor();
	char getSym();
	bool isValidmove(int i, int j, int n);
	virtual void draw() = 0;
	void Move(int& i, int& j, int n);
};

