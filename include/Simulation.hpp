#ifndef SIMULATION_SIMULATION_HPP
#define SIMULATION_SIMULATION_HPP

#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

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

    vector<int> timeVec;
    vector<int> susceptiblesVec;
    vector<int> zombiesVec;
};

#endif
