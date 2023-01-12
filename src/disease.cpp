#include "../include/disease.hpp"

Disease::Disease(const string name, int infectivity, int recovery) {
    this->name = name;
    this->infectivity = infectivity;
    this->recovery = recovery;
}

Disease::~Disease() {
}

void Disease::setInfectivity(double infectivity) {
    this->infectivity = infectivity;
}

void Disease::setRecovery(double recovery) {
    this->recovery = recovery;
}

double Disease::getInfectivity() {
    return this->infectivity;
}

double Disease::getRecovery() {
    return this->recovery;
}
