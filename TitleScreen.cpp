#include "TitleScreen.h"

TitleScreen::TitleScreen(sf::Font* fontTitre, sf::Font* fontPixel, sf::RenderWindow* window) {
    this->titre = new sf::Text();
    this->titre->setCharacterSize(80);
    this->titre->setFillColor(sf::Color::Yellow);
    this->titre->setFont(*fontTitre);
    this->titre->setString("FAR WEST");
    sf::FloatRect titreRect = this->titre->getLocalBounds();
    this->titre->setOrigin(titreRect.left + titreRect.width / 2.0f,
        titreRect.top + titreRect.height / 2.0f);
    this->titre->setPosition(sf::Vector2f(window->getSize().x / 2.0f, window->getSize().y / 2.8f));

    this->credits = new sf::Text;
    this->credits->setFont(*fontPixel);
    this->credits->setCharacterSize(30);
    this->credits->setFillColor(sf::Color::Red);
    this->credits->setString("ANTOINE DEYRIS VOUS PRESENTE");
    sf::FloatRect creditsRect = this->credits->getLocalBounds();
    this->credits->setOrigin(creditsRect.left + creditsRect.width / 2.0f,
        creditsRect.top + creditsRect.height / 2.0f);
    this->credits->setPosition(sf::Vector2f(window->getSize().x / 2.0f, window->getSize().y / 6.0f));

    this->version = new sf::Text;
    this->version->setFont(*fontPixel);
    this->version->setCharacterSize(25);
    this->version->setFillColor(sf::Color::White);
    this->version->setString("version BETA");
    sf::FloatRect verRect = this->version->getLocalBounds();
    this->version->setOrigin(verRect.left + verRect.width / 2.0f,
        verRect.top + verRect.height / 2.0f);
    this->version->setPosition(sf::Vector2f(window->getSize().x / 2.0f, window->getSize().y / 2.0f));

    this->trigger = new sf::Text;
    this->trigger->setFont(*fontPixel);
    this->trigger->setCharacterSize(35);
    this->trigger->setFillColor(sf::Color::Yellow);
    this->trigger->setString("APPUYEZ SUR [ESPACE] POUR COMMENCER\n  OU SUR [R] POUR LIRE LES REGLES");
    sf::FloatRect textRect = this->trigger->getLocalBounds();
    this->trigger->setOrigin(textRect.left + textRect.width / 2.0f,
        textRect.top + textRect.height / 2.0f);
    this->trigger->setPosition(sf::Vector2f(window->getSize().x / 2.0f, 5 * (window->getSize().y / 6.0f)));
    
    this->aide = new sf::Text();
    this->wait = new sf::Text();
    //this->tip = new sf::Text();

    this->fin = new sf::Text();
}

void TitleScreen::afficherTitre(sf::RenderWindow* window, sf::Font* fontTitre, sf::Font* fontPixel) {
    this->titre->setFont(*fontTitre);
    this->version->setFont(*fontPixel);
    this->trigger->setFont(*fontPixel);
    this->credits->setFont(*fontPixel);

    window->draw(*this->titre);
    window->draw(*this->trigger);
    window->draw(*this->credits);
    window->draw(*this->version);
}

