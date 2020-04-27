#include "Magasin.h"

Magasin::Magasin(sf::Font* fontTitre, sf::Font* fontPixel) {
	this->pancarte = new sf::RectangleShape(sf::Vector2f(50.0, 125.0));
	this->pancarte->setOutlineThickness(-3);
	this->pancarte->setOutlineColor(sf::Color::Yellow);

	this->nom = new sf::Text();
	this->nom->setFillColor(sf::Color::Black);
	this->nom->setFont(*fontTitre);

	this->actionM = new sf::Text();
	this->actionM->setFont(*fontPixel);
}

void Magasin::afficher(sf::RenderWindow* window) {
	window->draw(*this->pancarte);
	window->draw(*this->nom);
}
void Magasin::actionMagasin(sf::RenderWindow* window, Joueur* leJoueur) {
	this->getActionM()->setFillColor(sf::Color::Red);
	this->getActionM()->setCharacterSize(35);
	this->getActionM()->setString("ERREUR");
	sf::FloatRect actionMRect = this->getActionM()->getLocalBounds();
	this->getActionM()->setOrigin(actionMRect.left + actionMRect.width / 2.0f, actionMRect.top + actionMRect.height / 2.0f);
	this->getActionM()->setPosition(window->getSize().x / 2.0f, 100.0);
	window->draw(*this->getActionM());
}

PasMagasin::PasMagasin(sf::Font* fontTitre, sf::Font* fontPixel) : Magasin(fontTitre, fontPixel) {
	this->getPancarte()->setFillColor(sf::Color::Transparent);
	this->getPancarte()->setOutlineColor(sf::Color::Transparent);
}
Armurerie::Armurerie(sf::Font* fontTitre, sf::Font* fontPixel) : Magasin(fontTitre, fontPixel) {
	sf::FloatRect pancarteRect = this->getPancarte()->getLocalBounds();
	this->getPancarte()->setOrigin(pancarteRect.width / 2.0f, pancarteRect.height / 2.0f);
	this->getPancarte()->setFillColor(sf::Color::Blue);
	this->getPancarte()->setPosition(405.0, 515.0);

	this->getNom()->setCharacterSize(20);
	this->getNom()->setString("STORE");
	this->getNom()->setRotation(-90);
	sf::FloatRect nomRect = this->getNom()->getLocalBounds();
	this->getNom()->setOrigin(nomRect.width / 2.0f, nomRect.height / 2.0f);
	this->getNom()->setPosition(410.0, 515.0);
}
Banque::Banque(sf::Font* fontTitre, sf::Font* fontPixel) : Magasin(fontTitre, fontPixel) {
	sf::FloatRect pancarteRect = this->getPancarte()->getLocalBounds();
	this->getPancarte()->setOrigin(pancarteRect.width / 2.0f, pancarteRect.height / 2.0f);
	this->getPancarte()->setFillColor(sf::Color(0, 145, 15));
	this->getPancarte()->setPosition(405.0, 515.0);

	this->getNom()->setCharacterSize(20);
	this->getNom()->setString("BANK");
	this->getNom()->setRotation(-90);
	sf::FloatRect nomRect = this->getNom()->getLocalBounds();
	this->getNom()->setOrigin(nomRect.width / 2.0f, nomRect.height / 2.0f);
	this->getNom()->setPosition(413.0, 515.0);
}
Saloon::Saloon(sf::Font* fontTitre, sf::Font* fontPixel) : Magasin(fontTitre, fontPixel) {
	sf::FloatRect pancarteRect = this->getPancarte()->getLocalBounds();
	this->getPancarte()->setOrigin(pancarteRect.width / 2.0f, pancarteRect.height / 2.0f);
	this->getPancarte()->setFillColor(sf::Color(200, 0, 0));
	this->getPancarte()->setPosition(595.0, 515.0);

	this->getNom()->setCharacterSize(15);
	this->getNom()->setString("SALOON");
	this->getNom()->setRotation(90);
	sf::FloatRect nomRect = this->getNom()->getLocalBounds();
	this->getNom()->setOrigin(nomRect.width / 2.0f, nomRect.height / 2.0f);
	this->getNom()->setPosition(590.0, 515.0);
}

void PasMagasin::actionMagasin(sf::RenderWindow* window, Joueur* leJoueur) { }

