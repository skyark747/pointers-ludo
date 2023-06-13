#pragma once
#include <stack>
class Board;
class Player;
class Dice;
class Ludo
{
	int sr, sc, dr, dc;
	int k;
	Player* P[4];
	Board* B;
	int T;
public:
	Ludo(int c);
	int turnchange();
	void turnmsg(Player* Ps);
	void dice(Player*Ps, Dice &D);
	void mousemovesc(Dice &dc);
	void mousemovedc();
	bool isvaliddc(int dri, int dci, int D, Player* Ps);
	void Play();
	void restart(int &r,int&c,Dice& D);
	~Ludo();
};

