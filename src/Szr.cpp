#include "../include/Szr.hpp"
#include "../include/Colors.hpp"

Szr::Szr() : Simulation() {
    cout << BLUE << "Entrer le nombre de personne morte (R) : " << RESET;
    cin >> this->removed;
    cout << BLUE << "Entrer le taux de transmission Humain -> Zombie (DEFAULT = 0.0095) : " << RESET;
    cin >> this->beta;
    cout << BLUE << "Entrer le taux de retrait Humain -> Mort (DEFAULT = 0.0001) : " << RESET;
    cin >> this->alpha;
    cout << BLUE << "Entrer le taux de resurrection Mort -> Zombie (DEFAULT = 0.0001) : " << RESET;
    cin >> this->zeta;
    cout << BLUE << "Entrer le taux de retrait Zombie -> Mort (DEFAULT = 0.005) : " << RESET;
    cin >> this->gamma;
}

Szr::~Szr() {

}

void Szr::calculate() {
    cout << endl;
    cout << PURPLE << "Calculating SZR model..." << RESET << endl;
    while (this->time < this->timeMax) {
        this->display();
        this->susceptibles = this->susceptibles - (this->susceptibles * this->zombies * this->beta + this->susceptibles * this->alpha);
        this->zombies = this->zombies + (this->susceptibles * this->zombies * this->beta + this->removed * this->zeta - this->zombies * this->susceptibles * this->gamma);
        this->removed = this->removed + (this->susceptibles * this->alpha + this->susceptibles * this->zombies * this->gamma - this->removed * this->zeta);
        this->time++;
    }
    this->draw();
}

void Szr::display() {
    cout << endl;
    cout << GREEN << "Time : " << RESET << this->time << endl;
    cout << GREEN  << "Susceptibles : " << RESET << this->susceptibles << endl;
    cout << GREEN  << "Zombies : "  << RESET << this->zombies << endl;
    cout << GREEN  << "Removed : " << RESET << this->removed << endl;
}

void Szr::draw() {
    cout << endl;
    cout << YELLOW << "Drawing SZR model..." << RESET << endl;
}