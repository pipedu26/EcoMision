#pragma once
#include "ElementoInteractivo.h"

class Zona;

class PortalDeRuta : public ElementoInteractivo {
private:
    Zona* destino;

public:
    PortalDeRuta(Zona* destino);

    void interactuar(Explorador* explorador);
    void mostrarInfo();
};
