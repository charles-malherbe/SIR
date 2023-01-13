
#include "../include/person.hpp"
#include "../include/recovered.hpp"

Recovered::Recovered(int x, int y) : Person(x, y) {
    sf::CircleShape circle;
    circle.setRadius(1);
    circle.setFillColor(sf::Color::Magenta);
    this->shape = circle;
}

Recovered::~Recovered() {
}