void Armurerie::actionMagasin(sf::RenderWindow* window, Joueur* leJoueur) {
	this->getActionM()->setFillColor(sf::Color::Red);
	this->getActionM()->setCharacterSize(35);
	this->getActionM()->setString("VOUS ENTREZ DANS L'ARMURERIE");
	sf::FloatRect actionMRect = this->getActionM()->getLocalBounds();
	this->getActionM()->setOrigin(actionMRect.left + actionMRect.width / 2.0f, actionMRect.top + actionMRect.height / 2.0f);
	this->getActionM()->setPosition(window->getSize().x / 2.0f, 100.0);
	window->draw(*this->getActionM());

	if (6 - leJoueur->getPistolet()->getNbBalles() == 0) {
		this->getActionM()->setFillColor(sf::Color::Yellow);
		this->getActionM()->setCharacterSize(30);
		this->getActionM()->setString("Votre revolver est déjà plein.");
		actionMRect = this->getActionM()->getLocalBounds();
		this->getActionM()->setOrigin(actionMRect.left + actionMRect.width / 2.0f, actionMRect.top + actionMRect.height / 2.0f);
		this->getActionM()->setPosition(window->getSize().x / 2.0f, 350.0);
		window->draw(*this->getActionM());

		this->getActionM()->setFillColor(sf::Color::Red);
		this->getActionM()->setCharacterSize(35);
		this->getActionM()->setString("Vous quittez l'armurerie.");
		actionMRect = this->getActionM()->getLocalBounds();
		this->getActionM()->setOrigin(actionMRect.left + actionMRect.width / 2.0f, actionMRect.top + actionMRect.height / 2.0f);
		this->getActionM()->setPosition(window->getSize().x / 2.0f, 500.0);
		window->draw(*this->getActionM());
	}
	else {
		if (leJoueur->getArgent() > 5 * (6 - leJoueur->getPistolet()->getNbBalles())) {
			this->getActionM()->setFillColor(sf::Color::Yellow);
			this->getActionM()->setCharacterSize(30);
			this->getActionM()->setString("Vous remplissez votre revolver de balles.");
			actionMRect = this->getActionM()->getLocalBounds();
			this->getActionM()->setOrigin(actionMRect.left + actionMRect.width / 2.0f, actionMRect.top + actionMRect.height / 2.0f);
			this->getActionM()->setPosition(window->getSize().x / 2.0f, 250.0);
			window->draw(*this->getActionM());

			this->getActionM()->setFillColor(sf::Color::Yellow);
			this->getActionM()->setCharacterSize(30);
			this->getActionM()->setString("  Vous achetez " + to_string(6 - leJoueur->getPistolet()->getNbBalles()) + " balles\nElles coutent 5$ chacune.");
			actionMRect = this->getActionM()->getLocalBounds();
			this->getActionM()->setOrigin(actionMRect.left + actionMRect.width / 2.0f, actionMRect.top + actionMRect.height / 2.0f);
			this->getActionM()->setPosition(window->getSize().x / 2.0f, 350.0);
			window->draw(*this->getActionM());

			this->getActionM()->setFillColor(sf::Color::Red);
			this->getActionM()->setCharacterSize(35);
			this->getActionM()->setString("Vous payez " + to_string(5 * (6 - leJoueur->getPistolet()->getNbBalles())) + "$ !");
			actionMRect = this->getActionM()->getLocalBounds();
			this->getActionM()->setOrigin(actionMRect.left + actionMRect.width / 2.0f, actionMRect.top + actionMRect.height / 2.0f);
			this->getActionM()->setPosition(window->getSize().x / 2.0f, 500.0);
			window->draw(*this->getActionM());
			leJoueur->addArgent(-5 * (6 - leJoueur->getPistolet()->getNbBalles()));
			leJoueur->getPistolet()->remplirBalles();
		}
		else {
			this->getActionM()->setFillColor(sf::Color::Yellow);
			this->getActionM()->setCharacterSize(30);
			this->getActionM()->setString("Vous n'avez pas assez d'argent pour\nremplir votre revolver de balles !");
			actionMRect = this->getActionM()->getLocalBounds();
			this->getActionM()->setOrigin(actionMRect.left + actionMRect.width / 2.0f, actionMRect.top + actionMRect.height / 2.0f);
			this->getActionM()->setPosition(window->getSize().x / 2.0f, 250.0);
			window->draw(*this->getActionM());

			this->getActionM()->setString("Le patron fait venir le sheriff !");
			actionMRect = this->getActionM()->getLocalBounds();
			this->getActionM()->setOrigin(actionMRect.left + actionMRect.width / 2.0f, actionMRect.top + actionMRect.height / 2.0f);
			this->getActionM()->setPosition(window->getSize().x / 2.0f, 350.0);
			window->draw(*this->getActionM());

			this->getActionM()->setFillColor(sf::Color::Red);
			this->getActionM()->setCharacterSize(35);
			this->getActionM()->setString("Vous êtes emmené au pénitencier !");
			actionMRect = this->getActionM()->getLocalBounds();
			this->getActionM()->setOrigin(actionMRect.left + actionMRect.width / 2.0f, actionMRect.top + actionMRect.height / 2.0f);
			this->getActionM()->setPosition(window->getSize().x / 2.0f, 500.0);
			window->draw(*this->getActionM());

			leJoueur->setFin(4);
		}
	}
	

	this->getActionM()->setCharacterSize(30);
	this->getActionM()->setFillColor(sf::Color::Yellow);
	this->getActionM()->setString("Appuyez sur [ESPACE] pour continuer");
	actionMRect = this->getActionM()->getLocalBounds();
	this->getActionM()->setOrigin(actionMRect.left + actionMRect.width / 2.0f, actionMRect.top);
	this->getActionM()->setPosition(sf::Vector2f(window->getSize().x / 2.0f, 680.0));
	window->draw(*this->getActionM());
}

