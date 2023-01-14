#ifndef SIMULATION_SIRD_HPP
#define SIMULATION_SIRD_HPP

#include "Szr.hpp"

class Sizr : public Szr {
public:
        Sizr();
        ~Sizr();

        void calculate() override;
        void display() override;

protected:
    int incubation; // Time of incubation

    int beta; // Probability of infection
    int theta; // Probability of death
    int epsilon; // Probability of recovery
};

#endif
