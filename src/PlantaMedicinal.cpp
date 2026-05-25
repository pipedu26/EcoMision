#include "PlantaMedicinal.h"
#include "Explorador.h"

PlantaMedicinal::PlantaMedicinal(string propiedades) {
    this->nombre = "Planta medicinal";
    this->usado = false;
    this->propiedades = propiedades;
    this->recolectada = false;
}

void PlantaMedicinal::interactuar(Explorador* explorador) {
    if (usado) {
        cout << "  Esta planta ya fue recolectada." << endl;
        return;
    }
    cout << "  Recolectas la planta medicinal (" << propiedades << ")..." << endl;
    explorador->recolectar("Planta: " + propiedades);
    explorador->recuperarEnergia(10);
    recolectada = true;
    usado = true;
}

void PlantaMedicinal::mostrarInfo() {
    cout << nombre << " - " << propiedades;
    if (usado) {
        cout << " [recolectada]";
    }
    cout << endl;
}
