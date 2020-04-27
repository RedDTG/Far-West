#pragma once
#include "Case.h"
#include <SFML/Graphics.hpp>

class Boussole
{
private:
	sf::Text* soleil;
	sf::CircleShape* boussole;
	sf::RectangleShape* ligne1;
	sf::RectangleShape* ligne2;

public:
	Boussole(sf::Font* fontLogo);
	void detectionSoleil(int orientation);
	void afficherBoussole(sf::RenderWindow* window, int orientation);

};