void Saloon::actionMagasin(sf::RenderWindow* window, Joueur* leJoueur) {
	this->getActionM()->setFillColor(sf::Color::Red);
	this->getActionM()->setCharacterSize(35);
	this->getActionM()->setString("VOUS ENTREZ DANS LE SALOON");
	sf::FloatRect actionMRect = this->getActionM()->getLocalBounds();
	this->getActionM()->setOrigin(actionMRect.left + actionMRect.width / 2.0f, actionMRect.top + actionMRect.height / 2.0f);
	this->getActionM()->setPosition(window->getSize().x / 2.0f, 100.0);
	window->draw(*this->getActionM());

	this->getActionM()->setFillColor(sf::Color::Yellow);
	this->getActionM()->setCharacterSize(30);
	this->getActionM()->setString("Vous commandez un bon remontant pour 10$ !");
	actionMRect = this->getActionM()->getLocalBounds();
	this->getActionM()->setOrigin(actionMRect.left + actionMRect.width / 2.0f, actionMRect.top + actionMRect.height / 2.0f);
	this->getActionM()->setPosition(window->getSize().x / 2.0f, 250.0);
	window->draw(*this->getActionM());

	if (leJoueur->getArgent() >= 10) {
		this->getActionM()->setFillColor(sf::Color::Yellow);
		this->getActionM()->setCharacterSize(30);
		this->getActionM()->setString("Ca vous revigore le corps et l'esprit !");
		actionMRect = this->getActionM()->getLocalBounds();
		this->getActionM()->setOrigin(actionMRect.left + actionMRect.width / 2.0f, actionMRect.top + actionMRect.height / 2.0f);
		this->getActionM()->setPosition(window->getSize().x / 2.0f, 350.0);
		window->draw(*this->getActionM());

		this->getActionM()->setFillColor(sf::Color::Red);
		this->getActionM()->setCharacterSize(35);
		this->getActionM()->setString("Vous payez 10$ et sortez du saloon.");
		actionMRect = this->getActionM()->getLocalBounds();
		this->getActionM()->setOrigin(actionMRect.left + actionMRect.width / 2.0f, actionMRect.top + actionMRect.height / 2.0f);
		this->getActionM()->setPosition(window->getSize().x / 2.0f, 500.0);
		window->draw(*this->getActionM());
		leJoueur->addVie(100);
		leJoueur->addArgent(-10);
	}
	else {
		this->getActionM()->setFillColor(sf::Color::Yellow);
		this->getActionM()->setCharacterSize(30);
		this->getActionM()->setString("Vous n'avez pas assez d'argent !");
		actionMRect = this->getActionM()->getLocalBounds();
		this->getActionM()->setOrigin(actionMRect.left + actionMRect.width / 2.0f, actionMRect.top + actionMRect.height / 2.0f);
		this->getActionM()->setPosition(window->getSize().x / 2.0f, 350.0);
		window->draw(*this->getActionM());

		this->getActionM()->setFillColor(sf::Color::Red);
		this->getActionM()->setCharacterSize(35);
		this->getActionM()->setString("Le patron fait venir le sherif !");
		actionMRect = this->getActionM()->getLocalBounds();
		this->getActionM()->setOrigin(actionMRect.left + actionMRect.width / 2.0f, actionMRect.top + actionMRect.height / 2.0f);
		this->getActionM()->setPosition(window->getSize().x / 2.0f, 500.0);
		window->draw(*this->getActionM());
		leJoueur->addArgent(-10);
	}

	this->getActionM()->setCharacterSize(30);
	this->getActionM()->setFillColor(sf::Color::Yellow);
	this->getActionM()->setString("Appuyez sur [ESPACE] pour continuer");
	actionMRect = this->getActionM()->getLocalBounds();
	this->getActionM()->setOrigin(actionMRect.left + actionMRect.width / 2.0f, actionMRect.top);
	this->getActionM()->setPosition(sf::Vector2f(window->getSize().x / 2.0f, 680.0));
	window->draw(*this->getActionM());
}

