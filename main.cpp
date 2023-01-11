#include "./include/population.hpp"
#include "./include/simulation.hpp"
#include "./include/disease.hpp"
#include "./include/sir.hpp"

int main() {
    Population population = getPopulation();
    Disease disease = getDisease();
    Simulation simulation = Simulation(population, disease);
    simulation.run();
    return 0;
}

Population getPopulation()
{
    int size;
    int infected;
    cout << BLUE << "Entrer la taille de la population : " << PURPLE;
    cin >> size;
    cout << BLUE << "Entrer le nombre de personnes infectées : " << PURPLE;
    cin >> infected;
    Population population(size, infected, 0, 0);
    return population;
}

Disease getDisease() {
    string name;
    int infectivity;
    int recovery;
    cout << BLUE << "Entrer le nom de la maladie : " << PURPLE;
    cin >> name;
    cout << BLUE <<  "Entrer le taux d'infectiosité : " << PURPLE;
    cin >> infectivity;
    cout << BLUE <<  "Entrer le taux de récupération : " << PURPLE;
    cin >> recovery;
    cout << RESET;
    Disease disease(name, infectivity, recovery);
    return disease;
}