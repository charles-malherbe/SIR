
#include "../include/person.hpp"

Person::Person(int x, int y) {
    this->shape.setPosition(x, y);
}

Person::~Person() {
}

sf::CircleShape Person::getShape() {
    return shape;
}

void Person::move() {

}
