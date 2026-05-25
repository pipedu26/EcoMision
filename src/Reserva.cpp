#include "Reserva.h"

Reserva::Reserva(string codigoInicial) {
    this->codigoInicial = codigoInicial;
}

void Reserva::agregarZona(string codigo, Zona* zona) {
    // guardo la zona con su codigo como clave
    zonas[codigo] = zona;
}

Zona* Reserva::buscarZona(string codigo) {
    if (zonas.count(codigo) > 0) {
        return zonas[codigo];
    }
    return nullptr;
}

string Reserva::getCodigoInicial() {
    return codigoInicial;
}

void Reserva::mostrarZonas() {
    cout << "\n=== Zonas de la reserva ===" << endl;
    for (pair<string, Zona*> par : zonas) {
        cout << "  [" << par.first << "] " << par.second->getNombre() << endl;
    }
}
