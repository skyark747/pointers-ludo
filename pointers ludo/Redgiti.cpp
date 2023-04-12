#include "Redgiti.h"
#include "Board.h"
#include "Player.h"
#include <iostream>
using namespace std;

Redgiti::Redgiti(Color C, int sr, int sc, Board* B, char s) :Piece(C, sr, sc, B, s)
{
};
void Redgiti::draw()
{
	if (this->clr == RED)
		cout << this->sym;
}
