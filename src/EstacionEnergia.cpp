#include "EstacionEnergia.h"
#include "Explorador.h"

EstacionEnergia::EstacionEnergia(int energiaRecuperada) {
    this->nombre = "Estacion de energia";
    this->usado = false;
    this->energiaRecuperada = energiaRecuperada;
}

void EstacionEnergia::interactuar(Explorador* explorador) {
    if (usado) {
        cout << "  Esta estacion ya fue usada." << endl;
        return;
    }
    cout << "  Cargas energia en la estacion..." << endl;
    explorador->recuperarEnergia(energiaRecuperada);
    usado = true;
}

void EstacionEnergia::mostrarInfo() {
    cout << nombre << " (+" << energiaRecuperada << " energia)";
    if (usado) {
        cout << " [agotada]";
    }
    cout << endl;
}
