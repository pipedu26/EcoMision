#include "AnimalHerido.h"
#include "Explorador.h"

AnimalHerido::AnimalHerido(string especie) {
    this->nombre = "Animal herido (" + especie + ")";
    this->usado = false;
    this->especie = especie;
    this->curado = false;
}

void AnimalHerido::interactuar(Explorador* explorador) {
    if (usado) {
        cout << "  El " << especie << " ya fue curado." << endl;
        return;
    }
    cout << "  Curas al " << especie << " herido..." << endl;
    explorador->aumentarPuntaje(15);
    explorador->perderEnergia(10);
    curado = true;
    usado = true;
}

void AnimalHerido::mostrarInfo() {
    cout << nombre;
    if (usado) {
        cout << " [ya curado]";
    }
    cout << endl;
}
