#pragma once
#include "Piece.h"
#include "Player.h"
class Redgiti:public Piece
{
public:
	Redgiti(Color C, int sr, int sc, Board* B, char s);
	virtual void draw();
};