void TitleScreen::afficherAide(sf::RenderWindow* window, sf::Font* fontTitre, sf::Font* fontPixel) {
    this->aide->setCharacterSize(40);
    this->aide->setFillColor(sf::Color::Red);
    this->aide->setFont(*fontPixel);
    this->aide->setString("Bienvenue dans");
    sf::FloatRect aideRect = this->aide->getLocalBounds();
    this->aide->setOrigin(aideRect.left + aideRect.width / 2.0f,
        aideRect.top + aideRect.height / 2.0f);
    this->aide->setPosition(sf::Vector2f(window->getSize().x / 2.0f, 35.0));
    window->draw(*this->aide);

    this->aide->setCharacterSize(40);
    this->aide->setFillColor(sf::Color::Yellow);
    this->aide->setFont(*fontTitre);
    this->aide->setString("Far West");
    aideRect = this->aide->getLocalBounds();
    this->aide->setOrigin(aideRect.left + aideRect.width / 2.0f,
        aideRect.top + aideRect.height / 2.0f);
    this->aide->setPosition(sf::Vector2f(window->getSize().x / 2.0f, 100.0));
    window->draw(*this->aide);

    this->aide->setCharacterSize(25);
    this->aide->setFillColor(sf::Color::Yellow);
    this->aide->setFont(*fontPixel);
    this->aide->setString("  Votre but est de sortir d'une ville immense perdue en plein\nFar West ! Mais de nombreux obstacles vous barreront la route !\n\nVous partez du sud de la ville et vous devez sortir par le nord.\n     Si vous sortez par l'ouest, vous reviendrez par l'est\n                        et inversement.");
    aideRect = this->aide->getLocalBounds();
    this->aide->setOrigin(aideRect.left + aideRect.width / 2.0f,
        aideRect.top + aideRect.height / 2.0f);
    this->aide->setPosition(sf::Vector2f(window->getSize().x / 2.0f, 230.0));
    window->draw(*this->aide);

    this->aide->setCharacterSize(30);
    this->aide->setFillColor(sf::Color::Red);
    this->aide->setFont(*fontPixel);
    this->aide->setString("Le Soleil vous indiquera toujours le sud.");
    aideRect = this->aide->getLocalBounds();
    this->aide->setOrigin(aideRect.left + aideRect.width / 2.0f,
        aideRect.top + aideRect.height / 2.0f);
    this->aide->setPosition(sf::Vector2f(window->getSize().x / 2.0f, 345.0));
    window->draw(*this->aide);

    this->aide->setCharacterSize(25);
    this->aide->setFillColor(sf::Color::Yellow);
    this->aide->setFont(*fontPixel);
    this->aide->setString("Vous perdez la partie si :");
    aideRect = this->aide->getLocalBounds();
    this->aide->setOrigin(aideRect.left + aideRect.width / 2.0f,
        aideRect.top + aideRect.height / 2.0f);
    this->aide->setPosition(sf::Vector2f(window->getSize().x / 2.0f, 410.0));
    window->draw(*this->aide);

    this->aide->setCharacterSize(30);
    this->aide->setFillColor(sf::Color::Red);
    this->aide->setFont(*fontPixel);
    this->aide->setString("-> Vous n'avez plus de vie\n-> Vous n'avez plus d'argent pour payer\n-> Vous ressortez de la ville par le sud\n-> Vous atteignez les 200 jours");
    aideRect = this->aide->getLocalBounds();
    this->aide->setOrigin(aideRect.left + aideRect.width / 2.0f, aideRect.top);
    this->aide->setPosition(sf::Vector2f(window->getSize().x / 2.0f, 430.0));
    window->draw(*this->aide);

    this->aide->setCharacterSize(25);
    this->aide->setFillColor(sf::Color::Yellow);
    this->aide->setFont(*fontPixel);
    this->aide->setString("Vous gagnez la partie si :");
    aideRect = this->aide->getLocalBounds();
    this->aide->setOrigin(aideRect.left + aideRect.width / 2.0f,
        aideRect.top + aideRect.height / 2.0f);
    this->aide->setPosition(sf::Vector2f(window->getSize().x / 2.0f, 580.0));
    window->draw(*this->aide);

    this->aide->setCharacterSize(30);
    this->aide->setFillColor(sf::Color::Green);
    this->aide->setFont(*fontPixel);
    this->aide->setString("-> Vous ressortez de la ville par le nord");
    aideRect = this->aide->getLocalBounds();
    this->aide->setOrigin(aideRect.left + aideRect.width / 2.0f, aideRect.top);
    this->aide->setPosition(sf::Vector2f(window->getSize().x / 2.0f, 600.0));
    window->draw(*this->aide);

    this->aide->setCharacterSize(30);
    this->aide->setFillColor(sf::Color::Yellow);
    this->aide->setFont(*fontPixel);
    this->aide->setString("Appuyez sur [ESPACE] pour revenir a l'ecran titre");
    aideRect = this->aide->getLocalBounds();
    this->aide->setOrigin(aideRect.left + aideRect.width / 2.0f, aideRect.top);
    this->aide->setPosition(sf::Vector2f(window->getSize().x / 2.0f, 690.0));
    window->draw(*this->aide);
}

void TitleScreen::afficherWait(sf::RenderWindow* window, sf::Font* fontPixel) {
    aide->setCharacterSize(60);
    aide->setFillColor(sf::Color::Yellow);
    aide->setFont(*fontPixel);
    this->aide->setString("VEUILLEZ PATIENTER...\n LA VILLE SE GENERE!");
    sf::FloatRect aideRect = this->aide->getLocalBounds();
    this->aide->setOrigin(aideRect.left + aideRect.width / 2.0f,
        aideRect.top + aideRect.height / 2.0f);
    this->aide->setPosition(sf::Vector2f(window->getSize().x / 2.0f, window->getSize().y / 2.0f));
    window->draw(*this->aide);
}

