//
// Created by parallels on 1/10/23.
//

#ifndef SIR_DISPLAY_H
#define SIR_DISPLAY_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <map>
#include <list>

class Display {
    public:
        Display();
        Display(const Display &display);
        Display &operator=(const Display &display);
        ~Display();

        void init();
        void run();
        void update();
        void draw();

    private:
        void initWindow();
        void initText();
        void initCircle();
        void initInputs();
        void initButtons();

        void drawCircle();
        void drawText();
        void drawButtons();
        void drawInputs()

};
#endif //SIR_DISPLAY_H
