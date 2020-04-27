#include "Case.h"
#include <iostream>
using namespace std;

Case::Case(int haut, int droite, int gauche, int type, sf::Font* fontArrows, sf::Font* fontPixel, sf::Font* fontTitre) {
	this->haut = haut;
	this->droite = droite;
	this->gauche = gauche;
	this->type = type;
	this->unMagasin = this->randomMagasin(fontTitre, fontPixel);

	this->BatNO = new sf::RectangleShape(sf::Vector2f(400.0, 175.0));
	sf::FloatRect batRect = this->BatNO->getLocalBounds();
	this->BatNO->setFillColor(sf::Color::Transparent);
	this->BatNO->setOutlineColor(sf::Color::Yellow);
	this->BatNO->setOutlineThickness(-5);
	this->BatNO->setOrigin(batRect.left, batRect.top);
	this->BatNO->setPosition(50.0, 150.0);

	this->BatNE = new sf::RectangleShape(sf::Vector2f(400.0, 175.0));
	this->BatNE->setFillColor(sf::Color::Transparent);
	this->BatNE->setOutlineColor(sf::Color::Yellow);
	this->BatNE->setOutlineThickness(-5);
	this->BatNE->setOrigin(batRect.width, batRect.top);
	this->BatNE->setPosition(950.0, 150.0);

	this->BatSE = new sf::RectangleShape(sf::Vector2f(400.0, 175.0));
	this->BatSE->setFillColor(sf::Color::Transparent);
	this->BatSE->setOutlineColor(sf::Color::Yellow);
	this->BatSE->setOutlineThickness(-5);
	this->BatSE->setOrigin(batRect.width, batRect.height);
	this->BatSE->setPosition(950.0, 600.0);

	this->BatSO = new sf::RectangleShape(sf::Vector2f(400.0, 175.0));
	this->BatSO->setFillColor(sf::Color::Transparent);
	this->BatSO->setOutlineColor(sf::Color::Yellow);
	this->BatSO->setOutlineThickness(-5);
	this->BatSO->setOrigin(batRect.left, batRect.height);
	this->BatSO->setPosition(50.0, 600.0);

	this->FlecheG = new sf::Text();
	this->FlecheG->setCharacterSize(40);
	this->FlecheG->setFont(*fontArrows);
	this->FlecheG->setString('"');
	sf::FloatRect flecheRect = this->FlecheG->getLocalBounds();
	this->FlecheG->setOrigin(flecheRect.left + flecheRect.width / 2.0f,
		flecheRect.top + flecheRect.height / 2.0f);
	this->FlecheG->setPosition(50 + batRect.left + 2 * (batRect.width / 3),
		batRect.top + 150 + (9 * (batRect.height / 7)));

	this->FlecheH = new sf::Text();
	this->FlecheH->setCharacterSize(40);
	this->FlecheH->setFont(*fontArrows);
	this->FlecheH->setString('#');
	this->FlecheH->setOrigin(flecheRect.left + flecheRect.width / 2.0f,
		flecheRect.top + flecheRect.height / 2.0f);
	this->FlecheH->setPosition(50 + batRect.left + 18 * (batRect.width / 16),
		batRect.top + 150 + 2 * (batRect.height / 3));

	this->FlecheD = new sf::Text();
	this->FlecheD->setCharacterSize(40);
	this->FlecheD->setFont(*fontArrows);
	this->FlecheD->setString('!');
	this->FlecheD->setOrigin(flecheRect.left + flecheRect.width / 2.0f,
		flecheRect.top + flecheRect.height / 2.0f);
	this->FlecheD->setPosition(1000 - (50 + batRect.left + 2 * (batRect.width / 3)),
		batRect.top + 150 + 9 * (batRect.height / 7));

	this->diligence = new sf::RectangleShape(sf::Vector2f(150.0, 50.0));
	this->diligence->setFillColor(sf::Color(230, 0, 0));
	this->diligence->setOutlineColor(sf::Color::Black);
	this->diligence->setOutlineThickness(-2);
	sf::FloatRect diligenceRect = this->diligence->getLocalBounds();
	this->diligence->setOrigin(diligenceRect.left + diligenceRect.width / 2.0f,
		diligenceRect.top + diligenceRect.height / 2.0f);
	this->diligence->setPosition(500, 200);

	this->roue1 = new sf::RectangleShape(sf::Vector2f(40.0, 8.0));
	this->roue1->setFillColor(sf::Color(164, 57, 0));
	this->roue1->setOutlineColor(sf::Color::Black);
	this->roue1->setOutlineThickness(-2);
	sf::FloatRect roueRect = this->roue1->getLocalBounds();
	this->roue1->setOrigin(roueRect.left + roueRect.width / 2.0f,
		roueRect.top + roueRect.height / 2.0f);
	this->roue1->setPosition(450, 173);

	this->roue2 = new sf::RectangleShape(sf::Vector2f(40.0, 8.0));
	this->roue2->setFillColor(sf::Color(164, 57, 0));
	this->roue2->setOutlineColor(sf::Color::Black);
	this->roue2->setOutlineThickness(-2);
	this->roue2->setOrigin(roueRect.left + roueRect.width / 2.0f,
		roueRect.top + roueRect.height / 2.0f);
	this->roue2->setPosition(550, 173);

	this->roue3 = new sf::RectangleShape(sf::Vector2f(40.0, 8.0));
	this->roue3->setOutlineColor(sf::Color::Black);
	this->roue3->setOutlineThickness(-2);
	this->roue3->setFillColor(sf::Color(164, 57, 0));
	this->roue3->setOrigin(roueRect.left + roueRect.width / 2.0f,
		roueRect.top + roueRect.height / 2.0f);
	this->roue3->setPosition(550, 227);

	this->roue4 = new sf::RectangleShape(sf::Vector2f(40.0, 8.0));
	this->roue4->setOutlineColor(sf::Color::Black);
	this->roue4->setOutlineThickness(-2);
	this->roue4->setFillColor(sf::Color(164, 57, 0));
	this->roue4->setOrigin(roueRect.left + roueRect.width / 2.0f,
		roueRect.top + roueRect.height / 2.0f);
	this->roue4->setPosition(450, 227);

	this->fleuve = new sf::RectangleShape(sf::Vector2f(150.0, 440.0));
	this->fleuve->setFillColor(sf::Color::Cyan);
	this->fleuve->setOutlineColor(sf::Color::Blue);
	this->fleuve->setOutlineThickness(-3);
	this->fleuve->setPosition(750.0, 155);

	this->wagon = new sf::RectangleShape(sf::Vector2f(75.0, 200.0));
	this->wagon->setFillColor(sf::Color(10, 164, 0));
	this->wagon->setOutlineColor(sf::Color::Black);
	this->wagon->setOutlineThickness(-2);
	sf::FloatRect wagonRect = this->wagon->getLocalBounds();
	this->wagon->setOrigin(wagonRect.left + wagonRect.width / 2.0f,
		wagonRect.top + wagonRect.height / 2.0f);
	this->wagon->setPosition(150, 375);

	this->fenetre1 = new sf::RectangleShape(sf::Vector2f(25.0, 50.0));
	this->fenetre1->setFillColor(sf::Color(161, 241, 255));
	this->fenetre1->setOutlineColor(sf::Color::Black);
	this->fenetre1->setOutlineThickness(-2);
	sf::FloatRect fenetreRect = this->fenetre1->getLocalBounds();
	this->fenetre1->setOrigin(fenetreRect.left + fenetreRect.width / 2.0f,
		fenetreRect.top + fenetreRect.height / 2.0f);
	this->fenetre1->setPosition(140, 437);

	this->fenetre2 = new sf::RectangleShape(sf::Vector2f(25.0, 50.0));
	this->fenetre2->setFillColor(sf::Color(161, 241, 255));
	this->fenetre2->setOutlineColor(sf::Color::Black);
	this->fenetre2->setOutlineThickness(-2);
	this->fenetre2->setOrigin(fenetreRect.left + fenetreRect.width / 2.0f,
		fenetreRect.top + fenetreRect.height / 2.0f);
	this->fenetre2->setPosition(140, 375);

	this->fenetre3 = new sf::RectangleShape(sf::Vector2f(25.0, 50.0));
	this->fenetre3->setFillColor(sf::Color(161, 241, 255));
	this->fenetre3->setOutlineColor(sf::Color::Black);
	this->fenetre3->setOutlineThickness(-2);
	this->fenetre3->setOrigin(fenetreRect.left + fenetreRect.width / 2.0f,
		fenetreRect.top + fenetreRect.height / 2.0f);
	this->fenetre3->setPosition(140, 313);

	this->roueT1 = new sf::CircleShape(25);
	this->roueT1->setFillColor(sf::Color::Transparent);
	this->roueT1->setOutlineColor(sf::Color(83, 83, 83));
	this->roueT1->setOutlineThickness(-5);
	sf::FloatRect roueTRect = this->roueT1->getLocalBounds();
	this->roueT1->setOrigin(roueTRect.left + roueTRect.width / 2.0f,
		roueTRect.top + roueTRect.height / 2.0f);
	this->roueT1->setPosition(188, 430);

	this->roueT2 = new sf::CircleShape(25);
	this->roueT2->setFillColor(sf::Color::Transparent);
	this->roueT2->setOutlineColor(sf::Color(83, 83, 83));
	this->roueT2->setOutlineThickness(-5);
	this->roueT2->setOrigin(roueTRect.left + roueTRect.width / 2.0f,
		roueTRect.top + roueTRect.height / 2.0f);
	this->roueT2->setPosition(188, 320);

	this->toit = new sf::RectangleShape(sf::Vector2f(10.0, 220.0));
	this->toit->setFillColor(sf::Color(230, 0, 0));
	this->toit->setOutlineColor(sf::Color::Black);
	this->toit->setOutlineThickness(-2);
	sf::FloatRect toitRect = this->toit->getLocalBounds();
	this->toit->setOrigin(toitRect.left + toitRect.width / 2.0f,
		toitRect.top + toitRect.height / 2.0f);
	this->toit->setPosition(112, 375);

	this->barreR = new sf::RectangleShape(sf::Vector2f(5.0, 50.0));
	this->barreR->setFillColor(sf::Color(83, 83, 83));
	sf::FloatRect barreRect = this->barreR->getLocalBounds();
	this->barreR->setOrigin(barreRect.left + barreRect.width / 2.0f,
		barreRect.top + barreRect.height / 2.0f);

	this->texte = new sf::Text();
	this->texte->setCharacterSize(30);
	this->texte->setFillColor(sf::Color::Yellow);
	this->texte->setFont(*fontPixel);

	this->action = new sf::Text();
	this->action->setFont(*fontPixel);
}