void TitleScreen::afficherFin(Joueur* leJoueur, sf::RenderWindow* window, sf::Font* fontPixel, sf::Font* fontTitre) {
    sf::FloatRect finRect;

    while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
    {
        sf::Event evnt;
        while (window->pollEvent(evnt))
        {
            switch (evnt.type)
            {
            case sf::Event::Closed:
                window->close();
                break;
            }
        }

        window->clear();

        this->fin->setCharacterSize(80);
        this->fin->setFont(*fontPixel);
        if (leJoueur->getFin() != 1) {
            this->fin->setFillColor(sf::Color::Red);
            this->fin->setString("VOUS AVEZ PERDU !");
        }
        else {
            this->fin->setFillColor(sf::Color::Green);
            this->fin->setString("VICTOIRE !!");
        }
        finRect = this->fin->getLocalBounds();
        this->fin->setOrigin(finRect.left + finRect.width / 2.0f, finRect.top);
        this->fin->setPosition(sf::Vector2f(window->getSize().x / 2.0f, 100.0));
        window->draw(*this->fin);

        this->fin->setCharacterSize(40);
        this->fin->setFont(*fontPixel);
        this->fin->setFillColor(sf::Color::Yellow);
        if (leJoueur->getFin() == 1) {
            this->fin->setString("  Vous vous en êtes enfin sorti !\n       Et ce en " + to_string(leJoueur->getJours()) + " jours !\n\nEssayez de faire mieux lorsque vous\n       repasserez par ici !");
        }
        else if (leJoueur->getFin() == 2) {
            this->fin->setString("Vous êtes ressortis par le sud !\n\n     Vous n'avez aucun sens\n       de l'orientation !");
        }
        else if (leJoueur->getFin() == 3) {
            this->fin->setString("         Vous êtes mort\n troué comme du gruyère périmé !\n\n Essayez d'avoir des balles dans\nvotre revolver la prochaine fois !");
        }
        else if (leJoueur->getFin() == 4) {
            this->fin->setString("Vous finissez vôtre misérable\n    vie au pénitencier\n   à casser des cailloux\n    toute la journée !");
        }
        else if (leJoueur->getFin() == 5) {
            this->fin->setString("Cela fait maintenant 200 jours\n   que vous tournez en rond.\n\n Vous vous écroulez par terre\nde fatigue et de depression...");
        }

        finRect = this->fin->getLocalBounds();
        this->fin->setOrigin(finRect.left + finRect.width / 2.0f, finRect.top);
        this->fin->setPosition(sf::Vector2f(window->getSize().x / 2.0f, 300.0));
        window->draw(*this->fin);

        this->fin->setCharacterSize(30);
        this->fin->setString("Appuyez sur [ESPACE] pour continuer");
        finRect = this->fin->getLocalBounds();
        this->fin->setOrigin(finRect.left + finRect.width / 2.0f, finRect.top);
        this->fin->setPosition(sf::Vector2f(window->getSize().x / 2.0f, 680.0));
        window->draw(*this->fin);

        window->display();
    }

}

