#ifndef SIMULATION_SYSTEM_HPP
#define SIMULATION_SYSTEM_HPP

#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

#include "Sizr.hpp"
#include "Szr.hpp"

class System {
    public:
        System();
        ~System();

        void run();
};

#endif