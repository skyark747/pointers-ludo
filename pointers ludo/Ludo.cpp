#include "Ludo.h"
#include "Board.h"
#include "Utility.h"
#include <iostream>
using namespace std;

Ludo::Ludo()
{

}
Ludo::~Ludo()
{

}
void Ludo::Play()
{
	Board B{};
	B.PrintBoard(); 
	int r, c;
	getRowColbyLeftClick(r, c);
	std::cout << r << " " << c;
}