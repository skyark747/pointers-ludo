#pragma once
class Piece;
class Board
{
	int dim = 15;
	int R = 6;
	int C = 6;
	Piece*** P;
public:
	//Board();
	void PrintBoard();
	bool CentralBox(int i, int j);
	bool ValidBox(int i, int j);
	bool HollowBox(int i, int j);
	void DrawBox(int Sc, int Dc, int R, int C, int i, int j);
	Piece* getpiece(int r,int c);
};

