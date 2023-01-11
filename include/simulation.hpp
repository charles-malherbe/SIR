#ifndef SIR_SIMULATION_H
#define SIR_SIMULATION_H

#include <SFML/Graphics.hpp>

#include "population.hpp"
#include "disease.hpp"

class Simulation {

public:
    Simulation(Population population, Disease disease);
    ~Simulation();

    void run();

private:
    Population *population;
    Disease *disease;

};

#endif
