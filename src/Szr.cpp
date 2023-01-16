#include "../include/Szr.hpp"
#include "../include/Colors.hpp"
#include "../include/matplotlibcpp.hpp"
namespace plt = matplotlibcpp;

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
    plt::plot({1,3,2,4});
    plt::show();
}