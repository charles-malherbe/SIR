#include "../include/person.hpp"
#include "../include/sick.hpp"

Sick::Sick(int x, int y) : Person(x, y) {
    this->shape = sf::CircleShape shape(3);
    this->shape.setFillColor(sf::Color::Red, 125);
}

Sick::~Sick() {
}