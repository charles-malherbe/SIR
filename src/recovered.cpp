
#include "../include/person.hpp"
#include "../include/recovered.hpp"

Recovered::Recovered(int x, int y) : Person(x, y) {
    this->shape = sf::CircleShape shape(3);
    this->shape.setFillColor(sf::Color::Magenta, 125);
}

Recovered::~Recovered() {
}