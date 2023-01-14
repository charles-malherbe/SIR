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

    double beta; // Probability of infection
    double theta; // Probability of death
    double epsilon; // Probability of recovery

    void draw();
};

#endif