Magasin* Case::randomMagasin(sf::Font* fontTitre, sf::Font* fontPixel) {
	int randMagasin = 0;
	Magasin* unMagasin;
	randMagasin = rand() % 25 + 1;
	//randMagasin = 3;

	if (randMagasin == 1 || randMagasin == 2) { unMagasin = new Armurerie(fontTitre, fontPixel); this->typeMagasin = 1; }
	else if (randMagasin == 3 || randMagasin == 4) { unMagasin = new Banque(fontTitre, fontPixel); this->typeMagasin = 2; }
	else if (randMagasin == 5) { unMagasin = new Saloon(fontTitre, fontPixel); this->typeMagasin = 3; }
	else { unMagasin = new PasMagasin(fontTitre, fontPixel); this->typeMagasin = 0; }

	return unMagasin;
}

int Case::getHaut() { return this->haut; };
int Case::getDroite() { return this->droite; };
int Case::getGauche() { return this->gauche; };

void Case::afficher(sf::RenderWindow* window) {
	window->draw(*this->BatNO);
	window->draw(*this->BatNE);
	window->draw(*this->BatSO);
	window->draw(*this->BatSE);

	window->draw(*this->FlecheG);
	window->draw(*this->FlecheH);
	window->draw(*this->FlecheD);

	this->unMagasin->afficher(window);
}
void Case::actionCase(sf::RenderWindow* window, Joueur* leJoueur) { }

