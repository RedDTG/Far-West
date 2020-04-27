#pragma once
#include <vector>
#include "Revolver.h"
using namespace std;

class Joueur
{
private:
	int vie;
	Revolver* pistolet;
	int argent;
	int x;
	int y;
	int jours;
	int orientation; // 1: Nord | 2: Est | 3: Sud | 4: Ouest
	int fin;

	vector<int> chemin; // 1: Up | 2: Right | 4: Left 

public:
	Joueur();
	int getJours() { return this->jours; }
	int getVie();
	Revolver* getPistolet();
	int getArgent();
	int getX();
	int getY();
	int getOrientation();

	int getFin() { return this->fin; }
	// 0: Pas fini   |  1: Victoire
	// 2: Sortie Sud |  3: Mort
	// 4: Prison     |  5: 200 jours

	void setFin(int fin) { this->fin = fin; }

	void deplacement(int deplacementX, int deplacementY, int modifOrientation);
	void addVie(int modifVie);
	void addArgent(int modifArgent);
};

