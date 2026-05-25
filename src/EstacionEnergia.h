#pragma once
#include "ElementoInteractivo.h"

class EstacionEnergia : public ElementoInteractivo {
private:
    int energiaRecuperada;

public:
    EstacionEnergia(int energiaRecuperada);

    void interactuar(Explorador* explorador);
    void mostrarInfo();
};
