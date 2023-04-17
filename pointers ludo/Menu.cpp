#include "Menu.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;


Menu::Menu(float wi, float hi)
{
	if (!font.loadFromFile("JMH Typewriter-Black.ttf")) {};
	mainmenu[0].setFont(font);
	mainmenu[0].setFillColor(Color::Red);
	mainmenu[0].setString("2");
	mainmenu[0].setCharacterSize(100);
	mainmenu[0].setPosition(sf::Vector2f(400,500));
	
	mainmenu[1].setFont(font);
	mainmenu[1].setFillColor(Color::Red);
	mainmenu[1].setString("3");
	mainmenu[1].setCharacterSize(100);
	mainmenu[1].setPosition(sf::Vector2f(600, 500));
	
	mainmenu[2].setFont(font);
	mainmenu[2].setFillColor(Color::Red);
	mainmenu[2].setString("4");
	mainmenu[2].setCharacterSize(100);
	mainmenu[2].setPosition(sf::Vector2f(800, 500));

	mainmenu[3].setFont(font);
	mainmenu[3].setFillColor(Color::Red);
	mainmenu[3].setString("6");
	mainmenu[3].setCharacterSize(100);
	mainmenu[3].setPosition(sf::Vector2f(1000, 500));

	mainmenuselect = -1;
}
void Menu::draw(RenderWindow& w)
{
	for (int i = 0; i < 4; i++)
	{
		w.draw(mainmenu[i]);
	}
}
void Menu::moveleft()
{
	if (mainmenuselect + 1 <= Max_main_menu)
	{
		mainmenu[mainmenuselect].setFillColor(Color::White);
		mainmenuselect++;
		if (mainmenuselect == 4)
			mainmenuselect = 0;
		mainmenu[mainmenuselect].setOutlineColor(Color::Red);
		mainmenu[mainmenuselect].setFillColor(Color::Blue);
	}
}
void Menu::moveright()
{
	if (mainmenuselect - 1 >= 0)
	{
		mainmenu[mainmenuselect].setFillColor(Color::White);
		mainmenuselect--;
		if (mainmenuselect == -1)
			mainmenuselect = 3;
		mainmenu[mainmenuselect].setOutlineColor(Color::Red);
		mainmenu[mainmenuselect].setFillColor(Color::Blue);
	}
}