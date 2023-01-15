#ifndef SIMULATION_SIZRT_HPP
#define SIMULATION_SIZRT_HPP

#include "Simulation.hpp"

class Sizrt : public Simulation {
public:
        Sizrt();
        ~Sizrt();

        void calculate() override;
        void display() override;

protected:
    int tauxNaissance = 0; // Time of incubation
    int infected; // Infected
    int removed; // Removed

    double alpha = 0.0095; // Probability of Human -> Infected
    double beta = 0.005; // Probability of Infected -> Zombie

    double gamma = 0.0001; // Probability of Human -> Mort
    double delta = 0.0001; // Probability of Infected -> Mort

    double epsilon = 0.0001; // Probability of Mort -> Zombie
    double zeta = 0.005; // Probability of Zombie -> Mort

    double eta = 0.0045; // Probability of Zombie -> Human

    void draw();
};

#endif
