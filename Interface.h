
#pragma once
#include <SFML/Graphics.hpp>
#include "Revolver.h"
#include "TitleScreen.h"
#include "Joueur.h"
#include "Boussole.h"
#include <cstdlib>
#include "Case.h"

class Interface
{
private:

	sf::RenderWindow* window;

	TitleScreen* unEcranTitre;
	Boussole* uneBoussole;

	sf::Font* fontPixel;
	sf::Font* fontTitre;
	sf::Font* fontLogo;
	sf::Font* fontArrows;

	sf::RectangleShape* separation;
	sf::RectangleShape* fenetre;
	sf::RectangleShape* barreVie;
	sf::RectangleShape* barreVieC;
	sf::RectangleShape* barreArgent;
	sf::RectangleShape* barreArgentC;
	sf::RectangleShape* graduation;

	sf::Text* jours;
	sf::Text* coeur;
	sf::Text* dollar;

public:
	Interface(int vieJ, int argentJ);
	void detectionEvents();
 
	sf::Font* getFontPixel() { return this->fontPixel; }
	sf::Font* getFontTitre() { return this->fontTitre; }
	sf::Font* getFontArrows() { return this->fontArrows; }
	sf::RenderWindow* getWindow() { return this->window; }
	
	void afficherAide();
	void afficherTitleScreen();
	void afficherInterface(int vieJ, int argentJ, int orientation, int jours, Case* laCase, Revolver* leRevolver);
	void afficherActionCase(Case* laCase, Joueur* leJoueur);
	void afficherActionMagasin(Case* laCase, Joueur* leJoueur);
	void afficherWait();
	void afficherFin(Joueur* leJoueur);
	void afficherCredits();
};

