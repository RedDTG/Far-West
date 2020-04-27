#include "Joueur.h"

Joueur::Joueur() {
	this->fin = 0;
	this->vie = 100;
	this->argent = 100;
	this->x = 48;
	this->y = 0;
	this->pistolet = new  Revolver;
	this->orientation = 1;
	this->jours = 0;
}

int Joueur::getVie() { return this->vie; }
Revolver* Joueur::getPistolet() { return this->pistolet; }
int Joueur::getArgent() { return this->argent; }
int Joueur::getX() { return this->x; }
int Joueur::getY() { return this->y; }
int Joueur::getOrientation() { return this->orientation; }

void Joueur::deplacement(int deplacementX, int deplacementY, int modifOrientation) {
	this->jours = this->jours + 1;
	
	if (this->jours >= 200) { this->fin = 5; }

	if (this->x + (deplacementX) > 98) { this->x = 0; }
	else if (this->x + (deplacementX) < 0) { this->x = 98; }
	else { this->x = this->x + (deplacementX); }

	if (this->y + (deplacementY) > 98) { this->fin = 1; }
	else if (this->y + (deplacementY) < 0) { this->fin = 2; }
	else { this->y = this->y + (deplacementY); }

	this->orientation = this->orientation + modifOrientation; 
	if (this->orientation == 0) { this->orientation = 4; }
	else if (this->orientation == 5) { this->orientation = 1; }
	// 1: Nord | 2: Est | 3: Sud | 4: Ouest

	int deplacement = (deplacementX * 10) + deplacementY;
	// -10: Left | 1: Up | 10: Right
	
	if (deplacement == -10) { this->chemin.push_back(4); } //Left (4)
	else if (deplacement == 1) { this->chemin.push_back(1); } //Up (1)
	else { this->chemin.push_back(2); } //Right (2)

}
void Joueur::addVie(int modifVie) {
	if (this->vie + modifVie <= 0) { this->fin = 3;	}
	else if (this->vie + modifVie > 100) { this->vie = 100; }
	else { this->vie = this->vie + modifVie; }
}

void Joueur::addArgent(int modifArgent) {
	if (this->argent + modifArgent <= 0) { this->fin = 4; }
	else if (this->argent + modifArgent > 100) { this->argent = 100; }
	else { this->argent = this->argent + modifArgent; }
}