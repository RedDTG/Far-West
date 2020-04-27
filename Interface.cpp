#include "Interface.h"

Interface::Interface(int vieJ, int argentJ) {

	this->window = new sf::RenderWindow(sf::VideoMode(1000, 800), "Far West", sf::Style::Close);
	
	sf::Image icon;
	if (!icon.loadFromFile("logo.png")) { /*error*/ }

	this->window->setIcon(256, 256, icon.getPixelsPtr());
	
	this->fenetre = new sf::RectangleShape(sf::Vector2f(900.0, 450.0));
	this->fenetre->setFillColor(sf::Color::Transparent);
	this->fenetre->setOutlineThickness(-5);
	this->fenetre->setOutlineColor(sf::Color::Yellow);
	this->fenetre->setPosition(50.0, 150.0);

	this->fontPixel = new sf::Font();
	if (!this->fontPixel->loadFromFile("fonts/pixel_font.ttf")) { /*error*/ }

	this->fontTitre = new sf::Font();
	if (!fontTitre->loadFromFile("fonts/pixel_western.ttf")) { /*error*/ }

	this->fontLogo = new sf::Font();
	if (!fontLogo->loadFromFile("fonts/pixel_icon.ttf")) { /*error*/ }

	this->fontArrows = new sf::Font();
	if (!fontArrows->loadFromFile("fonts/pixel_arrows.ttf")) { /*error*/ }

	this->coeur = new sf::Text();
	coeur->setCharacterSize(50);
	coeur->setFillColor(sf::Color::Red);
	coeur->setFont(*this->fontLogo);
	coeur->setString("B");
	coeur->setPosition(50, 10);

	this->dollar = new sf::Text();
	dollar->setCharacterSize(65);
	dollar->setFillColor(sf::Color::Green);
	dollar->setFont(*this->fontPixel);
	dollar->setString("$");
	dollar->setPosition(52, 70);

	this->barreVie = new sf::RectangleShape(sf::Vector2f((vieJ*494/100), 44.0));
	this->barreVie->setFillColor(sf::Color::Red);
	this->barreVie->setPosition(108.0, 23.0);

	this->barreVieC = new sf::RectangleShape(sf::Vector2f(500.0, 50.0));
	this->barreVieC->setFillColor(sf::Color::Transparent);
	this->barreVieC->setOutlineThickness(-3);
	this->barreVieC->setOutlineColor(sf::Color(158, 158, 158));
	this->barreVieC->setPosition(105.0, 20.0);

	this->barreArgent = new sf::RectangleShape(sf::Vector2f((argentJ*494.0/100), 44.0));
	this->barreArgent->setFillColor(sf::Color::Green);
	this->barreArgent->setPosition(108.0, 88.0);

	this->barreArgentC = new sf::RectangleShape(sf::Vector2f(500.0, 50.0));
	this->barreArgentC->setFillColor(sf::Color::Transparent);
	this->barreArgentC->setOutlineThickness(-3);
	this->barreArgentC->setOutlineColor(sf::Color(158, 158, 158));
	this->barreArgentC->setPosition(105.0, 85.0);

	this->graduation = new sf::RectangleShape(sf::Vector2f(3.0, 5.0));
	this->graduation->setFillColor(sf::Color(158, 158, 158));
	sf::FloatRect gradRect = this->graduation->getLocalBounds();
	this->graduation->setOrigin(gradRect.left + gradRect.width / 2.0f, gradRect.top);
	this->graduation->setPosition(157.4, 23);

	this->separation = new sf::RectangleShape(sf::Vector2f(5.0, 150.0));
	this->separation->setFillColor(sf::Color::Yellow);
	sf::FloatRect sepRect = this->separation->getLocalBounds();
	this->separation->setOrigin(sepRect.left + sepRect.width / 2.0f,
		sepRect.top + sepRect.height / 2.0f);
	this->separation->setPosition(sf::Vector2f(window->getSize().x / 2.0f, 700));

	this->jours = new sf::Text();
	jours->setCharacterSize(40);
	jours->setFillColor(sf::Color::Yellow);
	jours->setFont(*this->fontPixel);
	jours->setPosition(555.0, 678.0);

	this->unEcranTitre = new TitleScreen(this->fontTitre, this->fontPixel, this->window);
	this->uneBoussole = new Boussole(this->fontLogo);
}

void Interface::detectionEvents() {
	sf::Event evnt;
	while (this->window->pollEvent(evnt))
	{
		switch (evnt.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		}
	}
}

void Interface::afficherTitleScreen() {
	this->unEcranTitre->afficherTitre(this->window, this->fontTitre, this->fontPixel);
}

void Interface::afficherAide() { this->unEcranTitre->afficherAide(this->window, this->fontTitre, this->fontPixel); }

void Interface::afficherInterface(int vieJ, int argentJ, int orientation, int jours, Case* laCase, Revolver* leRevolver) {
	this->barreVie->setSize(sf::Vector2f(vieJ * 494.0 / 100, 44.0));
	this->barreArgent->setSize(sf::Vector2f(argentJ * 494.0 / 100, 44.0));

	this->window->draw(*this->fenetre);
	this->window->draw(*this->barreVie);
	this->window->draw(*this->barreVieC);
	this->window->draw(*this->barreArgent);
	this->window->draw(*this->barreArgentC);
	this->window->draw(*this->coeur);
	this->window->draw(*this->dollar);
	this->window->draw(*this->separation);

	for (double f = 157.4; f < 600.0; f += 49.4) {
		this->window->draw(*this->graduation);
		this->graduation->setPosition(f, 23);
	}

	for (double f = 157.4; f < 600.0; f += 49.4) {
		this->window->draw(*this->graduation);
		this->graduation->setPosition(f, 88);
	}

	this->jours->setString("Jour " + to_string(jours));
	this->window->draw(*this->jours);

	leRevolver->afficherRevolver(this->window);
	this->uneBoussole->afficherBoussole(this->window, orientation);

	laCase->afficher(this->window);
}
void Interface::afficherActionCase(Case* laCase, Joueur* leJoueur) {
	laCase->actionCase(this->window, leJoueur);
}

void Interface::afficherWait() { this->unEcranTitre->afficherWait(this->window, this->fontPixel); }

void Interface::afficherFin(Joueur* leJoueur) {
	this->unEcranTitre->afficherFin(leJoueur, this->window, this->fontPixel, this->fontTitre);
}
void Interface::afficherCredits() {
	this->unEcranTitre->afficherCredits(this->window, this->fontTitre, this->fontPixel, this->fontLogo);
}

void Interface::afficherActionMagasin(Case* laCase, Joueur* leJoueur) {
	laCase->getMagasin()->actionMagasin(this->window, leJoueur);
}