#include "../include/Sizr.hpp"
#include "../include/Colors.hpp"

Sizr::Sizr() : Simulation() {
    cout << BLUE << "Entrer le nombre de personne morte (R) : " << RESET;
    cin >> this->removed;
    cout << BLUE << "Entrer de nombre de naissance par occurence (DEFAULT = 0) : " << RESET;
    cin >> this->tauxNaissance;
    cout << BLUE << "Entrer le taux de transmission Humain -> Infecté (DEFAULT = 0.0095) : " << RESET;
    cin >> this->alpha;
    cout << BLUE << "Entrer le taux d'infection Infecté -> Zombie (DEFAULT = 0.005) : " << RESET;
    cin >> this->beta;
    cout << BLUE << "Entrer le taux de resurrection Mort -> Zombie (DEFAULT = 0.0001) : " << RESET;
    cin >> this->epsilon;
    cout << BLUE << "Entrer le taux de retrait Humain -> Mort (DEFAULT = 0.0001) : " << RESET;
    cin >> this->gamma;
    cout << BLUE << "Entrer le taux de retrait Infecté -> Mort (DEFAULT = 0.0001) : " << RESET;
    cin >> this->delta;
    cout << BLUE << "Entrer le taux de retrait Zombie -> Mort (DEFAULT = 0.005) : " << RESET;
    cin >> this->zeta;
}

Sizr::~Sizr() {
}

void Sizr::calculate() {
    cout << endl;
    cout << PURPLE << "Calculating SZR model..." << RESET << endl;
    while (this->time < this->timeMax) {
        this->display();
        // Calcul de la différence de population d'Humains sur un très court intervalle de temps
        this->susceptibles = this->susceptibles + (this->tauxNaissance - this->susceptibles * this->zombies * this->alpha - this->susceptibles * this->gamma) * 0.0001;
        // Calcul de la différence de population d'Infectés sur un très court intervalle de temps
        this->infected = this->infected + (this->susceptibles * this->zombies *this->alpha - this->beta * this->infected - this->delta * this->infected) * 0.0001;
        // Calcul de la différence de population de Zombies sur un très court intervalle de temps
        this->zombies = this->zombies + (this->beta * this->infected + this->removed * this->epsilon - this->zombies * this->susceptibles * this->zeta) * 0.0001;
        // Calcul de la différence de population de Morts sur un très court intervalle de temps
        this->removed = this->removed + (this->susceptibles * this->gamma + this->delta * this->infected + this->susceptibles * this->zombies * this->zeta - this->removed * this->epsilon) * 0.0001;
        this->time++;
    }
}

void Sizr::display() {
    cout << endl;
    cout << GREEN << "Time : " << RESET << this->time << endl;
    cout << GREEN  << "Susceptibles : " << RESET << this->susceptibles << endl;
    cout << GREEN  << "Zombies : "  << RESET << this->zombies << endl;
    cout << GREEN  << "Infected : " << RESET << this->infected << endl;
    cout << GREEN  << "Removed : " << RESET << this->removed << endl;
}

void Sizr::draw() {
    cout << endl;
    cout << YELLOW << "Drawing SIZR model..." << RESET << endl;
}