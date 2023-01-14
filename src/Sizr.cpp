#include "../include/Sizr.hpp"
#include "../include/Colors.hpp"

Sizr::Sizr() : Szr() {
    cout << BLUE << "Entrer le temps d'incubation (I) : " << RESET;
    cin >> this->incubation;
}

Sizr::~Sizr() {
}

void Sizr::calculate() {
    cout << endl;
    cout << PURPLE << "Calculating SZR model..." << RESET << endl;
    while (this->time < this->timeMax) {
        this->susceptibles = this->susceptibles - (this->beta * this->susceptibles * this->zombies);
        this->zombies = this->zombies + (this->beta * this->susceptibles * this->zombies) - (this->alpha * this->zombies);
        this->removed = this->removed + (this->alpha * this->zombies);
        this->susceptibles = this->susceptibles + (this->zeta * this->removed);
        this->removed = this->removed - (this->zeta * this->removed);
        this->display();
        this->time++;
    }
}

void Sizr::display() {
    cout << endl;
    cout << GREEN << "Time : " << RESET << this->time << endl;
    cout << GREEN  << "Susceptibles : " << RESET << this->susceptibles << endl;
    cout << GREEN  << "Zombies : "  << RESET << this->zombies << endl;
    cout << GREEN  << "Removed : " << RESET << this->removed << endl;
}

void Sizr::draw() {
    cout << endl;
    cout << YELLOW << "Drawing SIZR model..." << RESET << endl;
}