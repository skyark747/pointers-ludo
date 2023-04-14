#include "Giti.h"
#include <iostream>
using namespace std;

Giti::Giti(Color C, int sr, int sc, Board* B, char s):
	Piece(C,sr,sc,B,s)
{
}

void Giti::draw()
{
	cout << this->sym;
}