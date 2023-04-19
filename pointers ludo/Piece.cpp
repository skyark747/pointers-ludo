#include "Piece.h"
#include "Board.h"
#include "Utility.h"
#include <iostream>
using namespace std;

Piece::Piece(Color c, int sr, int sc, Board* Brd,char s)
{
	this->clr = c;
	this->r = sr;
	this->c = sc;
	this->B = Brd;
	this->sym = s;
	this->isAlive = false;
	if (c == RED)
	{
		this->dir = RIGHT;
	}
	if (c == GREEN)
	{
		this->dir = DOWN;
	}
	if (c == YELLOW)
	{
		this->dir = UP;
	}
	if (c == BLUE)
	{
		this->dir = LEFT;
	}
}
Color Piece::getColor()
{
	return this->clr;
}
char Piece::getSym()
{
	return this->sym;
}
int Piece::Row()
{
	return r;
}
int Piece::Col()
{
	return c;
}
bool Piece::isValidmove(int i, int j, int n)
{
	if (this->dir == RIGHT  && i == 7 && j + n > 7)
	{
		return false;
	}
	else if (this->dir == LEFT && i == 7 && j - n > 7)
	{
		return false;
	}
	else if (this->dir == DOWN && j == 7 && i + n > 7)
	{
		return false;
	}
	else if (this->dir == UP && j == 7 && i - n > 7)
	{
		return false;
	}
	return true;
}
void Piece::PlaceOnHome(int& i, int& j)
{
	if (this->clr == RED)
	{
		i = 6;
		j = 1;
	}
	if (this->clr == GREEN)
	{
		i = 1;
		j = 8;
	}
	if (this->clr == BLUE)
	{
		i = 8;
		j = 13;
	}
	if (this->clr == YELLOW)
	{
		i = 13;
		j = 6;
	}
}
void Piece::Move(int& i, int& j, int n)
{
	if (this->isAlive == false && n == 6)
	{
		this->PlaceOnHome(i, j);
		this->isAlive = true;
	}
	else if (this->isAlive == true)
	{
		for (int ri = 0; ri < n; ri++)
		{
			switch (dir)
			{
			case UP:
				if (i - 1 == -1 || i - 1 == 5)
				{
					dir = RIGHT;
					break;
				}
				else if (i - 1 == 8)
				{
					dir = LEFT;
					i--;
					break;
				}
				break;
			case DOWN:
				if (i + 1 == 15 || i + 1 == 9)
				{
					dir = LEFT;
					break;
				}
				else if (i + 1 == 6)
				{
					dir = RIGHT;
					i++;
					break;
				}
				break;
			case LEFT:
				if (j - 1 == -1 || j - 1 == 5)
				{
					dir = UP;
					break;
				}
				else if (j - 1 == 8)
				{
					dir = DOWN;
					j--;
					break;
				}
				break;
			case RIGHT:
				if (j + 1 == 15 || j + 1 == 9)
				{
					dir = DOWN;
					break;
				}
				else if (j + 1 == 6)
				{
					dir = UP;
					j++;
					break;
				}
				break;
			}

			switch (dir)
			{
			case UP:
				i--;
				break;
			case DOWN:
				i++;
				break;
			case LEFT:
				j--;
				break;
			case RIGHT:
				j++;
				break;
			}
		}
	}
	this->r = i;
	this->c = j;
}
bool Piece::OnStop(int i, int j)
{
	if (i == 6 && j == 1)
	{
		return true;
	}
	else if (i == 6 && j == 12)
	{
		return true;
	}
	else if (i == 8 && j == 2)
	{
		return true;
	}
	else if (i == 8 && j == 13)
	{
		return true;
	}
	else if (i == 2 && j == 6)
	{
		return true;
	}
	else if (i == 1 && j == 8)
	{
		return true;
	}
	else if (i == 13 && j == 6)
	{
		return true;
	}
	else if (i == 12 && j == 8)
	{
		return true;
	}
	return false;
}
void Piece::Die(int i, int j)
{
	r = i;
	c = j;
	isAlive = false;
}