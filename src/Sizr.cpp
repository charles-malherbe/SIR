#include "../include/Sizr.hpp"
#include "../include/Colors.hpp"

Sizr::Sizr() : Simulation() {
    cout << BLUE << "Entrer le nombre de personne morte (R) : " << RESET;
    cin >> this->removed;
}

Sizr::~Sizr() {
}

void Sizr::calculate() {
    cout << endl;
    cout << PURPLE << "Calculating SIZR model..." << RESET << endl;

    while (this->susceptibles > 0) {
        this->display();
        int s1, i1, z1, r1;

        s1 = (0 - this->susceptibles*this->zombies*this->beta - this->susceptibles*this->gamma)*0.0001;
        i1 = (this->susceptibles*this->zombies*this->beta - this->beta*this->infected- this->delta*this->infected)*0.0001;
        z1 = (this->beta*this->infected + this->removed*this->epsilon - this->zombies*this->susceptibles*this->zeta)*0.0001;
        r1 = (this->susceptibles*this->gamma + this->delta*this->infected + this->susceptibles*this->zombies*this->zeta - this->removed*this->epsilon)*0.0001;

        this->susceptibles += s1;
        this->infected += i1;
        this->zombies += z1;
        this->removed += r1;

        this->timeVec.push_back(this->time);
        this->susceptiblesVec.push_back(this->susceptibles);
        this->infectedVec.push_back(this->infected);
        this->zombiesVec.push_back(this->zombies);
        this->removedVec.push_back(this->removed);

        this->time++;
    }
    this->draw();
}

void Sizr::display() {
    cout << endl;
    cout << GREEN << "Time : " << RESET << this->time << endl;
    cout << GREEN  << "Susceptibles : " << RESET << this->susceptibles << endl;
    cout << GREEN  << "Infected : " << RESET << this->infected << endl;
    cout << GREEN  << "Zombies : "  << RESET << this->zombies << endl;
    cout << GREEN  << "Removed : " << RESET << this->removed << endl;
}

void Sizr::draw() {
    cout << endl;
    cout << CYAN  << "End of the world in " << this->time << " cycles !" << RESET  << endl;
    Plot2D plot;
    plot.size(1500, 750);
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
    plot.drawCurve(this->timeVec, this->infectedVec).label("Infected").lineColor("purple");
    plot.drawCurve(this->timeVec, this->zombiesVec).label("Zombies").lineColor("red");
    plot.drawCurve(this->timeVec, this->removedVec).label("Removed").lineColor("cyan");
    Figure fig = {{plot}};
    fig.title("SIZR model");
    fig.palette("dark2");
    Canvas canvas = {{fig}};
    canvas.size(1500,750);
    canvas.show();
    canvas.save("plot_sizr.png");
}