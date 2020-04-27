#pragma once
#include <vector>
#include "Case.h"
#include <ctime>
#include <iostream>
using namespace std;

class Plateau
{

private:
	int largeur;
	int hauteur;
	vector<Case*> tableau;


public:
	Plateau(int largeur, int hauteur, sf::Font* fontArrows, sf::Font* fontPixel, sf::Font* fontTitre);

	Case* randomCase(sf::Font* fontArrows, sf::Font* fontPixel, sf::Font* fontTitre);
	Case* recuperer(int x, int y);

};

