#ifndef SIMULATION_SYSTEM_HPP
#define SIMULATION_SYSTEM_HPP

#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
using namespace std;

#include "Sizr.hpp"
#include "Szr.hpp"

class System {
    public:
        System();
        ~System();

        void run();

    private:
        sf::RenderWindow *window;
        sf::Clock clock;
        sf::Time time;
        sf::Font font;
};

#endif