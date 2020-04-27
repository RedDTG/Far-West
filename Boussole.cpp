#include "Boussole.h"

Boussole::Boussole(sf::Font* fontLogo) {
	this->boussole = new sf::CircleShape(35.0);
    this->boussole->setFillColor(sf::Color(241, 241, 241));
    this->boussole->setPosition(800.0, 665.0);
    this->boussole->setOutlineColor(sf::Color(158, 158, 158));
    this->boussole->setOutlineThickness(-5);

    this->soleil = new sf::Text();
    this->soleil->setFillColor(sf::Color::Yellow);
    this->soleil->setCharacterSize(40);
    this->soleil->setFont(*fontLogo);
    this->soleil->setString("p");

    this->ligne1 = new sf::RectangleShape(sf::Vector2f(5, 70));
    this->ligne1->setFillColor(sf::Color(158, 158, 158));
    this->ligne1->setPosition(833.0, 665.0);

    this->ligne2 = new sf::RectangleShape(sf::Vector2f(70, 5));
    this->ligne2->setFillColor(sf::Color(158, 158, 158));
    this->ligne2->setPosition(800.0, 698.0);
}

void Boussole::afficherBoussole(sf::RenderWindow* window, int orientation) {
    this->detectionSoleil(orientation);

    window->draw(*this->boussole);
    window->draw(*this->ligne1);
    window->draw(*this->ligne2);
    window->draw(*this->soleil);
}

void Boussole::detectionSoleil(int orientation) {
    if (orientation == 1) { this->soleil->setPosition(821.0, 730.0); }
    else if (orientation == 2) { this->soleil->setPosition(763.0, 677.0); }
    else if (orientation == 3) { this->soleil->setPosition(820.0, 618.0); }
    else { this->soleil->setPosition(875.0, 670.0); }
}