#ifndef SIR_PERSON_H
#define SIR_PERSON_H

#include "position.hpp"

class Person {

    public:
        Person(Position position);
        ~Person();
        Position getPosition();
        void setPosition(Position position);

    private:
        Position position;

};

#endif