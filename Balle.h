#pragma once
#include <string>
#include <SFML\Graphics.hpp>
using namespace std;

class Balle
{
private:
	int presente;
	sf::CircleShape* balle;

public:
	Balle(float posX, float posY);
	void balleTiree();
	void balleRechargee();
	void afficherBalle(sf::RenderWindow* window);
};

