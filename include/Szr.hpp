#ifndef SIMULATION_SIR_HPP
#define SIMULATION_SIR_HPP

#include "Simulation.hpp"
#include "Colors.hpp"

class Szr: public Simulation {
public:
        Szr();
        ~Szr();

        void calculate() override;
        void display() override;

protected:
        int removed; // Removed

        int alpha; // Probability of removal (by decapitation)
        int beta; // Probability of transmission
        int zeta; // Probability of resurrection (if dead)

        void draw();
};

#endif
