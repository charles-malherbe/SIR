#ifndef SIR_POPULATION_H
#define SIR_POPULATION_H

    class Population {

    public:
        Population(int size, int infected, int recovered, int dead);
        ~Population();
        int getSize();
        int getInfected();
        int getRecovered();
        int getDead();
        void setInfected(int infected);
        void setRecovered(int recovered);
        void setDead(int dead);
        void update();

    private:
        int size;
        int infected;
        int recovered;
        int dead;

    };

#endif
