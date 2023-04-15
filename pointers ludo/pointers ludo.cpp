// pointers ludo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "Board.h"
#include "Ludo.h"
#include "Utility.h"
#include "Menu.h"
//#include <SFML/Graphics.hpp>
using namespace std;
//using namespace sf;

int main()
{
	/*RenderWindow menu(VideoMode(1300, 900), "Pointers's Ludo");
	Menu m(menu.getSize().x, menu.getSize().y);
	RectangleShape background;
	background.setSize(Vector2f(1300, 900));
	Texture pic;
	pic.loadFromFile("start.PNG");
	background.setTexture(&pic);
	while (menu.isOpen())
	{
		Event event;
		while (menu.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				menu.close();
			if (event.type == Event::KeyReleased)
			{
				if (event.key.code == Keyboard::Up)
				{
					m.moveup(); break;
				}
				else if (event.key.code == Keyboard::Down)
				{
					m.movedown(); break;
				}
			}
			int x = m.mainmenupressed();
			if (x == 0)
			{
				if (event.key.code == Keyboard::Enter) {
					Ludo L(2);
					L.Play();
					break;
				}
			}
			if (x == 1)
			{
				if (event.key.code == Keyboard::Enter) {
					Ludo L(3);
					L.Play();
					break;
				}
			}
			if (x == 2)
			{
				if (event.key.code == Keyboard::Enter) {
					Ludo L(4);
					L.Play();
				}
			}
		}
		menu.clear();
		menu.draw(background);
		m.draw(menu);
		menu.display();
	}*/

 	Ludo L(2);
	L.Play();
	return 0;
}

