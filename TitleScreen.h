#pragma once
#include <SFML/Graphics.hpp>
#include "Joueur.h"

class TitleScreen
{
private:
	sf::Text* titre;
	sf::Text* credits;
	sf::Text* version;
	sf::Text* trigger;

	sf::Text* aide;

	sf::Text* wait;
	// sf::Text* tip;

	sf::Text* fin;

public:
	TitleScreen(sf::Font* fontTitre, sf::Font* fontPixel, sf::RenderWindow* window);

	void afficherCredits(sf::RenderWindow* window, sf::Font* fontTitre, sf::Font* fontPixel, sf::Font* fontLogo);
	void afficherFin(Joueur* leJoueur, sf::RenderWindow*, sf::Font* fontPixel, sf::Font* fontTitre);
	void afficherWait(sf::RenderWindow* window, sf::Font* fontPixel);
	void afficherTitre(sf::RenderWindow* window, sf::Font* fontTitre, sf::Font* fontPixel);
	void afficherAide(sf::RenderWindow* window, sf::Font* fontTitre, sf::Font* fontPixel);
};

