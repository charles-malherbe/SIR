#ifndef SIR_SIMULATION_H
#define SIR_SIMULATION_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "population.hpp"
#include "disease.hpp"

class Simulation {

public:
    Simulation(Population population, Disease disease);
    ~Simulation();

    void run();
    void draw(sf::RenderWindow &window);
    void drawPeople(sf::RenderWindow &window);
    void drawText(sf::RenderWindow &window);

private:
    Population *population;
    Disease *disease;

};

#endif
