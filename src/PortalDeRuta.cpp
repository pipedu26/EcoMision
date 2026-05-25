#include "PortalDeRuta.h"
#include "Explorador.h"
#include "Zona.h"

PortalDeRuta::PortalDeRuta(Zona* destino) {
    this->nombre = "Portal de ruta";
    this->usado = false;
    this->destino = destino;
}

void PortalDeRuta::interactuar(Explorador* explorador) {
    // el portal mueve al explorador a otra zona
    cout << "  Usas el portal hacia " << destino->getNombre() << "..." << endl;
    explorador->cambiarZona(destino);
    cout << "  Ahora estas en: " << destino->getNombre() << endl;
}

void PortalDeRuta::mostrarInfo() {
    cout << nombre << " -> " << destino->getNombre() << endl;
}
