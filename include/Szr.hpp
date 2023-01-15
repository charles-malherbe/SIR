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

        double beta = 0.0095; // Probability of Human -> Zombie
        double alpha = 0.0001; // Probability of Human -> Removed
        double zeta = 0.0001; // Probability of Removed -> Zombie
        double gamma = 0.005; // Probability of Zombie -> Removed

        void draw();
};

#endif
