#include "../include/Sizrt.hpp"
#include "../include/Colors.hpp"

Sizrt::Sizrt() : Simulation() {
    cout << BLUE << "Entrer le nombre de personne morte (R) : " << RESET;
    cin >> this->removed;
}

Sizrt::~Sizrt() {
}

void Sizrt::calculate() {
    cout << endl;
    cout << PURPLE << "Calculating SIZR WITH TREATMENT model..." << RESET << endl;
    while (this->susceptibles > 0 && this->zombies > 0 && this->removed > 0 && this->infected > 0) {
        this->display();
        int s1, i1, z1, r1;

        s1 = this->susceptibles + (this->naissance - this->susceptibles * this->zombies * this->alpha - this->susceptibles * this->epsilon + this->zombies * this->eta) * 0.0001;;
        i1 = this->infected + (this->susceptibles * this->zombies * this->alpha - this->beta * this->infected - this->gamma * this->infected) * 0.0001;
        z1 = this->zombies + (this->beta * this->infected + this->removed * this->delta - this->zombies * this->susceptibles * this->zeta - this->zombies * this->eta) * 0.0001;
        r1 = this->removed + (this->susceptibles * this->epsilon + this->gamma * this->infected + this->susceptibles * this->zombies * this->zeta - this->removed * this->delta) * 0.0001;

        this->susceptibles = s1;
        this->infected = i1;
        this->zombies = z1;
        this->removed = r1;

        this->timeVec.push_back(this->time);
        this->susceptiblesVec.push_back(this->susceptibles);
        this->infectedVec.push_back(this->infected);
        this->zombiesVec.push_back(this->zombies);
        this->removedVec.push_back(this->removed);

        this->time++;
    }
    this->draw();
}

void Sizrt::display() {
    cout << endl;
    cout << GREEN << "Time(s) : " << RESET << this->time << endl;
    cout << GREEN  << "Susceptible(s) : " << RESET << this->susceptibles << endl;
    cout << GREEN  << "Infected : " << RESET << this->infected << endl;
    cout << GREEN  << "Zombie(s) : "  << RESET << this->zombies << endl;
    cout << GREEN  << "Removed : " << RESET << this->removed << endl;
}

void Sizrt::draw() {
    cout << endl;
    cout << CYAN  << "End of the world in " << this->time << " cycles !" << RESET  << endl;
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
    plot.drawCurve(this->timeVec, this->infectedVec).label("Infected").lineColor("purple");
    plot.drawCurve(this->timeVec, this->zombiesVec).label("Zombies").lineColor("red");
    plot.drawCurve(this->timeVec, this->removedVec).label("Removed").lineColor("yelllow");
    Figure fig = {{plot}};
    fig.title("SIZR with treatment model");
    fig.palette("dark2");
    Canvas canvas = {{fig}};
    canvas.size(1500,750);
    canvas.show();
    canvas.save("plot_sizrt.png");
}