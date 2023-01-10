//
// Created by Charles MALHERBE for SIR Modelisation
//

#ifndef SIR_PERSON_HPP
#define SIR_PERSON_HPP
    class Person {
        public:
            Person();
            Person(const Person &person);
            Person &operator=(const Person &person);
            ~Person();
            int getAge();

    protected:
            int age;
    };
#endif
