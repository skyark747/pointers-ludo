#pragma once
#include <SFML/Graphics.hpp>
class logo
{
public:
	logo(float w, float h);
	void draw(sf::RenderWindow& window);
	int button()
	{
		return select;
	}
private:
	sf::Font f;
	sf::Text T[2];
	int select=0;
};

