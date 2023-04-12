#pragma once
#include "Piece.h"
class Giti :
    public Piece
{
public:
    Giti(Color C, int sr, int sc, Board* B, char s);
    virtual void draw();
};

