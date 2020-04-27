// Far West.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Plateau.h"
#include "Case.h"
#include "Joueur.h"
#include "Revolver.h"
#include <Windows.h>
#include "TitleScreen.h"
#include "Interface.h"

using namespace std;

int main()
{
    srand(time(NULL));
    Joueur* leJoueur = new Joueur();
    Interface* theInterface = new Interface(leJoueur->getVie(), leJoueur->getArgent());

    while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {

        theInterface->detectionEvents();
        theInterface->getWindow()->clear();
        theInterface->afficherTitleScreen();
        theInterface->getWindow()->display();
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)) {

            while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
                theInterface->detectionEvents();
                theInterface->getWindow()->clear();
                theInterface->afficherAide();
                theInterface->getWindow()->display();
            }

            while (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) { }
        }
    }

    theInterface->getWindow()->clear();
    theInterface->afficherWait();
    theInterface->getWindow()->display();

    Plateau* lePlateau = new Plateau(99, 99,
        theInterface->getFontArrows(), theInterface->getFontPixel(), theInterface->getFontTitre());
        
    int OldnumeroCase;
    int NewnumeroCase;

    while (leJoueur->getFin() == 0) {

        if (lePlateau->recuperer(leJoueur->getX(), leJoueur->getY())->getType() == 4
            || lePlateau->recuperer(leJoueur->getX(), leJoueur->getY())->getType() == 5
            || lePlateau->recuperer(leJoueur->getX(), leJoueur->getY())->getType() == 6)
        {
            theInterface->getWindow()->clear();
            theInterface->afficherActionCase(lePlateau->recuperer(leJoueur->getX(), leJoueur->getY()), leJoueur);
            theInterface->getWindow()->display();

            while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
            {
                theInterface->detectionEvents();
            }

            while (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {}
        }

        OldnumeroCase = (leJoueur->getY() * 99) + leJoueur->getX();
        NewnumeroCase = OldnumeroCase;

        if (leJoueur->getFin() == 0) {
            while (OldnumeroCase == NewnumeroCase && leJoueur->getFin() == 0) {
                theInterface->getWindow()->clear();

                theInterface->detectionEvents();

                theInterface->afficherInterface(leJoueur->getVie(), leJoueur->getArgent(),
                    leJoueur->getOrientation(), leJoueur->getJours(),
                    lePlateau->recuperer(leJoueur->getX(), leJoueur->getY()), leJoueur->getPistolet());

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)
                    && lePlateau->recuperer(leJoueur->getX(), leJoueur->getY())->getGauche() == 1)
                {
                    while (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {}
                    if (leJoueur->getOrientation() == 1) { leJoueur->deplacement(-1, 0, 1); } //Orientation Nord
                    else if (leJoueur->getOrientation() == 2) { leJoueur->deplacement(0, -1, 1); } //Orientation Est
                    else if (leJoueur->getOrientation() == 3) { leJoueur->deplacement(1, 0, 1); } //Orientation Sud
                    else { leJoueur->deplacement(0, 1, 1); } //Orientation Ouest

                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)
                    && lePlateau->recuperer(leJoueur->getX(), leJoueur->getY())->getHaut() == 1)
                {
                    while (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {}

                    if (leJoueur->getOrientation() == 1) { leJoueur->deplacement(0, 1, 0); } //Orientation Nord
                    else if (leJoueur->getOrientation() == 2) { leJoueur->deplacement(-1, 0, 0); } //Orientation Est
                    else if (leJoueur->getOrientation() == 3) { leJoueur->deplacement(0, -1, 0); } //Orientation Sud
                    else { leJoueur->deplacement(1, 0, 0); } //Orientation Ouest
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)
                    && lePlateau->recuperer(leJoueur->getX(), leJoueur->getY())->getDroite() == 1)
                {
                    while (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {}

                    if (leJoueur->getOrientation() == 1) { leJoueur->deplacement(1, 0, -1); } //Orientation Nord
                    else if (leJoueur->getOrientation() == 2) { leJoueur->deplacement(0, 1, -1); } //Orientation Est
                    else if (leJoueur->getOrientation() == 3) { leJoueur->deplacement(-1, 0, -1); } //Orientation Sud
                    else { leJoueur->deplacement(0, -1, -1); } //Orientation Ouest
                }

                theInterface->getWindow()->display();

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && lePlateau->recuperer(leJoueur->getX(), leJoueur->getY())->getTypeMagasin() != 0) {
                    while (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {}
                    theInterface->getWindow()->clear();
                    theInterface->detectionEvents();
                    theInterface->afficherActionMagasin(lePlateau->recuperer(leJoueur->getX(), leJoueur->getY()), leJoueur);
                    theInterface->getWindow()->display();
                    while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) { theInterface->detectionEvents(); }
                    while (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {}
                }


                NewnumeroCase = (leJoueur->getY() * 99) + leJoueur->getX();
            }
        }
        
    }

    theInterface->afficherFin(leJoueur);
    while (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) { }
    theInterface->afficherCredits();

    delete lePlateau;
    delete leJoueur;
    delete theInterface;
}