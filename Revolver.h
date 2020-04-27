#pragma once
#include <SFML/Graphics.hpp>
#include "Balle.h"
#include <vector>
using namespace std;

class Revolver
{
private:
	vector<Balle*> balles;
	int nbBalles;
	sf::CircleShape* barillet;
	sf::CircleShape* milieuB;

public:
	Revolver();
	int getNbBalles() { return this->nbBalles; }
	void afficherRevolver(sf::RenderWindow* window);

	void tirerBalle() {
		this->balles[((__int64)this->nbBalles - 1)]->balleTiree();
		this->nbBalles = this->nbBalles - 1; }

	void remplirBalles();
};

