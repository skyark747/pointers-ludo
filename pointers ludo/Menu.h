#pragma once
#include <SFML/Graphics.hpp>
#define Max_main_menu 4
class Menu
{
public:
	Menu(float w, float h);
	void draw(sf::RenderWindow& window);
	void moveright();
	void moveleft();
	int mainmenupressed()
	{
		return mainmenuselect;
	}
private:
	int mainmenuselect;
	sf::Font font;
	sf::Text mainmenu[Max_main_menu];
};

