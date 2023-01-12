#ifndef SIR_PERSON_H
#define SIR_PERSON_H

#include <stdlib.h>

#include "person.hpp"

class Heathly : public Person {

    public:
        Heathly(int x, int y);
        ~Heathly();
};

#endif