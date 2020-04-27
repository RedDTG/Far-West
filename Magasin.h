#pragma once
#include <SFML/Graphics.hpp>
#include "Joueur.h"

class Magasin
{
private:
	int effetArgent;
	int effetVie;
	int effetBalles;

	sf::RectangleShape* pancarte;
	sf::Text* nom;

	sf::Text* actionM;

public:
	Magasin(sf::Font* fontTitre, sf::Font* fontPixel);
	void afficher(sf::RenderWindow* window);
	virtual void actionMagasin(sf::RenderWindow* window, Joueur* leJoueur);

	sf::Text* getActionM() { return this->actionM; }

	sf::RectangleShape* getPancarte() { return this->pancarte; }
	sf::Text* getNom() { return this->nom; }
};

class Armurerie : public Magasin
{
public:
	Armurerie(sf::Font* fontTitre, sf::Font* fontPixel);
	virtual void actionMagasin(sf::RenderWindow* window, Joueur* leJoueur);
};

class Banque : public Magasin
{
public:
	Banque(sf::Font* fontTitre, sf::Font* fontPixel);
	virtual void actionMagasin(sf::RenderWindow* window, Joueur* leJoueur);
};

class Saloon : public Magasin
{
public:
	Saloon(sf::Font* fontTitre, sf::Font* fontPixel);
	virtual void actionMagasin(sf::RenderWindow* window, Joueur* leJoueur);
};

class PasMagasin : public Magasin
{
public:
	PasMagasin(sf::Font* fontTitre, sf::Font* fontPixel);
	virtual void actionMagasin(sf::RenderWindow* window, Joueur* leJoueur);
};
