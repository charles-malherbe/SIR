#ifndef SIMULATION_SIZR_HPP
#define SIMULATION_SIZR_HPP

#include "Simulation.hpp"

class Sizr : public Simulation {
    public:
        Sizr();
        ~Sizr();

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

        vector<int> infectedVec;
        vector<int> removedVec;

        void draw();
};

#endif