caseDiligence::caseDiligence(sf::Font* pixelArrows, sf::Font* fontPixel, sf::Font* fontTitre) : Case(0, 1, 1, 1, pixelArrows, fontPixel, fontTitre) { }
void caseDiligence::afficher(sf::RenderWindow* window) {
	this->getFlecheG()->setFillColor(sf::Color::Green);
	this->getFlecheH()->setFillColor(sf::Color::Red);
	this->getFlecheD()->setFillColor(sf::Color::Green);

	this->getTexte()->setString("Une diligence vous\nbloque le passage !");
	sf::FloatRect texteRect = this->getTexte()->getLocalBounds();
	this->getTexte()->setOrigin(texteRect.left + (texteRect.width / 2.0f), texteRect.top + (texteRect.height / 2.0f));
	this->getTexte()->setPosition(250, 700.0);

	Case::afficher(window);
	window->draw(*this->getRoue1());
	window->draw(*this->getRoue2());
	window->draw(*this->getRoue3());
	window->draw(*this->getRoue4());
	window->draw(*this->getDiligence());

	window->draw(*this->getTexte());
}

caseDuel::caseDuel(sf::Font* pixelArrows, sf::Font* fontPixel, sf::Font* fontTitre) : Case( 1, 1, 1, 4, pixelArrows, fontPixel, fontTitre) { }
void caseDuel::afficher(sf::RenderWindow* window) {
	this->getFlecheG()->setFillColor(sf::Color::Green);
	this->getFlecheH()->setFillColor(sf::Color::Green);
	this->getFlecheD()->setFillColor(sf::Color::Green);

	this->getTexte()->setString("Utilisez les fleches\n pour vous déplacer\n  et [ESPACE] pour\n    vous arreter");
	sf::FloatRect aideRect = this->getTexte()->getLocalBounds();
	this->getTexte()->setOrigin(aideRect.left + aideRect.width / 2.0f, aideRect.top + aideRect.height / 2.0f);
	this->getTexte()->setPosition(250, 700.0);
	
	Case::afficher(window);
	window->draw(*this->getTexte());
};
void caseDuel::actionCase(sf::RenderWindow* window, Joueur* leJoueur) {

	this->getAction()->setFillColor(sf::Color::Red);
	this->getAction()->setCharacterSize(35);
	this->getAction()->setString("UN COWBOY VOUS PROVOQUE EN DUEL !");
	sf::FloatRect actionRect = this->getAction()->getLocalBounds();
	this->getAction()->setOrigin(actionRect.left + actionRect.width / 2.0f, actionRect.top + actionRect.height / 2.0f);
	this->getAction()->setPosition(window->getSize().x / 2.0f, 100.0);
	window->draw(*this->getAction());

	if (leJoueur->getPistolet()->getNbBalles() != 0) {
			leJoueur->getPistolet()->tirerBalle();
			this->getAction()->setFillColor(sf::Color::Yellow);
			this->getAction()->setCharacterSize(30);
			this->getAction()->setString("Vous tirez !");
			actionRect = this->getAction()->getLocalBounds();
			this->getAction()->setOrigin(actionRect.left + actionRect.width / 2.0f, actionRect.top + actionRect.height / 2.0f);
			this->getAction()->setPosition(window->getSize().x / 2.0f, 250.0);
			window->draw(*this->getAction());

			int randDuel;
			this->getAction()->setFillColor(sf::Color::Yellow);
			this->getAction()->setCharacterSize(30);
			randDuel = rand() % 100 + 1;

			if (randDuel <= 23) {
				this->getAction()->setString("Mais l'autre cowboy a tiré avant vous !");
				actionRect = this->getAction()->getLocalBounds();
				this->getAction()->setOrigin(actionRect.left + actionRect.width / 2.0f, actionRect.top + actionRect.height / 2.0f);
				this->getAction()->setPosition(window->getSize().x / 2.0f, 350.0);
				window->draw(*this->getAction());

				this->getAction()->setFillColor(sf::Color::Red);
				this->getAction()->setCharacterSize(35);
				this->getAction()->setString("Vous perdez 15 PV et 1 balle !");
				actionRect = this->getAction()->getLocalBounds();
				this->getAction()->setOrigin(actionRect.left + actionRect.width / 2.0f, actionRect.top + actionRect.height / 2.0f);
				this->getAction()->setPosition(window->getSize().x / 2.0f, 500.0);
				window->draw(*this->getAction());

				leJoueur->addVie(-15);
			}

			else if (randDuel > 25) {
				this->getAction()->setString("Vous remportez le duel !");
				actionRect = this->getAction()->getLocalBounds();
				this->getAction()->setOrigin(actionRect.left + actionRect.width / 2.0f, actionRect.top + actionRect.height / 2.0f);
				this->getAction()->setPosition(window->getSize().x / 2.0f, 350.0);
				window->draw(*this->getAction());

				this->getAction()->setFillColor(sf::Color::Red);
				this->getAction()->setCharacterSize(35);
				this->getAction()->setString("     Vous perdez 1 balle\nmais vous avez la vie sauve !");
				actionRect = this->getAction()->getLocalBounds();
				this->getAction()->setOrigin(actionRect.left + actionRect.width / 2.0f, actionRect.top + actionRect.height / 2.0f);
				this->getAction()->setPosition(window->getSize().x / 2.0f, 500.0);
				window->draw(*this->getAction());

			}
			
			else {
				this->getAction()->setString("Mais l'autre cowboy vise mieux que vous !");
				actionRect = this->getAction()->getLocalBounds();
				this->getAction()->setOrigin(actionRect.left + actionRect.width / 2.0f, actionRect.top + actionRect.height / 2.0f);
				this->getAction()->setPosition(window->getSize().x / 2.0f, 350.0);
				window->draw(*this->getAction());

				this->getAction()->setFillColor(sf::Color::Red);
				this->getAction()->setCharacterSize(35);
				this->getAction()->setString("Vous perdez 35 PV et 1 balle !");
				actionRect = this->getAction()->getLocalBounds();
				this->getAction()->setOrigin(actionRect.left + actionRect.width / 2.0f, actionRect.top + actionRect.height / 2.0f);
				this->getAction()->setPosition(window->getSize().x / 2.0f, 500.0);
				window->draw(*this->getAction());

				leJoueur->addVie(-35);
			}
		}
	else {
			this->getAction()->setFillColor(sf::Color::Yellow);
			this->getAction()->setCharacterSize(30);
			this->getAction()->setString("Vous n'avez plus de balles !");
			actionRect = this->getAction()->getLocalBounds();
			this->getAction()->setOrigin(actionRect.left + actionRect.width / 2.0f, actionRect.top + actionRect.height / 2.0f);
			this->getAction()->setPosition(window->getSize().x / 2.0f, 250.0);
			window->draw(*this->getAction());

			this->getAction()->setString("L'autre cowboy a tiré sans vous attendre !");
			actionRect = this->getAction()->getLocalBounds();
			this->getAction()->setOrigin(actionRect.left + actionRect.width / 2.0f, actionRect.top + actionRect.height / 2.0f);
			this->getAction()->setPosition(window->getSize().x / 2.0f, 350.0);
			window->draw(*this->getAction());

			this->getAction()->setFillColor(sf::Color::Red);
			this->getAction()->setCharacterSize(35);
			this->getAction()->setString("Vous perdez 20 PV !");
			actionRect = this->getAction()->getLocalBounds();
			this->getAction()->setOrigin(actionRect.left + actionRect.width / 2.0f, actionRect.top + actionRect.height / 2.0f);
			this->getAction()->setPosition(window->getSize().x / 2.0f, 500.0);
			window->draw(*this->getAction());
			leJoueur->addVie(-20);
		}

	this->getAction()->setCharacterSize(30);
	this->getAction()->setFillColor(sf::Color::Yellow);
	this->getAction()->setString("Appuyez sur [ESPACE] pour continuer");
	actionRect = this->getAction()->getLocalBounds();
	this->getAction()->setOrigin(actionRect.left + actionRect.width / 2.0f, actionRect.top);
	this->getAction()->setPosition(sf::Vector2f(window->getSize().x / 2.0f, 680.0));
	window->draw(*this->getAction());
}

