#include "../include/person.hpp"
#include "../include/heathly.hpp"

Heathly::Heathly(int x, int y) : Person(x, y) {
    this->shape = sf::CircleShape shape(3);
    this->shape.setFillColor(sf::Color::Green, 125);
}

Heathly::~Heathly() {
}