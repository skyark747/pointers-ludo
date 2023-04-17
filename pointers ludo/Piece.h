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
	bool isAlive;

public:
	Piece(Color c, int sr, int sc,Board*Brd,char s);
	Color getColor();
	char getSym();
	bool isValidmove(int i, int j, int n);
	virtual void draw() = 0;
	void Die(int i, int j);
	bool OnStop(int i, int j);
	void Move(int& i, int& j, int n);
	void PlaceOnHome(int& i, int& j);
};
