#include "../include/simulation.hpp"

Simulation::Simulation(Population population, Disease disease) {
    this->population = &population;
    this->disease = &disease;
}

Simulation::~Simulation() {
}

void Simulation::run() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Pandemic - " + this->disease->getName(), sf::Style::Close | sf::Style::Titlebar);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
        this->draw(window);
        window.display();
    }
}

void Simulation::draw(sf::RenderWindow &window) {
    this->drawPeople(window);
    this->drawText(window);
}

void Simulation::drawPeople(sf::RenderWindow &window) {
    for (int i = 0; i < this->population->getSize(); i++) {
        window.draw(this->population->getPerson(i).getShape());
    }
}

void Simulation::drawText(sf::RenderWindow &window) {
    sf::Text text;
    text.setString("Pandemic - " + this->disease->getName());
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Magenta);
    text.setPosition(10, 10);
    window.draw(text);
}