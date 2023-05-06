#include "Ludo.h"
#include "Board.h"
#include "Utility.h"
#include "Dice.h"
#include "Player.h"
#include "Piece.h"
#include <conio.h>
#include "Dice.h"
#include <stack>
#include <vector>
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
void Ludo::dice(Player* Ps, Dice &D)
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
			PlaySound(TEXT("diceroll"), NULL, SND_ASYNC);
			D.PrintDice(i);
		}
		Sleep(300);
		D.PrintDice(D.getdicevalue());
	}
	else if(r==3 && c==136)
	{	
		D.rolldice2();
		for (int i = 0; i < 6; i++)
		{
			Sleep(200);
			PlaySound(TEXT("diceroll"), NULL, SND_ASYNC);
			D.PrintDice(i);
		}
		Sleep(300);
		D.PrintDice(D.getdicevalue());
	}
}
void Ludo::restart(int &r,int &c,int &turn)
{
	if (res.empty())
		return;
	else
	{
		B = res.top();
		res.pop();
	}
	B->PrintBoard();
	turn = 0;
	turnmsg(this->P[turn]);
	getRowColbyLeftClick(r, c);
}
void Ludo::mousemovesc()
{
	int r, c;
	getRowColbyLeftClick(r, c);
	if (r == 3 && c == 121)
	{
		restart(r, c,this->T);
	}
	if (r != 3 || c != 121)
	{
		this->sr = r / 6;
		this->sc = c / 6;
	}
}
void Ludo::mousemovedc()
{
	int r, c;
	getRowColbyLeftClick(r, c);
	this->dr = r / 6;
	this->dc = c / 6;
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
	_getch();
	Dice D{};
	Piece* PsR = nullptr;
	Piece* PsG = nullptr;
	Piece* PsY = nullptr;
	Piece* PsB = nullptr;
	vector<int>Vs;
	B->PrintBoard();
	res.push(new Board(*B));
	while (true)
	{
		this->turnmsg(P[T]);
		dice(P[T], D);
		undo.push(new Board(*B));
		do
		{
			mousemovesc();
		} while (!B->isvalidsc(this->sr, this->sc, 15, P[T]));
		switch(T)
		{
		case RED:
			B->updateBoard(sr, sc, D.getdicevalue(), PsR);
			break;
		case GREEN:
			B->updateBoard(sr, sc,D.getdicevalue(), PsG);
			break;
		case BLUE:
			B->updateBoard(sr, sc,D.getdicevalue(), PsB);
			break;
		case YELLOW:
			B->updateBoard(sr, sc,D.getdicevalue(), PsY);
			break;
		}
		B->PrintBoard();
		Vs.push_back(D.getdicevalue());
		while (D.getdicevalue() == 6)
		{
			dice(P[T], D);
			Vs.push_back(D.getdicevalue());
			do
			{
				mousemovesc();
			} while (!B->isvalidsc(this->sr, this->sc, 15, P[T]));
			switch (T)
			{
			case RED:
				B->updateBoard(sr, sc, D.getdicevalue(), PsR);
				break;
			case GREEN:
				B->updateBoard(sr, sc, D.getdicevalue(), PsG);
				break;
			case BLUE:
				B->updateBoard(sr, sc, D.getdicevalue(), PsB);
				break;
			case YELLOW:
				B->updateBoard(sr, sc, D.getdicevalue(), PsY);
				break;
			}
			B->PrintBoard();
			if (D.getdicevalue() == 6)
				dice(P[T], D);
			Vs.push_back(D.getdicevalue());
			if (Vs[0] == 6 && Vs[1] == 6 && Vs[2] == 6)
			{
				B = undo.top();
				B->PrintBoard();
				break;
			}
		}
		Vs.clear();
		undo.pop();
		this->turnchange();
	}
}
Ludo::~Ludo()
{

}