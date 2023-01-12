#ifndef SIR_PERSON_H
#define SIR_PERSON_H

#include <stdlib.h>

#include "person.hpp"

class Sick : public Person {

    public:
        Sick(int x, int y);
        ~Sick();
};

#endif