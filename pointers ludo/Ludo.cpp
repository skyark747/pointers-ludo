#include "Ludo.h"
#include "Board.h"
#include "Utility.h"
#include "Dice.h"
#include "Player.h"
#include "Piece.h"
#include <conio.h>
#include "Dice.h"
#include <iostream>
using namespace std;

Ludo::Ludo(int c)
{
	this->sr = 0;
	this->sc = 0;
	this->dr = 0;
	this->dc = 0;
	this->k = c;
	*this->P = new Player(k);
	if (this->P[0]->size == 2)
	{
		this->P[0] = new Player(RED, "Ahmed");
		this->P[1] = new Player(GREEN, "Mahnoor");
	}
	else if (this->P[0]->size == 3)
	{
		this->P[0] = new Player(RED, "Ahmed");
		this->P[1] = new Player(GREEN, "Mahnoor");
		this->P[2] = new Player(BLUE, "Soban");
	}
	else if (this->P[0]->size == 4)
	{
		this->P[0] = new Player(RED, "Ahmed");
		this->P[1] = new Player(GREEN, "Mahnoor");
		this->P[2] = new Player(BLUE, "Soban");
		this->P[3] = new Player(YELLOW, "Ifra");
	}
	this->B = new Board(15);
	this->T = RED;
}
int Ludo::turnchange()
{
	this->T = (T + 1) % this->k;
	return this->T;
}
void Ludo::turnmsg(Player* Ps)
{
	gotoRowCol(0,91);
	cout << Ps->getname() << "'s" << " turn\n";
}
void Ludo::dice(Player* Ps, Dice D)
{
	srand(time(0));
	int r, c;
	D.PrintDice(1);
	getRowColbyLeftClick(r, c);
	if (D.isdiceclicked(r, c))
	{
		D.rolldice();
		for (int i = 0; i < 6; i++)
		{
			Sleep(200);
			D.PrintDice(i);
		}
		Sleep(300);
		D.PrintDice(D.getdicevalue());
	}
}
void Ludo::mousemovesc()
{
	int r, c;
	getRowColbyLeftClick(r, c);
	this->sr = r/6;
	this->sc = c/6;
}
void Ludo::mousemovedc()
{
	int r, c;
	getRowColbyLeftClick(r, c);
	this->dr = r / 6;
	this->dc = c / 6;
}
bool Ludo::isvalidsc(int sri, int sci, int D, Player* Ps)
{
	if (sri < 0 || sri>D || sci < 0 || sci>D)
		return false;
	else
	{
		Piece* pc=B->getpiece(sri,sci);
		if (pc!=nullptr && (Ps->getclr() == pc->getColor()))
		{
			return true;
		}
	}
	return false;
}
bool Ludo::isvaliddc(int dri, int dci, int D, Player* Ps)
{
	if (dri < 0 || dri>D || dci < 0 || dci>D)
		return false;
	else
	{
		Piece* pc = B->getpiece(dri, dci);
		if (pc == nullptr)
		{
			return true;
		}
	}
	return false;
}
void Ludo::Play()
{
	Dice D{};
	B->PrintBoard();
	while (true)
	{
		this->turnmsg(P[T]); 
		dice(P[T], D);
		do
		{
			do
			{
				mousemovesc();
			} while (!isvalidsc(this->sr, this->sc, 15, P[T]));
			mousemovedc();
		} while (!isvaliddc(this->dr, this->dc, 15, P[T]));
		B->updateBoard(sr, sc, D.getdicevalue());
		B->PrintBoard();
		this->turnchange();
	}
}
Ludo::~Ludo()
{

}