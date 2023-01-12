#ifndef SIR_PERSON_H
#define SIR_PERSON_H

#include <stdlib.h>
#include <SFML/Graphics.hpp>

 class Person {

    public:
        Person(int x, int y);
        ~Person();
        sf::CircleShape getShape();
        void move();

    protected:
        sf::CircleShape shape;

};

#endif