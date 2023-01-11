#include "../include/population.hpp"

Population::Population(int size, int infected, int recovered, int dead) {
    this->size = size;
    this->infected = infected;
    this->recovered = recovered;
    this->dead = dead;
}

Population::~Population() {
}

int Population::getSize() {
    return this->size;
}

int Population::getInfected() {
    return this->infected;
}

int Population::getRecovered() {
    return this->recovered;
}

int Population::getDead() {
    return this->dead;
}

void Population::setInfected(int infected) {
    this->infected = infected;
}

void Population::setRecovered(int recovered) {
    this->recovered = recovered;
}

void Population::setDead(int dead) {
    this->dead = dead;
}

void Population::update() {
    // TODO
}