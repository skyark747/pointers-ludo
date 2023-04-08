#pragma once
class Player
{
private:
	Color Clr;
	string name;
public:
	Player(Color clr, string _n);
	string getname();
	Color getclr();
};

