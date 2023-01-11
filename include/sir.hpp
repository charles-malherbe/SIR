#ifndef SIR_SIR_H
#define SIR_SIR_H

#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include <cmath>
#include <stdio.h>
#include <iostream>
using namespace std;

#include "disease.hpp"
#include "population.hpp"

Disease getDisease();

Population getPopulation();

#endif