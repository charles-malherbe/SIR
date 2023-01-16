#include "../include/Sizrt.hpp"
#include "../include/Colors.hpp"

Sizrt::Sizrt() : Simulation() {
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
    cout << BLUE << "Entrer le taux de rétablissement Zombie -> Humain (DEFAULT = 0.0045) : " << RESET;
    cin >> this->eta;
}

Sizrt::~Sizrt() {
}

void Sizrt::calculate() {
    cout << endl;
    cout << PURPLE << "Calculating SIZR WITH TREATMENT model..." << RESET << endl;
    while (this->time < this->timeMax) {
        this->display();
        this->timeVec.push_back(this->time);
        // Calcul de la différence de population d'Humains sur un très court intervalle de temps
        this->susceptibles = this->susceptibles + (this->tauxNaissance - this->susceptibles * this->zombies *this->alpha - this->susceptibles * this->epsilon + this->zombies * this->eta) * 0.0001;
        this->susceptiblesVec.push_back(this->susceptibles);
        // Calcul de la différence de population d'Infectés sur un très court intervalle de temps
        this->infected = this->infected + (this->susceptibles * this->zombies * this->alpha - this->beta * this->infected - this->gamma * this->infected) * 0.0001;
        this->infectedVec.push_back(this->infected);
        // Calcul de la différence de population de Zombies sur un très court intervalle de temps
        this->zombies = this->zombies + (this->beta * this->infected + this->removed * this->delta - this->zombies * this->susceptibles * this->zeta - this->zombies * this->eta) * 0.0001;
        this->zombiesVec.push_back(this->zombies);
        // Calcul de la différence de population de Morts sur un très court intervalle de temps
        this->removed = this->removed + (this->susceptibles * this->epsilon + this->gamma * this->infected + this->susceptibles * this->zombies * this->zeta - this->removed * this->delta) * 0.0001;
        this->removedVec.push_back(this->removed);
        this->time++;
    }
}

void Sizrt::display() {
    cout << endl;
    cout << GREEN << "Time : " << RESET << this->time << endl;
    cout << GREEN  << "Susceptibles : " << RESET << this->susceptibles << endl;
    cout << GREEN  << "Infected : " << RESET << this->infected << endl;
    cout << GREEN  << "Zombies : "  << RESET << this->zombies << endl;
    cout << GREEN  << "Removed : " << RESET << this->removed << endl;
}

void Sizrt::draw() {
    cout << endl;
    cout << YELLOW << "Drawing SIZR WITH TREATMENT model..." << RESET << endl;
}