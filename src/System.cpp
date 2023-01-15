#include "../include/System.hpp"
#include "../include/Szr.hpp"
#include "../include/Sizr.hpp"
#include "../include/Sizrt.hpp"
#include "../include/Colors.hpp"

System::System() {
    cout << endl;
    cout << YELLOW <<  "Type de modélisation : " << RESET << endl;
    cout << " 1 - SZR" << endl;
    cout << " 2 - SIZR (sans traitement)" << endl;
    cout << " 3 - SIZRT (avec traitement)" << endl;}

System::~System() {

}

void System::run() {
    string systemNumber;
    cout << YELLOW  << "Entrer le nombre correspondant la modélisation choisi : " << RESET;
    cin >> systemNumber;
    cout << endl;
    switch (stoi(systemNumber)) {
        case 1: {
            Szr szr;
            szr.calculate();
            szr.display();
            break;
        }
        case 2: {
            Sizr sizr;
            sizr.calculate();
            sizr.display();
            break;
        }
        case 3: {
            Sizrt sizrt;
            sizrt.calculate();
            sizrt.display();
            break;
        }
        default : {
            cout << RED << "Erreur : le type de modélisation n'existe pas " << RESET << endl;
            break;
        }
    }
}