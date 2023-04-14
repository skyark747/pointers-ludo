#pragma once
class Piece;
class Board
{
protected:
	int dim;
	int R = 6;
	int C = 6;
	Piece*** P;
public:
	Board(int D);
	void PrintBoard();
	bool CentralBox(int i, int j);
	bool ValidBox(int i, int j);
	bool HollowBox(int i, int j);
	void updateBoard(int sri, int sci, int dri, int dci);
	void DrawBox(int Sc, int Dc, int R, int C, int i, int j, int clr,Piece*Ps);
	Piece* getpiece(int r,int c);
};

