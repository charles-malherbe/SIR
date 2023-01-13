#include "../include/person.hpp"
#include "../include/heathly.hpp"

Heathly::Heathly(int x, int y) : Person(x, y) {
    sf::CircleShape circle;
    circle.setRadius(1);
    circle.setFillColor(sf::Color::Green);
    this->shape = circle;
}

Heathly::~Heathly() {
}