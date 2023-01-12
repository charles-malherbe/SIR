#ifndef SIR_SIR_H
#define SIR_SIR_H

#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

#include "disease.hpp"
#include "population.hpp"

#define BLUE "\e[1;34m"
#define PURPLE "\e[1;35m"
#define RESET "\e[0m"

Disease getDisease();

Population getPopulation();

#endif