void TitleScreen::afficherCredits(sf::RenderWindow* window, sf::Font* fontTitre, sf::Font* fontPixel, sf::Font* fontLogo) {
    while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
        window->clear();

        sf::Event evnt;
        while (window->pollEvent(evnt))
        {
            switch (evnt.type)
            {
            case sf::Event::Closed:
                window->close();
                break;
            }
        }

        this->credits->setCharacterSize(40);
        this->credits->setFillColor(sf::Color::Red);
        this->credits->setFont(*fontPixel);
        this->credits->setString("Merci d'avoir joué à");
        sf::FloatRect creditsRect = this->credits->getLocalBounds();
        this->credits->setOrigin(creditsRect.left + creditsRect.width / 2.0f,
            creditsRect.top + creditsRect.height / 2.0f);
        this->credits->setPosition(sf::Vector2f(window->getSize().x / 2.0f, 35.0));
        window->draw(*this->credits);

        this->credits->setCharacterSize(40);
        this->credits->setFillColor(sf::Color::Yellow);
        this->credits->setFont(*fontTitre);
        this->credits->setString("Far West");
        creditsRect = this->credits->getLocalBounds();
        this->credits->setOrigin(creditsRect.left + creditsRect.width / 2.0f,
            creditsRect.top + creditsRect.height / 2.0f);
        this->credits->setPosition(sf::Vector2f(window->getSize().x / 2.0f, 100.0));
        window->draw(*this->credits);

        this->credits->setCharacterSize(25);
        this->credits->setFillColor(sf::Color::Yellow);
        this->credits->setFont(*fontPixel);
        this->credits->setString("Far West est un jeu original créé et imaginé par Antoine Deyris.\n   Il a été développé en 7 jours dans le cadre du projet C++\n           de fin de première année à l'EPSI Nantes.");
        creditsRect = this->credits->getLocalBounds();
        this->credits->setOrigin(creditsRect.left + creditsRect.width / 2.0f,
            creditsRect.top + creditsRect.height / 2.0f);
        this->credits->setPosition(sf::Vector2f(window->getSize().x / 2.0f, 190.0));
        window->draw(*this->credits);

        this->credits->setCharacterSize(30);
        this->credits->setFillColor(sf::Color::Yellow);
        this->credits->setFont(*fontPixel);
        this->credits->setString("Far West est fortement inspiré du jeu");
        creditsRect = this->credits->getLocalBounds();
        this->credits->setOrigin(creditsRect.left + creditsRect.width / 2.0f,
            creditsRect.top + creditsRect.height / 2.0f);
        this->credits->setPosition(sf::Vector2f(window->getSize().x / 2.0f, 285.0));
        window->draw(*this->credits);

        this->credits->setCharacterSize(40);
        this->credits->setFillColor(sf::Color::Red);
        this->credits->setFont(*fontPixel);
        this->credits->setString("La Ville Infernale");
            creditsRect = this->credits->getLocalBounds();
        this->credits->setOrigin(creditsRect.left + creditsRect.width / 2.0f,
            creditsRect.top + creditsRect.height / 2.0f);
        this->credits->setPosition(sf::Vector2f(window->getSize().x / 2.0f, 325.0));
        window->draw(*this->credits);

        this->credits->setCharacterSize(30);
        this->credits->setFillColor(sf::Color::Yellow);
        this->credits->setFont(*fontPixel);
        this->credits->setString("sorti sur Amstrad CPC en 1985.");
        creditsRect = this->credits->getLocalBounds();
        this->credits->setOrigin(creditsRect.left + creditsRect.width / 2.0f,
            creditsRect.top + creditsRect.height / 2.0f);
        this->credits->setPosition(sf::Vector2f(window->getSize().x / 2.0f, 362.0));
        window->draw(*this->credits);

        this->credits->setCharacterSize(30);
        this->credits->setFillColor(sf::Color::Red);
        this->credits->setFont(*fontPixel);
        this->credits->setString("Remerciements spéciaux :");
        creditsRect = this->credits->getLocalBounds();
        this->credits->setOrigin(creditsRect.left + creditsRect.width / 2.0f,
            creditsRect.top + creditsRect.height / 2.0f);
        this->credits->setPosition(sf::Vector2f(window->getSize().x / 2.0f, 450.0));
        window->draw(*this->credits);

        this->credits->setCharacterSize(30);
        this->credits->setFillColor(sf::Color::Yellow);
        this->credits->setFont(*fontPixel);
        this->credits->setString("       Jean Gautier (Alpha tester)\n          Bartho (Alpha tester)\nL'Auberge (Soutient moral & Alpha testers)");
        creditsRect = this->credits->getLocalBounds();
        this->credits->setOrigin(creditsRect.left + creditsRect.width / 2.0f, creditsRect.top);
        this->credits->setPosition(sf::Vector2f(window->getSize().x / 2.0f, 480.0));
        window->draw(*this->credits);

        this->credits->setCharacterSize(30);
        this->credits->setFillColor(sf::Color::Red);
        this->credits->setFont(*fontPixel);
        this->credits->setString("Et de manière générale à tous ceux qui ont soutenu\n          de près ou de loin le projet !");
        creditsRect = this->credits->getLocalBounds();
        this->credits->setOrigin(creditsRect.left + creditsRect.width / 2.0f, creditsRect.top);
        this->credits->setPosition(sf::Vector2f(window->getSize().x / 2.0f, 590.0));
        window->draw(*this->credits);

        this->credits->setCharacterSize(30);
        this->credits->setFillColor(sf::Color::Yellow);
        this->credits->setFont(*fontPixel);
        this->credits->setString("Appuyez sur [ESPACE] pour quitter le jeu");
        creditsRect = this->credits->getLocalBounds();
        this->credits->setOrigin(creditsRect.left + creditsRect.width / 2.0f, creditsRect.top);
        this->credits->setPosition(sf::Vector2f(window->getSize().x / 2.0f, 700.0));
        window->draw(*this->credits);

        window->display();
    }
}