#include "../include/population.hpp"
#include "../include/sick.hpp"
#include "../include/recovered.hpp"
#include "../include/heathly.hpp"

Population::Population(int size, int sick, int recovered, int dead) {
    this->size = size;
    this->sick = sick;
    this->recovered = recovered;
    this->dead = dead;
    for (int i = 0; i < size; i++) {
        if (i < sick) {
            people.push_back(Sick(0,0));
        } else if (i < sick + recovered) {
            people.push_back(Recovered(0,0));
        } else {
            people.push_back(Heathly(0,0));
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