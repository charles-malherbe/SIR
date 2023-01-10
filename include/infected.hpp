//
// Created by parallels on 1/10/23.
//

#ifndef SIR_INFECTED_H
#define SIR_INFECTED_H
    class Infected extends Person {
        public:
            Infected();
            Infected(const Infected &infected);
            Infected &operator=(const Infected &infected);
            ~Infected();

            void infect(Person &person);
    };
#endif //SIR_INFECTED_H
