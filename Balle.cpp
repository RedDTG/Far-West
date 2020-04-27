#include "Balle.h"
#include <SFML\Graphics.hpp>

Balle::Balle(float posX, float posY) {
	this->presente = 1;
	this->balle = new sf::CircleShape(12.0);
	this->balle->setOutlineThickness(-2);
	this->balle->setOutlineColor(sf::Color::Black);
	this->balle->setPosition(posX, posY);
	this->balle->setFillColor(sf::Color::Yellow);
}

void Balle::balleTiree() {
	this->presente = 0;
	this->balle->setFillColor(sf::Color::Black);
}

void Balle::balleRechargee() {
	this->presente = 1;
	this->balle->setFillColor(sf::Color::Yellow);
}

void Balle::afficherBalle(sf::RenderWindow* window) {
	window->draw(*this->balle);
}