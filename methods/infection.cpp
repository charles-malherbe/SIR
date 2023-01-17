#include <iostream>

using namespace std;

int main()
{
    double H = 500000;
    double Z = 1;
    double M = 0;
    double I = 0;
    
    double H1, Z1, M1, I1;
    
    double cHI = 0.0095; // coeff Humain -> Infecté
    double cIZ = 0.005; // coeff Infecté -> Zombie
    double cHM = 0.0001; // coeff Humain -> Mort
    double cIM = 0.0001; // coeff Infecté -> Mort
    double cMZ = 0.0001; // coeff Mort -> Zombie
    double cZM = 0.005; // coeff Zombie -> Mort

    int compte = 0;

    while (int(H) > 0) {

        //Pour le calcul j'ai considéré que le taux de naissance était de 0

        H1 = (0 - H*Z*cHI - H*cHM)*0.0001;  //calcul de la différence de population d'Humains sur un très court intervalle de temps
        I1 = (H*Z*cHI - cIZ*I- cIM*I)*0.0001; //calcul de la différence de population d'Infectés sur un très court intervalle de temps
        Z1 = (cIZ*I + M*cMZ - Z*H*cZM)*0.0001; //calcul de la différence de population de Zombies sur un très court intervalle de temps
        M1 = (H*cHM + cIM*I + H*Z*cZM - M*cMZ)*0.0001; //calcul de la différence de population de Morts sur un très court intervalle de temps
        
        //On met à jour le nombre d'Humains / Zombies / Infectés / Morts
        
        H = H+H1;
        Z = Z+Z1;
        M = M+M1;
        I = I+I1;
        
        compte++;
    }
    cout<<" Humains : "<<int(H)<<"\n Infectés : "<<int(I)<<"\n Zombies : "<<int(Z)<<"\n Morts : "<<int(M);
    cout<<"\n Il n'y a plus aucun Humain sain après la "<<compte<<"eme iterations";

    return 0;
}