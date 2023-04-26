#include "logo.h"
#include "SFML/Graphics.hpp"
using namespace sf;

logo::logo(float x,float y)
{
	if (!f.loadFromFile("logo.ttf")) {};
	T[0].setFont(f);
	T[0].setFillColor(Color::Red);
	T[0].setString("Pointers studios");
	T[0].setCharacterSize(80);
	T[0].setPosition(Vector2f(1000, 100));

	T[1].setFont(f);
	T[1].setFillColor(Color::Red);
	T[1].setString("press Enter key to continue");
	T[1].setCharacterSize(50);
	T[1].setPosition(Vector2f(400, 700));
}
void logo::draw(RenderWindow& w)
{
	for (int i = 0; i < 2; i++) {
		w.draw(T[i]);
	}
}
