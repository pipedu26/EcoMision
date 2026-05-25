#include "ResiduoContaminante.h"
#include "Explorador.h"

ResiduoContaminante::ResiduoContaminante(string tipo) {
    this->nombre = "Residuo contaminante";
    this->usado = false;
    this->tipo = tipo;
    this->limpiado = false;
}

void ResiduoContaminante::interactuar(Explorador* explorador) {
    if (usado) {
        cout << "  Este residuo ya fue limpiado." << endl;
        return;
    }
    cout << "  Limpias el residuo de tipo \"" << tipo << "\"..." << endl;
    // limpiar el residuo cuesta energia pero da puntos
    explorador->perderEnergia(15);
    explorador->aumentarPuntaje(20);
    limpiado = true;
    usado = true;
}

void ResiduoContaminante::mostrarInfo() {
    cout << nombre << " (" << tipo << ")";
    if (usado) {
        cout << " [limpiado]";
    }
    cout << endl;
}
