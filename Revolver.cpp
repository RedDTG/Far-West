#include "Revolver.h"

Revolver::Revolver() {
	this->nbBalles = 6;
    this->balles.push_back(new Balle(838.0, 33.0));
    this->balles.push_back(new Balle(866.0, 50.0));
    this->balles.push_back(new Balle(866.0, 82.0));
    this->balles.push_back(new Balle(838.0, 94.0));
    this->balles.push_back(new Balle(810.0, 82.0));
    this->balles.push_back(new Balle(810.0, 50.0));

    this->milieuB = new sf::CircleShape(15.0);
    this->barillet = new sf::CircleShape(50.0);
    this->barillet->setFillColor(sf::Color(158, 158, 158));
    this->milieuB->setFillColor(sf::Color::Black);
    this->barillet->setPosition(800.0, 25.0);
    this->milieuB->setPosition(835.0, 60.0);
}

void Revolver::afficherRevolver(sf::RenderWindow* window) {
    window->draw(*this->barillet);
    window->draw(*this->milieuB);
    for (int i = 0; i < 6; i++) {
        this->balles[i]->afficherBalle(window);
    }
}

void Revolver::remplirBalles() {
    this->nbBalles = 6;
    
    for (int i = 0; i < 6; i++) {
        this->balles[i]->balleRechargee();
    }
}