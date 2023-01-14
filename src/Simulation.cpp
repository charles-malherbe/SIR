#include "../include/Simulation.hpp"
#include "../include/Colors.hpp"

Simulation::Simulation() {
    cout << BLUE << "Entrer le nombre d'occurence (TIME) : " << RESET;
    cin >> this->timeMax;
    cout << BLUE << "Entrer le nombre de personne susceptible d'être infecté (S) : " << RESET;
    cin >> this->susceptibles;
    cout << BLUE << "Entrer le nombre de zombie (Z) : " << RESET;
    cin >> this->zombies;
}

Simulation::~Simulation() {

}