caseTrain::caseTrain(sf::Font* pixelArrows, sf::Font* fontPixel, sf::Font* fontTitre) : Case(1, 1, 0, 2, pixelArrows, fontPixel, fontTitre) { }
void caseTrain::afficher(sf::RenderWindow* window) {
	this->getFlecheG()->setFillColor(sf::Color::Red);
	this->getFlecheH()->setFillColor(sf::Color::Green);
	this->getFlecheD()->setFillColor(sf::Color::Green);

	this->getTexte()->setString("Un wagon renversé vous\n  bloque le passage !");
	sf::FloatRect aideRect = this->getTexte()->getLocalBounds();
	this->getTexte()->setOrigin(aideRect.left + aideRect.width / 2.0f, aideRect.top + aideRect.height / 2.0f);
	this->getTexte()->setPosition(250, 700.0);

	Case::afficher(window);
	window->draw(*this->getTexte());
	window->draw(*this->getWagon());
	window->draw(*this->getFenetre1());
	window->draw(*this->getFenetre2());
	window->draw(*this->getFenetre3());
	window->draw(*this->getRoueT1());
	window->draw(*this->getRoueT2());
	window->draw(*this->getToit());

	this->getBarreR()->setPosition(188, 430);
	this->getBarreR()->setRotation(0);
	window->draw(*this->getBarreR());
	this->getBarreR()->setRotation(45);
	window->draw(*this->getBarreR());
	this->getBarreR()->setRotation(90);
	window->draw(*this->getBarreR());
	this->getBarreR()->setRotation(135);
	window->draw(*this->getBarreR());

	this->getBarreR()->setPosition(188, 320);
	this->getBarreR()->setRotation(0);
	window->draw(*this->getBarreR());
	this->getBarreR()->setRotation(45);
	window->draw(*this->getBarreR());
	this->getBarreR()->setRotation(90);
	window->draw(*this->getBarreR());
	this->getBarreR()->setRotation(135);
	window->draw(*this->getBarreR());

};

