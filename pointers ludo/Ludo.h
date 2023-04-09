#pragma once

class Board;
class Player;

class Ludo
{
	Player* P;
	Board* B;
	int T;
public:
	Ludo();
	~Ludo();
	int turnchange();
	void move(int r, int c);
	void Play();
};

