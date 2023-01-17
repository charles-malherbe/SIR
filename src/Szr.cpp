#include "../include/Szr.hpp"
#include "../include/Colors.hpp"

Szr::Szr() : Simulation() {
    cout << BLUE << "Entrer le nombre de personne morte (R) : " << RESET;
    cin >> this->removed;
    cout << BLUE << "Entrer le taux de transmission Humain -> Zombie (DEFAULT = 0.0095) : " << RESET;
    cin >> this->beta;
    cout << BLUE << "Entrer le taux de retrait Humain -> Mort (DEFAULT = 0.0001) : " << RESET;
    cin >> this->alpha;
    cout << BLUE << "Entrer le taux de resurrection Mort -> Zombie (DEFAULT = 0.0001) : " << RESET;
    cin >> this->zeta;
    cout << BLUE << "Entrer le taux de retrait Zombie -> Mort (DEFAULT = 0.005) : " << RESET;
    cin >> this->gamma;
}

Szr::~Szr() {

}

void Szr::calculate() {
    cout << endl;
    cout << PURPLE << "Calculating SZR model..." << RESET << endl;
    while (this->time < this->timeMax) {
        this->display();
        this->timeVec.push_back(this->time);
        this->susceptibles = this->susceptibles - (this->susceptibles * this->zombies * this->beta + this->susceptibles * this->alpha);
        this->susceptiblesVec.push_back(this->susceptibles);
        this->zombies = this->zombies + (this->susceptibles * this->zombies * this->beta + this->removed * this->zeta - this->zombies * this->susceptibles * this->gamma);
        this->zombiesVec.push_back(this->zombies);
        this->removed = this->removed + (this->susceptibles * this->alpha + this->susceptibles * this->zombies * this->gamma - this->removed * this->zeta);
        this->removedVec.push_back(this->removed);
        this->time++;
    }
    this->draw();
}

void Szr::display() {
    cout << endl;
    cout << GREEN << "Time(s) : " << RESET << this->time << endl;
    cout << GREEN  << "Susceptible(s) : " << RESET << this->susceptibles << endl;
    cout << GREEN  << "Zombie(s) : "  << RESET << this->zombies << endl;
    cout << GREEN  << "Removed : " << RESET << this->removed << endl;
}

void Szr::draw() {
    Plot2D plot;
    plot.fontName("Palatino");
    plot.fontSize(12);
    plot.xlabel("Times");
    plot.ylabel("Population");
    plot.grid().show();
    plot.legend()
        .atTop()
        .fontSize(12)
        .displayHorizontal()
        .displayExpandWidthBy(1);
    plot.drawCurve(this->timeVec, this->susceptiblesVec).label("Susceptibles").lineColor("green");
    plot.drawCurve(this->timeVec, this->zombiesVec).label("Zombies").lineColor("red");
    plot.drawCurve(this->timeVec, this->removedVec).label("Removed").lineColor("blue");
    Figure fig = {{plot}};
    fig.title("SZR model");
    fig.palette("dark2");
    Canvas canvas = {{fig}};
    canvas.size(1500,750);
    canvas.show();
    canvas.save("./render/plot_szr.png");
}