caseRiviere::caseRiviere(sf::Font* pixelArrows, sf::Font* fontPixel, sf::Font* fontTitre) : Case(1, 0, 1, 3, pixelArrows, fontPixel, fontTitre) { }
void caseRiviere::afficher(sf::RenderWindow* window) {
	this->getFlecheG()->setFillColor(sf::Color::Green);
	this->getFlecheH()->setFillColor(sf::Color::Green);
	this->getFlecheD()->setFillColor(sf::Color::Red);

	this->getTexte()->setString("  Un fleuve torrentiel\nvous bloque le passage !");
	sf::FloatRect aideRect = this->getTexte()->getLocalBounds();
	this->getTexte()->setOrigin(aideRect.left + aideRect.width / 2.0f, aideRect.top + aideRect.height / 2.0f);
	this->getTexte()->setPosition(250, 700.0);

	Case::afficher(window);
	window->draw(*this->getFleuve());
	window->draw(*this->getTexte());
};

caseIndiens::caseIndiens(sf::Font* pixelArrows, sf::Font* fontPixel, sf::Font* fontTitre) : Case(1, 1, 1, 5, pixelArrows, fontPixel, fontTitre) { }
void caseIndiens::afficher(sf::RenderWindow* window) {
	this->getFlecheG()->setFillColor(sf::Color::Green);
	this->getFlecheH()->setFillColor(sf::Color::Green);
	this->getFlecheD()->setFillColor(sf::Color::Green);

	this->getTexte()->setString("Utilisez les fleches\n pour vous déplacer\n  et [ESPACE] pour\n    vous arreter");
	sf::FloatRect aideRect = this->getTexte()->getLocalBounds();
	this->getTexte()->setOrigin(aideRect.left + aideRect.width / 2.0f, aideRect.top + aideRect.height / 2.0f);
	this->getTexte()->setPosition(250, 700.0);

	Case::afficher(window);
	window->draw(*this->getTexte());
};
void caseIndiens::actionCase(sf::RenderWindow* window, Joueur* leJoueur) {

	this->getAction()->setFillColor(sf::Color::Red);
	this->getAction()->setCharacterSize(35);
	this->getAction()->setString("DES INDIENS VOUS PRENNENT EN EMBUSCADE !");
	sf::FloatRect actionRect = this->getAction()->getLocalBounds();
	this->getAction()->setOrigin(actionRect.left + actionRect.width / 2.0f, actionRect.top + actionRect.height / 2.0f);
	this->getAction()->setPosition(window->getSize().x / 2.0f, 100.0);
	window->draw(*this->getAction());

	if (leJoueur->getPistolet()->getNbBalles() != 0) {
		leJoueur->getPistolet()->tirerBalle();
		this->getAction()->setFillColor(sf::Color::Yellow);
		this->getAction()->setCharacterSize(30);
		this->getAction()->setString("Vous leur proposez une balle contre votre liberté.");
		actionRect = this->getAction()->getLocalBounds();
		this->getAction()->setOrigin(actionRect.left + actionRect.width / 2.0f, actionRect.top + actionRect.height / 2.0f);
		this->getAction()->setPosition(window->getSize().x / 2.0f, 250.0);
		window->draw(*this->getAction());

		int randDuel;
		this->getAction()->setFillColor(sf::Color::Yellow);
		this->getAction()->setCharacterSize(30);
		randDuel = rand() % 100 + 1;

		if (randDuel <= 25) {
			this->getAction()->setString("Mais le chef indien refuse !");
			actionRect = this->getAction()->getLocalBounds();
			this->getAction()->setOrigin(actionRect.left + actionRect.width / 2.0f, actionRect.top + actionRect.height / 2.0f);
			this->getAction()->setPosition(window->getSize().x / 2.0f, 350.0);
			window->draw(*this->getAction());

			this->getAction()->setFillColor(sf::Color::Red);
			this->getAction()->setCharacterSize(35);
			this->getAction()->setString("Vous perdez 15 PV !");
			actionRect = this->getAction()->getLocalBounds();
			this->getAction()->setOrigin(actionRect.left + actionRect.width / 2.0f, actionRect.top + actionRect.height / 2.0f);
			this->getAction()->setPosition(window->getSize().x / 2.0f, 500.0);
			window->draw(*this->getAction());

			leJoueur->addVie(-15);
		}

		else if (randDuel > 25) {
			this->getAction()->setString("Ils acceptent votre proposition !");
			actionRect = this->getAction()->getLocalBounds();
			this->getAction()->setOrigin(actionRect.left + actionRect.width / 2.0f, actionRect.top + actionRect.height / 2.0f);
			this->getAction()->setPosition(window->getSize().x / 2.0f, 350.0);
			window->draw(*this->getAction());

			this->getAction()->setFillColor(sf::Color::Red);
			this->getAction()->setCharacterSize(35);
			this->getAction()->setString("     Vous perdez 1 balle\nmais vous avez la vie sauve !");
			actionRect = this->getAction()->getLocalBounds();
			this->getAction()->setOrigin(actionRect.left + actionRect.width / 2.0f, actionRect.top + actionRect.height / 2.0f);
			this->getAction()->setPosition(window->getSize().x / 2.0f, 500.0);
			window->draw(*this->getAction());
		}

	}
	else {
		this->getAction()->setFillColor(sf::Color::Yellow);
		this->getAction()->setCharacterSize(30);
		this->getAction()->setString("Vous n'avez pas de balles à leur échanger !");
		actionRect = this->getAction()->getLocalBounds();
		this->getAction()->setOrigin(actionRect.left + actionRect.width / 2.0f, actionRect.top + actionRect.height / 2.0f);
		this->getAction()->setPosition(window->getSize().x / 2.0f, 250.0);
		window->draw(*this->getAction());

		this->getAction()->setString("Vous parvenez à leur échapper\n  avec quelques blessures !");
		actionRect = this->getAction()->getLocalBounds();
		this->getAction()->setOrigin(actionRect.left + actionRect.width / 2.0f, actionRect.top + actionRect.height / 2.0f);
		this->getAction()->setPosition(window->getSize().x / 2.0f, 350.0);
		window->draw(*this->getAction());

		this->getAction()->setFillColor(sf::Color::Red);
		this->getAction()->setCharacterSize(35);
		this->getAction()->setString("Vous perdez 25 PV !");
		actionRect = this->getAction()->getLocalBounds();
		this->getAction()->setOrigin(actionRect.left + actionRect.width / 2.0f, actionRect.top + actionRect.height / 2.0f);
		this->getAction()->setPosition(window->getSize().x / 2.0f, 500.0);
		window->draw(*this->getAction());

		leJoueur->addVie(-25);
	}

	this->getAction()->setCharacterSize(30);
	this->getAction()->setFillColor(sf::Color::Yellow);
	this->getAction()->setString("Appuyez sur [ESPACE] pour continuer");
	actionRect = this->getAction()->getLocalBounds();
	this->getAction()->setOrigin(actionRect.left + actionRect.width / 2.0f, actionRect.top);
	this->getAction()->setPosition(sf::Vector2f(window->getSize().x / 2.0f, 680.0));
	window->draw(*this->getAction());
}

