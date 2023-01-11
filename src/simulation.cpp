#include "../include/simulation.hpp"

Simulation::Simulation(Population population, Disease disease) {
    this->population = &population;
    this->disease = &disease;
}

Simulation::~Simulation() {
}

void Simulation::run() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Pandemic - " + this->disease.getName(), sf::Style::Close | sf::Style::Titlebar);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
        // DRAW ALL
        window.display();
    }
}