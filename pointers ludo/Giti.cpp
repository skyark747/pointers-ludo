#include "Giti.h"
#include <iostream>
using namespace std;

Giti::Giti(Color C, int sr, int sc, Board* B, char s):
	Piece(C,sr,sc,B,s)
{
}

void Giti::draw()
{ 
	int x = 0;
	if (sym == 'R')
	{
		x = 4;
		cout << sym;
	}
	else if (sym == 'G')
	{
		x = 2;
		cout << sym;
	}
	else if (sym == 'Y')
	{
		x = 6;
		cout << sym;
	}
	else if (sym == 'B')
	{
		x = 1;
		cout << sym;
	}
	/*hollowbox(4, 4, (r * 6) + 1, (c * 6) + 1, -37, 15);
	box(2, 2, (r * 6) + 2, (c * 6) + 2, -37, x);*/
	//cout << this->sym;
}