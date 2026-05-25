#pragma once
#include "ElementoInteractivo.h"

class PlantaMedicinal : public ElementoInteractivo {
private:
    string propiedades;
    bool recolectada;

public:
    PlantaMedicinal(string propiedades);

    void interactuar(Explorador* explorador);
    void mostrarInfo();
};
