#ifndef SIR_RECOVERED_H
#define SIR_RECOVERED_H

#include <stdlib.h>

#include "person.hpp"

class Recovered : public Person {

public:
    Recovered(int x, int y);
    ~Recovered();
};

#endif
