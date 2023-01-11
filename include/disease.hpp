#ifndef SIR_DISEASE_H
#define SIR_DISEASE_H

#include <string>
using namespace std;

    class Disease {

    public:
        Disease(const string name, int infectivity, int recovery);
        ~Disease();
        void setInfectivity(double);
        void setRecovery(double);
        double getInfectivity();
        double getRecovery();

    private:
        string name;
        int infectivity;
        int recovery;

    };

#endif