caseSheriff::caseSheriff(sf::Font* pixelArrows, sf::Font* fontPixel, sf::Font* fontTitre) : Case(1, 1, 1, 6, pixelArrows, fontPixel, fontTitre) { }
void caseSheriff::afficher(sf::RenderWindow* window) {
	this->getFlecheG()->setFillColor(sf::Color::Green);
	this->getFlecheH()->setFillColor(sf::Color::Green);
	this->getFlecheD()->setFillColor(sf::Color::Green);

	this->getTexte()->setString("Utilisez les fleches\n pour vous déplacer\n  et [ESPACE] pour\n    vous arreter");
	sf::FloatRect aideRect = this->getTexte()->getLocalBounds();
	this->getTexte()->setOrigin(aideRect.left + aideRect.width / 2.0f, aideRect.top + aideRect.height / 2.0f);
	this->getTexte()->setPosition(250, 700.0);

	Case::afficher(window);
	window->draw(*this->getTexte());
};
void caseSheriff::actionCase(sf::RenderWindow* window, Joueur* leJoueur) {

	this->getAction()->setFillColor(sf::Color::Red);
	this->getAction()->setCharacterSize(35);
	this->getAction()->setString("LE SHERIF DE LA VILLE VOUS ARRETE !");
	sf::FloatRect actionRect = this->getAction()->getLocalBounds();
	this->getAction()->setOrigin(actionRect.left + actionRect.width / 2.0f, actionRect.top + actionRect.height / 2.0f);
	this->getAction()->setPosition(window->getSize().x / 2.0f, 100.0);
	window->draw(*this->getAction());

	if (leJoueur->getArgent() > 15) {
		this->getAction()->setFillColor(sf::Color::Yellow);
		this->getAction()->setCharacterSize(30);
		this->getAction()->setString("Vous lui proposez une contrepartie financière...");
		actionRect = this->getAction()->getLocalBounds();
		this->getAction()->setOrigin(actionRect.left + actionRect.width / 2.0f, actionRect.top + actionRect.height / 2.0f);
		this->getAction()->setPosition(window->getSize().x / 2.0f, 250.0);
		window->draw(*this->getAction());

		this->getAction()->setFillColor(sf::Color::Yellow);
		this->getAction()->setCharacterSize(30);
			this->getAction()->setString(" Il accepte votre proposition\net vous relâche mine de rien !");
			actionRect = this->getAction()->getLocalBounds();
			this->getAction()->setOrigin(actionRect.left + actionRect.width / 2.0f, actionRect.top + actionRect.height / 2.0f);
			this->getAction()->setPosition(window->getSize().x / 2.0f, 350.0);
			window->draw(*this->getAction());

			this->getAction()->setFillColor(sf::Color::Red);
			this->getAction()->setCharacterSize(35);
			this->getAction()->setString("Vous perdez la moitié de vôtre argent !");
			actionRect = this->getAction()->getLocalBounds();
			this->getAction()->setOrigin(actionRect.left + actionRect.width / 2.0f, actionRect.top + actionRect.height / 2.0f);
			this->getAction()->setPosition(window->getSize().x / 2.0f, 500.0);
			window->draw(*this->getAction());
			leJoueur->addArgent(-(leJoueur->getArgent() / 2));
	}
	else {
		this->getAction()->setFillColor(sf::Color::Yellow);
		this->getAction()->setCharacterSize(30);
		this->getAction()->setString("Vous n'avez pas assez d'argent !");
		actionRect = this->getAction()->getLocalBounds();
		this->getAction()->setOrigin(actionRect.left + actionRect.width / 2.0f, actionRect.top + actionRect.height / 2.0f);
		this->getAction()->setPosition(window->getSize().x / 2.0f, 250.0);
		window->draw(*this->getAction());

		this->getAction()->setString("Vous ne pouvez pas graisser la patte du Sherif !");
		actionRect = this->getAction()->getLocalBounds();
		this->getAction()->setOrigin(actionRect.left + actionRect.width / 2.0f, actionRect.top + actionRect.height / 2.0f);
		this->getAction()->setPosition(window->getSize().x / 2.0f, 350.0);
		window->draw(*this->getAction());

		this->getAction()->setFillColor(sf::Color::Red);
		this->getAction()->setCharacterSize(35);
		this->getAction()->setString("Vous êtes emmené au pénitencier !");
		actionRect = this->getAction()->getLocalBounds();
		this->getAction()->setOrigin(actionRect.left + actionRect.width / 2.0f, actionRect.top + actionRect.height / 2.0f);
		this->getAction()->setPosition(window->getSize().x / 2.0f, 500.0);
		window->draw(*this->getAction());
	
		leJoueur->setFin(4);
	}

	this->getAction()->setCharacterSize(30);
	this->getAction()->setFillColor(sf::Color::Yellow);
	this->getAction()->setString("Appuyez sur [ESPACE] pour continuer");
	actionRect = this->getAction()->getLocalBounds();
	this->getAction()->setOrigin(actionRect.left + actionRect.width / 2.0f, actionRect.top);
	this->getAction()->setPosition(sf::Vector2f(window->getSize().x / 2.0f, 680.0));
	window->draw(*this->getAction());
}

caseRien::caseRien(sf::Font* pixelArrows, sf::Font* fontPixel, sf::Font* fontTitre) : Case(1, 1, 1, 0, pixelArrows, fontPixel, fontTitre) { }
void caseRien::afficher(sf::RenderWindow* window) {
	this->getFlecheG()->setFillColor(sf::Color::Green);
	this->getFlecheH()->setFillColor(sf::Color::Green);
	this->getFlecheD()->setFillColor(sf::Color::Green);

	this->getTexte()->setString("Utilisez les fleches\n pour vous déplacer\n  et [ESPACE] pour\n    vous arreter");
	sf::FloatRect aideRect = this->getTexte()->getLocalBounds();
	this->getTexte()->setOrigin(aideRect.left + aideRect.width / 2.0f, aideRect.top + aideRect.height / 2.0f);
	this->getTexte()->setPosition(250, 700.0);

	Case::afficher(window);
	window->draw(*this->getTexte());
};