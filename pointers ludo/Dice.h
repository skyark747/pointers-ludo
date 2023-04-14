#pragma once
class Dice
{
private:
	int dicevalue;
public:
	Dice();
	void rolldice(int*& Num, int& size);
	void PrintDice(int* Num, int size);
	void DrawBox(int Sc, int Dc, int R, int C, int n, int clr);
	int getdicevalue();
};

