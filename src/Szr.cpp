#include "../include/Szr.hpp"
#include "../include/Colors.hpp"

Szr::Szr() : Simulation() {
    cout << BLUE << "Entrer le nombre de personne morte (R) : " << RESET;
    cin >> this->removed;
}

Szr::~Szr() {

}

void Szr::calculate() {
    cout << endl;
    cout << PURPLE << "Calculating SZR model..." << RESET << endl;

    while (this->susceptibles > 0) {
        int s1, z1, r1;

        s1 = this->susceptibles - (this->susceptibles * this->zombies * this->beta + this->susceptibles * this->alpha);
        z1 = this->zombies + (this->susceptibles * this->zombies * this->beta + this->removed * this->zeta - this->zombies * this->susceptibles * this->gamma);
        r1 = this->removed + (this->susceptibles * this->alpha + this->susceptibles * this->zombies * this->gamma - this->removed * this->zeta);

        this->susceptibles = s1;
        this->zombies = z1;
        this->removed = r1;

        this->timeVec.push_back(this->time);
        this->susceptiblesVec.push_back(this->susceptibles);
        this->zombiesVec.push_back(this->zombies);
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
    cout << endl;
    cout << CYAN  << "End of the world in " << this->time << " cycle(s) !" << RESET  << endl;
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
    canvas.save("plot_szr.png");
}