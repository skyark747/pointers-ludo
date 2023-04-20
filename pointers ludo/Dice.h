#pragma once
class Dice
{
private:
	int dicevalue;
public:
	Dice();
	void rolldice();
	void rolldice2();
	void PrintDice(int n);
	void DrawBox(int Sc, int Dc, int R, int C, int n, int clr);
	int getdicevalue();
	bool isdiceclicked(int r,int c);
};

