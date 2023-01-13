#ifndef SIR_SICK_H
#define SIR_SICK_H

#include <stdlib.h>

#include "person.hpp"

class Sick : public Person {

    public:
        Sick(int x, int y);
        ~Sick();
};

#endif