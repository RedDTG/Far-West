#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "Joueur.h"
#include <Windows.h>
#include "Magasin.h"
using namespace std;

class Case
{
private:
	int haut;
	int droite;
	int gauche;

	Magasin* unMagasin;

	int type;
	//0: Rien    | 1: Diligence | 2: Train
	//3: Riviere | 4: Duel      | 5: Indiens
	//6: Sheriff

	int typeMagasin;
	//0: Rien | 1: Store | 2: Bank | 3: Saloon

	sf::RectangleShape* BatNO;
	sf::RectangleShape* BatNE;
	sf::RectangleShape* BatSE;
	sf::RectangleShape* BatSO;

	sf::Text* FlecheH;
	sf::Text* FlecheD;
	sf::Text* FlecheG;

	sf::RectangleShape* diligence;
	sf::RectangleShape* roue1;
	sf::RectangleShape* roue2;
	sf::RectangleShape* roue3;
	sf::RectangleShape* roue4;

	sf::RectangleShape* fleuve;

	sf::RectangleShape* wagon;
	sf::RectangleShape* fenetre1;
	sf::RectangleShape* fenetre2;
	sf::RectangleShape* fenetre3;
	sf::RectangleShape* toit;
	sf::CircleShape* roueT1;
	sf::CircleShape* roueT2;
	sf::RectangleShape* barreR;

	sf::Text* action;
	sf::Text* texte;

public:
	Case(int haut, int droite, int gauche, int type, sf::Font* pixelArrows, sf::Font* fontPixel, sf::Font* fontTitre);
	
	virtual void afficher(sf::RenderWindow* window);
	virtual void actionCase(sf::RenderWindow* window, Joueur* leJoueur);
	Magasin* randomMagasin(sf::Font* fontTitre, sf::Font* fontPixel);
	Magasin* getMagasin() { return this->unMagasin; }

	sf::Text* getFlecheH() { return this->FlecheH; }
	sf::Text* getFlecheD() { return this->FlecheD; }
	sf::Text* getFlecheG() { return this->FlecheG; }
	sf::Text* getTexte() { return this->texte; }
	sf::Text* getAction() { return this->action; }
	
	sf::RectangleShape* getDiligence() { return this->diligence; }
	sf::RectangleShape* getRoue1() { return this->roue1; }
	sf::RectangleShape* getRoue2() { return this->roue2; }
	sf::RectangleShape* getRoue3() { return this->roue3; }
	sf::RectangleShape* getRoue4() { return this->roue4; }

	sf::RectangleShape* getFleuve() { return this->fleuve; }

	sf::RectangleShape* getWagon() { return this->wagon; }
	sf::RectangleShape* getFenetre1() { return this->fenetre1; }
	sf::RectangleShape* getFenetre2() { return this->fenetre2; }
	sf::RectangleShape* getFenetre3() { return this->fenetre3; }
	sf::CircleShape* getRoueT1() { return this->roueT1; }
	sf::CircleShape* getRoueT2() { return this->roueT2; }
	sf::RectangleShape* getToit() { return this->toit; }
	sf::RectangleShape* getBarreR() { return this->barreR; }

	int getHaut();
	int getDroite();
	int getGauche();
	int getType() { return this->type; }
	int getTypeMagasin() { return this->typeMagasin; }
	
};

class caseDuel: public Case
{
public:
	caseDuel(sf::Font* pixelArrows, sf::Font* fontPixel, sf::Font* fontTitre);
	virtual void afficher(sf::RenderWindow* window);
	virtual void actionCase(sf::RenderWindow* window, Joueur* leJoueur);
};
class caseDiligence: public Case
{
public:
	caseDiligence(sf::Font* pixelArrows, sf::Font* fontPixel, sf::Font* fontTitre);
	virtual void afficher(sf::RenderWindow* window);
};
class caseTrain : public Case
{
public:
	caseTrain(sf::Font* pixelArrows, sf::Font* fontPixel, sf::Font* fontTitre);
	virtual void afficher(sf::RenderWindow* window);
};
class caseRiviere : public Case
{
public:
	caseRiviere(sf::Font* pixelArrows, sf::Font* fontPixel, sf::Font* fontTitre);
	virtual void afficher(sf::RenderWindow* window);
};
class caseIndiens : public Case
{
public:
	caseIndiens(sf::Font* pixelArrows, sf::Font* fontPixel, sf::Font* fontTitre);
	virtual void afficher(sf::RenderWindow* window);
	virtual void actionCase(sf::RenderWindow* window, Joueur* leJoueur);
};
class caseSheriff : public Case
{
public:
	caseSheriff(sf::Font* pixelArrows, sf::Font* fontPixel, sf::Font* fontTitre);
	virtual void afficher(sf::RenderWindow* window);
	virtual void actionCase(sf::RenderWindow* window, Joueur* leJoueur);
};
class caseRien : public Case
{
public:
	caseRien(sf::Font* pixelArrows, sf::Font* fontPixel, sf::Font* fontTitre);
	virtual void afficher(sf::RenderWindow* window);
};

