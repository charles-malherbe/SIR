#include "../include/simulation.hpp"

Simulation::Simulation(Population population, Disease disease) {
    this->population = &population;
    this->disease = &disease;
}

Simulation::~Simulation() {
}

void Simulation::run() {

}