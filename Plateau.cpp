#include "Plateau.h"

Plateau::Plateau(int largeur, int hauteur, sf::Font* fontArrows, sf::Font* fontPixel, sf::Font* fontTitre)
{
this->largeur = largeur;
this->hauteur = hauteur;
this->tableau.resize((__int64)largeur * (__int64)hauteur);
for (int i = 0; i < 9801; i++) {
	this->tableau[i] = this->randomCase(fontArrows, fontPixel, fontTitre);
}

//this->tableau[147] = new caseSheriff(fontArrows, fontPixel, fontTitre);
this->tableau[48] = new caseRien(fontArrows, fontPixel, fontTitre);
}

Case* Plateau::recuperer(int x, int y) {
	Case* caseRecup = tableau[((__int64)y * (__int64)this->largeur) + (__int64)x];
	//cout << "La case recup est la case " << ((y*this->largeur)+x) << " avec pour adresse " << caseRecup << endl;
	return caseRecup;
}

Case* Plateau::randomCase(sf::Font* fontArrows, sf::Font* fontPixel, sf::Font* fontTitre) {
	int randCase = 0;
	Case* laCase;
	randCase = rand() % 100 + 1;

	if (randCase <= 21) { laCase = new caseDiligence(fontArrows, fontPixel, fontTitre); }
	else if (randCase > 21 && randCase <= 42) { laCase = new caseTrain(fontArrows, fontPixel, fontTitre); }
	else if (randCase > 42 && randCase <= 63) { laCase = new caseRiviere(fontArrows, fontPixel, fontTitre); }
	else if (randCase > 63 && randCase <= 70) { laCase = new caseDuel(fontArrows, fontPixel, fontTitre); }
	else if (randCase > 70 && randCase <= 77) { laCase = new caseIndiens(fontArrows, fontPixel, fontTitre); }
	else if (randCase > 77 && randCase <= 84) { laCase = new caseSheriff(fontArrows, fontPixel, fontTitre); }
	else { laCase = new caseRien(fontArrows, fontPixel, fontTitre); }

	return laCase;
}
