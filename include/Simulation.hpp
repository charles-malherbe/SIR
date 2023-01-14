#ifndef SIMULATION_SIMULATION_HPP
#define SIMULATION_SIMULATION_HPP

#include <string>
#include <iostream>
using namespace std;
#include <sciplot/sciplot.hpp>
using namespace sciplot;

class Simulation {
public:
    Simulation();
    ~Simulation();

    virtual void calculate() = 0;
    virtual void display() = 0;

protected:
    int timeMax; // Time
    int time = 1; // Time

    int susceptibles; // Susceptible (s)
    int zombies; // Zombies (z)
};

#endif
