#ifndef SIR_POPULATION_H
#define SIR_POPULATION_H

#include <vector>
using namespace std;

#include "person.hpp"

class Population {

public:
    Population(int size, int sick, int recovered, int dead);
    ~Population();
    int getSize();
    Person getPerson(int index);
    void update();

private:
    int size;
    int sick;
    int recovered;
    int dead;
    vector<Person> people;

};

#endif
