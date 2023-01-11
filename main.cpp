#include "./include/population.hpp"
#include "./include/simulation.hpp"
#include "./include/disease.hpp"
#include "./include/sir.hpp"

int main() {
    /* Population population = getPopulation();
    Disease disease = getDisease();
    Simulation simulation = Simulation(population, disease);
    simulation.run(); */
    return 0;
}

Disease getDisease() {
    string name;
    int infectivity;
    int recovery;
    cout << "Entrer le nom de la maladie : ";
    cin >> name;
    cout << "Entrer le taux d'infectiosité : ";
    cin >> infectivity;
    cout << "Entrer le taux de récupération : ";
    cin >> recovery;
    return Disease(name, infectivity, recovery);
}
/*
Population getPopulation()
{
    int size;
    int infected;
    cout << "Entrer la taille de la population : ";
    cin >> size;
    cout << "Entrer le nombre de personnes infectées : ";
    cin >> infected;
    Population population(size, infected, 0, 0);
    return population;
}
*/