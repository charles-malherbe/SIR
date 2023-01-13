#ifndef SIR_HEATHLY_H
#define SIR_HEATHLY_H

#include <stdlib.h>

#include "person.hpp"

class Heathly : public Person {

    public:
        Heathly(int x, int y);
        ~Heathly();
};

#endif