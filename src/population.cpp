#include "../include/population.hpp"
#include "../include/sick.hpp"
#include "../include/recovered.hpp"
#include "../include/Heathly.hpp"

Population::Population(int size, int infected, int recovered, int dead) {
    this->size = size;
    this->infected = infected;
    this->recovered = recovered;
    this->dead = dead;
    for (int i = 0; i < size; i++) {
        if (i < infected) {
            people.push_back(Sick());
        } else if (i < infected + recovered) {
            people.push_back(Recovered());
        } else {
            people.push_back(Heathly());
        }
    }
}

Population::~Population() {
}

int Population::getSize() {
    return this->size;
}

Person Population::getPerson(int index) {
    return this->people.at(index);
}

void Population::update() {
    // TODO
}