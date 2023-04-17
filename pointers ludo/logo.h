#pragma once
#include <SFML/Graphics.hpp>
class logo
{
public:
	logo(float w, float h);
	void draw(sf::RenderWindow& window);
private:
	sf::Font f;
	sf::Text T[2];
};