void Banque::actionMagasin(sf::RenderWindow* window, Joueur* leJoueur) {
	this->getActionM()->setFillColor(sf::Color::Red);
	this->getActionM()->setCharacterSize(35);
	this->getActionM()->setString("VOUS BRAQUEZ LA BANQUE !");
	sf::FloatRect actionMRect = this->getActionM()->getLocalBounds();
	this->getActionM()->setOrigin(actionMRect.left + actionMRect.width / 2.0f, actionMRect.top + actionMRect.height / 2.0f);
	this->getActionM()->setPosition(window->getSize().x / 2.0f, 100.0);
	window->draw(*this->getActionM());

	this->getActionM()->setFillColor(sf::Color::Yellow);
	this->getActionM()->setCharacterSize(30);
	this->getActionM()->setString("Vous récupérez tout l'argent du coffre !");
	actionMRect = this->getActionM()->getLocalBounds();
	this->getActionM()->setOrigin(actionMRect.left + actionMRect.width / 2.0f, actionMRect.top + actionMRect.height / 2.0f);
	this->getActionM()->setPosition(window->getSize().x / 2.0f, 250.0);
	window->draw(*this->getActionM());

	int randBank;
	randBank = rand() % 3 + 1;

	if (randBank == 1) {
		if (leJoueur->getPistolet()->getNbBalles() == 0) {
			this->getActionM()->setFillColor(sf::Color::Yellow);
			this->getActionM()->setCharacterSize(30);
			this->getActionM()->setString("Vous perdez 10 PV dans l'incident !");
			actionMRect = this->getActionM()->getLocalBounds();
			this->getActionM()->setOrigin(actionMRect.left + actionMRect.width / 2.0f, actionMRect.top + actionMRect.height / 2.0f);
			this->getActionM()->setPosition(window->getSize().x / 2.0f, 350.0);
			window->draw(*this->getActionM());
			leJoueur->addVie(-10);
		}
		else {
			this->getActionM()->setFillColor(sf::Color::Yellow);
			this->getActionM()->setCharacterSize(30);
			this->getActionM()->setString("Vous perdez une balle dans l'incident !");
			actionMRect = this->getActionM()->getLocalBounds();
			this->getActionM()->setOrigin(actionMRect.left + actionMRect.width / 2.0f, actionMRect.top + actionMRect.height / 2.0f);
			this->getActionM()->setPosition(window->getSize().x / 2.0f, 350.0);
			window->draw(*this->getActionM());
			leJoueur->getPistolet()->tirerBalle();
		}
	}
	else {
		this->getActionM()->setFillColor(sf::Color::Yellow);
		this->getActionM()->setCharacterSize(30);
		this->getActionM()->setString("Vous arrivez à vous échapper sans égratinure");
		actionMRect = this->getActionM()->getLocalBounds();
		this->getActionM()->setOrigin(actionMRect.left + actionMRect.width / 2.0f, actionMRect.top + actionMRect.height / 2.0f);
		this->getActionM()->setPosition(window->getSize().x / 2.0f, 350.0);
		window->draw(*this->getActionM());
	}

	this->getActionM()->setFillColor(sf::Color::Red);
	this->getActionM()->setCharacterSize(35);
	this->getActionM()->setString("Vous sortez de la banque en courant\n         avec votre butin.");
	actionMRect = this->getActionM()->getLocalBounds();
	this->getActionM()->setOrigin(actionMRect.left + actionMRect.width / 2.0f, actionMRect.top + actionMRect.height / 2.0f);
	this->getActionM()->setPosition(window->getSize().x / 2.0f, 500.0);
	window->draw(*this->getActionM());
	leJoueur->addArgent(100);

	this->getActionM()->setCharacterSize(30);
	this->getActionM()->setFillColor(sf::Color::Yellow);
	this->getActionM()->setString("Appuyez sur [ESPACE] pour continuer");
	actionMRect = this->getActionM()->getLocalBounds();
	this->getActionM()->setOrigin(actionMRect.left + actionMRect.width / 2.0f, actionMRect.top);
	this->getActionM()->setPosition(sf::Vector2f(window->getSize().x / 2.0f, 680.0));
	window->draw(*this->getActionM());
}