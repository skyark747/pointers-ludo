// pointers ludo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "Board.h"
#include "Ludo.h"
#include "Utility.h"
#include "Menu.h"
#include "logo.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace std;
using namespace sf;

int main()
{
	RenderWindow menu(VideoMode(1400, 800), "Pointers's Ludo");
	Menu m(menu.getSize().x, menu.getSize().y);
	logo l(menu.getSize().x, menu.getSize().y);
	
	RectangleShape lg;
	lg.setSize(Vector2f(1400, 800));
	Texture p;
	p.loadFromFile("pointers.JPG");
	lg.setTexture(&p);

	RectangleShape background;
	background.setSize(Vector2f(1400, 800));
	Texture pic;
	pic.loadFromFile("maxres2.JPG");
	background.setTexture(&pic);

	SoundBuffer B;
	B.loadFromFile("voice.WAV");
	Sound s;
	s.setBuffer(B);
	
	while (menu.isOpen())
	{
		Event event;
		if (menu.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				menu.close();
			}
			if (event.type == Event::KeyReleased)
			{
				if (event.key.code == Keyboard::Enter)
				{
					RenderWindow start(VideoMode(1400, 800), "Pointers's Ludo");
					s.play();
					while (start.isOpen())
					{
						Event aevent;
						while (start.pollEvent(aevent))
						{
							if (aevent.type == sf::Event::Closed) {
								start.close();
							}
							if (aevent.type == Event::KeyReleased)
							{
								if (aevent.key.code == Keyboard::Right)
								{
									m.moveleft();
									break;
								}
								else if (aevent.key.code == Keyboard::Left)
								{
									m.moveright();
									break;
								}
								int x = m.mainmenupressed();
								if (x == 0)
								{
									if (aevent.key.code == Keyboard::Enter) {
										Ludo L(2);
										L.Play();
										break;
									}
								}
								if (x == 1) {
									if (aevent.key.code == Keyboard::Enter) {
										Ludo L(3);
										L.Play();
										start.close();
										break;
									}
								}
								if (x == 2) {
									if (aevent.key.code == Keyboard::Enter) {
										Ludo L(4);
										L.Play();
									}
								}
							}
						}
						menu.close();
						start.clear();
						start.draw(background);
						m.draw(start);
						start.display();

					}
					start.clear();
					start.draw(background);
					m.draw(start);
					start.display();
				}
			}
						
		}
		menu.clear();
		menu.draw(lg);
		l.draw(menu);
		menu.display();
	}

 	/*Ludo L(4);
	L.Play();*/
	return 0;
}
