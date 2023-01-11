
#include "../include/person.hpp"
#include "../include/position.hpp"

Person::Person(Position position) {
    this->position = position;
}

Person::~Person() {
}

Position Person::getPosition() {
    return this->position;
}

void Person::setPosition(Position position) {
    this->position = position;
}