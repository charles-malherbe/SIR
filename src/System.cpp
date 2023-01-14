#include "../include/System.hpp"
#include "../include/Szr.hpp"
#include "../include/Sizr.hpp"
#include "../include/Colors.hpp"

System::System() {
    this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Zombies simulation");
    this->window->setFramerateLimit(60);
    this->window->setVerticalSyncEnabled(true);
    this->window->setKeyRepeatEnabled(false);
    this->window->setActive(true);
}

System::~System() {

}

void System::run() {
    string systemNumber;
    cout << endl;
    cout << YELLOW <<  "Type de modélisation : " << RESET << endl;
    cout << " 1 - SZR" << endl;
    cout << " 2 - SIZR" << endl;
    cout << YELLOW  << "Entrer le nombre correspondant la modélisation choisi : " << RESET;
    cin >> systemNumber;
    cout << endl;
    switch (stoi(systemNumber)) {
        case 1: {
            Szr szr;
            szr.calculate();
            szr.display();
            break;
        }
        case 2: {
            Sizr sizr;
            sizr.calculate();
            sizr.display();
            break;
        }
        default : {
            cout << RED << "Erreur : le type de modélisation n'existe pas " << RESET << endl;
            break;
        }
    }
}