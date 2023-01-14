#include "../include/Szr.hpp"
#include "../include/Colors.hpp"

Szr::Szr() : Simulation() {
    cout << BLUE << "Entrer le nombre de personne retiré (R) : " << RESET;
    cin >> this->removed;
    cout << BLUE << "Entrer le taux de retrait (ALPHA) : " << RESET;
    cin >> this->alpha;
    cout << BLUE << "Entrer le taux de transmission (BETA) : " << RESET;
    cin >> this->beta;
    cout << BLUE << "Entrer le taux de resurrection (ZETA) : " << RESET;
    cin >> this->zeta;
}

Szr::~Szr() {

}

void Szr::calculate() {
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