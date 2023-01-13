#include "../include/person.hpp"
#include "../include/sick.hpp"

Sick::Sick(int x, int y) : Person(x, y) {
    sf::CircleShape circle;
    circle.setRadius(1);
    circle.setFillColor(sf::Color::Red);
    this->shape = circle;
}

Sick::~Sick() {
}